#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int x[500010], y[500010];
char s[500010];
const int INF = 1e7;

bool test(int xma, int xmi, int yma, int ymi, int xyma, int xymi, bool print, int d) {
    vector<pii> p;
    p.push_back(pii(xmi, ymi));
    p.push_back(pii(xmi, yma));
    p.push_back(pii(xma, ymi));
    p.push_back(pii(xma, yma));
    p.push_back(pii(xmi, xmi + xymi));
    p.push_back(pii(xma, xma + xymi));
    p.push_back(pii(xmi, xmi + xyma));
    p.push_back(pii(xma, xma + xyma));
    p.push_back(pii(ymi - xymi, ymi));
    p.push_back(pii(ymi - xyma, ymi));
    p.push_back(pii(yma - xymi, yma));
    p.push_back(pii(yma - xyma, yma));
    p.push_back(pii(1, 1));
    p.push_back(pii(1, 0));
    p.push_back(pii(0, 1));
    for (auto t:p) {
        int xx = t.first, yy = t.second;
        //printf("test %d %d\n",xx,yy);
        if (xx == 0 && yy == 0) continue;
        //printf("?? %d[%d,%d] %d[%d,%d] %d[%d,%d]\n",xx,xmi,xma,yy,ymi,yma,yy-xx,xymi,xyma);
        if (xx >= xmi && xx <= xma && yy >= ymi && yy <= yma && yy - xx >= xymi && yy - xx <= xyma) {
            if (print) {
                printf("%d\n",d);
                for (int i=0;i<xx;i++) printf("B");
                for (int i=0;i<yy;i++) printf("N");
            }
            return true;
        }
    }
    return false;
}

bool check(int d, bool print) {
    int x_down = 0, x_up = INF;
    int y_down = 0, y_up = INF;
    int xy_down = -INF, xy_up = INF;
    for (int i=1;i<=N;i++) {
        x_down = max(x_down, x[i] - d);
        x_up = min(x_up, x[i] + d);
        y_down = max(y_down, y[i] - d);
        y_up = min(y_up, y[i] + d);
        xy_down = max(xy_down, y[i] - x[i] - d);
        xy_up = min(xy_up, y[i] - x[i] + d);
    }
    //printf("%d %d %d %d %d %d\n",x_down,x_up,y_down,y_up,xy_down,xy_up);
    if (x_up < x_down || y_up < y_down || xy_up < xy_down) return false;
    return test(x_up, x_down, y_up, y_down, xy_up, xy_down, print, d);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%s", s + 1);
        int M = strlen(s + 1);
        for (int j=1;j<=M;j++) {
            if (s[j] == 'B') x[i]++;
            else y[i]++;
        }
        //printf("%d %d\n",x[i],y[i]);
    }
    int L = 0, R = 1000010;
    if (check(0, false)) {
        puts("0");
        for (int i=0;i<x[1];i++) printf("B");
        for (int i=0;i<y[1];i++) printf("N");
    } else {
        while(L < R - 1) {
            //printf("%d %d\n",L,R);
            int mid = (L + R) / 2;
            if (check(mid, false)) {
                R = mid;
            } else {
                L = mid;
            }
        }
        check(R, true);
    }
}