#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[10010];

int ord(int L, int R) {
    if (L >= R - 1) return 0;
    int S = 0;
    for (int i = L; i <= R; i++) {
        if (s[i] == '(') S++;
        if (s[i] == ')') S--;
        if (S == 0) {
            if (i == R) return ord(L + 1, R - 1);
            //assert(s[i + 1] == '-' && s[i + 2] == '>');
            return max(ord(L, i) + 1, ord(i + 3, R));
            break;
        }
    }
    return 0;
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    printf("%d\n",ord(1, n));
}