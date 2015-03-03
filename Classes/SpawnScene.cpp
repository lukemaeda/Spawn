//
//  SpawnScene.cpp
//  Spawn
//
//  Created by MAEDAHAJIME on 2015/03/03.
//
//

#include "SpawnScene.h"
// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

using namespace std; // String*

SpawnScene::SpawnScene()
{
    
}

SpawnScene::~SpawnScene()
{
    
}

Scene* SpawnScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = SpawnScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

// 「INIT」初期化
bool SpawnScene::init()
{
    if ( !Layer::init() )
    {
        
        return false;
    }
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    Size winSize = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー（ブルー）
    auto background = LayerColor::create(Color4B::BLUE,
                                         winSize.width,
                                         winSize.height);
    this->addChild(background);
    
    //_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
    
    //スプライトの作成
    auto Sprite = Sprite::create("Icon-152.png");
    Size size = Sprite->getContentSize();
    Sprite->setPosition(Vec2(size.width/2, size.height/2));
    this->addChild(Sprite);
    
    //ジャンプのアクション
    auto jumpAction = JumpBy::create(1, Vec2(200, 0), 400, 1);
    
    //回転のアクション
    auto rotateAction = RotateBy::create(1, 360);
    
    //アクションを作成
    auto spawn = Spawn::create(jumpAction, rotateAction, NULL);
    
    //リピート
    auto repeatForever = RepeatForever::create(spawn);
    
    //開始！
    Sprite->runAction(repeatForever);
    
    return true;
}
