#include <bits/stdc++.h>

using namespace std;

vector<double> gen_rate(vector<int> val) {
    sort(val.begin(), val.end());
    if (val[0] <= 4) {
        return {1.0, 0, 0, 0, 0};
    } else if (val[0] <= 8) {
        return {0.0, 1.0, 0.0, 0, 0};
    } else if (val[0] <= 12) {
        return {0.0, 0.0, 1.0, 0.0, 0};
    } else if (val[0] <= 19) {
        return {0.0, 0.0, 0.0, 1.0, 0};
    } else if (val[0] <= 28){
        return {0, 0, 0, 0, 1.0};
    } else {
        return {0, 0, 0, 0, 0.0};
    }
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        vector<int>a(5);
        for (int i = 0; i < 5; i++) scanf("%d",&a[i]);
        auto ret = gen_rate(a);
        for (int i = 0; i < 5; i++) printf("%.5lf%c",ret[i]," \n"[i==4]);
        fflush(stdout);
    }
}