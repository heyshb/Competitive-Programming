#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
char s[200010];
int N;
int cnt[200010][26];

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    for (int i=1;i<=N;i++) {
        for (int j=0;j<26;j++) {
            cnt[i][j] = cnt[i-1][j];
        }
        cnt[i][s[i] - 'a']++;
    }
    int Q;
    scanf("%d",&Q);
    while(Q--) {
        int L,R;
        scanf("%d%d",&L,&R);
        if (L == R) {
            puts("Yes");
            continue;
        }
        /*
        if (L == R - 1 && s[L] != s[R]) {
            puts("Yes");
            continue;
        } 
        */
        int difcnt = 0;
        for (int i=0;i<26;i++) {
            difcnt += (cnt[R][i] != cnt[L - 1][i]);
        }
        //printf("%d\n",difcnt);
        puts(difcnt > 1 ? "Yes" : "No");
    }
}