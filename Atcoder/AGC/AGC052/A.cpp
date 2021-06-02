#include <bits/stdc++.h>

using namespace std;
char s[1000010];
int main() {
    int T, N;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=3;i++) scanf("%s",s);
        printf("0");
        for (int i=0;i<N;i++) printf("1");
        for (int i=0;i<N;i++) printf("0");
        puts("");
    }
}