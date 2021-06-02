#include <bits/stdc++.h>

using namespace std;

int N,a[2010],M;
map<int,int>num;
vector<int>pos[2010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        if (num.find(a[i]) == num.end()) {
            num[a[i]] = ++M;
        }
        a[i] = num[a[i]];
        pos[a[i]].push_back(i);
    }    
    int ans = 1e9;
    for (int i=1;i<=N;i++) {
        int need = i - 1;
        for (int j=1;j<=M;j++) {
            if (pos[j].size() == 1) continue;
            if (pos[j][1] < i) {
                need = 1e9;
                break;
            }
            if (pos[j][0] >= i) need = max(need, pos[j][pos[j].size() - 2]);
            else need = max(need, pos[j][pos[j].size() - 1]);
        }
        //printf("%d %d\n",i,need);
        ans = min(ans, need - i + 1);
    }
    printf("%d\n",ans);
}