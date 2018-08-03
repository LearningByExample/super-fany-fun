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
  const cocos2d::Vec2 bottomLeft = cocos2d::Vec2(0.0f, 0.0f);

  enum BlockStatus
  {
    Starting,
    Bulding,
    Ending
  };
  BlockStatus status;

  void changeState(BlockStatus newStatus);

  void onStarting();
  void onBulding();
  void onEnding();

  int blocksBuilt;
  int maxBlockToBuild;
  int currentBlockPositionX;
  int totalBlocksAdded;

  const unsigned short int INITIAL_TAG = 1024;
  const unsigned short int BLOCK_GAP = 20;

  int getBlockSpritNumberFromStatus();
  void addNewBlock();

  unsigned short int getInitialNumberOfBlocksToBuild();
};

#endif /* __GAMEMAP_H__ */
