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

    bg = BackGround::create();
    if (bg == nullptr)
    {
        CCLOGERROR("error loading background");
        return false;
    }

    this->addChild(bg);

    fany = Fany::create();
    if (fany == nullptr)
    {
        CCLOGERROR("error loading funy sprite");
        return false;
    }

    this->addChild(fany);

    this->scheduleUpdate();

    CCLOG("game init complete");

    return true;
}

void GameScene::update(float delta)
{
    bg->scroll(delta * 50.0f);
}
