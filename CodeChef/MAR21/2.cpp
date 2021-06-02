#include <bits/stdc++.h>

using namespace std;
char s[100100];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int ans = 0;
        for (int i=1;i<=n;i++) {
            if (s[i] == '1' && (i == 1 || s[i - 1] == '0')) ans++;
        }
        printf("%d\n",ans);
    }
}