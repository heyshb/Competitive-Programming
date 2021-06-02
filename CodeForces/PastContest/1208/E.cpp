#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
vector<int>v[1000010];
int N,w;
int l[1000010];
int ans[1000010];
struct op {
    int tp;//0 erase 1 insert
    int num,v;
};
vector<op>o[1000010];
multiset<int>s[1000010];

int main() {
    scanf("%d%d",&N,&w);
    for (int i=1;i<=N;i++) {
        s[i].insert(-1e9-10);
        scanf("%d",&l[i]);
        v[i].resize(l[i]);
        for (int j=0;j<l[i];j++) {
            scanf("%d",&v[i][j]);
        }
        for (int j=0;j<l[i];j++) {
            o[j].push_back((op){1,i,v[i][j]});
            //printf("add %d %d %d %d\n",j,1,i,v[i][j]);
            o[w-l[i]+j+1].push_back((op){0,i,v[i][j]});
            //printf("add %d %d %d %d\n",w-l[i]+j+1,0,i,v[i][j]);
        }
    }
    LL mx = 0;
    for (int i=0;i<w;i++) {
        //printf("fuck %d\n",i);
        //printf("size =%d\n",o[i].size());
        for (auto O:o[i]) {
            if (O.tp == 0) {
                //printf("erase %d %d\n",O.num,O.v);
                //printf("before erase: %d\n",s[O.num].size());
                s[O.num].erase(s[O.num].find(O.v));
                //printf("after erase: %d\n",s[O.num].size());
            } else {
                //printf("insert %d %d\n",O.num,O.v);
                //printf("before insert: %d\n",s[O.num].size());
                s[O.num].insert(O.v);
                //printf("after insert: %d\n",s[O.num].size());
            }
            mx -= ans[O.num];
            LL newv = *s[O.num].rbegin();
            if (i > l[O.num] || i < w - l[O.num]) {
                newv = max(newv, 0LL);
            }
            ans[O.num] = newv;
            mx += ans[O.num];
        }
        printf("%lld%c",mx," \n"[i==w-1]);
    }
}