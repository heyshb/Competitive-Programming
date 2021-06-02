#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
int x[1010], y[1010];

int main() {
    int N;
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    while(true) {
        vector<int> ans;
        for (int i=1;i<=N;i++) {
            if (abs(x[i]) % 2 == abs(y[i]) % 2) {
                ans.push_back(i);
            }
        }   
        if (ans.size() != N && ans.size() != 0) {
            printf("%d\n",ans.size());
            for (int i=0;i<ans.size();i++) {
                printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
            }
            return 0;
        }
        for (int i=1;i<=N;i++) {
            int tx, ty;
            if (abs(x[i]) % 2 != abs(y[i]) % 2) {
                x[i]--;
            }
            tx = (x[i] + y[i]) / 2;
            ty = (x[i] - y[i]) / 2;
            x[i] = tx;
            y[i] = ty;
        }
    }
}