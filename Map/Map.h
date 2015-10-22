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




    ////��������̓Q�b�^�[����[
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
    ////�}�b�v�̃|�W�V�����ł���
    Vec2f pos;
    
    //////�}�b�v���e�L�X�g������������
    std::ifstream map_list[4];
    int map_chip[MAP_HEIGHT][MAP_WIDTH];
    
    //�㉺���E�ɉ������邩�̕ϐ�
    char up_block;
    char down_block;
    char left_block;
    char right_block;
    ////�㉺���E�ɓ������Ă邩�̕ϐ�
    bool up_hit;
    bool down_hit;
    bool left_hit;
    bool right_hit;

    /////�v���C���[�̂ǂ��ɓ������Ă��邩�̏���
    void HitBlock();
    ///////player�̏����󂯎���
    //////�Z�b�g����p�̕ϐ��ł���
    Vec2f player_vector;
    Vec2f player_size;

};
