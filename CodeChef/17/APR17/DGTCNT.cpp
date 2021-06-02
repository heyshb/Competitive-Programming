#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int a[10];
LL L,R;
LL fac[20];

LL calc2(int mask,int len)//only consider some numbers.mask 0~1023. illegal
{
	vector<int>v;
	v.clear();
	for (int i=0;i<10;i++)if (mask & (1<<i))v.push_back(i);
	int sum = 0;
	for (int i=0;i<v.size();i++)
	{
		if (a[v[i]] < 0) return 0;
		sum+=a[v[i]];
	}
	if (sum > len) return 0;
	//for (int i=0;i<10;i++)printf("%d",a[i]);puts("");
	//for (auto t:v) printf("%d ",t);puts("");
	//printf("Calc Mask = %d len = %d sum = %d\n",mask,len,sum);
	LL ans = fac[len]/fac[len-sum]; 
	//printf("%lld\n",ans);
	for (int i=0;i<v.size();i++)ans/=fac[a[v[i]]];
	//printf("%lld\n",ans);
	for (int i=1;i<=len-sum;i++)ans*=LL(10-v.size());
	//if (ans) printf("Size: %d ans: %lld\n",v.size(),ans);
	if (v.size() & 1)	
		return ans;
	else
		return -ans;
}

LL calc(LL x)//<=x legal
{
	if (!x) return 0;
	LL save = x;
	int len = 0;
	int v[20];
	do
	{
		v[++len] = x%10;
		x/=10;
	}while(x);
	v[len+1] = -1;
	for (int i=1;i<=len/2;i++)swap(v[i],v[len+1-i]);
	//for (int i=1;i<=len;i++)printf("%d ",v[i]);puts("");
	LL res = 0;
	for (int i=1;i<len;i++)
		for (int j=1;j<1024;j++)
		{
			res += calc2(j,i);
			a[0]--;
			res -= calc2(j,i-1);
			a[0]++; 
			/*
			for (int k=1;k<10;k++)
			{
				a[k]--;
				res += calc2(j,i-1);
				a[k]++;
			}*/	
		}
	//printf("Res = %lld\n",res);
	for (int i=1;i<v[1];i++)
		for (int j=1;j<1024;j++)
		{
			a[i]--;
			res += calc2(j,len-1);
			a[i]++;
		}
	//printf("Res = %lld\n",res);
	for (int i=1;i<len;i++)
	{
		for (int j=1;j<=i;j++)a[v[j]]--;
		for (int k=0;k<v[i+1];k++) 
		{
			a[k]--;
			for (int j=1;j<1024;j++)
				res += calc2(j,len-i-1);
			a[k]++;
		}
		for (int j=1;j<=i;j++)a[v[j]]++;
	}
	int cnt[10];
	for (int i=0;i<10;i++)cnt[i] = 0;
	for (int i=1;i<=len;i++)cnt[v[i]]++;
	for (int i=0;i<10;i++)
	if (cnt[i] == a[i])
	{
		res++;
		break;
	}
	//printf("Res = %lld\n",res);
	////printf("Last %lld = %lld\n",save,res);
	return save - res;
}

int main()
{
	//freopen("DGTCNT.txt","r",stdin);
	fac[0] = 1;
	for (int i=1;i<=18;i++)fac[i] = fac[i-1] * LL(i);
	//for (int i=1;i<=18;i++)printf("%lld\n",fac[i]);
	int Casi;
	scanf("%d",&Casi);
	while(Casi--)
	{
		scanf("%lld%lld",&L,&R);
		for (int i=0;i<10;i++)scanf("%d",&a[i]);
		printf("%lld\n",calc(R) - calc(L-1));		
		//system("pause");
		//printf("%d %d\n",calc(200),calc(199));
		//printf("%d\n",calc(200));
	}
}
