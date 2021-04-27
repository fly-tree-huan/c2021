#include "all.h"

using namespace std;
bool flag_exit=0;
int highest_score = 0;
int score = 0;

void muen_output()
{
	setbkcolor(BLACK);
	cleardevice();
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 50;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式

	settextcolor(WHITE);
	outtextxy(400, 100, _T("躲避绿球，红球；消灭红球，蓝球"));
	f.lfHeight = 33;
	settextstyle(&f);
	outtextxy(700, 230, _T("___v0.65"));

	setlinecolor(WHITE);
	rectangle(450, 370, 650, 420);
	
	f.lfHeight = 46;
	settextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("宋体"));
	outtextxy(480, 372, _T("开  始"));

	setlinecolor(WHITE);
	rectangle(450, 470, 650, 520);

	f.lfHeight = 46;
	settextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("宋体"));
	outtextxy(480, 472, _T("退  出"));

	f.lfHeight = 100;
	outtextxy(700, 350, _T("最高得分:"));
	TCHAR s[15];
	_stprintf_s(s, _T("%d"), highest_score);
	outtextxy(1000, 350, s);

	return;
}

bool mouse_hit(MOUSEMSG m, int left, int top, int right, int bottom)
{
	if (m.x >= left && m.x <= right && m.y >= top && m.y <= bottom)return 1;
	return 0;
}

void muen()
{
	muen_output();

	while (1)
	{
		MOUSEMSG m = GetMouseMsg();

		switch (m.uMsg)
		{

		case WM_LBUTTONDOWN: // 如果点左键
			if (mouse_hit(m, 450, 370, 650, 420)) {
				return;
			}
			else if (mouse_hit(m, 450, 470, 650, 520)) {
				flag_exit = 1;
				return;
			}break;
		case WM_RBUTTONUP:break;
		}
	}
	return;
}
void game_over()
{
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 200;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	outtextxy(300, 200, _T("DIED!"));    	// 获取当前字体设置
	f.lfHeight = 100;
	outtextxy(200, 400, _T("得分:"));
	TCHAR s[15];
	_stprintf_s(s, _T("%d"), score);	
	outtextxy(700, 400, s);

	return;
}
void game_ready()
{
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 400;						// 设置字体高度为 48
	_tcscpy_s(f.lfFaceName, _T("黑体"));	// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	outtextxy(300, 200, _T("3!"));
	Sleep(1000);
	outtextxy(300, 200, _T("2!"));
	Sleep(1000);
	outtextxy(300, 200, _T("1!"));
	Sleep(1000);
	outtextxy(300, 200, _T("开始"));
	Sleep(100);
	cleardevice();

	return;
}