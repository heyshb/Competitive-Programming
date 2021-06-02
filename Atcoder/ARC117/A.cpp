#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int A[1010], B[1010];

int main() {
    int AA, BB;
    scanf("%d%d",&AA,&BB);
    bool fuck = false;
    if (AA < BB) fuck = true, swap(AA, BB);
    int S = 0;
    for (int i = 1; i <= AA; i++) {
        A[i] = i;
        S += i;
    }
    for (int i = 1; i < BB; i++) {
        B[i] = -i;
        S -= i;
    }
    B[BB] = -S;
    vector<int> ans;
    for (int i = 1; i <= AA; i++) ans.push_back(A[i]);
    for (int i = 1; i <= BB; i++) ans.push_back(B[i]);
    if (fuck) {
        for (auto &t : ans) t = -t;
    }
    for (auto &t : ans) printf("%d ", t);
}