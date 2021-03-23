#include<bits/stdc++.h>
#include <windows.h>

using namespace std;
char game_map[55][55],morex;
int n,m,px,py,move_num,map_num,box_num;
char pl_now_name[25];
int wx[11],wy[11];
int pmy[] = {-1,0,0,1};
int pmx[] = {0,1,-1,0};
bool keep_flag = 1,win_flag = 0;
string game_num_num;
void Menu();
void game_open(int x);
void Map_display();
void plmove(int x);
void box_move(int x);
void game_work();
void game_over();
void data_save(int x);
void pl_updata(int x);
bool win_check();
void map_check();
void rank_show();
void rank_reset();




int main()
{
	Menu();
	bool game_keep = 1;
	while(game_keep)
	{
		cin >> map_num;
		if(map_num == 0)
		{
			game_keep = 0;
			break;
		}
		game_open(map_num);
		move_num = 0;
		game_work();
		game_over();
		win_flag = 0;
		keep_flag = 1;
		Menu();
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|            ���˳���Ϸ           |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
} 
void Menu()
{
	system("cls");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|       ��ӭ������������Ϸv0.5    |\n");
	printf("|                                 |\n");
	printf("|           ��ѡ��ؿ�            |\n");
    printf("|          ����ؿ�����           |\n");
    printf("|          Ŀǰ:1 to 1            |\n");
    printf("|                                 |\n");
    printf("|           0���˳���Ϸ           |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return ;
}
void game_open(int x)
{
	int x_game=x;
	string game_num_front = "pushBoxesgame",game_num_tail = ".txt";
	while(x)
	{
		game_num_num = char( x % 10 + '0') + game_num_num;
		x /= 10;
	}
	string game_num_name=game_num_front + game_num_num + game_num_tail;

	FILE *fp=fopen(game_num_name.c_str(),"r");
	fscanf(fp,"%d%d%d%d",&n,&m,&px,&py);
	box_num = 0;
	for(int i=1;i<=n;++i)
	{
		fscanf(fp,"%s",&game_map[i]);
		for(int j=1;j<=m;++j)
		if(game_map[i][j] == '@')
		{
			wx[++box_num] = i;
			wy[box_num] = j;
		}
	}
	fclose(fp);

	return ;
}
void Map_display()
{
	map_check();
	system("cls");
	for(int i=1;i<=n;++i)
	printf("%s\n",game_map[i]);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("������wasd�����ƶ�\n");
	printf("����p����\n");
	printf("����n�鿴����\n");
	printf("����r��������\n");
}
void map_check()
{
	for(int i=1;i<=box_num;++i)
	{
		if(game_map[wx[i]][wy[i]]=='.')
		game_map[wx[i]][wy[i]]='@';
	}
	return ;
}
void plmove(int x)
{
	if(game_map[px+pmx[x]][py+pmy[x]]=='X')
	{
		printf("ײǽ��\n");
		return ;
	}
	if(game_map[px+pmx[x]][py+pmy[x]]=='#')
	{
		box_move(x);
		win_flag = win_check();
		keep_flag = !win_flag;
		return ;
	}
	pl_updata(x);
}
void pl_updata(int x)
{
	game_map[px + pmx[x]][py + pmy[x]] = 'O';
	game_map[px][py] = '.';
	px += pmx[x];
	py += pmy[x];
	return ;
}
void box_move(int x)
{
	int tx = px + pmx[x] + pmx[x];
	int ty = py + pmy[x] + pmy[x];
	 
	if(game_map[tx][ty] == '.'||game_map[tx][ty] == '@') game_map[tx][ty] = '#' ;
	else 
	{
		printf("�����Ʋ���!!!\n");
		return ;
	}
	pl_updata(x);
}
void game_work()
{
	char tmp;
	while(keep_flag)
	{
		Map_display();
		cin>>tmp;
		move_num++;
		switch(tmp)
		{
			case 'a':plmove(0);break;
			case 's':plmove(1);break;
			case 'w':plmove(2);break;
			case 'd':plmove(3);break;
			case 'p':keep_flag=0;break;
			case 'n':rank_show();break;
			case 'r':rank_reset();break;
			default :printf("����ָ��!");
			
		}
		Sleep(500);
	}
	return ;
}
bool win_check()
{
	for(int i=1;i <= box_num;i++)
	{
		if(game_map[wx[i]][wy[i]] != '#')return 0;
	}
	return 1;
}
void game_over()
{
	system("cls");
	if(win_flag)
	{
		int pl_scour =10000-move_num*10;
		printf("��ϲ�������ˣ�������\n");
		printf("��ϲ�������ˣ�������\n");
		printf("��ϲ�������ˣ�������\n"); 
		printf("���ĵ÷��ǣ�%d\n",pl_scour);
		printf("���������ǣ�");
		cin>>pl_now_name;
		data_save(pl_scour);
	}
	else 
	{
		printf("��Ǹ����û�ܹ���\n");
	}
	printf("  #�밴�س������ز˵�#  \n");
	morex=getchar();morex=getchar();
}
void data_save(int x)
{
	string game_num_front = "pushBoxesgame",game_num_tail = "_scour.txt";
	string game_num_name=game_num_front + game_num_num + game_num_tail;
	
	FILE *fp=fopen(game_num_name.c_str(),"r");
	char pl_name[12][25];
	int pl_scour[12];
	int tmp = 0;
	bool saved = 0;
	while( tmp < 10)
	{
		tmp++;
		fscanf(fp,"%s%d",&pl_name[tmp],&pl_scour[tmp]);
		if(saved == 0 && pl_scour[tmp] < x)
		{
			strcpy(pl_name[tmp+1],pl_name[tmp]);
			pl_scour[tmp+1] = pl_scour[tmp];
			strcpy(pl_name[tmp],pl_now_name);
			pl_scour[tmp] = x;
			tmp++;
			saved = 1;
		}
	}
	fclose(fp);
	FILE *fpp=fopen(game_num_name.c_str(),"w");
	for(int i=1;i<10;++i)
	{
		fprintf(fpp,"��%d����%s %d\n",i,pl_name[i],pl_scour[i]);
	}
	fclose(fpp);
	return ;
}
