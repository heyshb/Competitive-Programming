#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int T, N;
int a[300010];
bool vis[300010];
bool pre_vis[300010];
char ans[300010];

int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) {
            vis[i] = false;
        }
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            vis[a[i]] = true;
        }
        pre_vis[1] = vis[1];
        for (int i=2;i<=N;i++) {
            pre_vis[i] = (pre_vis[i - 1] && vis[i]);
        }
        multiset<int>s;
        for (int i = 1; i <= N; i++) {
            s.insert(a[i]);
        }
        int n1 = 1, n2 = N;
        for (int i = 1; i < N; i++) {
            if (*s.begin() == i) {
                ans[N + 1 - i] = '1';
                if (a[n1] == i) {
                    n1++;
                    s.erase(s.find(i));
                } else if (a[n2] == i) {
                    n2--;
                    s.erase(s.find(i));
                }
            }
            else {
                for (int j=i;j<N;j++) ans[N + 1 - j] = '0'; 
                break;
            }
        }
        ans[1] = pre_vis[N] ? '1' : '0';
        ans[N + 1] = 0;
        printf("%s\n",ans + 1);
    }
}