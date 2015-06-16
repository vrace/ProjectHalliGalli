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
};

GameApp* CreateGameApp();
void DestroyGameApp(GameApp *app);

#endif
