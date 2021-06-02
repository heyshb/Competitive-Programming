#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
vector<pii>pp[2];
const int BIAS = 200022;
int up[2 * BIAS], down[2 * BIAS];
const int INF = 1e9;
vector<int> v[2 * BIAS];

LL solve(vector<pii> p) {
    //puts("solve");
    int N = p.size();
    for (int i=0;i<N;i++) {
        if ((p[i].X + p[i].Y) % 2 == 0) p[i].X++;
        pii tmp;
        tmp.X = p[i].X + p[i].Y;
        tmp.Y = p[i].Y - p[i].X;
        p[i] = tmp;
        //printf("(%d,%d)\n",tmp.X,tmp.Y);
    }
    for (int i=0;i<2*BIAS;i++) {
        up[i] = INF;
        down[i] = -INF;
    }
    int dx, dy, nowup, nowdown;

    // dir 1
    dx = -1;
    dy = -1;
    for (int i=0;i<2*BIAS;i++) {
        v[i].clear();
    }
    for (int i=0;i<N;i++) {
        v[p[i].X + dx + BIAS].push_back(p[i].Y + dy);
    }
    nowup = -INF;
    for (int i=2*BIAS-1;i>=0;i--) {
        for (auto t:v[i]) {
            nowup = max(nowup, t);
        }
        up[i] = min(up[i], nowup);
    }

    // dir 2
    dx = 1;
    dy = -1;
    for (int i=0;i<2*BIAS;i++) {
        v[i].clear();
    }
    for (int i=0;i<N;i++) {
        v[p[i].X + dx + BIAS].push_back(p[i].Y + dy);
    }
    nowup = -INF;
    for (int i=0;i<2*BIAS;i++) {
        for (auto t:v[i]) {
            nowup = max(nowup, t);
        }
        up[i] = min(up[i], nowup);
    }

    // dir 3
    dx = -1;
    dy = 1;
    for (int i=0;i<2*BIAS;i++) {
        v[i].clear();
    }
    for (int i=0;i<N;i++) {
        v[p[i].X + dx + BIAS].push_back(p[i].Y + dy);
    }
    nowdown = INF;
    for (int i=2*BIAS-1;i>=0;i--) {
        for (auto t:v[i]) {
            nowdown = min(nowdown, t);
        }
        down[i] = max(down[i], nowdown);
    }
    
    // dir 4
    dx = 1;
    dy = 1;
    for (int i=0;i<2*BIAS;i++) {
        v[i].clear();
    }
    for (int i=0;i<N;i++) {
        v[p[i].X + dx + BIAS].push_back(p[i].Y + dy);
    }
    nowdown = INF;
    for (int i=0;i<2*BIAS;i++) {
        for (auto t:v[i]) {
            nowdown = min(nowdown, t);
        }
        down[i] = max(down[i], nowdown);
    }

    LL ans = 0;
    for (int i=0;i<2*BIAS;i++) {
        if (i % 2 == 0 && up[i] >= down[i]) {
            //printf("%d %d %d\n",i,up[i],down[i]);
            assert(up[i] % 2 == 0);
            assert(down[i] % 2 == 0);
            ans += (up[i] - down[i]) / 2 + 1;
        }
    }
    return ans;
}

int main() {
    int N;
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        pp[abs(x+y)%2].push_back(pii(x,y));
    }
    LL ans = solve(pp[0]) + solve(pp[1]);
    printf("%lld\n",ans);
}