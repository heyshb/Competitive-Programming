#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 310;
const int MAXM = 310;
vector<int>e1[MAXM],e2[MAXM];
int L1[MAXM],R1[MAXM],L2[MAXM],R2[MAXM];
int N, M;
int fa[MAXN];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void dsu_init() {
    for (int i=1;i<=N;i++) {
        fa[i] = i;
    }
}

void edge_clear() {
    for (int i=1;i<=N;i++) {
        e1[i].clear();
        e2[i].clear();
    }
}

class Matroid_Intersect {
public:
    int n; // number of elements in the matroid system
    bool inI[MAXM];
    bool test_inI[MAXM];
    bool in_X1[MAXM], in_X2[MAXM];

    bool test1() { // check whether test_inI \in I_1
        for (int i=1;i<=n;i++) {

        }
    }

    bool test2() { // check whether test_inI \in I_2

    }

    bool check1(int u) { // check whether I + u \in I_1
        if (inI[u]) {
            return false;
        }
        // default check
        for (int i=1;i<=n;i++) {
            test_inI[i] = inI[i];
        }
        test_inI[u] = true;
        return check_test_1();
        // optimize start
        // optimize end
    }

    bool check2(int u) { // check whether I + u \in I_2
        if (inI[u]) {
            return false;
        }
        // optimize start
        // optimize end
    }

    bool pair_check1(int u, int v) { // check whether I - u + v \in I_1
        if (!(inI[u] && !inI[v])) {
            return false;
        }
        // optimize start
        // optimize end
    }

    bool pair_check2(int u, int v) { // check whether I - u + v \in I_2
        if (!(inI[u] && !inI[v])) {
            return false;
        }
        // optimize start
        // optimize end
    }

    void prework() { // do some prework like dfs

    }

    void init() {
        n = M;
        for (int i=1;i<=n;i++) {
            inI[i] = false;
        }
    }

    queue<int>q;
    int d[MAXM];
    vector<int>e[MAXM];

    int solve() {
        init();
        while(true) {
            vector<int>X1, X2;
            for (int i=1;i<=n;i++) {
                if (inI[i]) {
                    continue;
                }
                if (check1(i)) {
                    X1.push_back(i);
                }
                if (check2(i)) {
                    X2.push_back(i);
                }
            }
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    if (pair_check1(i, j)) {

                    }
                    if (pair_check2(i, j)) {

                    }
                }
            }
        }
    }
}MI;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N, &M);
        for (int i=1;i<=N;i++) {
            e1[i].clear();
            e2[i].clear();
        }
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            e1[u].push_back(v);
            e1[v].push_back(u);
            L1[i] = u;
            R1[i] = v;
        }
        for (int i=1;i<=M;i++) {
            int u, v;
            scanf("%d%d",&u,&v);
            e2[u].push_back(v);
            e2[v].push_back(u);
            L2[i] = u;
            R2[i] = v;
        }
    }
}