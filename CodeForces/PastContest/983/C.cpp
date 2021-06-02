#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int f[2010][10][1010];
int pv[10][10][10][10];
int rec[10010][4];
int tmp[4];
int tmp2[4];
int get()
{
	for (int i=0;i<4;i++)tmp2[i] = tmp[i];
	sort(tmp2,tmp2+4);
	return pv[tmp2[0]][tmp2[1]][tmp2[2]][tmp2[3]];
}

struct state
{
	int qpos,fpos,stnum;
	state(int qp,int fp,int st)
	{
		qpos = qp;
		fpos = fp;
		stnum = st;
	}
};
int N,a[2010],b[2010];
int cnt = 0;
queue<state>q;

int main()
{
	memset(f,-1,sizeof(f));
	for (int i=0;i<10;i++)
		for (int j=i;j<10;j++)
			for (int k=j;k<10;k++)
				for (int l=k;l<10;l++)
				{
					pv[i][j][k][l] = ++cnt;
					rec[cnt][0] = i;
					rec[cnt][1] = j;
					rec[cnt][2] = k;
					rec[cnt][3] = l;
				}
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d%d",&a[i],&b[i]);
	f[0][1][1] = 0;
	q.push(state(0,1,1));
	while(!q.empty())
	{
		auto now = q.front();
		q.pop();
		int qp = now.qpos,fp = now.fpos,st = now.stnum;
		int nqp,nfp,nst;
		for (int i=0;i<4;i++)
			tmp[i] = rec[st][i];
		if (qp < N && fp == a[qp + 1] && tmp[0] == 0)
		{
			nqp = qp + 1;
			nfp = fp;
			tmp[0] = b[qp+1];
			nst = get();
			if (f[nqp][nfp][nst] == -1)
			{
				f[nqp][nfp][nst] = f[qp][fp][st] + 1;
				q.push(state(nqp,nfp,nst));
			}
			tmp[0] = 0;
		}
		for (int i=0;i<4;i++)
		if (tmp[i] == fp)
		{
			nqp = qp;
			nfp = fp;
			tmp[i] = 0;
			nst = get();
			if (f[nqp][nfp][nst] == -1)
			{
				f[nqp][nfp][nst] = f[qp][fp][st] + 1;
				q.push(state(nqp,nfp,nst));
			}
			tmp[i] = fp;
			break;
		}
		if (fp > 1)
		{
			nqp = qp;
			nfp = fp - 1;
			nst = st;
			if (f[nqp][nfp][nst] == -1)
			{
				f[nqp][nfp][nst] = f[qp][fp][st] + 1;
				q.push(state(nqp,nfp,nst));
			}
		}
		if (fp < 9)
		{
			nqp = qp;
			nfp = fp + 1;
			nst = st;
			if (f[nqp][nfp][nst] == -1)
			{
				f[nqp][nfp][nst] = f[qp][fp][st] + 1;
				q.push(state(nqp,nfp,nst));
			}
		}
	}
	int ans = 1e9;
	for (int i=1;i<=9;i++)
		ans = min(ans,f[N][i][1]);
	printf("%d\n",ans);
}
