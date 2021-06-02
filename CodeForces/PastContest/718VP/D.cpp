#include <bits/stdc++.h>

using namespace std;

const int N = 40;

int n, m;
int a[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool in(int x, int y) {
  return x < n && x >= 0 && y < m && y >= 0;
}

int get(int x, int y) {
  return x * m + y;
}

struct Gauss {
  static const int N = 910;
  int e[N][N], x[N];
  int pos[N];
  void init(int n, int m) {
    for (int i = 0; i < n; ++i) for (int j = 0; j <= m; ++j) e[i][j] = 0;
    memset(pos, 0, sizeof(pos));
    memset(x, 0, sizeof(x));
  }
  void setmatrix(int x, int y) {
    int id = get(x, y);
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (in(nx, ny)) {
        e[get(nx, ny)][id] = 1;
      }
    }
    e[id][id] = 2;
  }
  int solve(int n, int m) {
    int r = 0;
    for (int c = 0, i, j, k; c <= m && r < n; ++c) {
      for (i = k = r; i < n; ++i)
        if (e[i][c] > e[k][c]) k = i;
      if (k != r) for (j = c; j <= m; ++j) swap(e[k][j], e[r][j]);
      if (e[r][c] == 0) continue;
      pos[r] = c;
      if (e[r][c] == 2) {
        for (j = c; j <= m; ++j) e[r][j] = e[r][j] * 2 % 3;
      }
      for (i = r + 1; i < n; ++i) {
        if (e[i][c] == 1) {
          for (int j = c; j <= m; ++j) e[i][j] = (e[i][j] + 3 - e[r][j]) % 3;
        }
        else if (e[i][c] == 2) {
          for (int j = c; j <= m; ++j) e[i][j] = (e[i][j] + e[r][j]) % 3;
        }
      }
      ++r;
    }
    if (r > 0 && pos[r - 1] == m) return -1;
    for (int i = 0; i < m; ++i) x[i] = 0;
    for (int i = r - 1; i >= 0; --i) {
      int c = pos[i];
      x[c] = e[i][m] * e[i][c] % 3;
      for (int j = 0; j < i; ++j) e[j][m] = (e[j][m] + 3 - e[j][c] * x[c]) % 3;
    }
    return r;
  }
  void print(int n, int m) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) printf("%d ", e[i][j]); puts("");
    }
  }
} gauss;

void print(int x, int y, int c) {
  while (c--) {
    printf("%d %d\n", x + 1, y + 1);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        scanf("%d", a[i] + j);
    }
    gauss.init(n * m, n * m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int id = get(i, j);
        gauss.setmatrix(i, j);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int id = get(i, j);
        gauss.e[id][n * m] = (3 - a[i][j]) % 3;
      }
    }
    //gauss.print(n * m, n * m);
    gauss.solve(n * m, n * m);
    //gauss.print(n * m, n * m);
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
      ans += gauss.x[i];
    }
    printf("%d\n", ans);
    for (int i = 0; i < n * m; ++i) {
      print(i / m, i % m, gauss.x[i]);
    }
  }
  return 0;
}
