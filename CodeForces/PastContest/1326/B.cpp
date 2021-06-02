#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int x[200010],a[200010],b[200010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&b[i]);
    }
    for (int i=1;i<=N;i++) {
        a[i] = b[i] + x[i];
        x[i + 1] = max(x[i], a[i]);
    }
    for (int i=1;i<=N;i++) {
        printf("%d%c",a[i]," \n"[i==N]);
    }
}