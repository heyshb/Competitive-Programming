#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
set<int>R[100010],C[100010];
vector<int>v[100010];
vector<bool>del[100010];

vector<pii> get_neighbors(int x,int y) {
    vector<pii> ret;
    auto it = R[x].find(y);
    if (it != R[x].begin()) {
        auto tmp = it;
        --tmp;
        ret.push_back(pii(x, *tmp));
    }
    ++it;
    if (it != R[x].end()) {
        ret.push_back(pii(x, *it));
    }

    it = C[y].find(x);
    if (it != C[y].begin()) {
        auto tmp = it;
        --tmp;
        ret.push_back(pii(*tmp, y));
    }
    ++it;
    if (it != C[y].end()) {
        ret.push_back(pii(*it,y));
    }
    return ret;
}

bool check(int x,int y) {
    vector<pii>nei = get_neighbors(x, y);
    if (nei.empty()) {
        return false;
    }
    int sum = 0;
    for (auto t:nei) {
        sum += v[t.first][t.second];
    }
    return v[x][y] * nei.size() < sum;
}

void rmv(int x,int y) {
    R[x].erase(y);
    C[y].erase(x);
}

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        scanf("%d%d",&N,&M);
        vector<pii> eri;
        LL ans = 0, sum = 0;
        for (int i=1;i<=N;i++) {
            R[i].clear();
        }
        for (int i=1;i<=M;i++) {
            C[i].clear();
        }
        for (int i=1;i<=N;i++) {
            v[i].resize(M + 1);
            del[i].assign(M + 1, false);
            for (int j=1;j<=M;j++) {
                scanf("%d",&v[i][j]);
                sum += v[i][j];
                R[i].insert(j);
                C[j].insert(i);
            }
        }
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                if (check(i, j)) {
                    eri.push_back(pii(i, j));
                    del[i][j] = true;
                }
            }
        }
        /*
        if (eri.empty()) {
            printf("Case #%d: %lld\n",T, sum);
            continue;
        }
        */
        ans = sum;
        while(!eri.empty()) {
            vector<pii> neri;
            vector<pii> candidate_neri;
            for (auto t:eri) {
                auto nei = get_neighbors(t.first, t.second);
                for (auto tt:nei) {
                    candidate_neri.push_back(tt);
                }
            }
            for (auto t:eri) {
                rmv(t.first, t.second);
                sum -= v[t.first][t.second];
            }
            ans += sum;
            for (auto tt:candidate_neri) {
                if (del[tt.first][tt.second]) continue;
                if (!check(tt.first,tt.second)) continue;
                del[tt.first][tt.second] = true;
                neri.push_back(tt);
            }
            eri = neri;
        }
        printf("Case #%d: %lld\n",T,ans);
    }
}

/*
1
1 3
3 1 2
*/