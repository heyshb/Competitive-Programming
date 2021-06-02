#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N, h[200010], t[200010];
vector<int>e[200010];
LL fin[200010], fout[200010];
const LL INF = 1e13;
LL ans = INF;

void dfs(int x, int fa) {
    for (auto t:e[x]) {
        if (t == fa) continue;
        dfs(t, x);
    }
    vector<LL>out, in, bi;
    for (auto t:e[x]) {
        if (t == fa) continue;
        if (h[t] > h[x]) out.push_back(t);
        if (h[t] < h[x]) in.push_back(t);
        if (h[t] == h[x]) bi.push_back(t);
    }
    LL sum = 0;
    for (auto t:out) sum += fin[t];
    for (auto t:in) sum += fout[t];
    for (auto t:bi) sum += fin[t];
    int size_out = out.size() + bi.size(), size_in = in.size(), size_bi = bi.size();
    fin[x] = sum + 1LL * max(size_in + 1, size_out) * t[x];
    fout[x] = sum + 1LL * max(size_in, size_out + 1) * t[x];
    if (x == 1) ans = sum + 1LL * max(size_in, size_out) * t[x];
    vector<LL> sb(size_bi);
    for (int i=0;i<size_bi;i++) {
        sb[i] = -fin[bi[i]] + fout[bi[i]];
    }
    sort(sb.begin(), sb.end());
    for (int i=1;i<size_bi;i++) sb[i] += sb[i - 1];
    for (int i=0;i<size_bi;i++) {
        int tmp_size_in = size_in + (i + 1);
        int tmp_size_out = size_out - (i + 1);
        LL tmp_sum = sum + sb[i];
        fin[x] = min(fin[x], tmp_sum + 1LL * max(tmp_size_in + 1, tmp_size_out) * t[x]);
        fout[x] = min(fout[x], tmp_sum + 1LL * max(tmp_size_in, tmp_size_out + 1) * t[x]);
        if (x == 1) ans = min(ans, tmp_sum + 1LL * max(tmp_size_in, tmp_size_out) * t[x]);
    }
    //printf("fin %d = %lld\n",x, fin[x]);
    //printf("fout %d = %lld\n",x, fout[x]);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&t[i]);
    }
    for (int i=1;i<=N;i++) {
        scanf("%d",&h[i]);
    }
    for (int i=1;i<N;i++) {
        int u, v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    printf("%lld\n",ans);
}