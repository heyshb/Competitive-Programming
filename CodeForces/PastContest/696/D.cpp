#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;
LL L;
int a[210];
char s[210][210];
int ch[210][26];
int fail[210], b[210];
int go[210][26];
int M = 1;

void insert(char *S, int val) {
    int len = strlen(S);
    int now = 1;
    for (int i = 0; i < len; i++) {
        int &CH = ch[now][S[i] - 'a'];
        if (!CH) {
            CH = ++M;
        }
        now = CH;
    }
    b[now] += val;
}

void build_AC() {
    queue<int>q;
    q.push(1);
    fail[1] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            if (!ch[now][i]) continue;
            int CH = ch[now][i];
            int tmp = fail[now];
            while(tmp && !ch[tmp][i]) tmp = fail[tmp];
            if (ch[tmp][i]) {
                fail[CH] = ch[tmp][i];
                b[CH] += b[fail[CH]];
            }
            else fail[CH] = 1;
            q.push(CH);
        }
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 26; j++) {
            int tmp = i;
            while(tmp && !ch[tmp][j]) tmp = fail[tmp];
            if (tmp) {
                go[i][j] = ch[tmp][j];
            } else {
                go[i][j] = 1;
            }
        }
    }
}

const LL INF = 1e18;
class matrix {
public:
    int n;
    LL val[210][210];
    matrix(){}
    matrix(int _n) : n(_n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                val[i][j] = -INF;
            }
        }
    }
    friend matrix operator * (matrix &m1, matrix &m2) {
        matrix ret(m1.n);
        for (int i = 0; i < m1.n; i++) {
            for (int k = 0; k < m1.n; k++) {
                for (int j = 0; j < m1.n; j++) {
                    ret.val[i][j] = max(ret.val[i][j], m1.val[i][k] + m2.val[k][j]);
                }
            }
        }
        return ret;
    }
};

matrix quick_pow(matrix a, LL x) {
    matrix ret(a.n);
    for (int i = 0; i < a.n; i++) {
        ret.val[i][i] = 0;
    }
    while(x) {
        if (x & 1) ret = ret * a;
        a = a * a;
        x >>= 1;
    }
    return ret;
}


int main() {
    scanf("%d%lld",&n,&L);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s",s[i]);
        insert(s[i], a[i]);
    } 
    build_AC();
    matrix trans(M);
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < 26; j++) {
            int to = go[i][j];
            trans.val[i - 1][to - 1] = b[to];
        }
    }
    matrix fuck = quick_pow(trans, L);
    LL ans = 0;
    /*
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) printf("%lld ",fuck.val[i][j]);
        puts("");
    }
    */
    for (int i = 0; i < M; i++) {
        ans = max(ans, fuck.val[0][i]);
    }
    printf("%lld\n",ans);
}