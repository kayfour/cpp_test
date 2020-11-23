#include <curses.h>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
#define MIN 1
#define MAX_X COLS-COLS
#define MAX_Y  15
#define OPPONENT 'O'
#define PLAYER '*'
#define WALL 'W'
#define E_TRACE ' '

void constrain(int *val,int max)
{
    if(*val<1) *val = 1;
    else if(*val>max) *val = max;
}

int is_move_ok(int y,int x)
{
    int comp_ch;
    comp_ch = mvinch(y,x);
    return !((comp_ch == 'O'));
}

void breakWall(int command,int x , int y)
{
    bool wall_ex = false;
    int sign = 1;
    for(int i=0; i<4;i++)
    {
        if(i<2)
        {
            sign = int(pow(-1,i));
            wall_ex= is_move_ok(y+sign,x);
        }            
        else
        {
            sign = int(pow(-1,i));
            wall_ex= is_move_ok(y,x+sign);
        }

    }

    if(wall_ex && command == 'a')
    {
        for(int i=0; i<4;i++)
        {
            if(i<2)
            {
                sign = int(pow(-1,i));
                mvaddch(y+sign,x,E_TRACE);
                move(y-sign,x);
            }                
            else
            {
                sign = int(pow(-1,i));
                mvaddch(y,x+sign,E_TRACE);
                move(y,x-sign);
            }
                
        }
    }
}

void command_move(int command,int *x,int *y)
{
    switch (command)
    {
        case  KEY_LEFT:     
            if(is_move_ok(*y,*x-1) && *x != 1)
            {
                *x -=1;
                constrain(x,100);            
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y,*x+1,E_TRACE);  
            }
                
            break;
        case  KEY_RIGHT:
         if( is_move_ok(*y,*x+1))
            {    
                *x +=1; 
                constrain(x,100);
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y,*x-1,E_TRACE);  
            }
            break;
        case  KEY_UP: 
            if( is_move_ok(*y-1,*x))
            {      
                *y -=1; 
                constrain(y,MAX_Y);
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y+1,*x,E_TRACE);  
            }
            break;
        case  KEY_DOWN: 
            if( is_move_ok(*y+1,*x))
            {    
                *y +=1; 
                constrain(y,MAX_Y);
                mvaddch(*y,*x,PLAYER);
                mvaddch(*y-1,*x,E_TRACE);  
            }
            break;    
    }

}

int main()
{
    WINDOW *w;
    w=initscr();
    curs_set(0);        //visible cursor
    //'start main
    keypad(stdscr, TRUE);
    timeout(30); //fps 를 30으로 한정 

    int max_y = LINES-1, max_x =COLS-COLS; // LINES = 가로행 갯수. COLS = 세로열 갯수 둘다 자동으로 할당됨
    int command = 'y';
    int move_x=0, move_y=0;
    printw("%d, %d",LINES,COLS);
    while(1)
    {        
        move(0,0);   
        printw("%d , %d",max_y,max_x);
        command = getch();    //getch (char ch; cin<<ch; 와 동일) 키가 입력될때 까지 대기하는 속성을 이용하여 프로그램 종료를 막음 
        mvaddch(++move_y,++move_x,OPPONENT);
        command_move(command,&max_x,&max_y);     
        breakWall(command,max_x,max_y);
        if(command == 'q' || command == 'Q')
            break;     
            
    }
    //end main  
    endwin(); //자원 반납으로 종료시킴
    return 0;
}


//     string str_var = "max_y,  max_x : "+to_string(int(LINES))+" , "+to_string(int(COLS));
//     mvaddstr(6,4,str_var.c_str()); //.c_str() ->function that change data type char to const char 
