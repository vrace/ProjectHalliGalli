#ifndef __HALLI_GALLI_H__
#define __HALLI_GALLI_H__

#include "Framework/GameApp.h"

class HalliGalliGameApp : public GameApp
{
public:
	HalliGalliGameApp();

	virtual void Init();
	virtual void Exit();

	virtual void Suspend();
	virtual void Resume();

	virtual void Frame();

	virtual int ScreenWidth() const;
	virtual int ScreenHeight() const;
};

#endif
