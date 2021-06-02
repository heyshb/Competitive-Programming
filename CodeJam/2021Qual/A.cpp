#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d",&T);
    int Case = 0;
    while(T--) {
        int N;
        scanf("%d",&N);
        vector<int>a(N);
        for (int i=0;i<N;i++) scanf("%d",&a[i]);
        int ans = 0;
        for (int i=0;i<N-1;i++) {
            int id = i;
            for (int j=i+1;j<N;j++) {
                if (a[j] < a[id]) id = j;
            }
            reverse(a.begin() + i, a.begin() + id + 1);
            ans += id - i + 1;
        }
        printf("Case #%d: %d\n",++Case,ans);
    }
}