#include <bits/stdc++.h>

using namespace std;

vector<int> a(5), b(5);

vector<double> gen_rate(vector<int> val) {
    sort(val.begin(), val.end());
    if (val[0] <= 3) {
        return {1.0, 0, 0, 0, 0};
    } else if (val[0] <= 6) {
        return {0.0, 1.0, 0.0, 0, 0};
    } else if (val[0] <= 11) {
        return {0.0, 0.0, 1.0, 0.0, 0};
    } else if (val[0] <= 18) {
        //return {0.0, 0.0, 0.0, 1.0 - 0.125 * (val[0] - 10), 0.125 * (val[0] - 10), 0};
        return {0.0, 0.0, 0.0, 1.0, 0.0, 0};
    } else if (val[0] <= 27){
        return {0, 0, 0, 0, 1.0};
    } else {
        return {0, 0, 0, 0, 0.0};
    }
}

double calc_rate(vector<double> r1, vector<double> r2, bool asmall) {
    if (!asmall) swap(r1, r2);
    double none_play = 1.0;
    double ret = 0;
    for (int i = 0; i < 5; i++) {
        ret += none_play * r1[i] * (1 - r2[i]);
        none_play *= (1 - r1[i]) * (1 - r2[i]);
    }
    return ret;
}

double test() {
    vector<int> rd(100);
    for (int i = 0; i < 100; i++) rd[i] = i + 1;
    random_shuffle(rd.begin(), rd.end());
    for (int i = 0; i < 5; i++) {
        a[i] = rd[i];
        b[i] = rd[i + 5];
    }
    return calc_rate(gen_rate(a), gen_rate(b), *min_element(a.begin(), a.end()) < *min_element(b.begin(), b.end()));
}

vector<double> gen_rate_par(vector<int> val, vector<int> par) {
    sort(val.begin(), val.end());
    if (val[0] <= par[0]) {
        return {1.0, 0, 0, 0, 0};
    } else if (val[0] <= par[1]) {
        return {0.0, 1.0, 0.0, 0, 0};
    } else if (val[0] <= par[2]) {
        return {0.0, 0.0, 1.0, 0.0, 0};
    } else if (val[0] <= par[3]) {
        //return {0.0, 0.0, 0.0, 1.0 - 0.125 * (val[0] - 10), 0.125 * (val[0] - 10), 0};
        return {0.0, 0.0, 0.0, 1.0, 0.0};
    } else if (val[0] <= par[4]){
        return {0, 0, 0, 0, 1.0};
    } else {
        return {0, 0, 0, 0, 0.0};
    }
}

double test_par(vector<int> par) {
    const int TT = 1000;
    double ret = 0;
    for (int T = 1; T <= TT; T++) {
        vector<int> rd(100);
        for (int i = 0; i < 100; i++) rd[i] = i + 1;
        random_shuffle(rd.begin(), rd.end());
        for (int i = 0; i < 5; i++) {
            a[i] = rd[i];
            b[i] = rd[i + 5];
        }
        ret += calc_rate(gen_rate_par(a, par), gen_rate_par(b, par), *min_element(a.begin(), a.end()) < *min_element(b.begin(), b.end()));
    }
    return ret / TT;
}

int main() {
    srand(time(0));
    printf("%.5lf\n",test_par({4,8,12,19,28}));
    return 0;
    for (int i1 = -1; i1 <= 1; i1++) 
        for (int i2 = -1; i2 <= 1; i2++) 
            for (int i3 = -1; i3 <= 1; i3++)
                for (int i4 = -1; i4 <= 1; i4++)
                    for (int i5 = -1; i5 <= 1; i5++)
                        printf("%d %d %d %d %d %.5lf\n",3+i1,6+i2,11+i3,18+i4,27+i5,test_par({3+i1,6+i2,11+i3,18+i4,27+i5}));
}