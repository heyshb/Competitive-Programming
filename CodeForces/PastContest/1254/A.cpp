#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,M,K;
int T;
char s[110][110];
char ans[110][110];
int nn,nm,nd;

int give(int id) {
    if (id <= 26) {
        ans[nn][nm] = 'a' + id - 1;
    } else if (id <= 52) {
        ans[nn][nm] = 'A' + id - 27;
    } else {
        ans[nn][nm] = '0' + id - 53;
    }
    int ret = (s[nn][nm] == 'R');
    nm += nd;
    if (nm == M + 1) {
        nn++;
        nm = M;
        nd = -1;
    } else if (nm == 0) {
        nn++;
        nm = 1;
        nd = 1;
    }
    return ret;
}

void give2(int id,int p) {
    if (p == 0) {
        give(id);
        return;
    }
    while(p > 0) {
        p -= give(id);
    }
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&M,&K);
        int R = 0;
        for (int i=1;i<=N;i++) {
            scanf("%s", s[i] + 1);
            for (int j=1;j<=M;j++) {
                R += (s[i][j] == 'R');
            }
        }
        nn = nm = nd = 1;
        for (int i=1;i<=K;i++) {
            if (i <= R % K) {
                give2(i, R / K + 1);
            } else {
                give2(i, R / K);
            }
        }
        while(nn <= N) give(K);
        for (int i=1;i<=N;i++) {
            ans[i][M + 1] = 0;
            printf("%s\n",ans[i] + 1);
        }
    }
}