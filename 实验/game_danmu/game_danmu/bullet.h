#pragma once

#include "mstruct.h"

bullet bullet_set();
bool bullet_move(bullet& X, COLORREF C);
void bu_output(bullet X, COLORREF C);
bool hit_check(bullet X, bullet C);
bool bullet_move_work(int& bullet_num,player s);
