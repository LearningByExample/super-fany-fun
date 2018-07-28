//
//  GameMap.hpp
//  super-fany-fun
//
//  Created by Juan Antonio Medina Iglesias on 28/07/2018.
//

#ifndef __GAMEMAP_H__
#define __GAMEMAP_H__

#include "cocos2d.h"

class GameMap : public cocos2d::Node
{
public:
  // implement the "static create()" method manually
  CREATE_FUNC(GameMap);
  virtual bool init();

  void scroll(float amount);

private:
  std::list<cocos2d::Sprite*> blocks;
};

#endif /* __GAMEMAP_H__ */
