#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
char s[110][110];
char ans[100010];
int N,L[110];
int fst[110], lst[110];
char prefix[110], suffix[110];
int M;

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d",&N);
        int maxpre = -1, maxsuf = -1;
        int mpid = -1, msid = -1;
        for (int i=1;i<=N;i++) {
            scanf("%s",s[i] + 1);
            L[i] = strlen(s[i] + 1);
            fst[i] = lst[i] = -1;
            for (int j=1;j<=L[i];j++) {
                if (s[i][j] == '*') {
                    if (fst[i] == -1) {
                        fst[i] = j;
                    }
                    lst[i] = j;
                }
            }
            if (fst[i] - 1 > maxpre) {
                maxpre = fst[i] - 1;
                mpid = i;
            }
            if (L[i] - lst[i] > maxsuf) {
                maxsuf = L[i] - lst[i];
                msid = i;
            }
        }
        //printf("%d %d %d %d\n",maxpre,maxsuf,mpid,msid);
        for (int i=1;i<=maxpre;i++) {
            prefix[i] = s[mpid][i];
        }
        for (int i=1;i<=maxsuf;i++) {
            suffix[i] = s[msid][L[msid] + 1 - i];
        } 
        bool ok = true;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<fst[i];j++) {
                ok &= (prefix[j] == s[i][j]);
            }
            for (int j=1;j<=L[i]-lst[i];j++) {
                ok &= (suffix[j] == s[i][L[i] + 1 - j]);
            }
        }
        if (ok) {
            M = 0;
            for (int i=1;i<=maxpre;i++) {
                ans[++M] = prefix[i];
            }
            for (int i=1;i<=N;i++) {
                for (int j=fst[i]+1;j<lst[i];j++) {
                    if (s[i][j] != '*') {
                        ans[++M] = s[i][j];
                    }
                }
            }
            for (int i=1;i<=maxsuf;i++) {
                ans[++M] = suffix[maxsuf + 1 - i];
            }
            ans[M + 1] = 0;
            printf("Case #%d: %s\n", T, ans + 1);
        } else {
            printf("Case #%d: *\n", T);
        }
    }
}