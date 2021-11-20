#include "header.h"
//#include "func.cpp"
int main()
{
    Setup();
    while(!gameover)
    {
        Draw();
        Input();
        Logic();
        Sleep(300); // to slow the game
    }

    return 0;
}
