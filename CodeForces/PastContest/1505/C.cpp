#include <bits/stdc++.h>

using namespace std;

bool ok(int x) {
    return x == 1 || x == 2 || x == 3 || x == 5 || x == 8 || x == 13 || x == 21;
}

char s[110];

int main() {
    scanf("%s",s);
    int n = strlen(s);
    bool OK = true;
    for (int i=0;i<n;i++) {
        s[i] -= 'A';
        //printf("%d\n",s[i]);
    }
    for (int i=2;i<n;i++) {
        if (s[i] != (s[i - 1] + s[i - 2]) % 26) OK = false;
    }
    puts(OK ? "YES" : "NO");
}