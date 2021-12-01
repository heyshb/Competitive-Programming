#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int m, n;
bool mf[2000010], mt[2000010];
constexpr int SLEN = 11000000;
int to[2000010], ind[2000010];
char s[SLEN];
vector<int>e[2000010];
bool vis[2000010];

int parse(int L, int R) {
    int ret = 0;
    for (int i = L; i <= R; i++) ret = ret * 10 + (s[i] - '0');
    return ret;
}

int main() {
    scanf("%d%d\n",&m,&n);
    for (int i = 1; i <= m; i++) {
        vector<int> sp = {-1};
        fgets(s, SLEN, stdin);
        int len = strlen(s) - 1;
        for (int j = 0; j < len; j++) {
            if (s[j] == ' ') sp.push_back(j);
        }
        if (sp.size() == 1) {
            if (s[0] == '!') mf[parse(1, len - 1)] = true;
            else mt[parse(0, len - 1)] = true;
            continue;
        } else {
            int M = sp.size();
            for (int j = 1; j < M - 1; j++) {
                e[parse(sp[j - 1] + 1, sp[j] - 1)].push_back(n + i);
            }
            ind[n + i] = M - 2;
            if (s[sp[M - 1] + 1] == '!') {
                to[n + i] = -parse(sp[M - 1] + 2, len - 1);
            } else {
                to[n + i] = parse(sp[M - 1] + 1, len - 1);
            }
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int &t : e[i]) printf("%d-->%d\n",i,t);
    }
    */
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (mf[i] && mt[i]) goto FAIL;
        if (mt[i]) {
            vis[i] = true;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int now = q.front();
        //printf("%d\n",now);
        q.pop();
        if (now <= n) {
            for (auto &t : e[now]) {
                if (--ind[t] == 0) {
                    vis[t] = true;
                    q.push(t);
                }
            }
        } else {
            if (to[now] < 0) {
                mf[-to[now]] = true;
            } else {
                mt[to[now]] = true;
                if (!vis[to[now]]) {
                    vis[to[now]] = true;
                    q.push(to[now]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mt[i] && mf[i]) goto FAIL;
    }
    for (int i = 1; i <= n; i++) {
        if (mt[i]) putchar('T');
        else putchar('F');
    }


    return 0;
    FAIL:
    puts("conflict");
}