#include <bits/stdc++.h>

using namespace std;

int T;
int N;
char s[600010];
int pre[600010], nxt[600010];
int head[10], tail[10];
int ans[100010][6];

int gethead(int x) {
    int ret = head[x];
    head[x] = nxt[head[x]];
    return ret;
}

int gettail(int x) {
    int ret = tail[x];
    tail[x] = pre[tail[x]];
    return ret;
}

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s + 1);
        N = strlen(s + 1);
        head[1] = head[4] = head[5] = -1;
        for (int i=1;i<=N;i++) {
            s[i] -= '0';
            if (head[s[i]] == -1) {
                head[s[i]] = i;
            }
            nxt[tail[s[i]]] = i;
            pre[i] = tail[s[i]];
            tail[s[i]] = i;
        }
        int M = 0;
        for (int i=1;i<=N;i++) {
            if (s[i] == 5) {
                M++;
                ans[M][0] = gethead(1);
                ans[M][1] = gethead(1);
                ans[M][2] = gethead(4);
                ans[M][3] = i;
            }
        }
        M = N / 6 + 1;
        for (int i=N;i>=1;i--) {
            if (s[i] == 5) {
                M--;
                ans[M][5] = gettail(4);
                ans[M][4] = gettail(1);
            }
        }
        for (int i=1;i<=N/6;i++) {
            for (int j=0;j<6;j++) {
                printf("%d%c",ans[i][j]," \n"[j==5]);
            }
        }
    }
 }