#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[310][310];
int N;
int fuck[3];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%s", s[i] + 1);
        }
        memset(fuck,0,sizeof(fuck));
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (s[i][j] == '.') continue;
                fuck[(i+j)%3]++;
            }
        }
        int mi = 1e9, id = 0;
        for (int i=0;i<3;i++) {
            if (fuck[i] < mi) {
                mi = fuck[i];
                id = i;
            }
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (s[i][j] == '.') continue;
                if ((i+j) % 3 == id) {
                    s[i][j] = 'O';
                }
            }
        }
        for (int i=1;i<=N;i++) {
            printf("%s\n",s[i] + 1);
        }
    }
}