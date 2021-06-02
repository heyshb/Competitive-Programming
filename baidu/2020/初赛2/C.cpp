#include <bits/stdc++.h>

using namespace std;

int T;
int N;
vector<int> per[110][20];
bool vir[22000];

int main() {
    scanf("%d",&T);
    while(T--) {
        for (int i=1;i<=100;i++) {
            for (int j=1;j<=10;j++) {
                per[i][j].clear();
            }
        }
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            int len;
            scanf("%d",&len);
            while(len--) {
                int t, p;
                scanf("%d%d",&t,&p);
                per[t][p].push_back(i);
            }
            vir[i] = false;
        }
        vir[1] = true;
        for (int t=1;t<=100;t++) {
            for (int p=1;p<=10;p++) {
                bool have = false;
                for (auto pp:per[t][p]) {
                    have |= vir[pp];
                }
                if (have) {
                    for (auto pp:per[t][p]) {
                        vir[pp] = true;
                    }
                }
            }
        }
        vector<int>ans;
        for (int i=1;i<=N;i++) {
            if (vir[i]) {
                ans.push_back(i);
            }
        }
        for (int i=0;i<ans.size();i++) {
            printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
        }
    }
}