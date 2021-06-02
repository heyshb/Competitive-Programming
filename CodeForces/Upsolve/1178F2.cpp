#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 2 * 510;
const int MAXM = 1000010;
int N, M, SN;
int col[MAXM];
vector<pii>seg;
int seg_col[MAXN];
int bg[MAXN], ed[MAXN];
const int MOD = 998244353;
LL f[MAXN][MAXN];

int get_pos(int x,int l,int r) {
    if (x < l) return 1;
    if (x > l && x < r) return 2;
    if (x > r) return 3;
    assert(false);
    return -1;
}

LL solve(int l,int r,int dep) {
    if (f[l][r] != -1) {
        return f[l][r];
    }
    if (l >= r) {
        return f[l][r] = 1;
    }
    int mi = 1e9;
    for (int i=l;i<=r;i++) {
        mi = min(mi, seg_col[i]);
    }
    for (int i=1;i<=N;i++) {
        bg[i] = -1;
        ed[i] = -1;
    }    
    vector<int> mi_pos;
    for (int i=l;i<=r;i++) {
        if (seg_col[i] == mi) {
            mi_pos.push_back(i);
        }
    }
    for (int i=l;i<=r;i++) {
        if (bg[seg_col[i]] == -1) {
            bg[seg_col[i]] = i;
        }
        ed[seg_col[i]] = i;
    }
    vector<int>forbidS(SN + 2);
    for (int i=1;i<=N;i++) {
        if (bg[i] == -1 || i == mi) {
            continue;
        }
        if (get_pos(bg[i], bg[mi], ed[mi]) == 1) {
            forbidS[bg[i] + 1]++;
            forbidS[ed[i] + 1]--;
        }
        if (get_pos(bg[i], bg[mi], ed[mi]) == 3) {
            forbidS[bg[i]]++;
            forbidS[ed[i]]--;
        }
    }
    for (int i=1;i<=SN;i++) {
        forbidS[i] += forbidS[i - 1];
    }
    int bgmi = bg[mi], edmi = ed[mi];
    LL ret = 1;
    for (int i=1;i<mi_pos.size();i++) {
        ret = ret * solve(mi_pos[i - 1] + 1, mi_pos[i] - 1, dep + 1) % MOD;
    }
    LL v1 = 0, v2 = 0;
    
    for (int i=l;i<=bgmi;i++) {
        if (forbidS[i]) continue;
        v1 = (v1 + solve(i, bgmi - 1, dep + 1) * solve(l, i - 1, dep + 1) % MOD) % MOD;
    }
    for (int i=edmi;i<=r;i++) {
        if (forbidS[i]) continue;
        v2 = (v2 + solve(edmi + 1, i, dep + 1) * solve(i + 1, r, dep + 1) % MOD) % MOD;
    }
    ret = ret * v1 % MOD * v2 % MOD;
    return f[l][r] = ret;
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        scanf("%d",&col[i]);
    }
    int nowlen = 0; 
    for (int i=1;i<=M;i++) {
        nowlen++;
        if (i == M || col[i] != col[i + 1]) {
            seg.push_back(pii(col[i], nowlen));
            nowlen = 0;
        }
    }
    SN = seg.size();
    if (SN > 2 * N - 1) {
        puts("0");
        return 0;
    } 
    for (int i=1;i<=SN;i++) {
        seg_col[i] = seg[i - 1].first;
    }
    for (int i=0;i<=SN+1;i++) {
        for (int j=0;j<=SN+1;j++) {
            f[i][j] = -1;
        }
    }
    printf("%lld\n",solve(1, SN, 0));
}