#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int N;
    scanf("%d",&N);
    for (int i=2;i<=1000;i++) {
        if (N % i == 0) {
            printf("%d%d\n",i,N/i);
            return 0;
        }
    }
    printf("1%d\n",N);
}