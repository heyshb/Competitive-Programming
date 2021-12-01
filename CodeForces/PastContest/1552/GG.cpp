#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

bool OK;
int n, m;
int query[110][110];
int arr[110][110];
bool vis[110];

void dfs(int dep) {
    if (dep == m + 1) {
        for (int i = 1; i <= n; i++) {
            if (i > 1 && arr[dep][i] < arr[dep][i - 1]) {
                OK = false;
                return;
            }
        }
        return;
    }
    int sz = query[dep][0];
    int cnt0 = 0, cnt1 = 0, cntn1 = 0;
    for (int i = 1; i <= sz; i++) {
        if (arr[dep][query[dep][i]] == 0) cnt0++;
        if (arr[dep][query[dep][i]] == 1) cnt1++;
    }
    cntn1 = sz - cnt0 - cnt1;
    for (int i = 1; i <= n; i++) {
        arr[dep + 1][i] = arr[dep][i];
    }
    for (int i = 1; i <= cnt0; i++) {
        arr[dep + 1][query[dep][i]] = 0;
    }
    for (int i = 1; i <= cnt1; i++) {
        arr[dep + 1][query[dep][sz + 1 - i]] = 1;
    }
    for (int i = cnt0 + 1; i <= sz - cnt1; i++) {
        arr[dep + 1][query[dep][i]] = 1;
    }
    dfs(dep + 1);
    if (!OK) return;
    for (int i = cnt0 + 1; i <= sz - cnt1; i++) {
        arr[dep + 1][query[dep][i]] = 0;
        dfs(dep + 1);
        if (!OK) return;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    if (n == 1) {puts("ACCEPTED"); return 0;}
    for (int i = 1; i <= m; i++) {
        int sz;
        scanf("%d",&sz);
        for (int j = 0; j < sz; j++) {
            int tmp;
            scanf("%d",&tmp);
            query[i][++query[i][0]] = tmp;
            vis[tmp] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            puts("REJECTED");
            return 0;
        }
    }
    OK = true;
    for (int i = 1; i <= n; i++) arr[1][i] = -1;
    dfs(1);
    puts(OK ? "ACCEPTED" : "REJECTED");
}