#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
int f[1010][1010];

int main() {
    int T;
    scanf("%d",&T);
    for (int i=1;i<=1000;i++) {
        for (int j=1;j<=1000;j++) {
            f[i][j] = max(f[i-1][j], f[i][j-1]) + (__gcd(i,j) == 1);
        }
    }
    while(T--) {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",f[x][y]);
    }
}