#include <bits/stdc++.h>
using namespace std;
inline bool rd(int &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class t="">
inline void pt(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef long long ll;
typedef pair<int, int=""> pii;
const int N = 1e5 + 100;
const int inf = 10000000;
struct BIT {
    int c[N], maxn;
    void init(int n) {
        maxn = n;
        memset(c, 0, (10 + n) *sizeof(int));
    }
    int lowbit(int x) { return x&-x; }
    int sum(int x) {
        int ans = 0;
        while (x)ans += c[x], x -= lowbit(x);
        return ans;
    }
    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void change(int x, int val) {
        while (x<=maxn)c[x] += val, x += lowbit(x);
    }
}bit;
struct Node *null;
struct Node {
    Node *fa, *ch[2];
    int val;
    int mi, min_id, id;
    bool rev;
    inline void put() {
        printf(%d: fa:%d [%d,%d] val:%d ma:%d,%d rev:%d
, id, fa->id, ch[0]->id, ch[1]->id, val, mi, min_id, rev);
    }
    inline void clear(int _id) {
        fa = ch[0] = ch[1] = null;
        rev = 0;
        id = _id;
        mi = inf;
        min_id = 0;
        val = 0;
    }
    inline void push_up() {
        if (this == null)return;
        if (val) {
            mi = min(id, min(ch[0]->mi, ch[1]->mi));
            if (id <= min(ch[0]->mi, ch[1]->mi)) min_id = id;
            else if (ch[0]->mi < min(ch[1]->mi, id ))min_id = ch[0]->min_id;
            else min_id = ch[1]->min_id;         
        }
        else
        {
            mi = min(ch[0]->mi, ch[1]->mi);
            if (ch[0]->mi < ch[1]->mi)min_id = ch[0]->min_id;
            else min_id = ch[1]->min_id;
        }
    }
    inline void push_down() {
        if (this == null)return;
        if (rev) {
            ch[0]->flip();
            ch[1]->flip();
            rev = 0;
        }
    }
    inline void setc(Node *p, int d) {
        ch[d] = p;
        p->fa = this;
    }
    inline bool d() {
        return fa->ch[1] == this;
    }
    inline bool isroot() {
        return fa == null || fa->ch[0] != this && fa->ch[1] != this;
    }
    inline void flip() {
        if (this == null)return;
        swap(ch[0], ch[1]);
        rev ^= 1;
    }
    inline void go() {//????????this  
        if (!isroot())fa->go();
        push_down();
    }
    inline void rot() {
        Node *f = fa, *ff = fa->fa;
        int c = d(), cc = fa->d();
        f->setc(ch[!c], c);
        this->setc(f, !c);
        if (ff->ch[cc] == f)ff->setc(this, cc);
        else this->fa = ff;
        f->push_up();
    }
    inline Node*splay() {
        go();
        while (!isroot()) {
            if (!fa->isroot())
                d() == fa->d() ? fa->rot() : rot();
            rot();
        }
        push_up();
        return this;
    }
    inline Node* access() {//access?this???????splay,??this?????splay???  
        for (Node *p = this, *q = null; p != null; q = p, p = p->fa) {
            p->splay()->setc(q, 1);
            p->push_up();
        }
        return splay();
    }
    inline Node* find_root() {
        Node *x;
        for (x = access(); x->push_down(), x->ch[0] != null; x = x->ch[0]);
        return x;
    }
    void make_root() {
        access()->flip();
    }
    void cut() {//???????????  
        access();
        ch[0]->fa = null;
        ch[0] = null;
        push_up();
    }
    void cut(Node *x) {
        if (this == x || find_root() != x->find_root())return;
        else {
            x->make_root();
            cut();
        }
    }
    void link(Node *x) {
        if (find_root() == x->find_root())return;
        else {
            make_root(); fa = x;
        }
    }
};
Node pool[N], *tail;
Node *node[N];
void init(int n) {
    tail = pool;
    null = tail++;
    null->clear(0);
    for (int i = 1; i <= n; i++) {
        node[i] = tail++;
        node[i]->clear(i);
    }
}
void debug(Node *x) {
    if (x == null)return;
    x->put();
    debug(x->ch[0]);
    debug(x->ch[1]);
}
int n, m, q;
struct BST {
    int f[N];
    void init(int n) { for (int i = 1; i <= n; i++)f[i] = i; }
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }
    void Union(int u, int v) {
        u = find(u); v = find(v);
        if (u == v)return;
        if (u > v)swap(u, v);
        f[u] = v;
    }
}cha;
void insert(int x, int y) {
//  puts(**===);    for (int i = 1; i <= max(x, y); i++)debug(node[i]), puts();puts();
    if (cha.find(x) == cha.find(y)) {
        node[y]->access();
//      puts(**);   for (int i = 1; i <= max(x, y); i++)debug(node[i]), puts();puts();
        int id = node[y]->min_id;
        if (y <= id)return;
//      printf(change id:%d
, id);
        bit.change(id, -1);
        node[id]->val--;
        node[id]->cut(node[x]);
    }
    else cha.Union(x, y);
//  puts(---------);for (int i = 1; i <= x; i++)debug(node[i]), puts();puts();
    bit.change(y, 1);
    node[y]->make_root();
    node[y]->val++;
    node[y]->push_up();
    node[y]->fa = node[x];
 
//  puts(@@@@@@);for (int i = 1; i <= x; i++)debug(node[i]), puts();puts();
}
int ans[N];
struct {
    struct Edge {
        int to, nex, id;
    }edge[N << 1];
    int head[N], edgenum;
    void init(int n) {
        memset(head, -1, (10 + n) *sizeof(int));
        edgenum = 0;
    }
    void add(int u, int v, int id = 0) {
        Edge E = { v, head[u], id};
        edge[edgenum] = E;
        head[u] = edgenum++;
    }
}E, Q;
int main() {
    while (~scanf(%d%d%d, &n,&m,&q)) {
        E.init(n); Q.init(n); cha.init(n);
        for (int i = 0, u, v;i < m; i++) 
        {
            rd(u), rd(v);
            if (u == v) {i--, m--;continue;}
            if (u < v)E.add(v, u);else E.add(u, v);
        }
        for (int i = 0, u, v;i < q; i++) {
            rd(u); rd(v);
            Q.add(v, u, i);
        }
        bit.init(n);
        init(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = E.head[i]; ~j; j = E.edge[j].nex) 
                insert(i, E.edge[j].to);
            for (int j = Q.head[i]; ~j; j = Q.edge[j].nex)
                ans[Q.edge[j].id] = n - bit.query(Q.edge[j].to, i);
        }
        for (int i = 0; i < q; i++)  pt(ans[i]), puts();
    }
    return 0;
}
