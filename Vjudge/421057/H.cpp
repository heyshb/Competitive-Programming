#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<int> hor[10];
vector<int> ver[10];
vector<int> mask[10];

vector<int>fuck(vector<int> seg) {
    vector<int> ret;
    for (int i=0;i<(1<<C);i++) {
        vector<int>d(C);
        for (int j=0;j<C;j++) {
            d[j] = ((i >> j) & 1);
        }
        vector<int>qaq;
        int nowseg = 0;
        for (int j=0;j<C;j++) {
            if (d[j] == 0) {
                nowseg = 0;
            } else {
                nowseg++;
                if (j == C - 1 || d[j + 1] == 0) {
                    qaq.push_back(nowseg);
                }
            }
        }
        if (qaq == seg) ret.push_back(i);
    }
    return ret;
}

int ans = 0;
int mp[10][10];
void dfs(int dep) {
    if (dep == R + 1) {
        /*
        puts("check");
        for (int i=1;i<=R;i++) {
            for (int j=1;j<=C;j++) {
                printf("%d",mp[i][j]);
            }puts("");
        }
        */
        for (int i=1;i<=C;i++) {
            vector<int>qaq;
            int nowseg = 0;
            for (int j=1;j<=R;j++) {
                if (mp[j][i] == 0) {
                    nowseg = 0;
                } else {
                    nowseg++;
                    if (j == R || mp[j+1][i] == 0) qaq.push_back(nowseg);
                }
                
            }
            //printf("col %d\n",i);
            //for (auto &t:qaq) printf("%d ",t);puts("");
            if (qaq != ver[i]) return;
        }
        ans++;
        return;
    }
    for (auto &t:mask[dep]) {
        for (int i=0;i<C;i++) {
            //printf("%d %d %d %d\n",dep,t,i+1,(t>>i)&1);
            mp[dep][i + 1] = (t >> i) & 1;
        }
        dfs(dep + 1);
    }
}

int main() {
    scanf("%d%d",&R,&C);
    for (int i=1;i<=R;i++) {
        int sz;
        scanf("%d",&sz);
        for (int j=1;j<=sz;j++) {
            int tmp;
            scanf("%d",&tmp);
            hor[i].push_back(tmp);
        }
        mask[i] = fuck(hor[i]);
    }
    for (int i=1;i<=C;i++) {
        int sz;
        scanf("%d",&sz);
        for (int j=1;j<=sz;j++) {
            int tmp;
            scanf("%d",&tmp);
            ver[i].push_back(tmp);
        }
    }
    dfs(1);
    printf("%d\n",ans);
}