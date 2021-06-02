#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, L[1010], R[1010], M;
int cnt[1010];
map<int,int> vis;

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&L[i], &R[i]);
    }
    scanf("%d",&M);
    for (int i=1;i<=M;i++) {
        int tmp;
        scanf("%d",&tmp);
        vis[tmp] = 1;
        for (int j=1;j<=N;j++) {
            if (tmp >= L[j] && tmp <= R[j]) {
                cnt[j]++;
                if (cnt[j] > 2) {
                    puts("impossible");
                    return 0;
                }
            }
        }
    }
    vector<int>ans;
    L[N + 1] = -1;
    for (int i=1;i<=N;i++) {
        while(true) {
            if (cnt[i] == 2) break;
            if (!vis[R[i]] && R[i] == L[i + 1] && cnt[i + 1] < 2) {
                vis[R[i]] = 1;
                ans.push_back(R[i]);
                cnt[i]++;
                cnt[i + 1]++;
                continue;
            }
            bool find = false;
            for (int j=L[i]+1;j<R[i];j++) {
                if (!vis[j]) {
                    find = true;
                    ans.push_back(j);
                    vis[j] = 1;
                    cnt[i]++;
                    break;
                }
            }
            if (!find) {
                puts("impossible");
                return 0;
            }
        }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++) {
        printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
    }

}