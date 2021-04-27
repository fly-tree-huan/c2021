#pragma once

#ifndef   PLAYER_H
#define   PLAYER_H 

#include "mstruct.h"

void pl_move(player& X);
void pl_output(player X, COLORREF C);
bool hit_check(player X, bullet C);
void pl_shoot(player X, int& pl_now_bullet_num);
void pl_bullet_move(int& pl_now_bullet_num, int& bullet_num, int& enemy_num);
void pl_bullet_num_output(int pl_now_bullet_num, int pl_max_bullet_num);


#endif 
