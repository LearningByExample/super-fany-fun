#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Fany.h"
#include "BackGround.h"

class GameScene : public cocos2d::Scene
{
public:
  static cocos2d::Scene *createScene();

  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(GameScene);

  virtual void update(float delta);

private:
  Fany *fany;
  BackGround *bg; 
};

#endif // __GAME_SCENE_H__
