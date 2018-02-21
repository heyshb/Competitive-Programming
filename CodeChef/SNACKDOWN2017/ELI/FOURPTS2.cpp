#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
const double eps = 1e-8, PI = atan2(0, -1);
inline double sqr(double x) {
return x * x;
}
inline bool zero(double x) {
return (x > 0 ? x : -x) < eps;
}
inline int sgn(double x) {
 return (x > eps ? 1 : (x + eps < 0 ? -1 : 0));
  }
 struct point {
 double x, y;
 point(double x, double y):x(x), y(y) {}
 point() {}
bool operator == (const point &a) const {
 return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
 }
2 bool operator != (const point &a) const {
3 return sgn(x - a.x) != 0 || sgn(y - a.y) != 0;
4 }
5 bool operator < (const point &a) const {
6 return sgn(x - a.x) < 0 || sgn(x - a.x) == 0 && sgn(y - a.y) < 0;
7 }
8 point operator + (const point &a) const {
9 return point(x + a.x, y + a.y);
0 }
1 point operator - (const point &a) const {
2 return point(x - a.x, y - a.y);
3 }
4 point operator * (const double &a) const {
5 return point(x * a, y * a);
36 }
7 point operator / (const double &a) const {
8 return point(x / a, y / a);
9 }
0 double operator * (const point &a) const {
1 return x * a.y - y * a.x; //xmult
2 }
3 double operator ^ (const point &a) const {
4 return x * a.x + y * a.y; //dmult
5 }
6 double length() const {
7 return sqrt(sqr(x) + sqr(y));
48 }
9 point trunc(double a) const {
0 return (*this) * (a / length());
1 }
2 point rotate(double ang) const {
3 point p(sin(ang), cos(ang));
4 return point((*this) * p, (*this) ^ p);
5 }
56 point rotate(const point &a) const {
7 point p(-a.y, a.x);
8 p = p.trunc(1.0);
 return point((*this) * p, (*this) ^ p);
0 }
};
62 bool isConvex(int n, const point *p) {
63 int i, s[3] = {1, 1, 1};
64 for(i = 0; i < n && /*s[1] && */ s[0] | s[2]; i++)
65 s[sgn((p[(i + 1) % n] - p[i]) * (p[(i + 2) % n] - p[i])) + 1] = 0;
66 return /*s[1] && */ s[0] | s[2];
67 } //?????????????
68 bool insideConvex(const point &q, int n, const point *p) {
69 int i, s[3] = {1, 1, 1};
70 for(i = 0; i < n && /*s[1] && */ s[0] | s[2]; i++)
71 s[sgn((p[(i + 1) % n] - p[i]) * (q - p[i])) + 1] = 0;
72 return /*s[1] && */ s[0] | s[2];
73 } //??????????
74 inline bool dotsInline(const point &p1, const point &p2, const point &p3) {
75 return zero((p1 - p3) * (p2 - p3));
76 } //????
77 inline int decideSide(const point &p1, const point &p2, const point &l1, const point &l2\
78 ) {
79 return sgn((l1 - l2) * (p1 - l2)) * sgn((l1 - l2) * (p2 - l2));
80 } //? p1 ? p2, ?? l1-l2,-1 ?????,0 ?????,1 ????
81 inline bool dotOnlineIn(const point &p, const point &l1, const point &l2) {
82 return zero((p - l2) * (l1 - l2)) && (l1.x - p.x) * (l2.x - p.x) < eps && (l1.y - p.\
83 y) * (l2.y - p.y) < eps;
84 } //????????????
85 inline bool parallel(const point &u1, const point &u2, const point &v1, const point &v2)\
86 {
87 return zero((u1 - u2) * (v1 - v2));
88 } //?????
89 inline bool perpendicular(const point &u1, const point &u2, const point &v1, const point\
90 &v2) {
91 return zero((u1 - u2) ^ (v1 - v2));
92 } //?????
93 inline bool intersectIn(const point &u1, const point &u2, const point &v1, const point &\
94 v2) {
95 if(!dotsInline(u1, u2, v1) || !dotsInline(u1, u2, v2))
96 return decideSide(u1, u2, v1, v2) != 1 && decideSide(v1, v2, u1, u2) != 1;
97 else
98 return dotOnlineIn(u1, v1, v2) || dotOnlineIn(u2, v1, v2) || dotOnlineIn(v1, u1,\
99 u2) || dotOnlineIn(v2, u1, u2);
100 } //??????, ?????????
101 inline bool intersectEx(const point &u1, const point &u2, const point &v1, const point &\
102 v2) {
103 return decideSide(u1, u2, v1, v2) < 0 && decideSide(v1, v2, u1, u2) < 0;
104 } //??????, ??????????
105 inline bool insidePolygon(const point &q, int n, const point *p, bool onEdge = true) {
106 if(dotOnlineIn(q, p[n - 1], p[0])) return onEdge;
107 for(int i = 0; i + 1 < n; i++) if(dotOnlineIn(q, p[i], p[i + 1])) return onEdge;
108 #define getq(i) Q[(sgn(p[i].x-q.x)>0)<<1|sgn(p[i].y-q.y)>0]
109 #define difq(a,b,i,j) (a==b?0:(a==((b+1)&3)?1:(a==((b+3)&3)?-1:(sgn((p[i]-q)*(p[j]-q))<<\
Routine Library | Zhejiang University ICPC Team 21
1.4. GEO CHAPTER 1. ??
110 1))))
111 int Q[4] = {2, 1, 3, 0}, oq = getq(n-1), nq = getq(0), qua = difq(nq, oq, n - 1, 0);
112 oq = nq;
113 for(int i = 1; i < n; i++) {
114 nq = getq(i);
115 qua += difq(nq, oq, i - 1, i);
116 oq = nq;
117 }
118 return qua != 0; //?????, ??
119 /*point q1; int i = 0, cnt = 0; const double OFFSET = 1e6;//????
120 for(q1 = point(rand() + OFFSET, rand() + OFFSET);i < n;) for(i = cnt = 0;i < n && !d\
121 otsInline(q, q1, p[i]);i++) cnt += intersectEx(q, q1, p[i], p[(i + 1) % n]);
122 return cnt & 1;*/ //?? rp ????
123 } //?????????
124 inline point intersection(const point &u1, const point &u2, const point &v1, const point\
125 &v2) {
126 return u1 + (u2 - u1) * (((u1 - v1) * (v1 - v2)) / ((u1 - u2) * (v1 - v2)));
127 } //??????, ???????
128 inline point ptoline(const point &p, const point &l1, const point &l2) {
129 point t = p;
130 t.x += l1.y - l2.y;
131 t.y += l2.x - l1.x;
132 return intersection(p, t, l1, l2);
133 } //????????, ?? l1 ???? l2
134 inline double disptoline(const point &p, const point &l1, const point &l2) {
135 return fabs((p - l2) * (l1 - l2)) / (l1 - l2).length();
136 } //??????, ?? l1 ???? l2
137 inline point ptoseg(const point &p, const point &l1, const point &l2) {
138 point t = p;
139 t.x += l1.y - l2.y;
140 t.y += l2.x - l1.x;
141 if(sgn((l1 - p) * (t - p)) * sgn((l2 - p) * (t - p)) > 0)
142 return (p - l1).length() < (p - l2).length() ? l1 : l2;
143 else
144 return intersection(p, t, l1, l2);
145 } //????????, ?? l1 ???? l2
146 inline double disptoseg(const point &p, const point &l1, const point &l2) {
147 point t = point(l1.y - l2.y, l2.x - l1.x);
148 if(sgn((l1 - p) * t) * sgn((l2 - p) * t) > 0)
149 return min((p - l1).length(), (p - l2).length());
150 else
151 return disptoline(p, l1, l2);
152 } //??????, ?? l1 ???? l2
153 double fermentpoint(int m, point p[]) {
154 point u(0, 0), v;
155 double step = 0, nowbest = 0, now;
156 for(int i = 0; i < m; ++i) u = u + p[i];
157 u = u / m;
158 for(int i = 0; i < m; ++i) nowbest += (u - p[i]).length();
159 for(step = u.x + u.y; step > 1e-10; step *= 0.97) //??????, ????
22 November 4, 2015
CHAPTER 1. ?? 1.4. GEO
160 for(int i = -1; i <= 1; i++)
161 for(int j = -1; j <= 1; j++) {
162 v = u + point(i, j) * step;
163 now = 0;
164 for(int i = 0; i < m; ++i) now += (v - p[i]).length();
165 if(now < nowbest) {
166 nowbest = now;
167 u = v;
168 }
169 }
170 return nowbest;
171 } //????????
