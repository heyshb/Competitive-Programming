#include <bits/stdc++.h>

using namespace std;

int upa, upb, downa, downb;
int a, b, x, y;

int main() {
    scanf("%d%d%d%d",&a,&b,&x,&y);
    int c = min(2 * x, y);
    int ans = c * abs(a - b) + x;
    if (a > b) ans -= c;
    printf("%d\n",ans);
}