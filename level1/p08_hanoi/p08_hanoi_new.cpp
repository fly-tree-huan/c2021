#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
void work(int num,int a,int b,int c)
{
	if(num==1)
	{
		printf("����%d�������ϵ�һ�������ƶ�����%d��������\n",a,b);
		return ;
	}
	work(num-1,a,c,b);
	printf("����%d�������ϵ�һ�������ƶ�����%d��������\n",a,b);
	work(num-1,c,b,a);
}
int main()
{
	cin>>n;
	work(n,1,3,2);
	return 0;
} 
