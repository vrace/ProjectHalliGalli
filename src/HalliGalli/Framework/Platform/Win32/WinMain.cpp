#include <Windows.h>
#include <windowsx.h>
#include <assert.h>
#include <stdio.h>
#include "../../GameApp.h"
#include "../../Render/Render.h"
#include "../../Input/InputManager.h"

namespace
{
	const TCHAR GameAppName[] = TEXT("GameApp");
	const double SecondPerFrame = 1.0 / 60.0;

	bool mouseDown = false;

	LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (iMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		case WM_LBUTTONDOWN:
			mouseDown = true;
			InputManager::GetInstance().PushTapInput(teDown, 0, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;

		case WM_LBUTTONUP:
			mouseDown = false;
			InputManager::GetInstance().PushTapInput(teUp, 0, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;

		case WM_MOUSEMOVE:
			if (mouseDown)
				InputManager::GetInstance().PushTapInput(teMove, 0, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;

		default:
			break;
		}

		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}

	void RegisterWndClass(HINSTANCE hInstance)
	{
		WNDCLASSEX wndclass;

		wndclass.cbSize = sizeof(wndclass);
		wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		wndclass.lpfnWndProc = WndProc;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInstance;
		wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndclass.hbrBackground = GetStockBrush(BLACK_BRUSH);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = GameAppName;
		wndclass.hIconSm = wndclass.hIcon;

		RegisterClassEx(&wndclass);
	}

	HWND CreateGameWindow(HINSTANCE hInstance)
	{
		RECT rc = { 0, 0, theApp->ScreenWidth(), theApp->ScreenHeight() };
		DWORD style = WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX;
		AdjustWindowRect(&rc, style, FALSE);

		int width = rc.right - rc.left;
		int height = rc.bottom - rc.top;
		int x = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
		int y = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;

		return CreateWindow(GameAppName, GameAppName, style,
			x, y, width, height, NULL, NULL, hInstance, NULL);
	}

	void SetupPixelFormat(HDC hdc)
	{
		PIXELFORMATDESCRIPTOR desc = { 0 };
		desc.nSize = sizeof(desc);
		desc.nVersion = 1;
		desc.cColorBits = 32;
		desc.cDepthBits = 16;
		desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL;
		desc.iPixelType = PFD_TYPE_RGBA;
		desc.iLayerType = PFD_MAIN_PLANE;

		int pf = ChoosePixelFormat(hdc, &desc);
		SetPixelFormat(hdc, pf, &desc);
	}

	HGLRC SetupOpenGL(HDC hdc)
	{
		HGLRC hrc = wglCreateContext(hdc);
		wglMakeCurrent(hdc, hrc);

		glViewport(0, 0, theApp->ScreenWidth(), theApp->ScreenHeight());
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		glShadeModel(GL_SMOOTH);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glClearColor(0, 0, 0, 1);
		glClearDepth(1);

		printf("Vendor: %s\n", glGetString(GL_VENDOR));
		printf("Renderer: %s\n", glGetString(GL_RENDERER));
		printf("Version: %s\n", glGetString(GL_VERSION));

		return hrc;
	}

	void RunLoop(HINSTANCE hInstance, HWND hwnd)
	{
		HDC hdc = GetDC(hwnd);
		SetupPixelFormat(hdc);

		HGLRC hrc = SetupOpenGL(hdc);

		ShowWindow(hwnd, SW_NORMAL);
		UpdateWindow(hwnd);

		MSG msg;

		LARGE_INTEGER freq;
		LARGE_INTEGER timer;

		QueryPerformanceFrequency(&freq);
		QueryPerformanceCounter(&timer);

		theApp->Init();

		while (1)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
			{
				if (GetMessage(&msg, NULL, 0, 0))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					break;
				}
			}
			else
			{
				LARGE_INTEGER tick;
				QueryPerformanceCounter(&tick);

				double delta = (double)(tick.QuadPart - timer.QuadPart) / (double)freq.QuadPart;

				if (delta >= SecondPerFrame)
				{
					timer = tick;
					theApp->Frame((float)delta);
					SwapBuffers(hdc);
				}
			}
		}

		theApp->Exit();

		wglMakeCurrent(hdc, NULL);
		wglDeleteContext(hrc);

		ReleaseDC(hwnd, hdc);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);

	theApp = GameAppCreate();
	assert(theApp != NULL);

	RegisterWndClass(hInstance);
	HWND hwnd = CreateGameWindow(hInstance);

	RunLoop(hInstance, hwnd);

	GameAppDestroy(theApp);
	theApp = NULL;

	FreeConsole();

	return 0;
}
