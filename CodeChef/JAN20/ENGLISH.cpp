#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,int> pli;
int T;
int N;
int ch[200010][26],val[200010],M,dep[200010];
char s[200010],ss[200010];

void ins(char *s, int len) {
    int now = 1;
    for (int i=1;i<=len;i++) {
        int &nxt = ch[now][s[i] - 'a'];
        if (!nxt) {
            nxt = ++M;
            dep[nxt] = dep[now] + 1;
            for (int j=0;j<26;j++) {
                ch[M][j] = 0;
            }
            val[nxt] = 0;
        }
        now = nxt;
    }
    val[now]++;
}

pli dfs(int x) {
    LL v1 = 0, v2 = val[x];
    for (int i=0;i<26;i++) {
        if (ch[x][i]) {
            auto tmp = dfs(ch[x][i]);
            v1 += tmp.first;
            v2 += tmp.second;
        }
    }
    if (dep[x] % 2 == 0) {
        v1 += 1LL * (dep[x] / 2) * (dep[x] / 2) * (v2 / 2);
        v2 %= 2;
    } 
    return pli(v1, v2);
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        M = 1;
        val[1] = 0;
        dep[1] = 0;
        for (int i=0;i<26;i++) {
            ch[1][i] = 0;
        }
        for (int i=1;i<=N;i++) {
            scanf("%s",s + 1);
            int len = strlen(s + 1);
            for (int i=1;i<=len;i++) {
                ss[i * 2 - 1] = s[i];
                ss[2 * (len + 1 - i)] = s[i];
            }
            ss[2 * len + 1] = 0;
            //printf("%s\n",ss + 1);
            ins(ss, 2 * len);
        }
        LL ans = dfs(1).first;
        printf("%lld\n",ans);
    }
}