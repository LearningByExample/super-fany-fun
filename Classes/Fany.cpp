#include "Fany.h"

USING_NS_CC;

bool Fany::init()
{
    auto result = this->initWithFile("sprites/ninja/Run__000.png");

    if (result)
    {
        auto width = Director::getInstance()->getVisibleSize().width;
        this->setAnchorPoint(Vec2(0.5f, 0.0f));
        this->setPosition(width / 2, 0);
        this->setScale(0.5f);
    }

    return result;
}

void Fany::update(float delta)
{
}
