#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
char s[1000010];
int a[1000010];
int sum[1000010];

int main() {
    scanf("%d",&N);
    scanf("%s", s + 1);
    vector<int>zero;
    zero.push_back(0);
    for (int i=1;i<=N;i++) {
        a[i] = (s[i] == '(' ? 1 : -1);
        sum[i] = sum[i - 1] + a[i];
        if (sum[i] == 0) {
            zero.push_back(i);
        }
    }
    if (sum[N] != 0) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int i=0;i<zero.size()-1;i++) {
        int p = zero[i];
        if (sum[p + 1] > 0) continue;
        ans += zero[i + 1] - zero[i];
    }
    printf("%d\n",ans);
}