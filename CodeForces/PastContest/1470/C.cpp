#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int N, K;
    scanf("%d%d",&N,&K);
    if (K % 2 != 0) {puts("K even");return 0;}
    vector<int>a(N,K),b(N,0);
    for (int _=0;_<=2*N;_++) {
        for (int i=0;i<N;i++) printf("%d ",a[i]);puts("");
        for (int i=0;i<N;i++) b[i] = 0;
        for (int i=0;i<N;i++) {
            int pre = (i-1+N)%N;
            int suc = (i+1)%N;
            int p = a[i];
            if (i != 0) {
                b[suc] += (p+1)/2;
                b[pre] += p/2;
            } else {
                b[suc] += p;
            }
        }
        swap(a, b);
    }
}