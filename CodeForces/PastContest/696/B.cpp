#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int fa[100010], sz[100010], dep[100010];

int main() {
    scanf("%d",&n);
    for (int i = 2; i <= n; i++) {
        scanf("%d",&fa[i]);
    }
    dep[1] = 0;
    for (int i = 2; i <= n; i++) dep[i] = dep[fa[i]] + 1;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    for (int i = n; i >= 1; i--) sz[fa[i]] += sz[i];
    for (int i = 1; i <= n; i++) {
        double ans = 0.5 * (n - sz[i] + dep[i]) + 1;
        printf("%.10lf%c",ans," \n"[i==n]);
    } 
}