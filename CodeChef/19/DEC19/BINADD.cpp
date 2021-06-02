#include <bits/stdc++.h>

using namespace std;

int A[200010];
set<int>B;
char s[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N, M;
        scanf("%s",s);
        N = strlen(s);
        for (int i=0;i<N;i++) {
            A[i] = (s[N - 1 - i] - '0');
        }
        scanf("%s",s);
        B.clear();
        M = strlen(s);
        for (int i=0;i<M;i++) {
            if (s[M - 1 - i] == '1') {
                B.insert(i);
            }
        }
        for (int i=N;i<N+M;i++) {
            A[i] = 0;
        }
        int ans = 0;
        while(!B.empty()) {
            ans++;
            set<int> NB;
            for (auto t:B) {
                if (A[t]) {
                    NB.insert(t + 1);
                } 
                A[t] ^= 1;
            }
            B = NB;
        }
        printf("%d\n",ans);
    }
}