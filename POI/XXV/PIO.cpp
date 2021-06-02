#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int N;
class point {
    public:
    int x, y;
    point(){}
    point(int _x, int _y):x(_x), y(_y){}
    point operator + (const point& p) {
        return point(x + p.x, y + p.y);
    }
    point& operator += (const point& p) {
        this->x += p.x;
        this->y += p.y;
        return *this;
    }
    point operator - (const point& p) {
        return point(x - p.x, y - p.y);
    }
    point& operator -= (const point& p) {
        this->x -= p.x;
        this->y -= p.y;
        return *this;
    }
    LL operator * (const point& p) {
        return 1LL * x * p.y - 1LL * y * p.x;
    }
    bool operator < (const point& p) {
    }
};

int N;
point p[200010];

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p+1,p+N+1);
}