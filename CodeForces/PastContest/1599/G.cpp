#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, k, outlier;

int x[200010], y[200010];

double sqr(double x){return x * x;}
double dis(int x1, int y1, int x2, int y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
double dis2(int id1, int id2) {
    return dis(x[id1], y[id1], x[id2], y[id2]);
}

void find_outlier() {
    while(true) {
        int v1, v2;
        mt19937 rd(233);
        uniform_int_distribution<int> dist(1, n);
        while(true) {
            v1 = dist(rd);
            v2 = dist(rd);
            if (v1 != v2) break;
        }
        int dx = x[v2] - x[v1];
        int dy = y[v2] - y[v1];
        int cnt = 0, this_outlier = -1;
        for (int i = 1; i <= n; i++) {
            if (i == v1 || i == v2) continue;
            int ndx = x[i] - x[v1];
            int ndy = y[i] - y[v1];
            if (1LL * ndx * dy - 1LL * ndy * dx != 0) {
                this_outlier = i;
                if (++cnt > 1) break;
            }
        }
        if (cnt == 1) {
            outlier = this_outlier;
            return;
        }
    }
}

double calc(vector<int> ord) {
    assert(ord.size() == n - 1);
    int last = k;
    double ret = 0;
    for (auto &t : ord) {
        ret += dis2(last, t);
        last = t;
    }
    return ret;
}

double calc2(vector<int> ord) {
    assert(ord.size() == n - 1);
    int start_idx = -1;
    for (int i = 0; i < n - 1; i++) {
        if (ord[i] == k) {
            start_idx = i;
            continue;
        }
    }
    assert(start_idx != -1);
    vector<double> S(n - 1);
    S[0] = 0;
    for (int i = 1; i < n - 1; i++) {
        S[i] = S[i - 1] + dis2(ord[i - 1], ord[i]);
    }
    auto range_dis = [&](int L, int R) {
        return S[R] - S[L];
    };
    double ret = 1e18;
    for (int i = 0; i < n - 1; i++) {
        int L = min(start_idx, i);
        int R = max(start_idx, i);
        double tmp = range_dis(L, R) + dis2(ord[i], outlier);
        if (R < n - 2) {
            double d1 = dis2(outlier, ord[R + 1]) + range_dis(R + 1, n - 2);
            if (L > 0) d1 += range_dis(0, n - 2);

            double d2 = dis2(outlier, ord[n - 2]) + range_dis(R + 1, n - 2);
            if (L > 0) d2 += range_dis(0, R + 1);

            tmp += min(d1, d2);
        } else {
            if (L > 0) {
                tmp += min(dis2(outlier, ord[0]) + range_dis(0, L - 1), dis2(outlier, ord[L - 1]) + range_dis(0, L - 1));
            }
        }
        ret = min(ret, tmp);

        
        tmp = range_dis(start_idx, n - 2) + range_dis(i, n - 2);
        tmp += dis2(ord[i], outlier);
        if (L > 0) {
            tmp += dis2(outlier, ord[L - 1]) + range_dis(0, L - 1);
        }
        ret = min(ret, tmp);
        
    }
    return ret;
}

int main() {
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    find_outlier();
    vector<int> id;
    for (int i = 1; i <= n; i++) {
        if (i != outlier) {
            id.push_back(i);
        }
    }
    sort(id.begin(), id.end(), [&](int id1, int id2) {
        if (x[id1] == x[id2]) return y[id1] < y[id2]; 
        return x[id1] < x[id2];
    });
    if (outlier == k) {
        double ans = calc(id);
        reverse(id.begin(), id.end());
        ans = min(ans, calc(id));
        printf("%.10lf\n",ans);
    } else {
        double ans = calc2(id);
        reverse(id.begin(), id.end());
        ans = min(ans, calc2(id));
        printf("%.10lf\n",ans);
    }
}