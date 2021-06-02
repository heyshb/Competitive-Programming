#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,int> pli;

LL query(int t,int i,int j,int k) {
    printf("%d %d %d %d\n",t,i,j,k);
    fflush(stdout);
    LL ret; 
    scanf("%lld",&ret);
    return ret;
}

LL s[1010];
vector<pair<LL,int>> sr,sl;

int main() {
    int N;
    scanf("%d",&N);
    int nb = 2;
    for (int i=3;i<=N;i++) {
        if (query(2,1,nb,i) == -1) {
            nb = i;
        }
    }
    LL mx = 0;
    int midx = -1;
    for (int i=2;i<=N;i++) {
        if (i != nb) {
            LL tmp = query(1,1,nb,i);
            s[i] = tmp;
            if (tmp > mx) {
                mx = tmp;
                midx = i;
            }
        }
    }
    for (int i=2;i<=N;i++) {
        if (i != nb && i != midx) {
            if (query(2,1,midx,i) > 0) {
                sr.push_back(pli(s[i], i));
            } else {
                sl.push_back(pli(s[i], i));
            }
        }
    }
    sort(sl.begin(),sl.end());
    sort(sr.begin(),sr.end());
    reverse(sr.begin(),sr.end());
    printf("0 1 %d",nb);
    for (auto t:sl) {
        printf(" %d",t.second);
    }
    printf(" %d",midx);
    for (auto t:sr) {
        printf(" %d",t.second);
    }
    puts("");
    fflush(stdout);
}