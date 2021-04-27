#pragma once
#ifndef   MSTRUCT_H
#define   MSTRUCT_H  

const int window_hight = 700;
const int window_width = 1280;
const int v0 = 10;
const int a0 = 1;

typedef struct player_like //暂时为圆
{
	int x, y;
	int r = 25;

	int vx, vy, ax, ay;

}player;

typedef struct bullet_like //暂时为圆
{
	int x, y;
	int r = 5;

	int vx, vy, ax, ay;

}bullet;

typedef struct enemy_like //暂时为圆
{
	int x, y;
	int r = 22;

	int vx, vy, ax = 0, ay = 0;

	int en_shoot_cd;
	int en_now_bullet_num = 0;
	int en_max_bullet_num = 20;
	bullet enemy_bullet[21];
}enemy;

#endif 