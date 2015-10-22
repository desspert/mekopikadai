#include "Map.h"

///�}�b�v�̃R���X�g���N�^
Map::Map(){
    
    map_list[0] = std::ifstream("res/ahoyama.txt");
    map_list[1] = std::ifstream("res/ahoyama1.txt");
    map_list[2] = std::ifstream("res/ahoyama2.txt");
    map_list[3] = std::ifstream("res/ahoyama3.txt");

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            map_list[0] >> map_chip[y][x];
            if (map_chip[y][x] == 2){
                pos = Vec2f(-BLOCK_SIZE / 2 + x*BLOCK_SIZE, BLOCK_SIZE / 2 - y*BLOCK_SIZE);
            }
        }
    }
    
}

////�}�b�v�̃A�b�v�f�[�g�Ȃ񂾂���
////�܂��{�҂ł͎g��Ȃ�����
////�l�̍l�������Ԉ���Ă��̂���������
void Map::Update(){
    Move();
    DirectionBlock();

    
}

//�}�b�v�̕`�悱��͂܂Ƃ߂Ă悩������������Ȃ�
//�`���͌�ł����Ƃ���Ă����Ă�
void Map::Draw(){
    
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            Vec2f map_pos = Vec2f(-BLOCK_SIZE / 2 + x*BLOCK_SIZE, BLOCK_SIZE / 2 - y*BLOCK_SIZE)-pos;


            switch (map_chip[y][x])
            {
            case 1:
                //std::cout << map_pos << std::endl;
                drawFillBox(map_pos.x() - BLOCK_SIZE / 2, map_pos.y() - BLOCK_SIZE / 2, 200, 200, Color::cyan);
                break;
            }

        }
    }
    

    //drawFillBox(-100, -100, 200, 200, Color::blue);
}


////�}�b�v�𓮂�������
//��������
void Map::Move(){
    /*switch (direction)
    {
    case DIRECTION_UP:
        pos.y() += speed;
        break;
    case DIRECTION_DOWN:
        pos.y() -= speed;
        break;
    case DIRECTION_LEFT:
        pos.x() -= speed;
        break;
    case DIRECTION_RIGHT:
        pos.x() += speed;
        break;
    }*/
    Map::pos -= player_vector;
}

void Map::DirectionBlock()
{
    up_block = 0;
    down_block = 0;
    left_block = 0;
    right_block = 0;

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            Vec2f map_pos = Vec2f(-BLOCK_SIZE / 2 + x*BLOCK_SIZE, BLOCK_SIZE / 2 - y*BLOCK_SIZE) - pos;
            if (collision2(pos, map_pos, Vec2f(BLOCK_SIZE, BLOCK_SIZE))){
                up_block = map_chip[y + 1][x];
                down_block = map_chip[y - 1][x];
                left_block = map_chip[y][x-1];
                right_block = map_chip[y][x+1];
            }
            
        }
    }
    
}

void Map::HitBlock(){

    up_hit = 0;
    down_hit = 0;
    left_hit = 0;
    right_hit = 0;

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            Vec2f map_pos = Vec2f(-BLOCK_SIZE / 2 + x*BLOCK_SIZE, BLOCK_SIZE / 2 - y*BLOCK_SIZE) - pos;
            if (collision2(pos+Vec2f( 0,player_size.y()/2), map_pos, Vec2f(BLOCK_SIZE, BLOCK_SIZE))){
                up_block = map_chip[y + 1][x];
                down_block = map_chip[y - 1][x];
                left_block = map_chip[y][x - 1];
                right_block = map_chip[y][x + 1];
            }

        }
    }

    
}


char Map::UpBlock(){
    return up_block;
}
char Map::DownBlock(){
    return down_block;
}
char Map::LeftBlock(){
    return left_block;
}
char Map::RightBlock(){
    return right_block;
}

bool Map::UpHit(){
    return up_hit;
}
bool Map::DownHit(){
    return down_hit;
}
bool Map::LeftHit(){
    return left_hit;
}
bool Map::RightHit(){
    return right_hit;
}





void Map::SetVector(Vec2f vector){
    player_vector = vector;
}
void Map::SetSize(Vec2f size){
    player_size = size;
}


