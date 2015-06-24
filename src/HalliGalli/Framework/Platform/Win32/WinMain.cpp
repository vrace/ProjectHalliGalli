#include <Windows.h>
#include <windowsx.h>
#include <assert.h>
#include "../../GameApp.h"

namespace
{
	const TCHAR GameAppName[] = TEXT("GameApp");

	LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (iMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			break;
		}

		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}

	void RegisterWndClass(HINSTANCE hInstance)
	{
		WNDCLASSEX wndclass;

		wndclass.cbSize = sizeof(wndclass);
		wndclass.style = CS_HREDRAW | CS_VREDRAW;
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

	void RunLoop(HINSTANCE hInstance, HWND hwnd)
	{
		ShowWindow(hwnd, SW_NORMAL);
		UpdateWindow(hwnd);

		MSG msg;

		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	theApp = GameAppCreate();
	assert(theApp != NULL);

	RegisterWndClass(hInstance);
	HWND hwnd = CreateGameWindow(hInstance);

	RunLoop(hInstance, hwnd);

	GameAppDestroy(theApp);
	theApp = NULL;

	return 0;
}
