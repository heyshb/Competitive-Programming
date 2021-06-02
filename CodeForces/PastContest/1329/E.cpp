#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

class matrix {
public:
    int N, M;
    LL v[2][2];
    matrix() {
        memset(v, 0, sizeof(v));
    }
    friend matrix operator * (matrix m1, matrix m2) {
        assert(m1.M == m2.N);
        matrix ret;
        ret.N = m1.N;
        ret.M = m2.M;
        for (int k=0;k<m1.M;k++) {
            for (int i=0;i<m1.N;i++) {
                for (int j=0;j<m2.M;j++) {
                   ret.v[i][j] += m1.v[i][k] * m2.v[k][j] % MOD; 
                   ret.v[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
};

matrix m_qp(matrix a, LL x) {
    matrix ret;
    ret.v[0][0] = ret.v[1][1] = 1;
    while(x) { 
        if (x & 1) {
            ret = ret * a;
        }
        a = a * a;
        x >>= 1;
    }
    return ret;
}

int main() {
    
}