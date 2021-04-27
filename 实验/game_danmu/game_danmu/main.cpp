#include "all.h"
using namespace std;
extern bool flag_exit;
extern int highest_score;
extern int pl_max_bullet_num;
extern bullet pl_bullet[101];
extern bullet en_bullet[1005];
extern enemy enemy_live[21];
extern int score;
double difficult_num;

int main()
{
	srand((unsigned)time(NULL));
	initgraph(window_width,window_hight);
	setbkcolor(BLACK);
	cleardevice();
	muen();
	
	if (flag_exit) {
		closegraph();
		return 0;
	}

	player s = { 200,300,25,0,0,0,0 };
	int bullet_num = 0;
	int enemy_num = 0;
	difficult_num = 0.5;
	int pl_now_bullet_num = 0;
	
	game_ready();
	clock_t mt_start, mt_end;
	mt_start = clock();

	while (1)
	{
		pl_max_bullet_num = 15;
//		pl_max_bullet_num = min(9, 3 + score / 5);
//		cleardevice();
		if (_kbhit())
		{
			char input = _getch();
			switch (input){
			case 'A':case'a': {
				s.vx = -v0;
				s.ax = a0;
				break;
			}
			case 's':case'S': {
				s.vy = v0;
				s.ay = -a0;
				break;
			}
			case 'D':case'd': {
				s.vx = v0;
				s.ax = -a0;
				break;
			}
			case 'W':case'w': {
				s.vy = -v0;
				s.ay = a0;
				break;
			}
			case 'R': case 'r':{
				setbkcolor(BLACK);
				cleardevice();
				break;
			}
			case ' ':{
				pl_shoot(s, pl_now_bullet_num);
				cleardevice();
				pl_bullet_num_output(pl_now_bullet_num, pl_max_bullet_num);
			}
			default:break;
			}
		}

		BeginBatchDraw();
		pl_output(s, BLACK);
		pl_move(s);
		pl_output(s, WHITE);
		Sleep(10);

		pl_bullet_move(pl_now_bullet_num, bullet_num,enemy_num);
		pl_bullet_num_output(pl_now_bullet_num, pl_max_bullet_num);
		FlushBatchDraw();    //player 相关显示

		if(bullet_num<100)en_bullet[++bullet_num] = bullet_set();
		if (enemy_num < 5)enemy_live[++enemy_num] = enemy_set();//生成敌人
		
		enemy_shoot_work(enemy_num);//处理敌人发射子弹
		if (enemy_move_work(enemy_num,s) == 1)//处理敌人移动
		{

			mt_end = clock();//待修改为函数，下重复
			int endtime = (mt_end - mt_start) / CLOCKS_PER_SEC;
			score = score + endtime;
			highest_score = max(score, highest_score);
			game_over();

			Sleep(1000);
			cleardevice();
			muen();
			if (flag_exit) {
				closegraph();
				return 0;
			}
			score = 0;
			enemy_num = 0;
			bullet_num = 0;
			pl_now_bullet_num = 0;
			game_ready();
			s = { 200,300,25,0,0,0,0 };
			mt_start = clock();

			continue;
		}
		FlushBatchDraw();    //敌人 相关显示


		if (bullet_move_work(bullet_num,s) == 1)//处理敌人子弹移动（待改为函数）
		{
			mt_end = clock();//待修改为函数，与上面重复
			int endtime = (mt_end - mt_start) / CLOCKS_PER_SEC;
			score = score + endtime;
			highest_score = max(score, highest_score);
			game_over();

			Sleep(1000);
			cleardevice();
			muen();
			if (flag_exit) {
				closegraph();
				return 0;
			}
			score = 0;
			enemy_num = 0;
			bullet_num = 0;
			pl_now_bullet_num = 0;
			game_ready();
			s = { 200,300,25,0,0,0,0 };
			mt_start = clock();

			continue;
		}

		FlushBatchDraw();
		EndBatchDraw();
		Sleep(10);
	}
	return 0;
}
