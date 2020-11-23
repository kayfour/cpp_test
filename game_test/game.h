#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <set>
#include <random>

struct Enemy
{
    char print = '*';
    int position[2] = {0,0};
    int hp = 6;
    bool LiveOrDie = true;
};

struct Me
{
    char print = 'X';
    int position[2] = {0,0};
    int hp = 100;
    bool LiveOrDie = true;

};    

struct Background
{
    char size[100][100]= {' '};
    int obj_ene[10][2] = {0};
    int obj_me[2]={0};

};
int randrange(int low,int high);
void GetRandom(Enemy Enemys[10],std::set<int>x,std::set<int>y);
void SetPosition(Background bgd,Enemy Enemys[10],Me me);
bool MovePosition(int *pos_x,int *pos_y,Enemy Enemys[10]);
bool live(Enemy Enemys[10]);
void attack(Me me,Enemy Enemys[10]);


#endif