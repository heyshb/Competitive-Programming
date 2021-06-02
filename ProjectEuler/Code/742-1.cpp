#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
vector<pii> farey;
const int N = 40;

void gen(int u1, int v1, int u2, int v2, int dep) {
    if (dep == 0) return;
    gen(u1, v1, u1 + u2, v1 + v2, dep - 1);
    farey.push_back({u1 + u2, v1 +v2});
    gen(u1 + u2, v1 + v2, u2, v2, dep - 1);
}

int main() {
    farey.push_back({0, 1});
    gen(0, 1, 1, 1, 3);
    farey.push_back({1, 1});
    for (auto t:farey) {
        printf("%d %d\n",t.first,t.second);
    }
}