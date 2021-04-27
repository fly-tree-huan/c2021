#include "all.h"

using namespace std;
bullet en_bullet[1005];
extern double difficult_num;


bool bullet_move(bullet& X, COLORREF C)
{
	X.x = X.x + X.vx;
	X.y = X.y + X.vy;
	if (C == RED) {
		if (X.x - X.r <= 0)return false;
		if (X.y - X.r <= 0)return false;
		if (X.x + X.r >= window_width)X.x = window_width - X.r, X.vx = -X.vx;
		if (X.y + X.r >= window_hight)return false;
	}
	else if (C == YELLOW){
		if (X.x - X.r <= 0)return false;
		if (X.x + X.r >= window_width)return false;
	}
	else if (C == GREEN)
	{
		if (X.x - X.r <= 0)return false;
		if (X.y - X.r <= 0)return false;
		if (X.x + X.r >= window_width)X.x = window_width - X.r, X.vx = -X.vx;
		if (X.y + X.r >= window_hight)return false;
	}
	return true;
}

void bu_output(bullet X, COLORREF C)
{
	setfillcolor(C);
	setlinecolor(C);
	fillcircle(X.x, X.y, X.r);
}

bullet bullet_set()
{
	bullet p;
	p.x = 1000;
	p.y = rand() % 500 + 100;
	p.vx = -rand() % 15 + 5;
	p.vy = rand() % 10 - 5;
	return p;
}

bool hit_check(bullet X, bullet C)
{
	double dis = (X.x - C.x) * (X.x - C.x) + (X.y - C.y) * (X.y - C.y);
	double dis_2 = (X.r + C.r) * (X.r + C.r) + difficult_num;
	if (dis_2 - dis > 0.00001)return 1;
	else return 0;
}

bool bullet_move_work(int& bullet_num,player s)
{
	for (int i = 1; i <= bullet_num; ++i)
	{
		bu_output(en_bullet[i], BLACK);
		if (bullet_move(en_bullet[i], RED) == false) {

			for (int j = i; j < bullet_num; ++j) {
				en_bullet[j] = en_bullet[j + 1];
			}
			bullet_num--;
		}
		else {

			if (hit_check(s, en_bullet[i])) {
				FlushBatchDraw();
				EndBatchDraw();
				return 1;
		//		return 0;//нч╣п
			}
			bu_output(en_bullet[i], RED);
		}
	}
	return 0;
}