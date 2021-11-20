#include "header.h"

void Setup()
{
    gameover=false;
    dir_move=STOP;
    // initial place of snake
    x=width/2;
    y=height/2;
    // initial place of food
    foodx= rand()% width;
    foody= rand()% height;
    score=0;
}
void Draw()
{
    system("cls");
    cout<<"           SCORE "<<score<<endl;
    for(int i=0; i<width+1; i++)
        cout<< "$";                     // print the outlines
    cout<<endl;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(j==0 || j==width-1)
                cout<<'$';              // print the outlines


            if(i==y && j==x)
                cout<<"O";          // print the snake head
            else if(i==foody && j==foodx)
                cout<<"*";          // print the food
            else
            {
                    // print the snake body
                    bool print=false;
                    for(int k=0; k<tail_len; ++k)
                    {
                        if(tailx[k]==j && taily[k]==i)
                        {
                            cout<<"o";
                            print= true;
                        }
                    }
                    if(!print)
                        cout<<" ";          // print spaces for the background
            }

        }
        cout<<endl;
    }
    for(int i=0; i<width+1; i++)
        cout<< "$";                     // print the outlines
    cout<<endl;
}
void Input()
{
    if(_kbhit())            // check if a button is pressed
    {
        switch(_getch())    // getch return the ascii of pressed char
        {
        case Left:
            dir_move = LEFT;
            break;
        case Right:
            dir_move = RIGHT;
            break;
        case Up:
            dir_move = UP;
            break;
        case Down:
            dir_move = DOWN;
            break;
        case Quit:
            gameover= true;
            break;
        default:
            break;
        }

    }

}
void Logic()
{
    // initiate the body position
    int prevx=tailx[0] , prevy=taily[0];
    int prevx2 , prevy2;
    tailx[0]=x;         taily[0]=y;
    // shape the snake body
    for(int i=1; i<tail_len; i++)
    {
        prevx2=tailx[i];    prevy2=taily[i];
        tailx[i]=prevx;     taily[i]=prevy;
        prevx=prevx2;       prevy=prevy2;
        tailx[0]=x;         taily[0]=y;

    }
    // check direction of move to place the snake head
    switch(dir_move)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case STOP:
        break;
    default:
        break;
    }
    // not allowed to touch the outlines
    if(x>=width || x<0 || y<0 || y>=height)
    {
        gameover=true;
    }
    // not allowed for the head of snake to touch body
    for(int i=0; i<tail_len; i++)
    {
        if(tailx[i]==x && taily[i]==y)
            gameover=true;
    }
    // change food place when eaten and increase score
    if(x== foodx && y== foody)
    {
        score+=5;
        foodx= rand()% (width-1);
        foody= rand()% (height-1);
        tail_len++;
    }
}
