#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene *GameScene::createScene()
{
    return GameScene::create();
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    fany = Sprite::create("sprites/ninja/Run__000.png");
    if (fany == nullptr)
    {
        log("error loading funy sprite");
        return false;
    }

    fany->setPosition(0, 100);
    fany->setScale(0.5f);

    this->addChild(fany);

    this->scheduleUpdate();

    return true;
}

void GameScene::update(float delta)
{
    auto pos = fany->getPosition();

    pos.x += (50 * delta);

    fany->setPosition(pos);
}
