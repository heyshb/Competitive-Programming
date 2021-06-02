#include <bits/stdc++.h>

using namespace std;

int N, M;
int fa[1 << 15];
char s[1 << 14];
int v[2][1 << 14];
int id[1 << 15], vis[1 << 15];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int merge(int id1,int id2) {
    id1 = find(id1);
    id2 = find(id2);
    if (id1 == id2) return 0;
    fa[id2] = id1;
    return 1;
}

int main() {
    scanf("%d%d",&N,&M);
    int now = 1, last = 0;
    int ans = 0;
    for (int i=0;i<2*M;i++) {
        fa[i] = i;
    }
    for (int i=1;i<=N;i++) {
        scanf("%s", s);
        for (int j=0;j<M/4;j++) {
            int tmp = -1;
            if (s[j] >= 'A' && s[j] <= 'F') {   
                tmp = s[j] - 'A' + 10;
            } else {
                tmp = s[j] - '0';
            }
            for (int k=0;k<4;k++) {
                v[now][j * 4 + k] = ((tmp >> (3 - k)) & 1);
            }
        }
        
        /*
        for (int j=0;j<M;j++) {
            printf("%d",v[last][j]);
        } 
        puts("");
        for (int j=0;j<M;j++) {
            printf("%d",v[now][j]);
        } 
        puts("");
        */
    
        for (int j=0;j<M;j++) {
            if (!v[now][j]) continue;
            ans++;
            if (v[last][j]) {
                //printf("merge up %d %d %d %d\n",j,j+M,find(j),find(j+M));
                ans -= merge(j, j + M);
            }
            if (j > 0 && v[now][j - 1]) {
                ans -= merge(j, j - 1);
            }
        }
        //printf("%d\n",ans);
        for (int j=0;j<2*M;j++) {
            vis[j] = -1;
        }

        for (int j=0;j<M;j++) {
            int ID = find(j);
            if (vis[ID] == -1) {
                vis[ID] = j;
            }
            id[j] = vis[ID];
        }
        for (int j=0;j<M;j++) {
            fa[j + M] = id[j] + M;
            fa[j] = j;
        }
        /*
        for (int j=0;j<2*M;j++) {
            printf("fa[%d]=%d\n",j,fa[j]);
        }
        */

        swap(now, last);
    }
    printf("%d\n",ans);
}