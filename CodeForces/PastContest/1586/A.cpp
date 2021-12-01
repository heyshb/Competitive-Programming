#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

bool com(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return true;
    }
    return false;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        int S = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            S += a[i];
        }
        if (com(S)) {
            printf("%d\n",n);
            for (int i = 0; i < n; i++) {
                printf("%d ", i + 1);
            }
            puts("");
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (com(S - a[i])) {
                printf("%d\n",n - 1);
                for (int j = 0; j < n; j++) {
                    if (j != i) printf("%d ",j + 1);
                }
                puts("");
                break;
            }
        }
    }
    
}