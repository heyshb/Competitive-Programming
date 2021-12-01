#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int INF = 1e9;

void updma(int &x, int y){x = max(x, y);}
void updmi(int &x, int y){x = min(x, y);}

int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    vector<int> vis(1 << k, 0);
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d",&tmp);
        vis[tmp] = 1;
    }
    vvi ma(1 << k, vi(2, -INF)), mi(1 << k, vi(2, INF)), mind(1 << k, vi(2, INF));
    for (int i = 0; i < (1 << k); i++) {
        if (vis[i]) {
            ma[i][0] = i;
            ma[i][1] = i ^ 1;
            mi[i][0] = i;
            mi[i][1] = i ^ 1;
            //printf("ma[%d] = %d,%d\n",i,ma[i][0]);
        }
    }
    for (int h = k - 1; h >= 0; h--) {
        int m = 1 << h;
        int w = 1 << (k - h + 1);
        int hi = w / 2;
        int hh = hi / 2;
        vvi new_ma(1 << h, vi(w, -INF));
        vvi new_mi(1 << h, vi(w, INF));
        vvi new_mind(1 << h, vi(w, INF));
        for (int i = 0; i < m; i++) {
            //printf("dep = %d, node = %d hi = %d\n", h, i, hi);
            int L = i * 2, R = i * 2 + 1;
            //printf("L = %d, R = %d\n",L,R);
            for (int j = 0; j < w / 2; j++) {
                updma(new_ma[i][j], ma[L][j]);
                updma(new_ma[i][j], ma[R][j]);
                updmi(new_mi[i][j], mi[L][j]);
                updmi(new_mi[i][j], mi[R][j]);
                new_mind[i][j] = min(mind[L][j], mind[R][j]);
                if (j & hh) updmi(new_mind[i][j], mi[L][j] - ma[R][j]);
                else updmi(new_mind[i][j], mi[R][j] - ma[L][j]);
                //updmi(new_mind[i][j], hi + mi[R][j] - ma[L][j]);
            }
            for (int j = w / 2; j < w; j++) {
                int lo = j - w / 2;
                updma(new_ma[i][j], ma[L][lo] ^ hi);
                updma(new_ma[i][j], ma[R][lo] ^ hi);
                updmi(new_mi[i][j], mi[L][lo] ^ hi);
                updmi(new_mi[i][j], mi[R][lo] ^ hi);
                new_mind[i][j] = min(mind[L][lo], mind[R][lo]);
                //printf("?? %d %d %d %d\n",j,lo,mi[R][lo],ma[L][lo]);
                if (lo & hh) updmi(new_mind[i][j], mi[L][lo] - ma[R][lo]);
                else updmi(new_mind[i][j], mi[R][lo] - ma[L][lo]);
            }
            /*
            for (int j = 0; j < w; j++) {
                printf("ma %d = %d\n",j,new_ma[i][j]);
                printf("mi %d = %d\n",j,new_mi[i][j]);
                printf("mind %d = %d\n",j,new_mind[i][j]);
            }
            */
        }
        ma = new_ma;
        mi = new_mi;
        mind = new_mind;
    }
    for (int i = 0; i < (1 << k); i++) {
        printf("%d%c",mind[0][i]," \n"[i == (1 << k) - 1]);
    }
}