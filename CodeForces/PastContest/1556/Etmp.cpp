struct SegmentTree2 {
    struct Node {
        LL sum, lmin, rmin, smin;
    }T[MAXN];
    Node merge(Node n1, Node n2) {
        Node ret;
        ret.sum = n1.sum + n2.sum;
        ret.lmin = min(n1.lmin, n1.sum + n2.lmin);
        ret.rmin = min(n2.rmin, n2.sum + n1.rmin);
        ret.smin = min(min(n1.smin, n2.smin), n1.rmin + n2.lmin);
        return ret;
    }
    void upd(int x) {
        T[x] = merge(T[x * 2], T[x * 2 + 1]);
    }
    Node query(int x, int L, int R, int ql, int qr) {
        if (L == ql && R == qr) return T[x];
        if (qr <= mid) return query(ls, L, mid, ql, qr);
        if (ql > mid) return query(rs, mid + 1, R, ql, qr);
        return merge(query(ls, L, mid, ql, mid), query(rs, mid + 1, R, mid + 1, qr));
    }
    void build(int x, int L, int R) {
        if (L == R) {
            T[x] = (Node){val[L], min(0, val[L]), min(0, val[L]), min(0, val[L])};
            return;
        }
    }
};