#include <bits/stdc++.h>

using namespace std;

int a[100];
int N;
int ans[100][100];
int weight[30];
int eq[40], val[40];

int main() {
    freopen("large.in","r",stdin);
    scanf("%d",&N);
    for (int i=0;i<N;i++) {
        scanf("%d",&eq[i]);
    }
    freopen("large.out","r",stdin);
    for (int i=0;i<N;i++) {
        scanf("%d",&val[i]);
    }
    for (int i=0;i<30;i++) {
        for (int j=i;j<N;j++) {
            if ((eq[j] >> i) & 1) {
                swap(eq[i], eq[j]);
                swap(val[i], val[j]);
                break;
            }
        }
        for (int j=i+1;j<N;j++) {
            if ((eq[j] >> i) & 1) {
                eq[j] ^= eq[i];
                val[j] ^= val[i];
            }
        }
    }
    for (int i=29;i>=0;i--) {
        for (int j=i-1;j>=0;j--) {
            if ((eq[j] >> i) & 1) {
                eq[j] ^= eq[i];
                val[j] ^= val[i];
            }
        }
    }
    for (int i=0;i<30;i++) {
        printf("%d,", val[i]);
    }
}