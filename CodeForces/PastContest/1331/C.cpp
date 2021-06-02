#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int d[10];

int main() {
    int N;
    scanf("%d",&N);
    for (int i=0;i<6;i++) {
        d[i] = (N >> i) & 1;
    }
    int ans = d[4] + d[1] * 2 + d[3] * 4 + d[2] * 8 + d[0] * 16 + d[5] * 32;
    printf("%d\n",ans);
}