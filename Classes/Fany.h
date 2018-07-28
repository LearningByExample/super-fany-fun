#ifndef __FANY_H__
#define __FANY_H__

#include "cocos2d.h"

class Fany : public cocos2d::Sprite
{
public:
  virtual bool init();

  // implement the "static create()" method manually
  CREATE_FUNC(Fany);

  inline const float getSpeed()
  {
    return speed;
  }

  virtual void update(float delta);

private:
  float speed;
  cocos2d::Animation *anim;

  unsigned const int MAX_SPEED = 10.0F;
  const float BASE_ANIM_SPEED = 0.05f;
};

#endif // __FANY_H__
