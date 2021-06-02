#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef pair<int,int> pii;
 
int v[10],vv[10];
int target;
 
bool check(int x) {
    for (int i=1;i<=4;i++) {
        vv[i] = v[i];
    }
    vv[5] = x;
    sort(vv+1,vv+6);
    int sum = 0;
    for (int i=2;i<=4;i++) {
        sum += vv[i];
    }
    return sum <= target * 3;
}
 
int main() {
    double tmp;
    for (int i=1;i<=4;i++) {
        scanf("%lf",&tmp);
        v[i] = int(tmp * 100 + 0.5);
    }
    scanf("%lf",&tmp);
    target = int(tmp * 100 + 0.5);
    if (!check(0)) {
        puts("impossible");
        return 0;
    }
    if (check(10000)) {
        puts("infinite");
        return 0;
    }
    for (int i=10000;i>=0;i--) {
        if (check(i)) {
            printf("%d.%02d\n",i/100,i%100);
            break;
        }
    }
}