#include <bits/stdc++.h>

using namespace std;

int N;
int a[100],b[100],t[100];
int f[1000];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d%d",&a[i],&b[i],&t[i]);
    }
    int ans = 0;
    for (int i=1;i<=100;i++) {
        f[i] = f[i - 1];
        for (int j=1;j<=N;j++) {
            if (i >= a[j] && i <= b[j] && i - t[j] >= a[j] && i - t[j] <= b[j]) {
                //printf("%d %d\n",i, f[i-t[j]]+1);
                f[i] = max(f[i], f[i - t[j]] + 1);
            }
        }
    }
    printf("%d\n",f[100]);
}
3
2 20 3
7 12 1
5 20 3
