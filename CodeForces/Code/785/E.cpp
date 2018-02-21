#include <bits/stdc++.h> 
#define MAXN 400010
#define MAXBLK 610
using namespace std;

int N,M,BLK;
int l[MAXBLK],r[MAXBLK];
int A[MAXN],B[MAXN],bl[MAXN];
typedef long long LL;
LL ans,cnt;

int tr[MAXN];
int lowbit(int x){return x&-x;}
void add(int x,int y){while(x<=N){tr[x]+=y;x+=lowbit(x);}}
int getsum(int x){int res=0;while(x){res+=tr[x];x-=lowbit(x);}return res;}

int sumsm(int num,int x)
{
	int ll=l[num],rr=r[num];
	int res=ll-1,st=ll;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1;
		if(A[mid]<x)res=mid,ll=mid+1;
		else rr=mid-1;
	}
	return res-st+1;
}

int sumbg(int num,int x)
{
	int ll=l[num],rr=r[num];
	int res=rr+1,ed=rr;
	while(ll<=rr)
	{
		int mid=(ll+rr)>>1;
		if(A[mid]>x)res=mid,rr=mid-1;
		else ll=mid+1;
	}
	return ed-res+1;
}

void resort(int x)
{
	for(int i=l[x];i<=r[x];i++)A[i]=B[i];
	sort(A+l[x],A+r[x]+1);
}

void modify(int L,int R)
{
	if(L==R)return;
	
	int LB = bl[L], RB = bl[R], rbound = r[LB], lbound = l[RB];
	//int LB=r[belong[x]],RB=l[belong[y]];
	
	if (B[L]>B[R]) 
	{
		ans--;
	}
	else 
	{
		ans++;
	}
	
	if(LB==RB)
	{
		for(int i=L+1;i<R;i++)
		{
			if(B[i]>B[L])ans++;
			if(B[i]>B[R])ans--;
			if(B[i]<B[R])ans++;
			if(B[i]<B[L])ans--;
		}
		swap(B[L],B[R]);
		return;
	}
	//printf("%d %d %d %d\n",LB,RB,rbound,lbound);
	
	
	
	for(int i=L+1;i<=rbound;i++)
	{
		
		if(B[i]>B[L])ans++;
		if(B[i]<B[L])ans--;
		if(B[i]>B[R])ans--;
		if(B[i]<B[R])ans++;
		//printf("%d %d\n",i,ans);
	}
	for(int i=lbound;i<R;i++)
	{
		if(B[i]>B[L])ans++;
		if(B[i]<B[L])ans--;
		if(B[i]>B[R])ans--;
		if(B[i]<B[R])ans++;
		//printf("%d %d\n",i,ans);
	}
	//printf("%d\n",ans);
	for(int i=LB+1;i<RB;i++)
	{
		ans-=sumsm(i,B[L]);
		ans+=sumsm(i,B[R]);
		ans+=sumbg(i,B[L]);
		ans-=sumbg(i,B[R]);
	}
	//printf("%d\n",ans);

	swap(B[L],B[R]);
	//for (int i=1;i<=N;i++)printf("%d ",B[i]);puts("");
	resort(LB);
	resort(RB);
}

int main()
{
	scanf("%d%d",&N,&M);
	BLK = int(sqrt(N)+0.5);
	for (int i=1;i<=N;i++)A[i] = B[i] = i;
	cnt = N/BLK;
	if (N%BLK) cnt++;
	for(int i=1;i<=cnt;i++)
	{
		l[i]=(i-1)*BLK+1;
		r[i]=i*BLK;
	}
	for (int i=1;i<=cnt;i++)
		for (int j=l[i];j<=r[i];j++) bl[j] = i;
	//for (int i=1;i<=N;i++)printf("%d\n",bl[i]);
	ans = 0;
	while(M--)
	{
		int L,R;
		scanf("%d%d",&L,&R);
		if(L>R)swap(L,R);
		modify(L,R);
		printf("%I64d\n",ans);
	}
	return 0;
}
