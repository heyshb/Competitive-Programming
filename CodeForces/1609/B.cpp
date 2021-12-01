#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    string s;
    int n, q;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s;
    auto check = [&](int idx) {
        if (idx < 0 || idx + 2 >= n) return false;
        return s[idx] == 'a' && s[idx + 1] == 'b' && s[idx + 2] == 'c';
    };
    set<int> st;
    for (int i = 0; i + 2 < n; i++) {
        if (check(i)) st.insert(i);
    }
    while(q--) {
        int pos;
        string ch;
        cin >> pos;
        cin >> ch;
        pos--;
        for (int i = pos - 2; i <= pos + 2; i++) {
            if (check(i)) st.erase(i);
        }
        s[pos] = ch[0];
        for (int i = pos - 2; i <= pos + 2; i++) {
            if (check(i)) st.insert(i);
        }
        cout << st.size() << endl;
    }
    
}