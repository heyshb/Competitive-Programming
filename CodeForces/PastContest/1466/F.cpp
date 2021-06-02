#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int x1[500100], x2[500100];
bool single[500010];

int p[10000010], siz[10000010], flag[1000010];
int getf(int x) {
	int i = x, j;
	while(x != p[x])
		x = p[x];
	while(i != p[i]) {
		j = p[i];
		p[i] = x;
		i = j;
	}
	return x;
}

int min_index[500010];

const int mod = 1000000007;
int fastpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (long long)r * a % mod;
		b >>= 1;
		a = (long long)a * a % mod;
	}
	return r;
}

int sum[500010][2];

int belong[500010];

int main() {
	scanf("%d%d", &n, &m);

	sum[0][0] = 1;
	sum[0][1] = 0;
	for(int i = 1 ; i <= m ; i++) {
		sum[i][0] = (sum[i - 1][0] + sum[i - 1][1]) % mod;
		sum[i][1] = (sum[i - 1][1] + sum[i - 1][0]) % mod;
	}

	for(int i = 1 ; i <= m ; i++)
		p[i] = i, siz[i] = 1;

	for(int i = 1 ; i <= n ; i++) {
		int k;scanf("%d", &k);
		if(k == 1){
			scanf("%d", &x1[i]);
			x2[i] = -1;single[i] = true;
		}
		else {
			scanf("%d%d", &x1[i], &x2[i]);

			if(getf(x1[i]) != getf(x2[i])) {
				int pa = getf(x1[i]), pb = getf(x2[i]);
				p[pa] = pb;
				siz[pb] += siz[pa];
			}
		}
	}

	int ans_cnt = 1;
	for(int i = 1 ; i <= n ; i++)
		if(single[i]) {
			if(!flag[getf(x1[i])]) {
				flag[getf(x1[i])] = true;
			}
		}
	for(int i = 1 ; i <= m ; i++) {
		if(p[i] == i) {
			if(flag[i]) {
				ans_cnt = (long long)ans_cnt * fastpow(2, siz[i]) % mod;
			}
			else {
				if(siz[i] == 1);
				else {
					ans_cnt = (long long)ans_cnt * sum[siz[i]][0] % mod;
				}
			}
		}
	}

	vector<int> ans;

	for(int i = 1 ; i <= m ; i++)
		belong[i] = getf(i) + m;
	for(int i = 1 ; i <= m * 2 ; i++)
		p[i] = i;
	for(int i = 1 ; i <= n ; i++) {
		if(x2[i] == -1) {
			x2[i] = belong[x1[i]];
		}

		int pa = getf(x1[i]), pb = getf(x2[i]);
		if(pa != pb) {
			p[pa] = pb;

			ans.push_back(i);
		}
	}

	printf("%d %d\n", ans_cnt, int(ans.size()));
	for(int i = 0 ; i < ans.size() ; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
