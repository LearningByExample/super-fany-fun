//
//  GameMap.cpp
//  super-fany-fun
//
//  Created by Juan Antonio Medina Iglesias on 28/07/2018.
//

#include "GameMap.h"

USING_NS_CC;

int GameMap::getBlockFromStatus()
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
unsigned short int GameMap::getMaxNumOfBlocks()
{
    auto cache = SpriteFrameCache::getInstance();

    auto img = cache->getSpriteFrameByName("2.png");
    auto originaslWidth = img->getOriginalSize().width;

    return (int)(Director::getInstance()->getVisibleSize().width / originaslWidth) + 1;
}

bool GameMap::init()
{
    this->setAnchorPoint(bottomLeft);

    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("sprites/titles/blocks.plist");

    numBlocks = 0;
    pos = 0;
    totalBlocks = 0;

    status = BlockStatus::Starting;
    for (unsigned short int i = 0; i < getMaxNumOfBlocks(); i++)
    {
        createBlock();
    }

    return true;
}

void GameMap::createBlock()
{
    auto cache = SpriteFrameCache::getInstance();

    char name[255];
    std::snprintf(name, 255, "%d.png", getBlockFromStatus());

    auto block = Sprite::createWithSpriteFrame(cache->getSpriteFrameByName(name));
    block->setPosition(pos, 0.0f);
    block->setAnchorPoint(bottomLeft);
    auto width = block->getContentSize().width - 1;
    pos += width;
    totalBlocks++;
    block->setTag(1024 + totalBlocks);

    this->addChild(block);

    numBlocks++;

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
    numBlocks = 0;
}

void GameMap::onStarting()
{
    changeState(BlockStatus::Bulding);
    maxBuilding = (rand() % 5) + 1;
}

void GameMap::onBulding()
{
    if (numBlocks > maxBuilding)
    {
        changeState(BlockStatus::Ending);
    }
}

void GameMap::onEnding()
{
    changeState(BlockStatus::Starting);
    pos += 5;
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
                createBlock();

                break;
            }
        }
    }
}
