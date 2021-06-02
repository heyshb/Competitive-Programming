#include <bits/stdc++.h>

using namespace std;
int N, C;
int calc(vector<int> a) {
    int ans = 0;
    for (int i=0;i<N-1;i++) {
        int id = i;
        for (int j=i+1;j<N;j++) {
            if (a[j] < a[id]) id = j;
        }
        reverse(a.begin() + i, a.begin() + id + 1);
        ans += id - i + 1;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        scanf("%d%d",&N,&C);
        vector<int>a(N);
        for (int i=0;i<N;i++) {
            a[i] = i + 1;
        }
        bool find = false;
        do {
            if (calc(a) == C) {
                printf("Case #%d:",++Case);
                for (auto &t: a) printf(" %d",t);
                puts("");
                find = true;
                break;
            }
        } while(next_permutation(a.begin(), a.end()));
        if (!find) {
            printf("Case #%d: IMPOSSIBLE\n",++Case);
        }
    }
}