#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int R,B;
int f[510][510];

int main()
{
	int T,_ = 0;
	R = 500;
	B = 500;
	for (int i=0;i*i<=2*R+10;i++)
		for (int j=0;j*j<=2*B+10;j++)
		if (!(i==0 && j==0))
			for (int k=R;k>=i;k--)
				for (int l=B;l>=j;l--)
					f[k][l] = max(f[k][l],f[k-i][l-j] + 1);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&R,&B);
		printf("Case #%d: %d\n",++_,f[R][B]);
	}
}
