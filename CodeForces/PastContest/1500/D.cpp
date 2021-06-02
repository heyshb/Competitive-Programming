#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

bool print = false;
const int MAXD = 11;
int N, Q;
int a[1510][1510];
int fuck[1510][1510][21], last_fuck[1510][1510][21];
int maxd[1510][1510];
int ans[1510][1510];
int tt[21];

int v3[100];

void merge(int *v1, int *v2) {
    if (v1[0] == 0 || v2[0] == 0) {
        v1[0] = 0; 
        return;
    }
    v3[0] = 0;
    int node1 = 1, node2 = 1;
    while(node1 <= v1[0] && node2 <= v2[0]) {
        if (v1[node1] < v2[node2]) {
            if (v1[node1] != v3[v3[0]]) v3[++v3[0]] = v1[node1];
            node1++;
        } else {
            if (v2[node2] != v3[v3[0]]) v3[++v3[0]] = v2[node2];
            node2++;
        }
    }
    while(node1 <= v1[0]) {
        if (v1[node1] != v3[v3[0]]) v3[++v3[0]] = v1[node1];
        node1++;
    }
    while(node2 <= v2[0]) {
        if (v2[node2] != v3[v3[0]]) v3[++v3[0]] = v2[node2];
        node2++;
    }
    if (v3[0] > Q) v3[0] = 0;
    for (int i=0;i<=Q;i++) v1[i] = v3[i];
}

int sum[1510];

int main() {
    scanf("%d%d",&N,&Q);
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            last_fuck[i][j][0] = 1;
            last_fuck[i][j][1] = a[i][j];
            maxd[i][j] = MAXD;
        }
    }
    for (int d=1;d<=MAXD;d++) {
        int skp = (1 << (d - 1));
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                for (int k=0;k<=Q;k++) fuck[i][j][k] = last_fuck[i][j][k];
                if (fuck[i][j][0] == 0) continue;
                if (i + skp > N || j + skp > N) {
                    fuck[i][j][0] = 0;
                    continue;
                }
                merge(fuck[i][j], last_fuck[i + skp][j]);
                merge(fuck[i][j], last_fuck[i][j + skp]);
                merge(fuck[i][j], last_fuck[i + skp][j + skp]);
            }
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (fuck[i][j][0] == 0) maxd[i][j] = min(maxd[i][j], d - 1);
                for (int k=0;k<=Q;k++) {
                    last_fuck[i][j][k] = fuck[i][j][k];
                }
            }
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            ans[i][j] = 1;
        }
    }
    for (int d=0;d<=MAXD;d++) {
        if (d > 0) {
            int skp = (1 << (d - 1));
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=N;j++) {
                    for (int k=0;k<=Q;k++) fuck[i][j][k] = last_fuck[i][j][k];
                    if (fuck[i][j][0] == 0) continue;
                    if (i + skp > N || j + skp > N) {
                        fuck[i][j][0] = 0;
                        continue;
                    }
                    merge(fuck[i][j], last_fuck[i + skp][j]);
                    merge(fuck[i][j], last_fuck[i][j + skp]);
                    merge(fuck[i][j], last_fuck[i + skp][j + skp]);
                }
            }
        } else {
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=N;j++) {
                    fuck[i][j][0] = 1;
                    fuck[i][j][1] = a[i][j];
                }
            }
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (maxd[i][j] == d) {
                    int L = (1 << d);
                    int R = min((1 << (d + 1)), min(N + 2 - i, N + 2 - j));
                    int len = (1 << d);
                    while(L < R - 1) {
                        int mid = (L + R) / 2;
                        int ii = i + mid - 1;
                        int jj = j + mid - 1;
                        for (int k=0;k<=Q;k++) tt[k] = fuck[i][j][k];
                        merge(tt, fuck[i][jj - len + 1]);
                        merge(tt, fuck[ii - len + 1][j]);
                        merge(tt, fuck[ii - len + 1][jj - len + 1]);
                        if (tt[0] == 0) R = mid;
                        else L = mid;
                    }
                    ans[i][j] = L;
                }
            }
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                for (int k=0;k<=Q;k++) {
                    last_fuck[i][j][k] = fuck[i][j][k];
                }
            }
        }
    }
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            sum[ans[i][j]]++;
        }
    }
    
    for (int i=N-1;i>=0;i--) sum[i] += sum[i + 1];
    for (int i=1;i<=N;i++) {
        printf("%d\n",sum[i]);
    }
}
/*
7 10
10 1  2  2  7  11 4
8  8  13 9  7  7  10
5  6  5  10 6  3  6
10 13 5  7  5  3  3
12 1  3  9  12 3  5
1  2  11 9  7  9  2
13 8  13 10 3  11 1
*/
