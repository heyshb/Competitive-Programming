#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;

int a[11] = {95,90,85,80,75,70,67,65,62,60,0};
int b[11] = {43,40,37,33,30,27,23,20,17,10,0};
int ans[410];

int main() {
    int T;
    scanf("%d",&T);
    for (int i=0;i<11;i++) {
        for (int j=0;j<11;j++) {
            for (int k=0;k<11;k++) {
                for (int l=0;l<11;l++) {
                    ans[a[i]+a[j]+a[k]+a[l]] = max(ans[a[i]+a[j]+a[k]+a[l]], b[i]+b[j]+b[k]+b[l]);
                }
            }
        }
    }
    for (int i=1;i<=400;i++) {
        ans[i] = max(ans[i], ans[i-1]);
    }
    while(T--) {
        int x;
        scanf("%d",&x);
        printf("%.1lf\n",ans[x] * 0.1);
    }
}