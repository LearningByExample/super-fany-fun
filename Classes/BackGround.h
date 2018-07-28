#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"

class BackGround : public cocos2d::Node
{
public:
  static BackGround *create(std::string fileName);
  virtual bool init(std::string fileName);

  void scroll(float amount);

private:
  float layerWidth;
};

#endif // __BACKGROUND_H__
