#include <bits/stdc++.h>

using namespace std;

int N;
const int B = 10;
bool vis[1010][B + 1];

void ask(vector<int> q, int id) {
    int M = q.size();
    if (M == 0) return;
    printf("ASK %d",M);
    for (auto &t:q) {
        printf(" %d", t);
    }
    puts("");
    fflush(stdout);
    int tmp;
    for (int i=1;i<=M;i++) {
        scanf("%d",&tmp);
        vis[tmp][id] = true;
    }
}

int ans[1010];

int main() {
    int N;
    scanf ("%d",&N);
    for (int i=0;i<B;i++) {
        vector<int>q;
        for (int j=1;j<=N;j++) {
            if (j & (1 << i)) q.push_back(j);
        }
        ask(q, i);
    }
    for (int i=1;i<=N;i++) {
        ans[i] = 0;
        for (int j=0;j<B;j++) {
            if (vis[i][j]) ans[i] |= (1 << j);
        }
    }
    printf("ANSWER ");
    for (int i=1;i<=N;i++) {
        printf("%d%c",ans[i]," \n"[i==N]);
    }
    fflush(stdout);
}