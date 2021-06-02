#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
char S[100010], T[100010];
int cntS[100010], cntT[100010], cntD[100010];

int main() {
    int Cases;
    scanf("%d",&Cases);
    while(Cases--) {
        scanf("%d",&N);
        scanf("%s", S + 1);
        scanf("%s", T + 1);
        S[N+1] = T[N+1] = '0';
        for (int i=1;i<=N+1;i++) {
            S[i] -= '0';
            T[i] -= '0';
            cntS[i] = cntS[i - 1] + S[i];
            cntT[i] = cntT[i - 1] + T[i];
            cntD[i] = cntD[i - 1] + (S[i] != T[i]);
        }
        int ans = cntD[N];
        for (int i=1;i<=N;i++) {
            int tmp = i - cntS[i];
            tmp += S[i+1];
            tmp++;
            tmp += (T[i+1] == 0);
            tmp += cntT[i];
            tmp += cntD[N + 1] - cntD[i + 1];
            ans = min(ans, tmp);
        }
        printf("%d\n", ans);
    }
}