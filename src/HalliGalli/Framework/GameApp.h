#ifndef __GAME_APP_H__
#define __GAME_APP_H__

class GameApp
{
public:
	GameApp();
	virtual ~GameApp();

	virtual void Init() = 0;
	virtual void Exit() = 0;

	virtual void Suspend() = 0;
	virtual void Resume() = 0;

	virtual void Frame() = 0;

	virtual int ScreenWidth() const = 0;
	virtual int ScreenHeight() const = 0;
};

extern GameApp *theApp;

GameApp* GameAppCreate();
void GameAppDestroy(GameApp *app);

#endif
