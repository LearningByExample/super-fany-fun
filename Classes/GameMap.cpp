//
//  GameMap.cpp
//  super-fany-fun
//
//  Created by Juan Antonio Medina Iglesias on 28/07/2018.
//

#include "GameMap.h"

USING_NS_CC;

bool GameMap::init()
{
    auto bottomLeft = Vec2(0.0f, 0.0f);
    this->setAnchorPoint(bottomLeft);

    auto sprite = Sprite::create("sprites/titles/2.png");

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprites/titles/2.png");

    if (sprite == nullptr)
    {
        CCLOG("fail to load titles");
        return false;
    }

    sprite->setAnchorPoint(bottomLeft);
    sprite->setPosition(0.0f, 0.0f);

    auto width = sprite->getContentSize().width;
    auto pos = 0;
    for (unsigned int i = 0; i < 500; i++)
    {
        auto block = Sprite::createWithSpriteFrame(sprite->getSpriteFrame());
        block->setPosition(pos, 0.0f);
        block->setAnchorPoint(bottomLeft);
        pos += width;
        this->addChild(block);
    }

    sprite->setOpacity(0.0f);
    this->addChild(sprite);

    return true;
}

void GameMap::scroll(float amount)
{
    auto pos = this->getPosition();

    pos.x -= amount;

    this->setPosition(pos);
}
