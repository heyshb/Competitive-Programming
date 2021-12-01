#include <bits/stdc++.h>
#define x1 xcnlvz
#define x2 zxclnv
#define y1 qwerty
#define y2 zxcnvl
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int W, H, w, h, x1, x2, y1, y2;
        scanf("%d%d",&W,&H);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int ww = x2 - x1, hh = y2 - y1;
        scanf("%d%d",&w,&h);
        //printf("%d %d\n",w+ww,h+hh);
        if (w + ww > W && h + hh > H) {
            puts("-1");
            continue;
        }
        int dx = 1e9, dy = 1e9;
        if (w + ww <= W) {
            if (x1 >= w || x2 <= W - w) dx = 0;
            else dx = min(w - x1, x2 - (W - w));
        }
        if (h + hh <= H) {
            if (y1 >= h || y2 <= H - h) dy = 0;
            else dy = min(h - y1, y2 - (H - h));
        }
        printf("%d\n",min(dx, dy));
    }
}