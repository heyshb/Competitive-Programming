#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[310][310];
int N;
int fuck[2][3];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            scanf("%s", s[i] + 1);
        }
        memset(fuck,0,sizeof(fuck));
        int sum = 0;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (s[i][j] == '.') continue;
                if (s[i][j] == 'O') fuck[0][(i+j)%3]++;
                if (s[i][j] == 'X') fuck[1][(i+j)%3]++;
                sum++;
            }
        }
        for (int i=0;i<3;i++) { // O
            for (int j=0;j<3;j++) { // X
                if (i == j) continue;
                int modify = fuck[0][i] + fuck[1][j];
                if (modify * 3 <= sum) {
                    for (int k=1;k<=N;k++) {
                        for (int l=1;l<=N;l++) {
                            if ((k + l) % 3 == i && s[k][l] == 'O') s[k][l] = 'X';
                            if ((k + l) % 3 == j && s[k][l] == 'X') s[k][l] = 'O';
                        }
                    }
                    goto PRINT;
                }
            }
        }
        PRINT:
        for (int i=1;i<=N;i++) {
            printf("%s\n",s[i] + 1);
        }
    }
}