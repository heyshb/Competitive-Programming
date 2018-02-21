#include <bits/stdc++.h>

using namespace std;

//11311
typedef long long LL;
typedef __int128 BI;
BI UP = 1000000000000000001LL;
LL INF = 1000000000000000001LL;
LL f[110][110],ans = INF;
int N;
char s[110];

LL get(int x,int y,int z)
{
	BI tmp = 0, tmp1 = 0;
	if (s[x-z+1]=='0' && z>1) return INF;
	for (int i=x-z+1;i<=x;i++)
		tmp1 = tmp1*__int128(10) + s[i]-'0';
	if (LL(tmp1) >= LL(N)) return INF;
	tmp = __int128(f[x-z][y-1])*__int128(N) + tmp1;
	
	//printf("get %d %d %d\n",x,y,z);
	//printf("FROM %d %d %I64d\n",x-z,y-1,f[x-z][y-1]);
	//printf("CALC %I64d %d %I64d\n",f[x-z][y-1],N,LL(tmp1));
	//printf("ILL %d\n",tmp>=UP);
	//if (tmp >= UP) printf("GET RES:%I64d\n",LL(tmp));
	//cout<<LL(tmp)<<endl;
	if (tmp >= UP) return INF;
	else return LL(tmp);
}

int main()
{
	scanf("%d",&N);
	scanf("%s",s+1);
	int len = strlen(s+1);
	for (int i=0;i<=len;i++)
	{
		for (int j=0;j<=len;j++)
			f[i][j] = INF;
	}
	
	f[0][0] = 0;
	for (int i=1;i<=len;i++)
	{
		for (int j=1;j<=i;j++)
			for (int k=1;k<=i;k++)
			{
				f[i][j] = min(f[i][j],get(i,j,k));
				//printf("F[%d][%d] = %I64d\n",i,j,f[i][j]);
			}
	}
	for (int i=1;i<=len;i++) ans = min(ans,f[len][i]);
	printf("%I64d\n",ans);
}
