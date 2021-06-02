#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[1010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int N;
        scanf("%d",&N);
        scanf("%s",s);
        sort(s,s+N);
        printf("%s\n",s);
    }
}