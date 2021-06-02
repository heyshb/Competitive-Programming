#include <bits/stdc++.h>

using namespace std;

int swp(int x, int y) {
    printf("S %d %d\n",x,y);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int ask(int L, int R) {
    printf("M %d %d\n",L,R);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret; 
}

int main() {
    int T, N;
    scanf("%d%d",&T,&N);
    while(T--) {
        for (int i = 1; i <= N - 1; i++) {
            int pos = ask(i, N);
            if (i != pos) swp(i, pos);
        }
        puts("D");
        fflush(stdout);
        int ret;
        scanf("%d",&ret);
    }
}