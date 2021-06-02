#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, a[510];
int ans[510][510];

int sum;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};
void dfs(int x, int y, int val) {
    if (x < 1 || x > n || y < 1 || y > x) return;
    if (ans[x][y]) return;
    //printf("fuck %d %d %d\n",x,y,val);
    ans[x][y] = val;
    if (++sum == val) return;
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], val);
        if (sum == val) return;
    }
}

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i++) {
        sum = 0;
        dfs(i, i, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d%c",ans[i][j]," \n"[j==i]);
        }
    }
}