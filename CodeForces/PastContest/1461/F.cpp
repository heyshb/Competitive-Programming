#include <bits/stdc++.h>

using namespace std;

// +-*
bool ok[3];
int N;
int a[100010];
char ans[100010];
char ch[10];

void print() {
    for (int i=1;i<=N;i++) {
        printf("%d",a[i]);
        if (i < N) printf("%c",ans[i]);
    }
    puts("");
}

typedef pair<int,int> pii;
typedef long long LL;
const LL INF = 1e9;
void solve(int L,int R) {
    if (a[L] == 1) {
        while(a[L] == 1 && L <= R) {
            ans[L] = '+';
            L++;
        }
    }
    if (a[R] == 1) {
        while(a[R] == 1 && L <= R) {
            ans[R - 1] = '+';
            R--;
        }
    }
    int l = L;
    for (int i=L;i<R;i++) {
        ans[i] = '*';
    }
    vector<pii> fuck;
    while(l <= R) {
        int r = l;
        while(r + 1 <= R && ((a[r+1] == 1) == (a[r] == 1))) r++;
        fuck.push_back(pii(l, r));
        //printf("push %d %d\n",l,r);
        l = r + 1;
    }
    int M = fuck.size();
    if (M == 0) return;
    assert(a[fuck[0].first] != 1 && a[fuck[M - 1].first] != 1);
    assert(M % 2 == 1);
    int cnt1 = M / 2;
    vector<LL> mul(M, 1);
    LL all_mul = 1;
    for (int id=0;id<M;id++) {
        auto t = fuck[id];
        if (a[t.first] != 1) {
            for (int i=t.first;i<=t.second;i++) {
                mul[id] *= a[i];
                if (mul[id] > INF) mul[id] = INF;
            }
        } 
        all_mul *= mul[id];
        if (all_mul > INF) all_mul = INF;
    }
    const LL coe = 4;
    if (all_mul <= coe * (R - L + 1)) {
        LL best_ans = 0;
        int best_mask = 0;
        for (int mask=0;mask<(1<<(M / 2));mask++) {
            //printf("mask = %d\n",mask);
            LL tmpans = 0;
            LL tmpmul = mul[0];
            for (int i=1;i<M;i++) {
                if (i & 1) {
                    if (mask & (1 << (i / 2))) {
                        tmpans += tmpmul;
                        tmpans += fuck[i].second - fuck[i].first + 1;
                        tmpmul = 1;
                    } 
                } else {
                    tmpmul *= mul[i];
                }
            }
            tmpans += tmpmul;
            //printf("tmpans = %lld\n",tmpans);
            if (tmpans > best_ans) {
                best_ans = tmpans;
                best_mask = mask;
            }
        }
        for (int i=0;i<M;i++) {
            if ((i & 1) && (best_mask & (1 << (i / 2)))) {
                for (int j=fuck[i].first-1;j<=fuck[i].second;j++) {
                    //printf("gao %d\n",j);
                    ans[j] = '+';
                }
            } 
        }
    }
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%s",ch);
    int M = strlen(ch);
    int cnt = 0;
    for (int i=0;i<M;i++) {
        if (ch[i] == '+') ok[0] = true;
        if (ch[i] == '-') ok[1] = true;
        if (ch[i] == '*') ok[2] = true;
    }
    if (ok[0] && ok[2]) goto FUCK;
    // -
    if (ok[1] && !ok[0] && !ok[2]) {
        for (int i=1;i<N;i++) ans[i] = '-';
        print();
        return 0;
    }
    // have +
    if (ok[0]) {
        for (int i=1;i<N;i++) ans[i] = '+';
        print();
        return 0;
    }
    // -*
    if (ok[2] && ok[1]) {
        for (int i=1;i<N;i++) {
            ans[i] = '*';
        }
        for (int i=1;i<=N;i++) {
            if (a[i] == 0) {
                ans[i - 1] = '-';
                break;
            }
        }
        print();
        return 0;
    }
    if (ok[2] && !ok[1]) {
        for (int i=1;i<N;i++) {
            ans[i] = '*';
        }
        print();
        return 0;
    }
    FUCK:
    a[N + 1] = 0;
    int last_zero = 0;
    for (int i=1;i<=N+1;i++) {
        if (a[i] == 0) {
            ans[i - 1] = ans[i] = '+';
            solve(last_zero + 1, i - 1);
            last_zero = i;
        }
    }
    print();
}