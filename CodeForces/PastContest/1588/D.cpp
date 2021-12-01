#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char num_to_char(int x) {
    if (x < 26) {
        return 'a' + x;
    } else {
        return 'A' + x - 26;
    }
}

int char_to_num(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 'a';
    return ch - 'A' + 26;
}

const int M = 52;

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        vector<vector<int>> w(n);
        vector<vector<vector<int>>> idx(n, vector<vector<int>>(M));
        vector<vector<vector<int>>> nxt;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.length(); j++) {
                char ch = s[j];
                int num = char_to_num(ch);
                a[i].push_back(num);
                w[i].push_back(idx[i][num].size());
                idx[i][num].push_back(j);
            }
            vector<vector<int>> skp(s.length(), vector<int>(M, -1));
            for (int j = s.length() - 1; j >= 0; j--) {
                if (j < s.length() - 1) {
                    for (int k = 0; k < 52; k++) {
                        skp[j][k] = skp[j + 1][k];
                    }
                }
                skp[j][a[i][j]] = j;
            }
            nxt.push_back(skp);
        }
        vector<vector<int>> ok(M, vector<int>(1 << n, 0));
        vector<vector<vector<int>>> state(M, vector<vector<int>>(1 << n));
        auto calc_transfer = [&](int now_ch, int now_mask, int nxt_ch) {
            if (state[now_ch][now_mask].empty()) {
                return -1;
            }
            int nxt_mask = 0;
            for (int i = 0; i < n; i++) {
                int now_pos = state[now_ch][now_mask][i];
                if (now_pos == a[i].size() - 1) return -1;
                int nxt_pos = nxt[i][now_pos + 1][nxt_ch];
                if (nxt_pos == -1) return -1;
                nxt_mask |= ((w[i][nxt_pos]) << i);
            }
            return nxt_mask;
        };
        vector<vector<int>> dp(M, vector<int>(1 << n, 1));
        vector<vector<pii>> from(M, vector<pii>(1 << n, pii(-1, -1)));
        vector<vector<pii>> valid_states(a[0].size());
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < (1 << n); j++) {
                bool ok = true;
                vector<int> state_idx;
                for (int k = 0; k < n; k++) {
                    int offset = (j >> k) & 1;
                    if (idx[k][i].size() < offset + 1) {
                        ok = false;
                        break;
                    }
                    state_idx.push_back(idx[k][i][offset]);
                }
                if (ok) {
                    state[i][j] = state_idx;
                    valid_states[state_idx[0]].push_back(pii(i, j));
                }
            }
        }
        int best_ans = 0;
        pii best_state(-1, -1);
        for (auto &state_vec : valid_states) {
            for (auto &state: state_vec) {
                int now_ch = state.first;
                int now_mask = state.second;
                for (int nxt_ch = 0; nxt_ch < M; nxt_ch++) {
                    int nxt_mask = calc_transfer(now_ch, now_mask, nxt_ch);
                    if (nxt_mask != -1) {
                        if (dp[now_ch][now_mask] + 1 > dp[nxt_ch][nxt_mask]) {
                            dp[nxt_ch][nxt_mask] = dp[now_ch][now_mask] + 1;
                            from[nxt_ch][nxt_mask] = pii(now_ch, now_mask);
                        }
                    }
                }
                if (dp[now_ch][now_mask] > best_ans) {
                    best_ans = dp[now_ch][now_mask];
                    best_state = pii(now_ch, now_mask);
                }
            }
        }
        cout << best_ans << endl;
        string best_str = "";
        pii now_state = best_state;
        while(now_state.first != -1) {
            best_str += num_to_char(now_state.first);
            now_state = from[now_state.first][now_state.second];
        }
        reverse(best_str.begin(), best_str.end());
        cout << best_str << endl;
    }
}