#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL N;
LL C[100010],H[100010],dep[100010],f[100010];
vector<int>e[100010];

LL Gauss(LL A,LL B)
{
	return (A + B) * (B - A + 1) / 2; 
}

LL g(LL u)
{
	return f[u] - H[u-1] + C[u-1] * C[u-1] * u  +
		   C[u-1] * (2 * LL(N) * u - u * u + u) / 2;
}

LL trans(LL i,LL u)
{
	return f[u] - H[u-1] + C[u-1] * C[u-1] * (u - i) +
		   C[u-1] * Gauss(N-(u-1), N-i);
}

pair<pair<LL,LL>,LL> make(LL a,LL b,LL c)
{
	return make_pair(make_pair(a,b),c);
}

multiset<pair<pair<LL,LL>,LL> >st;

#define TEST

void printset()
{
	puts("---------");
	for (auto t = st.begin();t != st.end(); t++)
		printf("%lld %lld %lld\n",(*t).first.first,(*t).first.second,(*t).second);
	puts("xxxxxxxxx");
}

int main()
{
	#ifdef TEST
		freopen("KILLER.in","r",stdin);
		//freopen("KILLER2.out","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&N);
		for (int i=1;i<=N;i++)e[i].clear();
		for (int i=1;i<=N;i++)scanf("%lld%lld",&H[i],&C[i]);
		for (int i=1;i<N;i++)
		{       
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		st.clear();
		f[N + 1] = 0;
		st.insert(make(-C[N],g(N+1),N+1));
		for (int i=N;i>=1;i--)
		{
			//printf("%d\n",i);
			f[i] = 1e18;
			/*
			for (int j=i+1;j<=N+1;j++)
			{
				//printf("%d %d %lld\n",i,j,trans(i,j)); 
				f[i] = min(f[i],trans(i,j));
			}*/
			
			/*
			printf("Solving %d\n",i);
			for (int j=i+1;j<=N+1;j++)
			{
				printf("From %d %d\n",j,trans(i,j));puts("");
				printf("%d %d\n",trans(i,j), g(j) + C[j-1] * (i*i - (C[j-1] + 2*N + 1)*i));
			}*/
			//printset();
			while(st.size() > 1)
			{
				auto t1 = st.begin();
				auto t2 = t1;
				t2++;
				LL v1 = trans(i,(*t1).second), v2 = trans(i,(*t2).second);
				if (v1 >= v2)
					st.erase(t1);
				else
					break;
			}
			//printset();
			
			auto t1 = st.begin();
			f[i] = trans(i,(*t1).second);
			
			if (i==1) break;
			
			auto pr = make(-C[i-1],g(i),i);
			st.insert(pr);
			t1 = st.find(pr);
			auto t2 = t1;
			
			
			//printset();
			if (t1 != st.begin() && (*prev(t1)).first.first == -C[i-1])
			{
				//puts("done1");
				t1 = prev(t1);
				st.erase(next(t1));
			}
			else if (next(t1) != st.end() && (*next(t1)).first.first == -C[i-1])
			{
				//puts("done2");
				st.erase(next(t1));
			}
			
			//printset();
			
			while(t1 != st.begin() && trans(i-1,(*t1).second) <= trans(i-1,(*prev(t1)).second))
			{
				//printf("%d %d\n",(*t1).second,(*prev(t1)).second);
				st.erase(prev(t1));
			}
			printf("%lld\n",f[i]);
		}
		printf("%lld\n",f[1]);
	}
}
