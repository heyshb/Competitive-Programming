#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, N;
char s[2000010];
int r[2000010];
int mx;

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%s", s + 1);
        N = strlen(s + 1);
        for (int i=N;i>=1;i--) {
            s[i * 2 - 1] = s[i];
            s[i * 2] = '#';
        }
        s[0] = '#';
        s[N * 2 + 1] = 0;
        printf("%s\n",s);
        int mx = -1, id = -1;
        for (int i=0;i<=N*2;i++) {
            r[i] = 0;
            if (i<=mx) {
                r[i] = min(mx - i, r[2 * id - i]);
            } else {
                mx = i;
                id = i;
            }
            while(i + r[i] + 1 <= 2 * N && i - r[i] - 1 >= 0 && s[i - r[i] - 1] == s[i + r[i] + 1]) {
                r[i]++;
                if (i + r[i] > mx) {
                    mx = i + r[i];
                    id = i;
                }
            }
        }
        for (int i=0;i<=2*N;i++) {
            printf("%d ",r[i]);
        }
        int 
        for (int i=1;i<2*N-i;i+=2) {

        }
    }
}