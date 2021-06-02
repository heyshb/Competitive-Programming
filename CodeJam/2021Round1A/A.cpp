#include <bits/stdc++.h>

using namespace std;

int N;
char s[110][110];


int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        printf("Case #%d: ", ++Case);
        scanf("%d",&N);
        int ans = 0;
        memset(s, 0, sizeof(s));
        for (int i=1;i<=N;i++) {
            scanf("%s", s[i] + 1);
        }
        for (int i=2;i<=N;i++) {
            int len1 = strlen(s[i - 1] + 1);
            int len2 = strlen(s[i] + 1);
            if (len2 > len1) continue;
            int lcp = 0;
            for (int j=1;j<=min(len1,len2);j++) {
                if (s[i - 1][j] == s[i][j]) lcp++;
                else break;
            }
            bool all_9 = true;
            for (int j=lcp+1;j<=len1;j++) {
                if (s[i - 1][j] != '9') all_9 = false;
            }
            if (s[i][lcp + 1] > s[i - 1][lcp + 1]) {
                for (int j=len2+1;j<=len1;j++) {
                    ans++;
                    s[i][j] = '0';
                }
                continue;
            }
            if (lcp == len2) {
                if (all_9) {
                    for (int j=len2+1;j<=len1+1;j++) {
                        ans++;
                        s[i][j] = '0';
                    }
                } else {
                    ans += len1 - len2;
                    int last_none_9 = -1;
                    for (int j=len2+1;j<=len1;j++) {
                        if (s[i - 1][j] != '9') {
                            last_none_9 = j;
                        }
                    }
                    for (int j=len2+1;j<last_none_9;j++) {
                        s[i][j] = s[i - 1][j];
                    }
                    s[i][last_none_9] = s[i - 1][last_none_9] + 1;
                    for (int j=last_none_9 + 1;j<=len1;j++) s[i][j] = '0';
                }
            } else {
                for (int j=len2+1;j<=len1+1;j++) {
                    ans++;
                    s[i][j] = '0';
                }
            }
        }
        printf("%d\n",ans);
    }
}