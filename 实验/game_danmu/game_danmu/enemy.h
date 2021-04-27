#pragma once
#ifndef   ENEMY_H
#define   ENEMY_H 

#include "mstruct.h"

enemy enemy_set();
bool en_move(enemy& X);
void en_output(enemy X, COLORREF C);
bool hit_check(enemy X, bullet C);
bullet en_shoot(enemy X);
void enemy_shoot_work(int enemy_num);
bool enemy_move_work(int& enemy_num,player s);


#endif 