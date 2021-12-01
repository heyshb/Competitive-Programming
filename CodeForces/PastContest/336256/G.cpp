#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
int a[1000010];
int stk[1000010], top;
int nxt[1000010];
int d[1000010];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    a[n + 1] = 1e9 + 10;
    stk[top = 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (a[stk[top]] >= a[i]) {
            nxt[i] = i;
        } else {
            int L = 1, R = top;
            while(L < R - 1) {
                int mid = (L + R) / 2;
                if (a[stk[mid]] < a[i]) {
                    R = mid;
                } else {
                    L = mid;
                }
            }
            nxt[i] = stk[R];
        }
        if (a[i] < a[stk[top]]) stk[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        d[i]++;
        d[nxt[i]]--;
    }
    //for (int i = 1; i <= n; i++) printf("%d ",nxt[i]);puts("");
    int s = 0;
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        s += d[i];
        //printf("%d %d\n",i,s);
        if (s == 0) cnt++;
    }
    printf("%d\n",cnt + 1);
}