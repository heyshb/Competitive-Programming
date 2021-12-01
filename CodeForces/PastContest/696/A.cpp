#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pll;
int Q, m = 0;
LL q[1010][3];
vector<int>sq[1010][3];

vector<int> seq(LL x) {
    vector<int> ret;
    while(x) {
        ret.push_back(x % 2);
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> lca(vector<int> &v1, vector<int> &v2) {
    int n1 = v1.size(), n2 = v2.size();
    vector<int> ret;
    for (int i = 0; i < n1 && i < n2; i++) {
        if (v1[i] != v2[i]) break;
        ret.push_back(v1[i]);
    }
    return ret;
}

/*
void println(vector<int> x) {
    for (int i = 0; i < x.size(); i++) printf("%d",x[i]);puts("");
}
*/
LL calc(vector<int> s) {
    auto len = [](vector<int> &s1, vector<int> &s2) {
        return lca(s1, s2).size() - 1;
    };
    LL ret = 0;
    for (int i = 1; i <= m; i++) {
        //vector<int> su = seq(q[i][0]), sv = seq(q[i][1]), sl = lca(su, sv);
        //println(su);
        LL tmp_len = len(s, sq[i][0]);
        //println(sv);
        tmp_len += len(s, sq[i][1]);
        //println(sl);
        tmp_len -= 2LL * len(s, sq[i][2]);
        ret += tmp_len * q[i][2];
    }
    return ret;
}


int main() {
    scanf("%d",&Q);
    for (int i = 1; i <= Q; i++) {
        int tp;
        scanf("%d",&tp);
        if (tp == 1) {
            m++;
            scanf("%lld%lld%lld",&q[m][0],&q[m][1],&q[m][2]);
            sq[m][0] = seq(q[m][0]);
            sq[m][1] = seq(q[m][1]);
            sq[m][2] = lca(sq[m][0], sq[m][1]);
        } else {
            LL ans = 0;
            LL u, v;
            scanf("%lld%lld",&u,&v);
            auto su = seq(u), sv = seq(v);
            printf("%lld\n",calc(su) + calc(sv) - 2LL * calc(lca(su, sv)));
        }
    }
}