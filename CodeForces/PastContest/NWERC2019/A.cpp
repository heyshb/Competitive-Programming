#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, M;
vector<int>a[300010];
vector<int>b[300010];
double ans[300010];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=1;i<=M;i++) {
        int K;
        scanf("%d",&K);
        for (int j=1;j<=K;j++) {
            int tmp;
            scanf("%d",&tmp);
            a[tmp].push_back(i);
            b[i].push_back(tmp);
        }
    }
}