#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, s[i] - '0');
        }
        printf("%d\n",ans);
    }
}