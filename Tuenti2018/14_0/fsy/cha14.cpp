#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> void mini(T &l, T r) {l = min(l, r);}
template <class T> void maxi(T &l, T r) {l = max(l, r);}

template <class T> using Tree = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(bool a) {
  return a ? "T" : "F";
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;

const int MaxVertices = 4100;
const int MaxTriangles = 4100 << 2;
//const int n_MaxPoints = 10; // for the test programm
const ld EPSILON = 1e-8;//0.000001;
const ld inf = 1e40;

#define X first
#define Y second

struct ITRIANGLE {
  int p1, p2, p3;
};

string to_string(ITRIANGLE a) {
  return "(" + to_string(a.p1) + "," + to_string(a.p2) + "," + to_string(a.p3) + ")";
}

struct IEDGE {
  int p1, p2;
};

struct XYZ {
  ld x, y, z;

  XYZ(ld _x = 0, ld _y = 0) {
    x = _x;
    y = _y;
    z = 0;
  }

  XYZ operator-(const XYZ &a) const {
    return XYZ{x - a.x, y - a.y};
  }

  XYZ operator+(const XYZ &a) const {
    return XYZ{x + a.x, y + a.y};
  }

  ld operator*(const XYZ &a) const {
    return x * a.x + y * a.y;
  }

  ld operator%(const XYZ &a) const {
    return x * a.y - y * a.x;
  }

  ld abs() {
    return sqrt(x * x + y * y);
  }

};

ld dis(XYZ a, XYZ b) {
  return (a - b).abs();
}

int cmp(ld a, ld b) {
  if (fabs(a - b) < EPSILON) return 0;
  if (a > b) return 1;
  return -1;
}

bool samedir(XYZ a, XYZ b, XYZ x, XYZ y) {
  return cmp((b - a) * (y - x), 0) >= 0;
}

bool in(XYZ a, XYZ b, XYZ c) {
  return samedir(a, b, a, c) && samedir(b, a, b, c);
}

////////////////////////////////////////////////////////////////////////
// CircumCircle() :
//   Return true if a point (xp,yp) is inside the circumcircle made up
//   of the points (x1,y1), (x2,y2), (x3,y3)
//   The circumcircle centre is returned in (xc,yc) and the radius r
//   Note : A point on the edge is inside the circumcircle
////////////////////////////////////////////////////////////////////////

int CircumCircle(ld xp, ld yp, ld x1, ld y1, ld x2, 
    ld y2, ld x3, ld y3, ld &xc, ld &yc, ld &r){
  ld m1, m2, mx1, mx2, my1, my2;
  ld dx, dy, rsqr, drsqr;

  /* Check for coincident points */
  if(abs(y1 - y2) < EPSILON && abs(y2 - y3) < EPSILON)
    return(false);
  if(abs(y2-y1) < EPSILON){ 
    m2 = - (x3 - x2) / (y3 - y2);
    mx2 = (x2 + x3) / 2.0;
    my2 = (y2 + y3) / 2.0;
    xc = (x2 + x1) / 2.0;
    yc = m2 * (xc - mx2) + my2;
  }else if(abs(y3 - y2) < EPSILON){ 
    m1 = - (x2 - x1) / (y2 - y1);
    mx1 = (x1 + x2) / 2.0;
    my1 = (y1 + y2) / 2.0;
    xc = (x3 + x2) / 2.0;
    yc = m1 * (xc - mx1) + my1;
  }else{
    m1 = - (x2 - x1) / (y2 - y1); 
    m2 = - (x3 - x2) / (y3 - y2); 
    mx1 = (x1 + x2) / 2.0; 
    mx2 = (x2 + x3) / 2.0;
    my1 = (y1 + y2) / 2.0;
    my2 = (y2 + y3) / 2.0;
    xc = (m1 * mx1 - m2 * mx2 + my2 - my1) / (m1 - m2); 
    yc = m1 * (xc - mx1) + my1; 
  }
  dx = x2 - xc;
  dy = y2 - yc;
  rsqr = dx * dx + dy * dy;
  r = sqrt(rsqr); 
  dx = xp - xc;
  dy = yp - yc;
  drsqr = dx * dx + dy * dy;
  return((drsqr <= rsqr) ? true : false);
}
///////////////////////////////////////////////////////////////////////////////
// Triangulate() :
//   Triangulation subroutine
//   Takes as input NV vertices in array pxyz
//   Returned is a list of ntri triangular faces in the array v
//   These triangles are arranged in a consistent clockwise order.
//   The triangle array 'v' should be malloced to 3 * nv
//   The vertex array pxyz must be big enough to hold 3 more points
//   The vertex array must be sorted in increasing x values say
//
//   qsort(p,nv,sizeof(XYZ),XYZCompare);
///////////////////////////////////////////////////////////////////////////////

int Triangulate(int nv, XYZ pxyz[], ITRIANGLE v[], int &ntri){
  int *complete = NULL;
  IEDGE *edges = NULL; 
  IEDGE *p_EdgeTemp;
  int nedge = 0;
  int trimax = nv * 4, emax = nv * 4;
  int status = 0;
  int inside;
  int i, j, k;
  ld xp, yp, x1, y1, x2, y2, x3, y3, xc, yc, r;
  ld xmin, xmax, ymin, ymax, xmid, ymid;
  ld dx, dy, dmax; 

  /* Allocate memory for the completeness list, flag for each triangle */
  trimax = 4 * nv;
  complete = new int[trimax];
  /* Allocate memory for the edge list */
  edges = new IEDGE[emax];
  /*
     Find the maximum and minimum vertex bounds.
     This is to allow calculation of the bounding triangle
   */
  xmin = pxyz[0].x;
  ymin = pxyz[0].y;
  xmax = xmin;
  ymax = ymin;
  for(i = 1; i < nv; i++){
    if (pxyz[i].x < xmin) xmin = pxyz[i].x;
    if (pxyz[i].x > xmax) xmax = pxyz[i].x;
    if (pxyz[i].y < ymin) ymin = pxyz[i].y;
    if (pxyz[i].y > ymax) ymax = pxyz[i].y;
  }
  dx = xmax - xmin;
  dy = ymax - ymin;
  dmax = (dx > dy) ? dx : dy;
  xmid = (xmax + xmin) / 2.0;
  ymid = (ymax + ymin) / 2.0;
  /*
     Set up the supertriangle
     his is a triangle which encompasses all the sample points.
     The supertriangle coordinates are added to the end of the
     vertex list. The supertriangle is the first triangle in
     the triangle list.
   */
  pxyz[nv+0].x = xmid - 20 * dmax;
  pxyz[nv+0].y = ymid - dmax;
  pxyz[nv+1].x = xmid;
  pxyz[nv+1].y = ymid + 20 * dmax;
  pxyz[nv+2].x = xmid + 20 * dmax;
  pxyz[nv+2].y = ymid - dmax;
  v[0].p1 = nv;
  v[0].p2 = nv+1;
  v[0].p3 = nv+2;
  complete[0] = false;
  ntri = 1;
  /*
     Include each point one at a time into the existing mesh
   */
  for(i = 0; i < nv; i++){
    xp = pxyz[i].x;
    yp = pxyz[i].y;
    nedge = 0;
    /*
       Set up the edge buffer.
       If the point (xp,yp) lies inside the circumcircle then the
       three edges of that triangle are added to the edge buffer
       and that triangle is removed.
     */
    for(j = 0; j < ntri; j++){
      if(complete[j])
        continue;
      x1 = pxyz[v[j].p1].x;
      y1 = pxyz[v[j].p1].y;
      x2 = pxyz[v[j].p2].x;
      y2 = pxyz[v[j].p2].y;
      x3 = pxyz[v[j].p3].x;
      y3 = pxyz[v[j].p3].y;
      inside = CircumCircle(xp, yp, x1, y1, x2, y2, x3, y3, xc, yc, r);
      //if (xc + r < xp)
      if (cmp(xc + r, xp) < 0)
        // Suggested
        // if (xc + r + EPSILON < xp)
        complete[j] = true;
      if(inside){
        /* Check that we haven't exceeded the edge list size */
        if(nedge + 3 >= emax){
          emax += 100;
          p_EdgeTemp = new IEDGE[emax];
          for (int i = 0; i < nedge; i++) { // Fix by John Bowman
            p_EdgeTemp[i] = edges[i];   
          }
          delete []edges;
          edges = p_EdgeTemp;
        }
        edges[nedge+0].p1 = v[j].p1;
        edges[nedge+0].p2 = v[j].p2;
        edges[nedge+1].p1 = v[j].p2;
        edges[nedge+1].p2 = v[j].p3;
        edges[nedge+2].p1 = v[j].p3;
        edges[nedge+2].p2 = v[j].p1;
        nedge += 3;
        v[j] = v[ntri-1];
        complete[j] = complete[ntri-1];
        ntri--;
        j--;
      }
    }
    /*
       Tag multiple edges
Note: if all triangles are specified anticlockwise then all
interior edges are opposite pointing in direction.
     */
    for(j = 0; j < nedge - 1; j++){
      for(k = j + 1; k < nedge; k++){
        if((edges[j].p1 == edges[k].p2) && (edges[j].p2 == edges[k].p1)){
          edges[j].p1 = -1;
          edges[j].p2 = -1;
          edges[k].p1 = -1;
          edges[k].p2 = -1;
        }
        /* Shouldn't need the following, see note above */
        if((edges[j].p1 == edges[k].p1) && (edges[j].p2 == edges[k].p2)){
          edges[j].p1 = -1;
          edges[j].p2 = -1;
          edges[k].p1 = -1;
          edges[k].p2 = -1;
        }
      }
    }
    /*
       Form new triangles for the current point
       Skipping over any tagged edges.
       All edges are arranged in clockwise order.
     */
    for(j = 0; j < nedge; j++) {
      if(edges[j].p1 < 0 || edges[j].p2 < 0)
        continue;
      v[ntri].p1 = edges[j].p1;
      v[ntri].p2 = edges[j].p2;
      v[ntri].p3 = i;
      complete[ntri] = false;
      ntri++;
    }
  }
  /*
     Remove triangles with supertriangle vertices
     These are triangles which have a vertex number greater than nv
   */
  for(i = 0; i < ntri; i++) {
    if(v[i].p1 >= nv || v[i].p2 >= nv || v[i].p3 >= nv) {
      v[i] = v[ntri-1];
      ntri--;
      i--;
    }
  }
  delete[] edges;
  delete[] complete;
  return 0;
} 

void randomize(){
  srand((time_t) time(NULL));  
}

int random(int n){
  return rand()%n; 
}

int XYZCompare(const void *v1, const void *v2){
  XYZ *p1, *p2;

  p1 = (XYZ*)v1;
  p2 = (XYZ*)v2;
  if(p1->x < p2->x)
    return(-1);
  else if(p1->x > p2->x)
    return(1);
  else
    return(0);
}

void outputtriangle(int &nv, XYZ p[], ITRIANGLE v[], int &ntri){
  int X, Y, i = 0;
  ld x, y;

  for(int i = 0; i < ntri; i++){// replace cout by a compatible lineto to trace
    cout<<(int)p[v[i].p1].x<<" "<< (int)p[v[i].p1].y<<" "<< (int)p[v[i].p2].x
      <<" "<< (int)p[v[i].p2].y<<"\n";
    cout<<(int)p[v[i].p2].x<<" "<< (int)p[v[i].p2].y<<" "<< (int)p[v[i].p3].x
      <<" "<< (int)p[v[i].p3].y<<"\n";
    cout<<(int)p[v[i].p3].x<<" "<< (int)p[v[i].p3].y<<" "<< (int)p[v[i].p1].x
      <<" "<< (int)p[v[i].p1].y<<"\n";
  }
}

int n;
XYZ p[MaxVertices + 10];
ITRIANGLE v[40 * MaxVertices];
XYZ pfrom, pto;
XYZ cir_o[40 * MaxVertices];
map < pair <int, int>, vector <int> > mp;

XYZ calc(int i) {
  vector <int> vv = {v[i].p1, v[i].p2, v[i].p3};

  ld xc, yc, r;
  CircumCircle(0, 0, p[vv[0]].x, p[vv[0]].y, p[vv[1]].x, p[vv[1]].y, p[vv[2]].x, p[vv[2]].y, xc, yc, r);
  return XYZ{xc, yc};
}

bool check(XYZ a, XYZ b, XYZ c) {
  return cmp(dis(a, b), dis(a, c)) == 0;
}

void clear() {
  memset(p, 0, sizeof(p));
  memset(v, 0, sizeof(v));
  memset(cir_o, 0, sizeof(cir_o));
  mp.clear();
}

ld read() {
  ll x, y;
  scanf("%lld/%lld", &x, &y);
  return ld(x) / y;
}

void add(ITRIANGLE tri, int x) {
  vector <int> v = {tri.p1, tri.p2, tri.p3};
  sort(v.begin(), v.end());
  tri.p1 = v[0];
  tri.p2 = v[1];
  tri.p3 = v[2];
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      mp[{v[i], v[j]}].push_back(x);
    }
  }
}

