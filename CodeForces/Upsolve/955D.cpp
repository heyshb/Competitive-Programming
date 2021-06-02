#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAXN = 1000010;

const int HASH_SIZE = 2;
const int HASH_TOTAL = 3;
const LL seeds[HASH_TOTAL] = {233, 237, 239};
const LL MODS[HASH_TOTAL] = {1000000007, 1000000009, 998244353};
typedef array<LL,HASH_SIZE> arr;
struct Hash {
    LL seed, MOD;
    LL v[MAXN],po[MAXN];
    Hash(){}
    void init(char *s, int N,LL _seed = seeds[0],LL _MOD = MODS[0]) {
        MOD = _MOD;
        seed = _seed;
        v[0] = 0;
        po[0] = 1;
        for (int i=1;i<=N;i++) {
            v[i] = (v[i - 1] * seed + s[i]) % MOD;
            po[i] = po[i - 1] * seed % MOD;
        }
    }
    LL get_interval_hash(int L,int R) {
        LL ret = v[R] - v[L - 1] * po[R - L + 1] % MOD;
        if (ret < 0) {
            ret += MOD;
        }
        if (ret >= MOD) {
            ret -= MOD;
        }
        return ret;
    }
    LL get_string_hash(char *s,int N) {
        LL ret = 0;
        for (int i=0;i<N;i++) {
            ret = (ret * seed + s[i]) % MOD;
        }
        return ret;
    }
};

int N,M,K;
char s[500010],t[500010]; 
int lcp[500010],rlcp[500010]; 

void solve(char *s, char *t, int N, int M, int *ret) {
    Hash H1, H2;
    H1.init(s, N);
    H2.init(t, M);
    for (int i=1;i<=N;i++) {
        int ml = min(M, N - i + 1);
        if (H1.get_interval_hash(i, i + ml - 1) == H2.get_interval_hash(1, ml)) {
            ret[i] = ml;
            continue;
        }
        int L = 0, R = ml;
        while(L < R - 1) {
            int mid = (L + R) / 2;
            if (H1.get_interval_hash(i, i + mid - 1) == H2.get_interval_hash(1, mid)) {
                L = mid;
            } else {
                R = mid;
            }
        }
    }
}

int main() {
    scanf("%d%d%d",&N,&M,&K);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    solve(s, t, N, M, lcp);
    reverse(s + 1, s + N + 1);
    reverse(t + 1, t + M + 1);
    solve(s, t, N, M, rlcp);
    reverse(rlcp + 1, rlcp + N + 1);
}