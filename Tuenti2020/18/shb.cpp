#include <bits/stdc++.h>

using namespace std;

int N = 0;
char s[4010], tmp[4010];
int a[4010];
int f[4010][4010][5][2];
// [   ]  , \n x

void upd(int &x, int y) {
    x = min(x, y);
}

int trans(char ch) {
    if (ch == '[') return 0;
    if (ch == ']') return 1;
    if (ch == ',') return 2;
    if (ch == '\n') return 3;
    return 4;
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        int L;
        scanf("%d",&L);
        N = 0;
        string ss;
        getline(cin, ss);
        for (int i=1;i<=L;i++) {
            getline(cin, ss);
            for (auto &ch : ss) s[++N] = ch;
            if (i < L) s[++N] = '\n';
        }
        s[N + 1] = 0;
        /*
        printf("%d\n",N);
        printf("%s", s + 1); */
        for (int i=1;i<=N;i++) a[i] = trans(s[i]);
        const int INF = 1e9;
        for (int i=0;i<=N;i++) {
            for (int j=0;j<=N;j++) {
                for (int k=0;k<5;k++) {
                    for (int l=0;l<2;l++) {
                        f[i][j][k][l] = INF;
                    }
                }
            }
        }
        f[1][1][0][0] = (a[1] == 0 ? 0 : 1);
        for (int i=0;i<N;i++) {
            for (int j=1;j<=N;j++) {
                for (int k=0;k<5;k++) {
                    for (int l=0;l<2;l++) {
                        if (f[i][j][k][l] == INF) continue;
                        //printf("%d %d %d %d %d\n",i,j,k,l,f[i][j][k][l]);
                        int onl = l;
                        if (k == 3) onl = 0;
                        int ni, nj, nk, nl;
                        for (nk=0;nk<5;nk++) {
                            int cost = (nk == a[i + 1] ? 0 : 1);
                            if (nk == 0) {
                                if (k != 0 && k != 2) continue;
                                nj = j + 1;
                                nl = onl;
                            }
                            if (nk == 1) {
                                nj = j - 1;
                                if (nj < 0) continue;
                                nl = onl;
                            }
                            if (nk == 2) {
                                nj = j;
                                nl = 1;
                            }
                            if (nk == 3) {
                                if (onl == 0) continue;
                                if (k == 1) continue;
                                nj = j;
                                nl = onl;
                            }
                            if (nk == 4) {
                                if (k == 1) continue;
                                nj = j;
                                nl = onl;
                            }

                            if (f[i][j][k][l] + cost < f[i + 1][nj][nk][nl]) {
                                //printf("ts %d %d %d %d -> %d %d %d %d, val = %d\n",i,j,k,l,i+1,nj,nk,nl,f[i][j][k][l] + cost);
                            }
                            upd(f[i + 1][nj][nk][nl], f[i][j][k][l] + cost);
                        }
                    }
                }
            }
        }
        int ans = f[N][0][1][1];
        if (ans == INF) {
            printf("Case #%d: IMPOSSIBLE\n", T);
        } else {
            printf("Case #%d: %d\n",T, ans);
        }
    }
}