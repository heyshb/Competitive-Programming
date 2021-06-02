#include <bits/stdc++.h>

using namespace std;

char s[1010][2][21];
char nm[1010][2][5];
int N;
int v[1010][2],cnt;
char al[5010][5];
bool ok[1010][2];
vector<int>e[2010];

int add(int x,int px,int y,int py)
{
	e[x*2-2+px].push_back(y*2-2+py);
}

int main()
{
	scanf("%d",&N);
	memset(nm,0,sizeof(nm));
	cnt = 0;
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<2;j++)
			scanf("%s",s[i][j]);
		
		nm[i][0][0] = s[i][0][0];
		nm[i][0][1] = s[i][0][1];
		nm[i][0][2] = s[i][0][2];
		for (int j=1;j<=cnt;j++)
		if (strcmp(nm[i][0],al[j])==0) 
		{
			v[i][0] = j;
			break;
		}
		if (!v[i][0])
		{
			v[i][0] = ++cnt;
			strcpy(al[cnt],nm[i][0]);
		}
		nm[i][1][0] = s[i][0][0];
		nm[i][1][1] = s[i][0][1];
		nm[i][1][2] = s[i][1][0];
		for (int j=1;j<=cnt;j++)
		if (strcmp(nm[i][1],al[j])==0) 
		{
			v[i][1] = j;
			break;
		}
		if (!v[i][1])
		{
			v[i][1] = ++cnt;
			strcpy(al[cnt],nm[i][1]);
		}
		//printf("%s\n%s\n",nm[i][0],nm[i][1]);
	}
	
	memset(ok,true,sizeof(ok));
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
		{
			if (i==j) continue;
			if (v[i][0]==v[j][0] || v[i][0]==v[j][1])
			{
				if (v[i][0]==v[j][0] && v[i][0]==v[j][1])
				{
					add(i,0,i,1);
				}
				else
				{
					if (v[i][0]==v[j][0])
					{
						add(i,1,j,1);
						add(i,0,j,1);
					}
					else
						add(i,0,j,0);
				}
			}
			
			if (v[i][1]==v[j][0] || v[i][1]==v[j][1])
			{
				if (v[i][1]==v[j][0] && v[i][1]==v[j][1])
				{
					add(i,1,i,0);
				}
				else
				{
					if (v[i][1]==v[j][0])
						add(i,1,j,1);
					else
						add(i,1,j,0);
				}
			}
		}
	
}
