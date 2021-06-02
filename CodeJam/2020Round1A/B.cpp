#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL C[41][41];

int main() {
    C[1][1] = 1;
    for (int i=2;i<=40;i++) {
        for (int j=1;j<=i;j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        printf("Case #%d:\n",T);
        int N;
        scanf("%d",&N);
        if (N <= 500) {
            for (int i=1;i<=N;i++) {
                printf("%d 1\n",i);
            }
            continue;
        }
        const int delta = 40;
        N -= delta;
        LL sum = 0;
        bool atL = true;
        for (int i=0;i<30;i++) {
            if (N & (1 << i)) {
                if (atL) {
                    for (int j=1;j<=i+1;j++) {
                        printf("%d %d\n",i+1,j);
                    }
                } else {
                    for (int j=i+1;j>=1;j--) {
                        printf("%d %d\n",i+1,j);
                    }
                }
                sum += (1 << i);
                atL = !atL;
            } else {
                if (atL) {
                    printf("%d %d\n",i+1,1);
                } else {
                    printf("%d %d\n",i+1,i+1);
                }
                sum+=1;
            }
        }
        N += delta;
        assert(sum<=N && N-sum<delta);
        for (int i=1;i<=N-sum;i++) {
            if (atL) {
                printf("%d %d\n",30+i,1);
            } else {
                printf("%d %d\n",30+i,30+i);
            }
        }
    }
}