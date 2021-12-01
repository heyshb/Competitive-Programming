#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        string A, B;
        cin >> n >> A >> B;
        int nodeL = 0, nodeR = n - 1;
        int flip = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            char now_A = A[nodeR] ^ flip;
            char target = B[i];
            if (now_A != target) {
                if ((A[nodeL] ^ flip) == target) {
                    ans.push_back(1);
                }
                flip ^= 1;
                ans.push_back(i + 1);
                swap(nodeL, nodeR);
            }
            if (nodeR <= nodeL) nodeR++;
            else nodeR--;
        }
        printf("%d",ans.size());
        for (auto &t : ans) printf(" %d",t);
        puts("");
    }
}