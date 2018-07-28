#include "Fany.h"

USING_NS_CC;

bool Fany::init()
{
    auto result = this->initWithFile("sprites/ninja/Run__000.png");

    if (result)
    {
        auto width = Director::getInstance()->getVisibleSize().width;
        this->setAnchorPoint(Vec2(0.5f, 0.0f));
        this->setPosition(width / 2, 110.0f);
        this->setScale(0.5f);
    }

    anim = Animation::create();
    for (unsigned short int num = 0; num <= 9; num++)
    {
        char name[255];
        std::snprintf(name, 255, "sprites/ninja/Run__%03d.png", num);
        anim->addSpriteFrameWithFile(name);
    }
    anim->setLoops(-1);
    anim->setDelayPerUnit(BASE_ANIM_SPEED);

    auto animAction = Animate::create(anim);

    this->runAction(animAction);

    speed = 1.0f;

    return result;
}

void Fany::update(float delta)
{
    this->speed += (delta * 1.0f);

    if (speed > MAX_SPEED)
    {
        speed = MAX_SPEED;
    }

    anim->setDelayPerUnit(BASE_ANIM_SPEED * speed);
}
