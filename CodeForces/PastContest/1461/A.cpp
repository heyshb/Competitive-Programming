#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
char s[4] = "abc";
int main() {
    int T,N,K;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&K);
        for (int i=0;i<N;i++) {
            printf("%c",s[i%3]);
        }
        puts("");
    }
}