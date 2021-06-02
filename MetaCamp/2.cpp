#include <bits/stdc++.h>

using namespace std;

int n, w;
int e[200010];

int main() {
    while(scanf("%d%d",&n,&w) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d",&e[i]);
        }
        multiset<int> fuck;
        for (int i = 1; i <= w; i++) {
            fuck.insert(e[i]);
        }
        auto get_max = [&]() {
            return (*fuck.rbegin());
        };
        vector<int> ans;
        for (int i = w; i <= n; i++) {
            int v1 = get_max();
            fuck.erase(fuck.find(v1));
            int v2 = get_max();
            fuck.erase(fuck.find(v2));
            int v3 = get_max();
            ans.push_back(v3);
            fuck.insert(v1);
            fuck.insert(v2);
            if (i < n) {
                fuck.erase(fuck.find(e[i - w + 1]));
                fuck.insert(e[i + 1]);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
        }
    }
}