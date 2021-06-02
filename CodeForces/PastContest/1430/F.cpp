#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N;
char s[100010];
vector<pii>seg;
pii stk[100010];
int top, lft[100010], rgt[100010];

int main() {
    scanf("%d",&N);
    scanf("%s", s + 1);
    s[0] = '0';
    for (int i=1;i<=N;i++) {
        if (s[i] == '1' && s[i - 1] == '0') {
            int len = 0;
            for (int j=i;j<=N && s[j] == '1';j++) {
                len++;
            }
            seg.push_back(pii(i, len));
            //printf("%d %d\n",i,len);
        }
    }
    LL ans = 0;
    top = 0;
    // prefix
    for (int id=0;id<seg.size();id++) {
        int bg = seg[id].first;
        int len = seg[id].second;
        for (int i=1;i<=len;i++) {
            int rg = -1e9;
            if (top == 0 || stk[1].second < i) {
                rg = bg;
            } else if (stk[top].second >= i) {
                rg = (bg - stk[top].first - stk[top].second + i);
            } else {
                int L = 1, R = top;
                while(L < R - 1) {
                    int mid = (L + R) / 2;
                    if (stk[mid].second >= i) {
                        L = mid;
                    } else {
                        R = mid;
                    }
                }
                rg = (bg  - stk[L].first - stk[L].second + i);
            }
            //printf("prefix %d %d %d\n",id,i,rg);
            if (i < len) ans += 1LL * i * rg;
            else lft[id] = rg;
        }
        while(top > 0 && stk[top].second <= len) top--;
        stk[++top] = seg[id];
    }
    top = 0;
    // suffix
    for (int id=seg.size()-1;id>=0;id--) {
        int bg = seg[id].first;
        int len = seg[id].second;
        for (int i=1;i<=len;i++) {
            int rg = -1e9;
            if (top == 0 || stk[1].second <= i) {
                rg = (N - (bg + len) + 2);
            } else if (stk[top].second > i) {
                rg = (stk[top].first - bg - len + i + 1);
            } else {
                int L = 1, R = top;
                while(L < R - 1) {
                    int mid = (L + R) / 2;
                    if (stk[mid].second > i) {
                        L = mid;
                    } else {
                        R = mid;
                    }
                }
                rg = (stk[L].first - bg - len + i + 1);
            }
            //printf("suffix %d %d %d\n",id,i,rg);
            if (i < len) ans += 1LL * i * rg;
            else rgt[id] = rg;
        }
        while(top > 0 && stk[top].second <= len) top--;
        stk[++top] = seg[id];
    }
    for (int id=0;id<seg.size();id++) {
        int len = seg[id].second;
        //printf("cnm %d %d %d\n",lft[id],rgt[id],len);
        ans += 1LL * lft[id] * rgt[id] * len;
        if (len > 2) {
            for (int j=1;j<=len-2;j++) {
                ans += 1LL * j * (len - 1 - j);
            }
        }
    }
    printf("%lld\n",ans);
}