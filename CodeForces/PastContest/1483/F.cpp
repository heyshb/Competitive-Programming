#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n;
const int MAXN = 1000010;
string s[MAXN];
int ans = 0;
int ch[MAXN][26], M;
int fail[MAXN], ed[MAXN], id[MAXN], skp[MAXN];
vector<int>e[MAXN];
int L[MAXN], R[MAXN], time_tag = 0;

void build_AC() {
    queue<int>q;
    q.push(1);
    skp[1] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i=0;i<26;i++) {
            if (ch[now][i]) {
                int CH = ch[now][i];
                int F = fail[now];
                while(F && !ch[F][i]) F = fail[F];
                if (F) fail[CH] = ch[F][i];
                else fail[CH] = 1;
                if (id[CH]) {
                    skp[CH] = CH;
                } else {
                    skp[CH] = skp[fail[CH]];
                }
                e[fail[CH]].push_back(CH);
                q.push(CH);
            }
        }
    }
}

void dfs(int x) {
    L[x] = ++time_tag;
    for (auto &t: e[x]) {
        dfs(t);
    }
    R[x] = time_tag;
}

int cnt[MAXN];
int T[MAXN];
int lowbit(int x){return x&-x;}
int get_sum(int x) {
    int ret = 0;
    while(x) {
        ret += T[x];
        x -= lowbit(x);
    }
    return ret;
}
void add(int x,int y) {
    while(x <= M) {
        T[x] += y;
        x += lowbit(x);
    }
}
int range_sum(int x,int y) {
    return get_sum(y) - get_sum(x - 1);
}

int main() {
    cin >> n;
    M = 1;
    for (int i=1;i<=n;i++) {
        cin >> s[i];
        int len = s[i].length();
        int now = 1;
        for (int j=0;j<len;j++) {
            int &CH = ch[now][s[i][j] - 'a'];
            if (!CH) {
                CH = ++M;
            }
            now = CH;
        }
        ed[i] = now;
        id[now] = i;
    }
    /*
    for (int i=1;i<=M;i++) {
        for (int j=0;j<26;j++) {
            if (ch[i][j]) printf("ch %d %d = %d\n",i,j,ch[i][j]);
        }
    }
    */
    build_AC();
    //for (int i=1;i<=M;i++) printf("fail[%d]=%d\n",i,fail[i]);
    //for (int i=1;i<=M;i++) printf("skp[%d]=%d\n",i,skp[i]);
    dfs(1);
    for (int i=1;i<=n;i++) {
        int now = 1;
        int len = s[i].length();
        vector<pii> stk;
        for (int j=0;j<len;j++) {
            now = ch[now][s[i][j] - 'a'];
            //printf("j = %d, now = %d\n",j,now);
            add(L[now], 1);
            if (j == len - 1) now = fail[now];
            int suffix_node = skp[now];
            if (suffix_node == 0) continue;
            //printf("suffix node: %d\n",suffix_node);
            int suffix_id = id[suffix_node];
            assert(suffix_id);
            int cover_left = j - s[suffix_id].length() + 1;
            while(!stk.empty() && stk.back().first >= cover_left) stk.pop_back();
            stk.push_back(pii(cover_left, suffix_id));
        }
        vector<int> candidate;
        for (auto &t: stk) {
            //printf("!!! %d %d\n",t.first,t.second);
            if (cnt[t.second] == 0) candidate.push_back(t.second);
            cnt[t.second]++;
        }
        for (auto &t: candidate) {
            // t: string id
            assert(t != i);
            //printf("candidate = %d\n",t);
            int appear_time = range_sum(L[ed[t]], R[ed[t]]);
            //printf("rangesum = %d\n",appear_time);
            if (appear_time == cnt[t]) ans++;
        }
        for (auto &t: stk) cnt[t.second]--;
        now = 1;
        for (int j=0;j<len;j++) {
            now = ch[now][s[i][j] - 'a'];
            add(L[now], -1);
        }
    }
    cout << ans << endl;
}