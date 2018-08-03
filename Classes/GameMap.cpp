//
//  GameMap.cpp
//  super-fany-fun
//
//  Created by Juan Antonio Medina Iglesias on 28/07/2018.
//

#include "GameMap.h"

USING_NS_CC;

int GameMap::getBlockSpritNumberFromStatus()
{
    int num = 1;

    switch (status)
    {
    case BlockStatus::Starting:
        num = 1;
        break;
    case BlockStatus::Bulding:
        num = 2;
        break;
    case BlockStatus::Ending:
        num = 3;
        break;
    }

    return num;
}
unsigned short int GameMap::getInitialNumberOfBlocksToBuild()
{
    auto cache = SpriteFrameCache::getInstance();

    auto img = cache->getSpriteFrameByName("2.png");
    auto originalWidth = img->getOriginalSize().width;

    return (int)(Director::getInstance()->getVisibleSize().width / originalWidth) + 1;
}

bool GameMap::init()
{
    this->setAnchorPoint(bottomLeft);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/titles/blocks.plist");

    blocksBuilt = 0;
    currentBlockPositionX = 0;
    totalBlocksAdded = 0;
    status = BlockStatus::Starting;

    for (unsigned short int i = 0; i < getInitialNumberOfBlocksToBuild(); i++)
    {
        addNewBlock();
    }

    return true;
}

void GameMap::addNewBlock()
{
    auto cache = SpriteFrameCache::getInstance();

    char name[255];
    std::snprintf(name, 255, "%d.png", getBlockSpritNumberFromStatus());

    auto block = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(name));
    block->setPosition(currentBlockPositionX, 0.0f);
    block->setAnchorPoint(bottomLeft);

    auto width = block->getContentSize().width - 1;
    currentBlockPositionX += width;
    totalBlocksAdded++;

    block->setTag(INITIAL_TAG + totalBlocksAdded);

    this->addChild(block);

    blocksBuilt++;

    switch (status)
    {
    case BlockStatus::Starting:
        onStarting();
        break;
    case BlockStatus::Bulding:
        onBulding();
        break;

    case BlockStatus::Ending:
        onEnding();
        break;
    }
}
void GameMap::changeState(BlockStatus newStatus)
{
    status = newStatus;
    blocksBuilt = 0;
}

void GameMap::onStarting()
{
    changeState(BlockStatus::Bulding);
    maxBlockToBuild = (rand() % 5) + 1;
}

void GameMap::onBulding()
{
    if (blocksBuilt > maxBlockToBuild)
    {
        changeState(BlockStatus::Ending);
    }
}

void GameMap::onEnding()
{
    changeState(BlockStatus::Starting);
    currentBlockPositionX += BLOCK_GAP;
}

void GameMap::scroll(float amount)
{
    auto pos = this->getPosition();

    pos.x -= amount;

    this->setPosition(pos);

    for (const auto &block : this->getChildren())
    {
        if (block != nullptr)
        {
            auto blockPos = block->getPosition();

            int xPosInScreen = pos.x + blockPos.x;

            if (xPosInScreen < -(block->getContentSize().width))
            {
                this->removeChildByTag(block->getTag());
                addNewBlock();

                break;
            }
        }
    }
}
