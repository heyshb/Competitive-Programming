#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
char s[110];
int a[110];
LL p[110];
LL f[110][110][110][2], g[110];
const LL INF = 1e18;

int main() {
    scanf("%d",&N);
    scanf("%s",s+1);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    p[0] = 0;
    for (int i=1;i<=N;i++) {
        for (int j=i;j<=N;j++) {
            p[j] = max(p[j], p[j - i] + a[i]);
        }
    }
    vector<int>seg;
    int nowseg = 0;
    for (int i=1;i<=N;i++) {
        nowseg++;
        if (i == N || s[i] != s[i + 1]) {
            seg.push_back(nowseg);
            nowseg = 0;
        }
    }
    int n = seg.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            for (int k=0;k<n;k++) {
                f[i][j][k][0] = f[i][j][k][1] = -INF; 
            }
        }
    }
    for (int i=0;i<n;i++) {
        f[i][i][seg[i]][i%2] = 0;
        f[i][i][0][0] = f[i][i][0][1] = p[seg[i]];
    }
}