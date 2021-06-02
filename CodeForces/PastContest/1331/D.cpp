#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    char s[10];
    scanf("%s", s + 1);
    int N = strlen(s + 1);
    printf("%d\n", (s[N] - '0') % 2);
}