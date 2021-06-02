#include <bits/stdc++.h>

using namespace std;

int same[26][26];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        set<string> st[26];
        string s;
        for (int i=1;i<=N;i++) {
            cin >> s;
            st[s[0] - 'a'].insert(s.substr(1));
        }
        int ans = 0;
        for (int i=0;i<26;i++) {
            for (int j=i+1;j<26;j++) {
                int same_cnt = 0;
                for (auto &t : st[i]) {
                    if (st[j].find(t) != st[j].end()) {
                        same_cnt++;
                    }
                }
                ans += (st[i].size() - same_cnt) * (st[j].size() - same_cnt) * 2;
            }
        }
        printf("%d\n",ans);
    }
}