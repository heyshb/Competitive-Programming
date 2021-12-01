#include <bits/stdc++.h>
#define ls (x*2)
#define rs (x*2+1)
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

struct Node {
    int cnt[3];
    int v[3][3];
}T[888888];
int n, q;
string s;
const int INF = 1e9;

void update(int x) {
    for (int i = 0; i < 3; i++) {
        T[x].cnt[i] = T[ls].cnt[i] + T[rs].cnt[i];
        T[x].v[i][i] = T[x].cnt[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            T[x].v[i][j] = INF;
            for (int k = i; k <= j; k++) {
                T[x].v[i][j] = min(T[x].v[i][j], T[ls].v[i][k] + T[rs].v[k][j]);
            }
        }
    }
}

void set_val(int x, int val) {
    T[x].cnt[0] = T[x].cnt[1] = T[x].cnt[2] = 0;
    T[x].cnt[val] = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            T[x].v[i][j] = 0;
        }
    }
    T[x].v[val][val] = 1;
}

void build(int x, int l, int r) {
    if (l == r) {
        set_val(x, s[l] - 'a');
        return;
    }    
    int mid = (l + r) / 2;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    update(x);
    /*
    printf("%d %d %d:\n",x,l,r);
    for (int i = 0 ; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            printf("[%d][%d] = %d\n",i,j,T[x].v[i][j]);
        }
    }
    */
}

void modify(int x, int l, int r, int pos, int val) {
    if (l == r) {
        set_val(x, val);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) modify(ls, l, mid, pos, val);
    else modify(rs, mid + 1, r, pos, val);
    update(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    cin >> s;
    build(1, 0, n - 1);
    while(q--) {
        int pos;
        string ch;
        cin >> pos >> ch;
        --pos;
        modify(1, 0, n - 1, pos, ch[0] - 'a');
        cout << T[1].v[0][2] << endl;
    }
}