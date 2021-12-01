#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

double test(vector<int> a) {
    int TT = 1000000;
    double sum = 0;
    int dim = a.size();
    int S = 0;
    for (auto &t : a) S += t;
    for (int T = 1; T <= TT; T++) {
        vector<int> b = a;
        while(*max_element(b.begin(), b.end()) != S) {
            sum += 1;
            int from = rand() % dim;
            int to = rand() % dim;
            while(b[from] == 0) from = rand() % dim;
            b[from]--;
            b[to]++; 
        }
    }
    return sum / TT;
}

int main() {
    srand(time(NULL));
    printf("%.5lf\n",test({1, 1, 1}));
}