#include <bits/stdc++.h>

using namespace std;

int N;
vector<int>e[100010];
int cost[100010];
typedef long long LL;
unordered_map<LL,int> ha,ha2;

bool check(int fa,int X,int K);

bool check2(int fa,int X,int K,int len)
{
	//printf("%d %d %d %d %d\n",fa,X,K,len,cost[len]);
	LL hv = LL(X)*LL(N)+K;
	bool have = ha2.find(hv) != ha2.end();
	if (have && len<=ha2[hv]) return true;
    vector<int>v;
    v.clear();
    if (e[X].size() == 1) return (cost[len]<=K);
    //puts("FUCK");
    for (int i=0;i<e[X].size();i++)
    if (e[X][i]!=fa)
    {
        int Y = e[X][i];
        if (!check(X,Y,K-cost[len]-1)) v.push_back(Y);
    }
    bool ans;
    if (v.size()==0) ans = true;
    else if (v.size()>1) ans = false;
    else ans = check2(X,v[0],K,len+1);
    if (ans)
    {
    	if (!have || len>ha2[hv])
    		ha2[hv] = len;
    }
    return ans;
}

bool check(int fa,int X,int K)
{
    //printf("%d %d %d\n",fa,X,K);
    if (K<0) return false;
    LL hv = LL(X)*LL(N)+K;
    if (ha.find(hv) != ha.end()) return ha[hv];
    vector<int>v;
    v.clear();
    for (int i=0;i<e[X].size();i++)
    if (e[X][i]!=fa)
    {
        int Y = e[X][i];
        if (!check(X,Y,K-1)) v.push_back(Y);
    }
    //printf("dfs %d %d %d\n",fa,X,K);
    //for (auto t:v) printf("%d ",t);puts("");
    if (v.size()==0) return ha[hv] = true;
    if (v.size()>1) return ha[hv] = false;
    return ha[hv] = check2(X,v[0],K,1);
}

int main()
{
    cost[1] = 1;
    for (int i=2;i<=100000;i*=2)
    {
        cost[i]=cost[i/2]+1;
        cost[100000] = cost[i] + 1;
    }
    for (int i=100000;i>=1;i--)
    if (!cost[i])
        cost[i] = cost[i+1];
    //for (int i=1;i<=10;i++)printf("%d\n",cost[i]);
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	ha.clear();
    	ha2.clear();
        scanf("%d",&N);
        for (int i=1;i<=N;i++) e[i].clear();
        for (int i=1;i<N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int L,R;
        L = 0, R = N;
        while(L < R-1)
        {
            int mid = (L+R)>>1;
            //printf(" Check %d %d %d\n",L,R,mid);
            if (check(0,1,mid))
                R = mid;
            else
                L = mid;
        }
        printf("%d\n",R);
    }
}
