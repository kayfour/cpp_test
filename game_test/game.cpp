#include "game.h"

using namespace std;


int randrange(int low,int high)   /* generates a random number within given range*/
{
    return rand()%(high-low+1)+low;     
}


//  get random postion for enemy site
void GetRandom(Enemy Enemys[10],std::set<int>x,std::set<int>y)
{
     while( x.size() < 10 )
    {
        x.insert( rand() % 100 );
        y.insert( rand() % 100 );
    }

    for(std::set<int>::iterator it=x.begin();it!=x.end();++it)
    {
        static int i = 0;
        Enemys[i].position[0] = *it;
        i++;
    }
    for(std::set<int>::iterator it=y.begin();it!=y.end();++it)
    {
        static int i = 0;
        Enemys[i].position[1] = *it;
        i++;
    }
}  

//  Set position enemy and me
void SetPosition(Background bgd,Enemy Enemys[10],Me me)
{
    for(int i =0;i<10;i++)
    {
        if(Enemys[i].LiveOrDie == false )
        {
            Enemys[i].print='0';
            bgd.obj_ene[Enemys[i].position[0]][Enemys[i].position[1]] = Enemys[i].print;
        }
        else
        {
            bgd.obj_ene[Enemys[i].position[0]][Enemys[i].position[1]] = Enemys[i].print;
        }
        
    }
    bgd.obj_me[0] = me.position[0]; 
    bgd.obj_me[1] = me.position[1]; 

    printf("내 위치 - x: %d y: %d",me.position[0],me.position[1]);
    //std::cout<<"내 위치 - x:"<<me.position[0]<<" y:"<<me.position[1]<<std::endl;
}

//  moving to enemy
bool MovePosition(int *pos_x,int *pos_y,Enemy Enemys[10])
{
    int x=0,y=0;
    bool setpos= false;
    char sel;
    for(int i =0 ; i<10 ; i++)
    {
        if( Enemys[i].position[0]==*pos_x && Enemys[i].position[1]==*pos_y && Enemys[i].LiveOrDie)
        {
            printf("적을 공격하시겠습니까? yes = y : ");
            scanf("%c",&sel);
            if(sel == 'y' || sel == 'Y')
            {
                return true;
            }
            else break;
        }
    }

    printf("x축 위치를 입력하세요 : ");
    scanf("%d",pos_x);
    printf("y축 위치를 입력하세요 : ");
    scanf("%d",pos_y);

    return false;
}

//  check all enemies live or die
bool live(Enemy Enemys[10])
{
    int live = 0;
    for(int i = 0;i<10;i++)
    {
        if(Enemys[i].LiveOrDie == true)
            live +=1;
    }

    if (live != 0)
        return true;
    else 
        return false;
}

//  if i'm in same position with enemy, decrease -3 hp of enemy
void attack(Me me,Enemy Enemys[10])
{
    bool attack = false;
    int count = 0;
    random_device rd;
    mt19937_64 mersenne_twister_engine(rd());
    uniform_int_distribution<> dice(0,6);


    for (int i = 0; i<10; i++)
    {
        if (me.position[0]==Enemys[i].position[0] && me.position[1]==Enemys[i].position[1] )
        {
       
            printf("\n 적을 공격합니다.\n");
            int dm = dice(mersenne_twister_engine);
            *(&Enemys[i].hp) = Enemys[i].hp - dm;
            printf("Enemy %d 에게 %d 의 데미지를 주었습니다.",i,dm);
            if(Enemys[i].hp <0)
            {
                *(&Enemys[i].hp) = 0;
                *(&Enemys[i].LiveOrDie)= false;  
                std::cout<<"Enemy"<<i<<"가 죽었습니다"<<std::endl;     
            }      
       
        }
        else if(count==9)
        {
            std::cout<<"가까운 곳에 적이 없습니다!"<<std::endl;
            count++;
        }
        else
        {
            count++;
        }
        
    }


          
}