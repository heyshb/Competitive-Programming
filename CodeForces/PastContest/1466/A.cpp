#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        vector<int>a;
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            int tmp;
            scanf("%d",&tmp);
            a.push_back(tmp);
        }
        sort(a.begin(),a.end());
        set<int>s;
        for (int i=0;i<N;i++) {
            for (int j=i+1;j<N;j++) {
                s.insert(a[j] - a[i]);
            }
        }
        printf("%d\n",s.size());
    }
}