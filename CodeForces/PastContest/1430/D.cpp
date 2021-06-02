#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

vector<pii>ans;
int N;
vector<int>pos[4];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        int tmp;
        scanf("%d",&tmp);
        pos[tmp].push_back(i);
    }
    int nowrow = N + 1;
    while(pos[1].size() > 0) {
        nowrow--;
        int p1 = pos[1].back(), p2, p3;
        if (pos[2].size() > 0) p2 = pos[2].back(); else p2 = -1;
        if (pos[3].size() > 0) p3 = pos[3].back(); else p3 = -1;
        printf("fuck %d %d %d\n",p1,p2,p3);
        if (p2 != -1 && p2 > p1) {puts("-1");return 0;}
        if (p3 != -1 && p3 > p1) {puts("-1");return 0;}
        pos[1].pop_back();
        if (p2 != -1) pos[2].pop_back();
        int nowcol = p1;
        ans.push_back(pii(nowrow, p1));
        if (p2 != -1) ans.push_back(pii(nowrow, p2)), nowcol = p2;
        if (p3 != -1 && (p2 == -1 || p3 < p2)) {
            //puts("here");
            for (int i=pos[3].size()-1;i>=0;i--) {
                nowrow--;
                //printf("fuck %d %d %d\n",nowrow,nowcol,pos[3][i]);
                ans.push_back(pii(nowrow, nowcol));
                ans.push_back(pii(nowrow, pos[3][i]));
                nowcol = pos[3][i];
            }
            pos[3].clear();
        }
    }
    if (pos[2].size() > 0 || pos[3].size() > 0) {
        puts("-1");
        return 0;
    }
    printf("%d\n",ans.size());
    for (auto t:ans) {
        printf("%d %d\n",t.first,t.second);
    }
}