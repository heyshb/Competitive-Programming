#include <bits/stdc++.h>

using namespace std;

int main() {
    int val;
    scanf("%d",&val);
    //val = int(sqrt(val) + 1e-6);
    int ans = 0;
    while(val) {
        ans += val % 10;
        val /= 10;
    }
    printf("%d\n",ans);
}