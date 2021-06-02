#include <bits/stdc++.h>

using namespace std;

char a[100010],b[100010];
int f1[100010],f2[100010];

int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	int lena = strlen(a+1), lenb = strlen(b+1);
	f1[0]=0;
	int now=1;
	for (int i=1;i<=lenb;i++)
	{
		while(now<=lena && a[now]!=b[i]) now++;
		f1[i] = now;
		if (now<=lena) now++;
	}
	//for (int i=1;i<=lenb;i++)printf("%d",f1[i]);puts("");
	now=lena;
	
	for (int i=lenb;i>=1;i--)
	{
		while(now>0 && a[now]!=b[i]) now--;
		f2[i] = now;
		if (now>0) now--;
	}
	//for (int i=1;i<=lenb;i++)printf("%d",f2[i]);puts("");
	int L,R,MAXLEN=0;
	for (int i=1;i<=lenb;i++)
	{
		if (f1[i]<=lena)
		{
			L = 1;
			R = i;
			MAXLEN = i;
		}
	}
	for (int i=lenb;i>=1;i--)
	{
		if (f2[i]>0 && lenb-i+1>MAXLEN)
		{
			MAXLEN = lenb-i+1;
			L = i;
			R = lenb;
		}
	}
	f2[lenb+1] = lena+1;
	bool flag = false;
	for (int i=1;i<=lenb;i++)
	{
		if (f1[i] > lena) break;
		int l=i+1, r=lenb+1;
		while(l!=r-1)
		{
			int mid = (l+r)>>1;
			if (f2[mid]>f1[i])
				r = mid;
			else
				l = mid;
		}
		if (f2[r]==lena+1) continue;
		if (lenb-r+1+i > MAXLEN)
		{
			MAXLEN = lenb-r+1+i;
			flag = true;
			//printf("UP %d %d\n",i,r);
			L = i;
			R = r;
		}
	}
	if (MAXLEN == 0) puts("-");
	else if (flag)
	{
		for (int i=1;i<=L;i++)printf("%c",b[i]);
		for (int i=R;i<=lenb;i++)printf("%c",b[i]);
		puts("");
	}
	else
	{
		for (int i=L;i<=R;i++)printf("%c",b[i]);
		puts("");
	}
}
