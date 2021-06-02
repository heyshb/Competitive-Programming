#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

bool cmp_sum(pii p1, pii p2) {
    return p1.first + p1.second < p2.first + p2.second;
}

bool cmp_k(pii p1, pii p2) {
    // p1.y / p1.x < p2.y / p2.x
    return p1.second * p2.first < p1.first * p2.second;
}

template<typename T>
void upd(T &x, T y) {
    x = min(x, y);
}

// f[M][D][y] pre i j not chosen y 
const int MAXY = 40000;
const int MAXD = 200;
int f[2][MAXD + 10][MAXY + 10];
const int INF = 1e9;
void solve(int N) {
    if (N % 4 != 0) {
        puts("N % 4 must == 0!");
        return;
    }
    vector<pii> seg;
    N /= 4;
    //seg.push_back(pii(1, 0));
    //seg.push_back(pii(0, 1));
    for (int x=1;x<=N;x++) {
        for (int y=1;y<=N;y++) {
            if (__gcd(x, y) == 1) {
                seg.push_back(pii(x, y));
            }
        }
    }
    sort(seg.begin(), seg.end(), cmp_sum);
    int M = min(int(seg.size()), N + MAXD);
    seg.erase(seg.begin() + M, seg.end());
    assert(seg.size() == M);
    int D = M - (N - 1);
    sort(seg.begin(), seg.end(), cmp_k);
    reverse(seg.begin(), seg.end());
    /*
    for (auto t:seg) {
        printf("%d %d\n",t.first,t.second);
    }
    */
    for (int j=0;j<=D;j++) {
        for (int y=0;y<=MAXY;y++) {
            f[0][j][y] = INF;
        }
    }
    f[0][0][0] = 0;
    for (int i=1;i<=M;i++) {
        int now = (i & 1), last = (now ^ 1);
        auto pnow = seg[i - 1];
        for (int j=0;j<=D;j++) {
            for (int k=0;k<=MAXY;k++) {
                f[now][j][k] = INF;
                if (k>=pnow.second) upd(f[now][j][k], f[last][j][k-pnow.second] + 
                                        2 * pnow.first * (2*k - pnow.second) + 2 * pnow.first);
                if (j>0) upd(f[now][j][k], f[last][j-1][k]);
            }
        }
    }
    int ret = INF;
    for (int y=0;y<=20000;y++) {
        upd(ret, f[M&1][D][y] + 2 * y + 1);
    }
    printf("solve %d = %d\n",N * 4 ,ret);
}

int main() {
    //solve(8);
    //solve(40);
    //solve(100);
    solve(1000);
}