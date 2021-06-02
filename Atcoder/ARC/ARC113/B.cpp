#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int qp(int a,int x,int MOD) { 
    int ret = 1;
    while(x) {
        if (x & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        x >>= 1;
    }
    return ret;
}

int main() {
    int A, B, C;
    scanf("%d%d%d",&A,&B,&C);
    int tmp = 4 + qp(B, C, 4);
    tmp = qp(A, tmp, 5);
    if (tmp % 2 != A % 2) tmp = (tmp + 5) % 10;
    printf("%d\n",tmp);
}