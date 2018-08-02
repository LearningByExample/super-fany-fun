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
  enum BlockStatus
  {
    Starting,
    Bulding,
    Ending

  };

  BlockStatus status;
  int numBlocks;
  int maxBuilding;
  int pos;
  int totalBlocks;
  const cocos2d::Vec2 bottomLeft = cocos2d::Vec2(0.0f, 0.0f);

  std::list<cocos2d::Sprite *> blocks;

  int getBlockFromStatus();

  void onStarting();
  void onBulding();
  void onEnding();

  void changeState(BlockStatus newStatus);

  void createBlock();

  unsigned short int getMaxNumOfBlocks();
};

#endif /* __GAMEMAP_H__ */
