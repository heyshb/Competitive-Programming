#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int>ans;

void solve(int N, int M) {
    if (N > M) swap(N, M);
    for (int i=1;i<=N;i++) {
        ans.push_back(N);
    }
    if (N == M || N == 0) {
        return;
    }
    M -= N;
    solve(N, M);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N, &M);
        ans.clear();
        solve(N, M);
        printf("%d\n", ans.size());
        for (int i=0;i<ans.size();i++) {
            printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
        }
    }
}