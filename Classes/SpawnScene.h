//
//  SpawnScene.h
//  Spawn
//
//  Created by MAEDAHAJIME on 2015/03/03.
//
//

#ifndef __Spawn__SpawnScene__
#define __Spawn__SpawnScene__

#include "cocos2d.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class SpawnScene : public cocos2d::Layer
{
protected:
    SpawnScene();
    virtual ~SpawnScene();
    //初期化のメソッド
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(SpawnScene);
    
};

#endif /* defined(__Spawn__SpawnScene__) */
