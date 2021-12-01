#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii gen() {
    vector<int> rd(100);
    for (int i = 0; i < 100; i++) rd[i] = i + 1;
    random_shuffle(rd.begin(), rd.end());
    return pii(*min_element(rd.begin(), rd.begin() + 5), *min_element(rd.begin() + 5, rd.begin() + 10));
}

const int T0 = 100000;
double appear[110], win[110];

int main() {
    for (int i = 0; i <= T0; i++) {
        auto p = gen();
        int A = p.first, B = p.second;
        appear[A] += 1.0 / T0;
        win[A] += double(A < B) / T0;
    }
    for (int i = 1; i <= 100; i++) {
        win[i] /= (appear[i] + 1e-7);
        printf("%.5lf %.5lf\n",appear[i], win[i]);
    }
}