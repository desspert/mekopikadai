#pragma once
#include "../lib/framework.hpp"
#include <iostream>
#include "../Singleton.h"
#include "../Collosion/Collision.h"

enum MAP{
    BLOCK_SIZE = 200,
    MAP_WIDTH = 32,
    MAP_HEIGHT = 56

};
 
class Player;

class Map
{
public:
    Map();
    
    
    void Update();
    void Draw();




    ////ここからはゲッターだよー
    ////
    char UpBlock();
    char DownBlock();
    char LeftBlock();
    char RightBlock();

    bool UpHit();
    bool DownHit();
    bool LeftHit();
    bool RightHit();


    
    void Move();
    void DirectionBlock();
    void SetVector(Vec2f vector);
    void SetSize(Vec2f size);

private:
    ////マップのポジションである
    Vec2f pos;
    
    //////マップをテキストから入れるよっと
    std::ifstream map_list[4];
    int map_chip[MAP_HEIGHT][MAP_WIDTH];
    
    //上下左右に何があるかの変数
    char up_block;
    char down_block;
    char left_block;
    char right_block;
    ////上下左右に当たってるかの変数
    bool up_hit;
    bool down_hit;
    bool left_hit;
    bool right_hit;

    /////プレイヤーのどこに当たっているかの処理
    void HitBlock();
    ///////playerの情報を受け取るで
    //////セットする用の変数である
    Vec2f player_vector;
    Vec2f player_size;

};
