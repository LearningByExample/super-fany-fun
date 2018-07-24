#include "BackGround.h"

USING_NS_CC;

bool BackGround::init()
{
    auto bottomLeft = Vec2(0.0f, 0.0f);
    this->setAnchorPoint(bottomLeft);

    auto layer1 = Sprite::create("sprites/backgrounds/forest.png");
    layer1->setAnchorPoint(bottomLeft);
    layer1->setPosition(0.0f, 0.0f);
    this->addChild(layer1);

    this->layerWidth = layer1->getContentSize().width;
    auto height = layer1->getContentSize().height;

    auto layer2 = Sprite::create("sprites/backgrounds/forest.png");
    layer2->setAnchorPoint(bottomLeft);
    layer2->setPosition(layerWidth, 0.0f);
    this->addChild(layer2);

    auto layer3 = Sprite::create("sprites/backgrounds/forest.png");
    layer3->setAnchorPoint(bottomLeft);
    layer3->setPosition(layerWidth * 2, 0.0f);
    this->addChild(layer3);

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
