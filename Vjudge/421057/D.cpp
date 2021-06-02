#include <bits/stdc++.h>

using namespace std;

int N, h1, m1, h2, m2, alpha;
typedef pair<int,double> pid;
const int R = 86400 / 2;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d:%d",&h1,&m1);
        scanf("%d:%d",&h2,&m2);
        scanf("%d",&alpha);
        int start_d = 11 * (h1 * 3600 + m1 * 60);
        int end_d = 11 * (h2 * 3600 + m2 * 60);
        int ans = 0;
        for (int d=start_d;d<=end_d;d++) {
            if (alpha == 0 && d % R == 0) ans++;
            if (alpha == 90 && (d % R == R / 4 || d % R == R * 3 /4 )) ans++;
            if (alpha == 180 && d % R == R / 2) ans++;
        }
        printf("%d\n",ans);
    }
}