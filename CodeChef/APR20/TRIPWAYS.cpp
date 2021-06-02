#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007, M = 4096, LOG = 63;
const int NICO = 16;
int m;

struct Vector {
	int a[M];

	Vector() {
		memset(a, 0, sizeof(a));
	}
	
	int& operator[] (const int &i) { return a[i]; }
	const int operator[] (const int &i) const { return a[i]; }

	int operator * (const Vector &b) {
		unsigned long long ret = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < NICO && i < m; ++j, ++i) {
				ret = ret + (unsigned long long)a[i] * b[i];
			}
			--i;
			ret %= MOD;
		}
		return (int)(ret);
	}

	Vector operator + (const Vector &b) {
		Vector ret;
		for (int i = 0; i < m; ++i) {
			if ((ret[i] = a[i] + b[i]) >= MOD) {
				ret[i] -= MOD;
			}
		}
		return ret;
	}

};

Vector operator * (int k, const Vector &b) {
	Vector ret;
	for (int i = 0; i < m; ++i) {
		ret[i] = (long long)k * b[i] % MOD;
	}
	return ret;
}

typedef pair<int, int> PII;

struct SparseMatrix {
    struct row {
        int ii, i;
        int pos[M];
        int cnt = 0;
        int operator * (const Vector &b) {
		    int ret = (long long)ii * b[i] % MOD;
            for (int j = 0; j < cnt; j++) {
                ret += b[pos[j]];
                if (ret >= MOD) ret -= MOD;
            }
            return (int)(ret);
        }
        void add(int x) {
            pos[cnt++] = x;
        }
    };
	row a[M];

	Vector operator * (const Vector &b) {
		Vector ret;
		for (int i = 0; i < m; ++i) {
            ret[i] = a[i] * b;
		}
		return ret;
	}
} A;

int inverse(int a) {
	return a == 1 ? 1 : (long long)(MOD - MOD / a) * inverse(MOD % a) % MOD;
}

struct Poly {
	vector<int> a;

	Poly() { a.clear(); }

	Poly(vector<int> &a): a(a) {}

	int length() const { return a.size(); }

	Poly move(int d) {
		vector<int> na(d, 0);
		na.insert(na.end(), a.begin(), a.end());
		return Poly(na);
	}

	int calc(vector<int> &d, int pos) {
		unsigned long long ret = 0;
		for (int i = 0; i < (int)a.size(); ++i) {
			for (int j = 0; j < NICO && i < (int)a.size(); ++j, ++i) {
				ret = ret + (unsigned long long)a[i] * d[pos - i];
			}
			--i;
			ret %= MOD;
		}
		return (int)(ret);
	}

	Poly operator - (const Poly &b) {
		vector<int> na(max(this->length(), b.length()));
		for (int i = 0; i < (int)na.size(); ++i) {	
			int aa = i < this->length() ? this->a[i] : 0,
				bb = i < b.length() ? b.a[i] : 0;
			na[i] = (aa + MOD - bb) % MOD;
		}
		return Poly(na);
	}
};

Poly operator * (const int &c, const Poly &p) {
	vector<int> na(p.length());
	for (int i = 0; i < (int)na.size(); ++i) {
		na[i] = (long long)c * p.a[i] % MOD;
	}
	return na;
}

vector<int> Berlekamp(vector<int> a) {
	int n = a.size();
	Poly s, b;
	s.a.push_back(1), b.a.push_back(1);
	for (int i = 1, j = 0, ld = a[0]; i < n; ++i) {
		int d = s.calc(a, i);
		if (d) {
			if ((s.length() - 1) * 2 <= i) {
				Poly ob = b;
				b = s;
				s = s - (long long)d * inverse(ld) % MOD * ob.move(i - j);
				j = i;
				ld = d;
			} else {
				s = s - (long long)d * inverse(ld) % MOD * b.move(i - j);
			}
		}
	}
	return s.a;
}

struct LinearRec {

	int n;
	vector<Vector> first; 
	vector<int> trans;
	vector<vector<int> > bin;

