#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, H, S;
    scanf("%d%d%d",&N,&H,&S);
    while(N--) {
        int t;
        scanf("%d",&t);
        if (t+S>=H) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}