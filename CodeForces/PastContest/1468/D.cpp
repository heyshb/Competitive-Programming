#include <bits/stdc++.h>

using namespace std;

int N, M, a, b;
int s[200010];

bool check(int x) {
    if (x > N) return false;
    int R = a, B = b;
    if (x > a) {
        R = x;
        B -= (x - a);
        if (B <= R) return false;
    } 
    int maxt = 0;
    for (int i=1;i<=x;i++) {
        maxt = max(maxt, s[x + 1 - i] + 2 * (i - 1) + 1);
    }
    int nowt = 2 * x - 1;
    R -= x - 1;
    B -= 2 * x - 1;
    //printf("%d %d %d\n",nowt,R,B);
    if (B <= R) return false;
    return (nowt + B - 1 >= maxt);
}  

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d",&N,&M,&a,&b);
        if (a > b) {
            a = N + 1 - a;
            b = N + 1 - b;
        }
        for (int i=1;i<=M;i++) {
            scanf("%d",&s[i]);
        }
        sort(s+1,s+M+1);
        int L = 0, R = M + 1;
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (check(mid)) L = mid;
            else R = mid;
        }
        printf("%d\n",L);
    }
}