#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

class BackGround : public cocos2d::Node
{
public:
  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(BackGround);

  void scroll(float amount);

private:
  float layerWidth;
};

#endif // __BACKGROUND_H__
