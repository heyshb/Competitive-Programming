#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T;
int n;
char s[1000010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        scanf("%s", s + 1);
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += (s[i] == '?');
        if (cnt == n) {
            for (int i = 1; i <= n; i++) {
                s[i] = "RB"[i%2];
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (s[i] == '?' && (s[i - 1] == 'R' || s[i - 1] == 'B')) {
                    if (s[i - 1] == 'R') s[i] = 'B';
                    else s[i] = 'R';
                }
            }
            for (int i = n; i >= 1; i--) {
                if (s[i] == '?' && (s[i + 1] == 'R' || s[i + 1] == 'B')) {
                    if (s[i + 1] == 'R') s[i] = 'B';
                    else s[i] = 'R';
                }
            }
        }
        printf("%s\n",s + 1);
    }
}