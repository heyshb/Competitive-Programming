#include <bits/stdc++.h>

using namespace std;

int n;
int a[400010];
int g[400010];
int id[400010];
char ans[400010];
int stk[4000010];

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d",&a[i]);
        id[i] = i;
    }
    sort(id+1,id+2*n+1,[&](int &id1, int &id2) {
        if (a[id1] == a[id2]) return id1 < id2;
        return a[id1] < a[id2];
    });
    for (int i = 1; i <= n; i++) {
        g[id[i]] = 1;
    }
    int top = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (top && stk[top] != g[i]) {
            top--;
            ans[i] = ')';
        } else {
            stk[++top] = g[i];
            ans[i] = '(';
        }
    }
    ans[2 * n + 1] = 0;
    printf("%s\n",ans + 1);
}