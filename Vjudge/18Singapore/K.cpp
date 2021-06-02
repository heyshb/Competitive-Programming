#include <bits/stdc++.h>

using namespace std;

int N, M, B;
typedef pair<int,int> pii;
vector<pii>ver[400010], hor[400010];
map<pii, int>id;
int x[400010], y[400010];
int fa[400010], dir[400010];

/*
  1
3   0
  2
*/
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
vector<int> e[4000010];
int ind[400010];
void addedge(int u, int v) {
    ind[v]++;
    e[u].push_back(v);
}

void dfs0(int ID) {
    int X = x[ID], Y = y[ID];
    //printf("fa[%d] = %d\n",ID, fa[ID]);
    for (int d=0;d<4;d++) {
        int nx = X + dx[d], ny = Y + dy[d];
        if (id.find(pii(nx, ny)) == id.end()) continue;
        int nid = id[pii(nx, ny)];
        if (nid == fa[ID]) continue;
        fa[nid] = ID;
        dir[nid] = 3 - d;
        addedge(ID, nid);
        dfs0(nid);
    }
}

/*
  1
3   0
  2
*/
char output_dir[5] = ">^v<";
void print(int ID) {
    if (ID == 1 || ID > B) return;
    int val = (dir[ID] == 1 || dir[ID] == 2 ? y[ID] : x[ID]);
    printf("%c %d\n",output_dir[dir[ID]], val);
}
int MM = N;

int main() {
    scanf("%d%d%d",&N,&M,&B);
    int X, Y;
    for (int i=1;i<=B;i++) {
        scanf("%d%d",&x[i],&y[i]);
        //printf("id[%d,%d] = %d\n",x[i],y[i],i);
        id[pii(x[i], y[i])] = i;
        hor[x[i]].push_back(pii(y[i], i));
        ver[y[i]].push_back(pii(x[i], i));
    }
    for (int i=1;i<=N;i++) sort(hor[i].begin(), hor[i].end());
    for (int i=1;i<=M;i++) sort(ver[i].begin(), ver[i].end());
    dir[1] = -1;
    dfs0(1);
    for (int i=1;i<=N;i++) {
        int SZ = hor[i].size();
        int last_left = -1;
        for (int j=0;j<SZ;j++) {
            int ID = hor[i][j].second;
            if (dir[ID] == 0) {
                assert(j < SZ - 1);
                addedge(hor[i][j+1].second, ID);
                for (int k=last_left+1;k<j;k++) {
                    addedge(ID, hor[i][k].second);
                }
                last_left = j;
            }
        }
        int last_right = SZ;
        for (int j=SZ-1;j>=0;j--) {
            int ID = hor[i][j].second;
            if (dir[ID] == 3) {
                assert(j > 0);
                addedge(hor[i][j-1].second, ID);
                for (int k=last_right-1;k>j;k--) {
                    addedge(ID, hor[i][k].second);
                }
                last_right = j;
            }
        }
    }
    for (int i=1;i<=M;i++) {
        int SZ = ver[i].size();
        int last_left = -1;
        for (int j=0;j<SZ;j++) {
            int ID = ver[i][j].second;
            if (dir[ID] == 2) {
                assert(j < SZ - 1);
                addedge(ver[i][j+1].second, ID);
                for (int k=last_left+1;k<j;k++) {
                    addedge(ID, ver[i][k].second);
                }
                last_left = j;
            }
        }
        int last_right = SZ;
        for (int j=SZ-1;j>=0;j--) {
            int ID = ver[i][j].second;
            if (dir[ID] == 1) {
                assert(j > 0);
                addedge(ver[i][j-1].second, ID);
                for (int k=last_right-1;k>j;k--) {
                    addedge(ID, ver[i][k].second);
                }
                last_right = j;
            }
        }
    }
    vector<int>topo;
    queue<int>q;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        topo.push_back(now);
        for (auto &t: e[now]) {
            if (--ind[t] == 0) {
                q.push(t);
            }
        }
    }
    if (topo.size() == B) {
        puts("possible");
        for (auto &ID: topo) {
            print(ID);
        }
    } else {
        puts("impossible");
    }
}