#include "BackGround.h"

USING_NS_CC;

BackGround *BackGround::create(std::string fileName)
{
    BackGround *pRet = new (std::nothrow) BackGround();

    if (pRet && pRet->init(fileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

bool BackGround::init(std::string fileName)
{
    auto bottomLeft = Vec2(0.0f, 0.0f);
    this->setAnchorPoint(bottomLeft);

    auto layerBase = Sprite::create(fileName);
    layerBase->setAnchorPoint(bottomLeft);
    layerBase->setPosition(0.0f, 0.0f);
    this->addChild(layerBase);

    auto screenWidth = Director::getInstance()->getVisibleSize().width;
    auto screenHeight = Director::getInstance()->getVisibleSize().height;
    this->layerWidth = layerBase->getContentSize().width;
    auto layerHeight = layerBase->getContentSize().height;

    float scale = screenHeight / layerHeight;

    layerBase->setScale(scale);

    this->layerWidth *= scale;
    layerHeight *= scale;

    float pos = layerWidth;
    while (pos < (screenWidth + layerWidth))
    {
        auto newLayer = Sprite::createWithSpriteFrame(layerBase->getSpriteFrame());
        newLayer->setAnchorPoint(bottomLeft);
        newLayer->setPosition(pos, 0.0f);
        newLayer->setScale(scale);
        this->addChild(newLayer);

        pos += layerWidth;
    }

    return true;
}

void BackGround::scroll(float amount)
{
    auto pos = this->getPosition();

    pos.x -= amount;

    if ((-pos.x) > this->layerWidth)
    {
        pos.x = 0;
    }

    this->setPosition(pos);
}
