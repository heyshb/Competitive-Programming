#include <bits/stdc++.h>

using namespace std;

string s, t;
int tt[1000010];
int lens, lent;
const int MOD = 1e9 + 7;
int N, T, S, Q;

vector<int> get_match_length(string &s, string &t) {

}

int main() {
    std::ios::sync_with_stdio(false);
    cin >> N >> Q;
    cin >> s >> t;
    lens = s.length();
    lent = t.length();
    tt[0] = 1;
    for (int i=1;i<=100010;i++) {
        tt[i] = (tt[i - 1] * 2 + 1) % MOD;
    }
    for (int qq=1;qq<=Q;qq++) {
        int K;
        string q;
        cin >> K;
        cin >> q;
        int qlen = q.length();
        int M = 0;
        string si = s;
        while(M < K && si.length() < qlen) {
            si = si + t[M++] + si;
        }
        if (qlen < si.length()) {
            cout << 0 << endl;
            continue;
        }
        for (int i=0;i<)
    }
}