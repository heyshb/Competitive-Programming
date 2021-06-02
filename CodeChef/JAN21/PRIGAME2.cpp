#include <bits/stdc++.h>

using namespace std;

int p[1000010];

int main() {
    int T, X, Y;
    int M = 1000000;
    for (int i=2;i<=M;i++) p[i] = 1;
    for (int i=2;i<=M;i++) {
        for (int j=i*2;j<=M;j+=i) {
            p[j] = 0;
        }
    }
    for (int i=1;i<=M;i++) {
        p[i] += p[i - 1];
    }
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&X,&Y);
        if (p[X] <= Y) {
            puts("Chef");
        } else {
            puts("Divyam");
        }
    }
}