#ifndef header_H
#define header_H

#include<iostream>
#include<conio.h>
#include<windows.h>
#define Up '8'
#define Left '4'
#define Right '6'
#define Down '2'
#define Quit '0'
using namespace std;
bool gameover;
const int height=30;
const int width=30;
int x,y, foodx, foody, score;
int tailx[100],taily[100], tail_len=0;
enum Direction
{
    STOP=0, LEFT,RIGHT,UP,DOWN
};
Direction dir_move;
void Setup();
void Draw();
void Input();
void Logic();

#endif // header_H

