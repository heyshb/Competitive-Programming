#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,a[1000010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
    }
    int fst = -1, lst = -1;
    for (int i=1;i<N;i++) {
        if (a[i] > a[i + 1]) {
            if (fst == -1) fst = i;
            lst = i;
        }
    }
    if (fst == -1) {
        puts("1 1");
        return 0;
    }
    while(fst > 1 && a[fst - 1] == a[fst]) fst--;
    lst++;
    while(lst < N && a[lst + 1] == a[lst]) lst++;
    reverse(a+fst, a+lst+1);
    for (int i=1;i<N;i++) {
        if (a[i] > a[i + 1]) {
            puts("impossible");
            return 0;
        }
    }
    printf("%d %d\n",fst, lst);
}