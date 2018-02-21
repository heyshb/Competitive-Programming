#include <bits/stdc++.h>

using namespace std;

bool iscube(int x)
{
	int v = int(pow(x,0.33333333333));
	for (int i=v-5;i<=v+5;i++)
	if (i * i * i == x) return true;
	return false;
}

bool check(int x)
{
	for (int i=2;i*i<=x;i++)
	if (x % i == 0) return false;
	for (int i=1;i<=2000;i++)
		if (iscube(i*i*(i + x))) return true;
	return false;
}

int cnt = 0;

void check2(int x)
{
	if (x > 1000000) return;
	for (int i=2;i*i<=x;i++)
	if (x % i == 0) return;
	cnt++;
	printf("%d\n",x);
}

int main()
{
	//for (int i=2;i<=200;i++)
	//if (check(i)) printf("%d\n",i);
	for (int i=2;i<=1000;i++)
	{
		check2(3*i*i-3*i+1);
	}
	printf("%d\n",cnt);
} 