const int N = MaxVertices * 40 + 10;

bool fl = 0;

struct Graph {
  vector < pair <int, ld> > e[N];
  ld dis[N];
  int vis[N];
  int n;
  void init(int _n) {
    n = _n;
    for (int i = 0; i < N; ++i) e[i].clear();
    fill_n(dis, N, 0);
    fill_n(vis, N, 0);
  }

  void add(int x, int y, ld v) {
    if (fl)
      debug(x, y, v);
    e[x].emplace_back(y, v);
    e[y].emplace_back(x, v);
  }

  ld dij(int s, int t) {
    //debug(s, t);
    fill_n(dis, n, inf);
    fill_n(vis, n, 0);
    priority_queue < pair <ld, int> > pq;
    dis[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      int v = t.Y;
      if (vis[v]) continue;
      //debug(v, dis[v]);
      vis[v] = 1;
      for (auto ee : e[v]) {
        int u = ee.X;
        if (cmp(dis[u], dis[v] + ee.Y) > 0) {
          dis[u] = dis[v] + ee.Y;
          pq.emplace(-dis[u], u);
        }
      }
    }
    return dis[t];
  }

} G;

void run() {
  int T;
  cin >> T;
  for (int _ = 1; _ <= T; ++_) {
    cin >> n;
    clear();
    if (_ == 104) fl = 0;
    else fl = 0;
    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    qsort(p, n, sizeof(XYZ), XYZCompare);

    if (fl) {
      for (int i = 0; i < n; ++i) {
        debug(p[i].x, p[i].y, i);
      }
    }
    int ntri;
    Triangulate(n, p, v, ntri);
    //outputtriangle(n, p, v, ntri); // use this fonction to trace the mesh (via 
    ld r = read();
    pfrom.x = read();
    pfrom.y = read();
    pto.x = read();
    pto.y = read();

    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      if (cmp(dis(pfrom, p[i]), r) < 0) ok = 0;
    }

    for (int i = 0; i < n; ++i) {
      if (cmp(dis(pto, p[i]), r) < 0) ok = 0;
    }
    if (!ok) {
      printf("Case #%d: IMPOSSIBLE\n", _);
      continue;
    }

    for (int i = 0; i < ntri; ++i) {
      add(v[i], i);
      if (fl)
        debug(v[i], i);
    }
    
    if (fl)
      for (auto kv : mp) {
        debug(kv.X);
        debug(kv.Y);
      }

    for (int i = 0; i < ntri; ++i) {
      cir_o[i] = calc(i);
    }

    if (fl)
      for (int i = 0; i < ntri; ++i) debug(i, cir_o[i].x, cir_o[i].y);

    int from = ntri + 1, to = ntri + 2;

    G.init(to + 1);

    vector <XYZ> pts = {pfrom, pto};
    vector <int> ptsid = {from, to};

    for (auto &kv : mp) {
      auto p1 = p[kv.X.X], p2 = p[kv.X.Y];
      if (cmp(dis(p1, p2), 2 * r) >= 0) {
        if (kv.Y.size() >= 2) {
          G.add(kv.Y[0], kv.Y[1], dis(cir_o[kv.Y[0]], cir_o[kv.Y[1]]));

          for (int _ = 0; _ < 2; ++_) {
            auto xx = pts[_];
            auto idxx = ptsid[_];
            if (check(xx, p1, p2) && in(cir_o[kv.Y[0]], cir_o[kv.Y[1]], xx)) {
              G.add(idxx, kv.Y[0], dis(xx, cir_o[kv.Y[0]]));
              G.add(idxx, kv.Y[1], dis(xx, cir_o[kv.Y[1]]));
            }
          }

        } else if (kv.Y.size() == 1) {
          for (int _ = 0; _ < 2; ++_) {
            auto xx = pts[_];
            auto idxx = ptsid[_];
            if (check(xx, p1, p2) && samedir(cir_o[kv.Y[0]], p1, cir_o[kv.Y[0]], xx)) {
              G.add(idxx, kv.Y[0], dis(xx, cir_o[kv.Y[0]]));
            }
          }
        }
      } else {
        if (kv.Y.size() >= 2) {
          for (int _ = 0; _ < 2; ++_) {
            auto xx = pts[_];
            auto idxx = ptsid[_];
            if (check(xx, p1, p2) && in(cir_o[kv.Y[0]], cir_o[kv.Y[1]], xx)) {
              if (samedir(cir_o[kv.Y[0]], cir_o[kv.Y[1]], xx, p1)) {
                G.add(idxx, kv.Y[0], dis(xx, cir_o[kv.Y[0]]));
              } else {
                G.add(idxx, kv.Y[1], dis(xx, cir_o[kv.Y[1]]));
              }
            }
          }

        } else if (kv.Y.size() == 1) {
          for (int _ = 0; _ < 2; ++_) {
            auto xx = pts[_];
            auto idxx = ptsid[_];
            if (check(xx, p1, p2)) {
              if (samedir(cir_o[kv.Y[0]], p1, cir_o[kv.Y[0]], xx) && samedir(xx, p1, cir_o[kv.Y[0]], p1)) {
                G.add(idxx, kv.Y[0], dis(xx, cir_o[kv.Y[0]]));
              }
            }
          }
        }
      }
    }


    auto ans = G.dij(from, to);
    if (cmp(ans, inf) >= 0) {
      printf("Case #%d: IMPOSSIBLE\n", _);
    } else {
      printf("Case #%d: %.3Lf\n", _, ans);
    }

  }
}

int main() {
  //freopen("14_final_test.in","r",stdin);
  //freopen("fsy.out","w",stdout);
  freopen("14_submit.in","r",stdin);
  freopen("14.submit.out","w",stdout);
  run();
  return 0;
}
