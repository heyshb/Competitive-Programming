#include <bits/stdc++.h>

using namespace std;

int query(int L,int R) {
    printf("? %d %d\n",L,R);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int a[1010];
int b;
int ans[1010];

int main() {
    int N;
    scanf("%d",&N);
    for (int i=2;i<=N;i++) {
        a[i] = query(1, i);
    } 
    b = query(2, N);
    a[1] = ans[1] = a[N] - b;
    for (int i=2;i<=N;i++) {
        ans[i] = a[i] - a[i-1];
    }
    printf("!");
    for (int i=1;i<=N;i++) {
        printf(" %d",ans[i]);
    }
    puts("");
}