#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, n;
    scanf("%d%d%d%d",&a,&b,&c,&n);
    a--;b--;c--;n-=3;
    bool ok = true;
    if (a < 0 || b < 0 || c < 0 || n < 0 || n > a + b + c) ok = false;
    puts(ok ? "YES" : "NO");
}