#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

struct Node {
    int mi, mi_idx;
};

int n, a[300010], b[300010];

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf("%d",&a[n + 1 - i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d",&b[n + 1 - i]);
    }
}