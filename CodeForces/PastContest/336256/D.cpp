#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

LL H, M, A;

struct solver {
    LL MOD;
    solver(){}
    solver(LL _MOD) : MOD(_MOD) {}
    LL S(LL k) {   
        return (k*(k+1)/2ll)%MOD;
    }
    LL f(LL a,LL b,LL c,LL n) {
        if(!a)return 0;
        if(a>=c || b>=c)
        return ((a/c)*S(n)%MOD+(n+1)*(b/c)%MOD+f(a%c,b%c,c,n))%MOD;
        LL m=(a*n+b)/c;
        return (m*n%MOD-f(c,c-b-1,a,m-1)+MOD)%MOD;
    }
    LL solve() {
        LL ret1 = H * M % MOD;
        if ((M - 1) * (H - 1) > A) {
            puts("?");
            LL mx = ((M - 1) * (H - 1) - A) / M;
            printf("mx = %lld\n",mx);
            ret1 = f(M, A, H - 1, mx) + mx + 1 + (H - 1 - mx) * M;
            ret1 %= MOD;
        }
        printf("%lld\n",ret1);
        if ((M * (H - 1) - A + (H - 2)) / (H - 1) <= 0) return ret1;
        printf("? %lld %lld\n",f(M, -A, H - 1, H - 1), f(M, - A - 1, H - 1, A / M));
        LL tmp = (f(M, -A, H - 1, H - 1) - f(M, - A - 1, H - 1, A / M) + MOD) % MOD;

        return (ret1 - tmp + MOD) % MOD;
    }

};

typedef pair<LL, LL> pll;
LL gcd(LL x,LL y) {
    return y==0?x:gcd(y,x%y);
}

LL lcm(LL x,LL y) {
    return x / gcd(x, y) * y;
}
LL exgcd(LL A,LL B,LL &x,LL &y) {
    if (B == 0) {
        x = 1;
        y = 0;
        return A;
    }
    LL tx,ty;
    LL d = exgcd(B, A%B, tx, ty);
    x = ty;
    y = tx - ty * (A / B);
    return d;
}

//solve Ax + By = C with minimum x >= 0
//No solution: (-1, -1)
pll solve(LL A,LL B,LL C) {
    LL x,y;
    LL g = exgcd(A,B,x,y);
    if (C % g != 0) {
        return pll(-1,-1);
    }
    x *= C / g;
    y *= C / g;
    LL retx = x % (B / g);
    if (retx < 0) {
        retx += B / g;
    }
    LL rety = y - A / g * (retx - x) / (B / g); 
    //printf("%lld %lld %lld\n",retx,rety,A*retx+B*rety);
    return pll(retx,rety);
}

//return the solution of equation set {x = a_i (mod m_i)}
//if no solution, return (-1, -1)
//else return (a, m)
//{(2,3),(3,5),(2,7)} --> (23,105)
pll CRT(vector<pll> eq) {
    if (eq.empty()) {
        return pll(-1,-1);
    }
    LL a = eq[0].first, m = eq[0].second;
    for (int i=1;i<eq.size();i++) {
        LL b = eq[i].first, n = eq[i].second;
        auto tmp = solve(m, n, b - a);
        if (tmp.first == -1) {
            return pll(-1,-1);
        }
        a = tmp.first * m + a;
        m = lcm(n, m);
    }
    return pll(a,m);
}

int main() {
    scanf("%lld%lld%lld",&H,&M,&A);
    const LL MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
    solver s1(MOD1), s2(MOD2);
    LL ans1 = s1.solve(), ans2 = s2.solve();
    auto ret = CRT({pll(ans1, MOD1), pll(ans2, MOD2)});
    printf("%lld\n",ret.first);
}