#include <bits/stdc++.h>

using namespace std;

int ask(int q) {
    printf("? %d\n",q + 1);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

void answer(int q) {
    printf("! %d\n",q + 1);
    fflush(stdout);
}

int N, K;
int fuck[2010][1010];

void solve(int pos,int val) {
    int B = max(1, int(sqrt(sqrt(N) - 1) - 1));
    if (val < K) {
        int R = pos;
        while(true) {
            pos = (pos + B) % N;
            if (ask(pos) < K) {
                R = pos;
            } else {
                break;
            }
        }
        for (int i=0;i<=B;i++) {
            int pp = (R + i) % N;
            if (ask(pp) == K) {
                answer(pp);
                return;
            }
        }
    } 
}

int main() {
    scanf("%d%d",&N,&K);
    vector<int>a(N,K),b(N,0);
    /*
    if (N <= 2000) {
        for (int i=0;i<N;i++) fuck[i][0] = K;
        for (int _=1;_<=1000;_++) {
            for (int i=0;i<N;i++) b[i] = 0;
            b[1] += a[0];
            for (int i=1;i<N;i++) {
                int suc = (i + 1) % N;
                int pre = (i - 1 + N) % N;
                int p = a[i];
                b[suc] += (p + 1) / 2;
                b[pre] += p / 2;
            }
            swap(a, b);
            for (int i=0;i<N;i++) {
                fuck[i][_] = a[i];
            }
        }
        vector<int>q0;
        for (int i=0;i<1000;i++) {
            q0.push_back(ask(0));
        }
        for (int i=0;i<N;i++) {
            bool same = true;
            for (int j=0;j<1000;j++) {
                if (q0[j] != fuck[i][j]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                if (i == 0) answer(0);
                else answer(N - i);
                return 0;
            }
        }
    }
    */
    int B = int(sqrt(N)) - 1;
    for (int i=0;i<B;i++) ask(0);
    for (int i=0;i<N;i+=B) {
        int tmp = ask(i);
        if (tmp < K) {
            solve(i, tmp);
            return 0;
        }
    }
}