#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

vector<int>a[1010], b[1010];

int N, M;

int main() {
    scanf("%d%d",&N,&M);
    for (int i=0;i<N;i++) {
        a[i].resize(M);
        for (int j=0;j<M;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    bool all_same = true;
    for (int i=0;i<N;i++) {
        b[i].resize(M);
        for (int j=0;j<M;j++) {
            scanf("%d",&b[i][j]);
            if (a[i][j] != b[i][j]) all_same = false;
        }
    }
    if (all_same) {
        puts("0");
        return 0;
    }
}