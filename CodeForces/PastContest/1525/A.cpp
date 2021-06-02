#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T, val;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&val);
        printf("%d\n",100 / __gcd(100, val));
    }
}