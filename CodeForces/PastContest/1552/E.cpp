#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k;
int col[10010];
vector<int>pos[110];
bool done[110];

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n * k; i++) {
        scanf("%d",&col[i]);
        pos[col[i]].push_back(i);
    }
    vector<pii> ans(n + 1);
    for (int i = 1; i <= n; i++) done[i] = false;
    int t = (n + k - 1 - 1) / (k - 1);
    for (int i = 0; i < k - 1; i++) {
        vector<pii> tmp;
        for (int j = 1; j <= n; j++) if (!done[j]) tmp.push_back(pii(pos[j][i + 1], j));
        sort(tmp.begin(), tmp.end());
        for (int j = 0; j < min(int(tmp.size()), t); j++) {
            int id = tmp[j].second;
            done[id] = true;
            ans[id] = pii(pos[id][i], pos[id][i + 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
}