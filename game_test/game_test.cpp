#include "game.h"
#include <string>

using namespace std;
int main()
{
    Enemy Enemys[10];
    Background bgd;
    Me me1;

    srand((unsigned)time(0));
    std::set<int> x,y;
    GetRandom(Enemys,x,y);
    std::cout<<"게임 스타트!"<<endl<<endl;
    bool bool1;
    while(live(Enemys))
    {
        for(int i =0;i<10;i++)
        {
            std::cout<<" Enemy "<<i<<" postions :"<<Enemys[i].position[0]<<" , "<<Enemys[i].position[1]<<" HP :"<<Enemys[i].hp<<"  "<<Enemys[i].print <<endl;
        }
        bool1 = MovePosition(&me1.position[0],&me1.position[1],Enemys);
        if(bool1)
            attack(me1,Enemys);
        SetPosition(bgd,Enemys,me1);

        
        if(!live)
            std::cout<<" 적을 모두 죽였습니다! 게임을 종료합니다."<<endl;

    }
    
    
}
