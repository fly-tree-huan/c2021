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
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 50;
	_tcscpy_s(f.lfFaceName, _T("����"));
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ

	settextcolor(WHITE);
	outtextxy(400, 100, _T("������򣬺��������������"));
	f.lfHeight = 33;
	settextstyle(&f);
	outtextxy(700, 230, _T("___v0.65"));

	setlinecolor(WHITE);
	rectangle(450, 370, 650, 420);
	
	f.lfHeight = 46;
	settextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("����"));
	outtextxy(480, 372, _T("��  ʼ"));

	setlinecolor(WHITE);
	rectangle(450, 470, 650, 520);

	f.lfHeight = 46;
	settextstyle(&f);
	_tcscpy_s(f.lfFaceName, _T("����"));
	outtextxy(480, 472, _T("��  ��"));

	f.lfHeight = 100;
	outtextxy(700, 350, _T("��ߵ÷�:"));
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

		case WM_LBUTTONDOWN: // ��������
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
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 200;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	outtextxy(300, 200, _T("DIED!"));    	// ��ȡ��ǰ��������
	f.lfHeight = 100;
	outtextxy(200, 400, _T("�÷�:"));
	TCHAR s[15];
	_stprintf_s(s, _T("%d"), score);	
	outtextxy(700, 400, s);

	return;
}
void game_ready()
{
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 400;						// ��������߶�Ϊ 48
	_tcscpy_s(f.lfFaceName, _T("����"));	// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	outtextxy(300, 200, _T("3!"));
	Sleep(1000);
	outtextxy(300, 200, _T("2!"));
	Sleep(1000);
	outtextxy(300, 200, _T("1!"));
	Sleep(1000);
	outtextxy(300, 200, _T("��ʼ"));
	Sleep(100);
	cleardevice();

	return;
}