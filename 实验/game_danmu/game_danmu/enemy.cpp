#include "all.h"

using namespace std;

enemy enemy_live[21];
extern double difficult_num;
extern bullet en_bullet[1005];

enemy enemy_set()
{
	enemy p;
	p.en_shoot_cd = rand() % 20 + 10;
	p.x = 1000 + rand() % 280;
	p.y = rand() % 2;
	if (p.y == 1) {
		p.y = 700 - p.r; //下边界
		p.vy = -rand() % 10 - 5;
	}
	else {
		p.y = 0 + p.r;//上边界
		p.vy = rand() % 10 + 5;
	}

	p.vx = -rand() % 10 - 5 ;

	return p;
}

bool en_move(enemy& X) 
{
//	X.vx += X.ax;
//	X.vy += X.ay;
//	if (X.vx * X.ax >= 0)X.vx = X.ax = 0;
//	if (X.vy * X.ay >= 0)X.vy = X.ay = 0;

	X.x = X.x + X.vx;
	X.y = X.y + X.vy;
	if (X.x - X.r <= 0)return false;
	if (X.y - X.r <= 0) {
		X.y = X.r;
		X.vy = -X.vy;
	}
	if (X.x + X.r >= window_width)return false;//超出边界
	if (X.y + X.r >= window_hight) {
		X.y = window_hight-X.r;
		X.vy = -X.vy;
	}
	return true;
}

void en_output(enemy X, COLORREF C)
{
	setfillcolor(C);
	setlinecolor(C);
	fillcircle(X.x, X.y, X.r);
}

bullet en_shoot(enemy X)
{
	bullet p;
	p.x = X.x - X.r - p.r;
	p.y = X.y;
	p.vx = -rand() % 10 -5;
	p.vy = 0;
	
	return p;
}

void enemy_shoot_work(int enemy_num)
{
	for (int i = 1; i <= enemy_num; ++i){
		if (enemy_live[i].en_now_bullet_num < enemy_live[i].en_max_bullet_num){
			
			if (enemy_live[i].en_shoot_cd > 0)enemy_live[i].en_shoot_cd--;
			else {
				enemy_live[i].enemy_bullet[++enemy_live[i].en_now_bullet_num] = en_shoot(enemy_live[i]);
				enemy_live[i].en_shoot_cd = rand() % 20 + 10;
			}
		}
	}
}

bool hit_check(enemy X, bullet C)
{
	double dis = sqrt((X.x - C.x) * (X.x - C.x) + (X.y - C.y) * (X.y - C.y));
	double dis_2 = X.r + C.r + difficult_num*2;
	if (dis_2 - dis > 0.00001)return 1;
	else return 0;
}

bool enemy_move_work(int& enemy_num,player s)
{
	for (int i = 1; i <= enemy_num; ++i)
	{
		en_output(enemy_live[i], BLACK);
		if (en_move(enemy_live[i]) == false) {//敌人出界
			for (int j = 1; j <= enemy_live[i].en_now_bullet_num; ++j)//处理敌人发射的子弹
			{
				bu_output(enemy_live[i].enemy_bullet[j], BLACK);
			}
			for (int j = i; j < enemy_num; ++j) {
				enemy_live[j] = enemy_live[j + 1];
			}
			enemy_num--;
			continue;
		}
		en_output(enemy_live[i], BLUE);

		for (int j = 1; j <= enemy_live[i].en_now_bullet_num; ++j)//处理敌人发射的子弹
		{
			bu_output(enemy_live[i].enemy_bullet[j], BLACK);
			if (bullet_move(enemy_live[i].enemy_bullet[j], GREEN) == false) {

				for (int k = j; k < enemy_live[i].en_now_bullet_num; ++k) {
					enemy_live[i].enemy_bullet[k] = enemy_live[i].enemy_bullet[k + 1];
				}
				enemy_live[i].en_now_bullet_num--;
				continue;
			}
			else if (hit_check(s, enemy_live[i].enemy_bullet[j])) {
				FlushBatchDraw();
				EndBatchDraw();
				return 1;
			//	return 0;//无敌
			}

			bu_output(enemy_live[i].enemy_bullet[j], GREEN);
		}

	}
	return 0;
}
