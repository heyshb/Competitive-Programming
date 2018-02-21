#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<int> pr;

bool check(LL x)
{
	for (int i=0;i<pr.size();i++)
	{
		while(x%pr[i]==0) x/=pr[i];
		if (x==1) return true;
	}
	return x==1;
}
int main()
{
	for (int i=2;i<=47;i++)
	{
		bool ok = true;
		for (int j=2;j<i;j++)
		if (i%j==0) ok=false;
		if (ok) pr.push_back(i);
	}
	for (int i=0;i<pr.size();i++)printf("%d\n",pr[i]);
	//system("pause"); 
	int N = pr.size();
	LL S = 25958833668LL;
	bool now,last=true;
	//10390000000LL 25958833668
	freopen("581.txt","w",stdout);
	for (LL i=10390000000LL;;i++)
	{
		now = check(i+1);
		if (now && last) 
		{
			S+=i;
			printf("%lld\n",i);
		}
		last = now;
		if (i%100000000 == 0) 
			printf("%lld %lld\n",i,S);
	}
}

//22495633669
