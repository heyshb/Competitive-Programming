#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[1000010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        bool all_same = true;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if (i>1&&a[i]!=a[1]) all_same = false;
        }
        if (all_same) printf("%d\n",n);
        else printf("%d\n",1);
    }
}