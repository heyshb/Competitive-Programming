#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
char s[100010];
char t[100010];
int n;

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s", s + 1);
        for (int i = 1; i <= n; i++) t[i] = s[i];
        sort(t+1,t+n+1);
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += (t[i] != s[i]);
        printf("%d\n",ans);
    }
}