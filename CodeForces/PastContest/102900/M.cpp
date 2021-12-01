#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n, m;
typedef pair<int,string> pis;
typedef pair<int,int> pii;
map<string, int> ch[100010];
int M;
char s[100010];
int cnt[100010][2], fa[100010];

void insert(int col) {
    scanf("%s",s + 1);
    int len = strlen(s + 1);
    s[++len] = '/';
    int last_slash = 0;
    int now = 1;
    cnt[now][col]++;
    for (int i = 1; i <= len; i++) {
        if (s[i] == '/') {
            string tmp = string(s + last_slash + 1, i - last_slash);
            if (ch[now].find(tmp) == ch[now].end()) {
                ch[now][tmp] = ++M;
                fa[M] = now;
                cnt[M][0] = cnt[M][1] = 0;
                ch[M].clear();
            }
            now = ch[now][tmp];
            cnt[now][col]++;
            last_slash = i;
        }
    }
}

const int INF = 10000;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        M = 1;
        cnt[1][0] = cnt[1][1] = 0;
        ch[1].clear();
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++) {
            insert(0);
        }
        for (int i = 1; i <= m; i++) {
            insert(1);
        }
        int ans = 0;
        for (int i = 2; i <= M; i++) {
            if (cnt[i][1] == 0 && (fa[i] == 1 || cnt[fa[i]][1] != 0)) {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
}