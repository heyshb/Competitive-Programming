#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

struct point {
    int x,y,z,num;
}p[100010];
int N;

bool cmp(point a,point b) {
    if (a.x == b.x && a.y == b.y) {
        return a.z < b.z;
    }
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool v[100100];

void print(int p1,int p2) {
    printf("%d %d\n",p[p1].num,p[p2].num);
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        p[i].num = i;
        v[i] = false;
    }
    v[0] = true;
    sort(p+1,p+N+1,cmp);
    vector<int>rmx;
    for (int i=1;i<=N;i++) {
        if (i > 1 && p[i].x == p[i-1].x) {
            continue;
        }
        //printf("cnm %d\n",i);
        vector<int>rm;
        int lst = -1;
        for (int j=i;j<=N && p[j].x == p[i].x;j++) {
            lst = j;
            if (!v[j] && !v[j-1] && p[j].y == p[j-1].y) {
                v[j] = true;
                v[j-1] = true;
                print(j,j-1);
            } 
            if (j > i && !v[j-1]) {
                rm.push_back(j-1);
            }
        }
        //printf("%d--%d\n",i,lst);
        if (!v[lst]) {
            rm.push_back(lst);
        }
        for (int i=1;i<rm.size();i+=2) {
            print(rm[i-1],rm[i]);
        }
        if (rm.size() % 2 == 1) {
            //printf("push %d\n",p[rm[rm.size()-1]].num);
            rmx.push_back(rm[rm.size()-1]);
        }
    }
    for (int i=1;i<rmx.size();i+=2) {
        print(rmx[i-1],rmx[i]);
    }
}