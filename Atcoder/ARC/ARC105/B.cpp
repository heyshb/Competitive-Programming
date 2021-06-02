#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    set<int>a,b;
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        int tmp;
        scanf("%d",&tmp);
        a.insert(tmp);
    }
    while(a.size() > 1) {
        //for (auto t:a) printf("%d ",t);puts("");
        b.clear();
        int mi = *a.begin();
        b.insert(mi);
        for (auto &t:a) {
            if (t > mi) {
                b.insert(t % mi + mi);
            }
        }
        a = b;
        if (a.size() == 1) break;
        int ma = *a.rbegin();
        assert(ma < 2 * mi);
        a.erase(ma);
        a.insert(ma - mi);
    }
    printf("%d\n",*a.begin());
}