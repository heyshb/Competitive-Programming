#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, a[100010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int down_cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d",&a[i]);
            down_cnt += (a[i] == 1);
        }
        vector<int> ans;
        if (down_cnt == 0) {
            for (int i = 1; i <= n + 1; i++) ans.push_back(i);
        } else {
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) {
                    if (i == 1) {
                        ans.push_back(n + 1);
                        for (int j = 1; j <= n; j++) ans.push_back(j);
                    } else {
                        for (int j = 1; j < i; j++) ans.push_back(j);
                        ans.push_back(n + 1);
                        for (int j = i; j <= n; j++) ans.push_back(j);
                    }
                    break;
                }
            }
        }
        for (int i = 0; i <= n; i++) printf("%d%c",ans[i]," \n"[i==n]);
    }
}