#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[1010];
int N, a[1010], sum[1010];
vector<int>ans, L, R;

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    for (int i=1;i<=N;i++) {
        if (s[i] == '(') {
            L.push_back(i);
        } else {
            R.push_back(i);
        }
    }
    int M = min(L.size(), R.size());
    reverse(R.begin(),R.end());
    bool find = false;
    for (int i=M-1;i>=0;i--) {
        if (L[i] < R[i]) {
            for (int j=0;j<=i;j++) {
                ans.push_back(L[j]);
                ans.push_back(R[j]);
            }
            find = true;
            break;
        }
    }
    if (!find) {
        puts("0");
        return 0;
    }
    puts("1");
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++) {
        printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
    }
}