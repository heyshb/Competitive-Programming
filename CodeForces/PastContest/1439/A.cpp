#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
char s[110][110];
int M;
int ans[10010][6];
void flip(int a, int b, int c, int d, int e, int f) {
    M++;
    ans[M][0] = a;
    ans[M][1] = b;
    ans[M][2] = c;
    ans[M][3] = d;
    ans[M][4] = e;
    ans[M][5] = f;
    //printf("flip %d,%d %d,%d %d,%d\n",a,b,c,d,e,f);
    //printf("? %d %d %d\n",s[a][b],s[c][d],s[e][f]);
    s[a][b] ^= 1;
    s[c][d] ^= 1;
    s[e][f] ^= 1;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        M = 0;
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j++) {
                s[i][j] -= '0';
            }
        }
        //printf("!!!! %d\n",s[1][2]);
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 1; j <= m - 1; j += 2) {
                if (s[i][j] == 0 && s[i][j + 1] == 0) continue;
                if (s[i][j] == 0 && s[i][j + 1] == 1) flip(i,j+1,i+1,j,i+1,j+1);
                if (s[i][j] == 1 && s[i][j + 1] == 0) flip(i,j,i+1,j,i+1,j+1);
                if (s[i][j] == 1 && s[i][j + 1] == 1) flip(i,j,i,j+1,i+1,j+1);
            }
            if (m % 2 == 1 && s[i][m] == 1) flip(i,m,i+1,m,i+1,m-1); 
        }
        //printf("!!!! %d\n",s[1][2]);
        for (int i = 1; i <= m - 2; i++) {
            if (s[n-1][i] == 0 && s[n][i] == 0) continue;
            if (s[n-1][i] == 0 && s[n][i] == 1) flip(n,i,n,i+1,n-1,i+1);
            if (s[n-1][i] == 1 && s[n][i] == 0) flip(n-1,i,n,i+1,n-1,i+1);
            if (s[n-1][i] == 1 && s[n][i] == 1) flip(n-1,i,n,i,n,i+1);
        }
        //printf("!!!! %d\n",s[1][2]);
        pii fuck[4] = {pii(n-1,m-1),pii(n-1,m),pii(n,m-1),pii(n,m)};
        vector<vector<pii> > seq;
        function<void(int, vector<pii>)> dfs;
        dfs = [&](int dep, vector<pii>tmp) {
            if (dep == 4) {
                seq.push_back(tmp);
                return;
            }
            dfs(dep + 1, tmp);
            tmp.push_back(fuck[dep]);
            dfs(dep + 1, tmp);
        };
        dfs(0, {});
        for (auto &t : seq) {
            for (auto &p : t) s[p.first][p.second] ^= 1;
            bool ok = true;
            for (int i = n - 1; i <= n; i++) {
                for (int j = m - 1; j <= m; j++) {
                    if (s[i][j] != t.size() % 2) ok = false;
                }
            }
            if (ok) {
                for (auto &p : t) {
                    vector<pii> cnm;
                    for (int i = n - 1; i <= n; i++) {
                        for (int j = m - 1; j <= m; j++) {
                            if (i != p.first || j != p.second) cnm.emplace_back(i, j);
                        }
                    }
                    flip(cnm[0].first,cnm[0].second,cnm[1].first,cnm[1].second,cnm[2].first,cnm[2].second);
                }
            }
            for (auto &p : t) s[p.first][p.second] ^= 1;
            if (ok) break;
        }
        printf("%d\n",M);
        for (int i = 1; i <= M; i++) {
            for (int j = 0; j < 6; j++) {
                printf("%d%c",ans[i][j]," \n"[j==5]);
            }
        }
    }
}