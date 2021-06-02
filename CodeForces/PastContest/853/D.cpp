#include <bits/stdc++.h>

using namespace std;

typedef long long LL; 
int N;
int a[300010];
LL s[300010];
vector<int>d1,d2; 

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&a[i]),s[i] = s[i-1] + a[i];
	for (int i=1;i<=N;i++)
	{
		if (a[i] == 1000)
			d1.push_back(i);
		else
			d2.push_back(i);
	}
	
}
