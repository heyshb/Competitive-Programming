#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
LL a[100010];
int M;
LL ans[300010][3];
priority_queue<pii>hp;

void push(int x,int y,int z) {
    M++;
    ans[M][0] = x;
    ans[M][1] = y;
    ans[M][2] = z;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        LL sum = 0;
        for (int i=1;i<=N;i++) {
            scanf("%lld",&a[i]);
            sum += a[i];
        }
        if (sum % N != 0) {
            puts("-1");
            continue;
        }
        printf("%d\n",3*N-3);
        for (int i=2;i<=N;i++) {
            LL tmp = 0;
            if (a[i]%i) tmp = i - a[i] % i;
            printf("%d %d %d\n",1,i,tmp);
            a[1] -= tmp;
            a[i] += tmp;
            tmp = a[i] / i;
            printf("%d %d %d\n",i,1,tmp);
            a[1] += tmp*i;
            a[i] -= tmp*i;
        }
        for (int i=2;i<=N;i++) {
            LL target = sum / N;
            printf("%d %d %d\n",1,i,target);
        }
    }
}