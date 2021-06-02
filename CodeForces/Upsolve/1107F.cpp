#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;
struct offer {
    LL a,b,k;
}o[510];

bool cmp(offer o1, offer o2) {
    return o1.b > o2.b;
}

/*
maximize \sum_{i=0}^{M-1} {a_i - b_i * min(k_i, i)} 
*/

LL f[510][510];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%lld%lld%lld",&o[i].a,&o[i].b,&o[i].k);
    }
    sort(o+1,o+N+1,cmp);
    LL ans = 0;
    for (int i=1;i<=N;i++) {
        for (int j=0;j<=N;j++) {
            f[i][j] = f[i - 1][j];

            // try to use offer_i and pay it after k days
            f[i][j] = max(f[i][j], f[i - 1][j] + o[i].a - o[i].b * o[i].k);
            
            // try to use the offer today. If k days have passed, the previous line will update a better answer
            if (j > 0) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + o[i].a - o[i].b * (j - 1));
            }
            ans = max(ans, f[i][j]);
        }
    }
    printf("%lld\n",ans);
}