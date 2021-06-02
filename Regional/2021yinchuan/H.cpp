#include <bits/stdc++.h>

using namespace std;

int n, m;
class Point {
    public:
    double x, y, z;
    Point(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    friend Point operator - (Point &p1, Point &p2) {
        return Point(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
    }
    friend Point operator + (Point &p1, Point &p2) {
        return Point(p1.x + p2.x, p1.y + p2.y, p1.z + p2.z);
    }
    double len() {
        return x * x + y * y + z * z;
    }
    void print() {
        printf("%.10lf %.10lf %.10lf\n",x,y,z);
    }
};

const double pi = acos(-1);
std::mt19937 rnd(233);
typedef vector<Point> ps;
class poly{
    public:
    poly(){}
    poly(ps _points): points(_points){}
    ps points;
    //int deg;
    friend poly operator * (poly p1, poly p2) {
        poly ret;
        // ret.deg = p1.deg + p2.deg;
        ret.points.clear();
        for (auto &t1 : p1.points) {
            for (auto &t2 : p2.points) {
                ret.points.push_back(t1 + t2);
            }
        }
        return ret;
    }
    void rotate(double &x, double &y, double &theta) {
        double newx = cos(theta) * x - sin(theta) * y;
        double newy = sin(theta) * x + cos(theta) * y;
        x = newx;
        y = newy;
    }
    poly random_rotate() {
        poly ret = *this;
        double theta1 = uniform_real_distribution<double>(0, pi / 2)(rnd);
        double theta2 = uniform_real_distribution<double>(0, pi / 2)(rnd);
        double theta3 = uniform_real_distribution<double>(0, pi / 2)(rnd);
        for (auto &p : ret.points) {
            rotate(p.x, p.y, theta1);
            rotate(p.x, p.z, theta2);
            rotate(p.y, p.z, theta3);
        }
        return ret;
    }
    void check() {
        for (auto &t1 : points) {
            int cnt = 0;
            for (auto &t2 : points) {
                if (fabs((t1 - t2).len() - 1) < 1e-6) {
                    cnt++;
                }
            }
            printf("%d\n",cnt);
        }
    }
}ans[11];

void gen() {
    ans[1] = poly({Point(0, 0, 0), Point(0, 0, 1)});
    ans[2] = poly({Point(0, 0, 0), Point(1, 0, 0), Point(0.5, sqrt(3) / 2, 0)});
    ans[3] = poly({Point(0, 0, 0), Point(1, 0, 0), Point(0.5, sqrt(3) / 2, 0), Point(0.5, sqrt(3) / 6, sqrt(6) / 3)});
    ans[4] = poly({Point(0, 0, 0), Point(1, 0, 0), Point(0, 1, 0), Point(1, 1, 0), Point(0.5, 0.5, sqrt(2) / 2), Point(0.5, 0.5, -sqrt(2) / 2)});
    ans[5] = ans[4] * ans[1].random_rotate();
    ans[6] = ans[4] * ans[2].random_rotate();
    ans[7] = ans[4] * ans[3].random_rotate();
    ans[8] = ans[4] * ans[4].random_rotate();
    ans[9] = ans[6] * ans[3].random_rotate();
    ans[10] = ans[7] * ans[3].random_rotate();
}


int main() {
    gen();
    int n;
    scanf("%d",&n);
    //ans[n].check();
    printf("%d\n",ans[n].points.size());
    for (auto &t : ans[n].points) {
        t.print();
    }
}