#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
char ans[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int M;
        scanf("%d",&M);
        int dif = 0;
        int len = 0;
        while(M) {
            int k;
            for (k=1;k*(k+1)/2<=M;k++);
            k--;
            //printf("%d %d\n",M,k);
            char ch = 'a' + dif;
            for (int i=1;i<=k;i++) ans[len++] = ch;
            if (++dif == 3) dif = 0;
            M -= k * (k + 1) / 2;
        }
        ans[len] = 0;
        printf("%s\n",ans);
    }
}