	vector<int> add(vector<int> &a, vector<int> &b) {
		vector<unsigned long long> result(n * 2 + 1, 0);
		//You can apply constant optimization here to get a ~10x speedup
		for (int i = 0; i <= n; ++i) {
            if ((i & 15) == 15) {
                for (int j = 0; j <= n; ++j) {
                    result[i + j] += (long long)a[i] * b[j];
                    result[i + j] %= MOD;
                }
            }
            else {
                for (int j = 0; j <= n; ++j) {
                    result[i + j] += (long long)a[i] * b[j];
                }
            }
		}
        for (int i = 0; i <= 2 * n; i++) result[i] %= MOD;
		for (int i = 2 * n; i > n; --i) {
            result[i] %= MOD;
            if (((2 * n - i) & 15) == 15) {
                for (int j = 0; j < n; ++j) {
                    result[i - 1 - j] += (long long)result[i] * trans[j];
                }
            }
            else {
                for (int j = 0; j < n; ++j) {
                    result[i - 1 - j] += (long long)result[i] * trans[j];
                    result[i - 1 - j] %= MOD;
                }
            }
			result[i] = 0;
		}
		result.erase(result.begin() + n + 1, result.end());
        vector<int> res(n + 1, 0);
        for (int i = 0; i <= n; i++) res[i] = (int)(result[i]);
		return res;
	}

	LinearRec(vector<Vector> &first, vector<int> &trans):first(first), trans(trans) {
		n = first.size();
		vector<int> a(n + 1, 0);
		a[1] = 1;
		bin.push_back(a);
		for (int i = 1; i < LOG; ++i) {
			bin.push_back(add(bin[i - 1], bin[i - 1]));
		}
	}

	Vector calc(long long k) {
		vector<int> a(n + 1, 0);
		a[0] = 1;
		for (int i = 0; i < LOG; ++i) {
			if (k >> i & 1) {
				a = add(a, bin[i]);
			}
		}
		Vector ret;
		for (int i = 0; i < n; ++i) {
			ret = ret + a[i + 1] * first[i];
		}
		return ret;
	}
};

long long ans[1000];
typedef pair<long long, int> PLI;
vector<PLI> K;

void solve(SparseMatrix &A) {
    // cout << "???" << endl;
	vector<Vector> vs;
    Vector b;
    for (int i = 0; i < m; i++)
        b[i] = (i == 0);
	vs.push_back(A * b);
	for (int i = 1; i < m * 2; ++i) {
		vs.push_back(A * vs.back());
	}
    // for (auto&v : vs) {
    //     for (int i = 0; i < m; i++) {
    //         cout << v[i] << ' ';
    //     }cout << endl;
    // }
    // cout << "???" << endl;
	Vector x;
	for (int i = 0; i < m; ++i) {
		x[i] = rand() % MOD;
	}
	vector<int> a(m * 2);
	for (int i = 0; i < m * 2; ++i) {
		a[i] = 	vs[i] * x;
	}
    // cout << "???" << endl;
	vector<int> s = Berlekamp(a);
	s.erase(s.begin());
	for (int i = 0; i < s.size(); ++i) {
		s[i] = (MOD - s[i]) % MOD;
	}
	vector<Vector> vf(vs.begin(), vs.begin() + s.size());
	LinearRec f(vf, s);
    // cout << "???" << endl;
	sort(K.begin(), K.end());
    for (auto &k : K) {
        if (k.first == 0) ans[k.second] = (m == 1);
        else if (k.first <= m * 2) {
            ans[k.second] = vs[k.first - 1][m - 1];
        }
        else {
            ans[k.second] = f.calc(k.first)[m - 1];
        }
    }
    // cout << "???" << endl;
}

int main() {
    int e, Q;
    scanf("%d%d%d", &m, &e, &Q);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        A.a[i].ii = x;
        A.a[i].i = i;
    }
    // cout << "???" << endl;
    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        A.a[y].add(x);
    }
    for (int i = 0; i < Q; i++) {
        long long k;
        scanf("%lld", &k);
        K.emplace_back(PLI(k, i));
    }
    solve(A);
    for (int i = 0; i < Q; i++)
	    printf("%lld\n", ans[i]);
	return 0;
}