#include "all.h"

using namespace std;
int pl_max_bullet_num = 3;
bullet pl_bullet[101];
extern double difficult_num;
extern enemy enemy_live[21];
extern bullet en_bullet[1005];
extern int score;

void pl_move(player& X) {
	X.vx += X.ax;
	X.vy += X.ay;
	if (X.vx * X.ax >= 0)X.vx = X.ax = 0;
	if (X.vy * X.ay >= 0)X.vy = X.ay = 0;

	X.x = X.x + X.vx;
	X.y = X.y + X.vy;
	if (X.x - X.r <= 0)X.x = X.r;
	if (X.y - X.r <= 0)X.y = X.r;
	if (X.x + X.r >= window_width)X.x = window_width - X.r;
	if (X.y + X.r >= window_hight)X.y = window_hight - X.r;
}
void pl_output(player X, COLORREF C)
{
	setfillcolor(C);
	setlinecolor(C);
	fillcircle(X.x, X.y,X.r);
}
bool hit_check(player X, bullet C)
{
	double dis = sqrt((X.x - C.x) * (X.x - C.x) + (X.y - C.y) * (X.y - C.y));
	double dis_2 = X.r + C.r - difficult_num;
	if (dis_2 - dis > 0.00001)return 1;
	else return 0;
}

void pl_shoot(player X,int& pl_now_bullet_num)
{
	if (pl_now_bullet_num < pl_max_bullet_num)
	{//��ǰֱ�߷����ӵ�
		pl_bullet[++pl_now_bullet_num].r = 10;
		pl_bullet[pl_now_bullet_num].x = X.x + X.r + pl_bullet[pl_now_bullet_num].r;
		pl_bullet[pl_now_bullet_num].y = X.y;
		pl_bullet[pl_now_bullet_num].vx = 10;
		pl_bullet[pl_now_bullet_num].vy = 0;

	}
	return;
}
void pl_bullet_move(int& pl_now_bullet_num, int& bullet_num, int& enemy_num)
{
	for (int i = 1; i <= pl_now_bullet_num; ++i)//���������ӵ�
	{
		bu_output(pl_bullet[i], BLACK);
		if (bullet_move(pl_bullet[i],YELLOW) == false) {//�ӵ�������ʧ
			//	free(pl_bullet[i]);
			for (int j = i; j < pl_now_bullet_num; ++j)
				pl_bullet[j] = pl_bullet[j + 1];
			pl_now_bullet_num--;
			continue;
		}
		else {
			for (int k = 1; k <= bullet_num; ++k){//�ж��Ƿ����Ŀ��(�ӵ�)
				if (hit_check(en_bullet[k], pl_bullet[i])) {//����
					//enemy_killed(enemy_live[k]); ��������
					bu_output(en_bullet[k], BLACK);
					for (int j = k; j < bullet_num; ++j)
						en_bullet[j] = en_bullet[j + 1];
					bullet_num--;

					//	continue;
				}
			}
			for (int k = 1; k <= enemy_num; ++k)//�ж��Ƿ����Ŀ��(����)
			{
				if (hit_check(enemy_live[k], pl_bullet[i])) {//����
					//enemy_killed(enemy_live[k]); ��������
					en_output(enemy_live[k], BLACK);
					for (int j = 1; j <= enemy_live[i].en_now_bullet_num; ++j)//������˷�����ӵ�
					{
						bu_output(enemy_live[i].enemy_bullet[j], BLACK);
					}
					for (int j = k; j < enemy_num; ++j)
						enemy_live[j] = enemy_live[j + 1];
					enemy_num--;
					score++;
					continue;
				}
			}
			bu_output(pl_bullet[i],YELLOW);

		}
	}
}

void pl_bullet_num_output(int pl_now_bullet_num, int pl_max_bullet_num)//������ʾ
{
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 30;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ

	settextcolor(WHITE);
	outtextxy(10, 10, _T("�ӵ���"));
	TCHAR s[15];
	_stprintf_s(s, _T("%d/%d"), pl_max_bullet_num - pl_now_bullet_num, pl_max_bullet_num);
	outtextxy(100, 10, s);

}
