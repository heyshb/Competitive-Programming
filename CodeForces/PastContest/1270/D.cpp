#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int N,K;
    scanf("%d%d",&N,&K);
    map<int,int>cnt;
    int mv = 0;
    for (int del=1;del<=K+1;del++) {
        printf("?");
        for (int i=1;i<=K+1;i++) {
            if (i != del) {
                printf(" %d",i);
            }
        }
        puts("");
        fflush(stdout);
        int v1, v2;
        scanf("%d%d",&v1,&v2);
        mv = max(mv, v2);
        if (cnt.find(v2) == cnt.end()) {
            cnt[v2] = 1;
        } else {
            cnt[v2]++;
        }
    }
    printf("! %d\n",cnt[mv]);
    fflush(stdout);
}