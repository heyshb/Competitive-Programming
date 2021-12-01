#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n, s;
        scanf("%d%d",&n,&s);
        int cnt = (n + 1) / 2;
        if (n % 2 == 0) cnt++;
        printf("%d\n",s/cnt);
    }
}