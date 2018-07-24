#ifndef __FANY_H__
#define __FANY_H__

#include "cocos2d.h"

class Fany : public cocos2d::Sprite
{
  public:
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(Fany);

  private:
    virtual void update(float delta);
};

#endif // __FANY_H__
