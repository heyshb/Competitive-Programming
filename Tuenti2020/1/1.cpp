#include <bits/stdc++.h>

using namespace std;

int main() {
    int Cases;
    scanf("%d",&Cases);
    for (int T=1;T<=Cases;T++) {
        char s1[5], s2[5];
        scanf("%s",s1);
        scanf("%s",s2);
        char ans = '-';
        if (s1[0] != s2[0]) {
            int sum = int('R') + 'S' + 'P' - s1[0] - s2[0];
            if (sum == 'R') {
                ans = 'S';
            } else if (sum == 'S') {
                ans = 'P';
            } else {
                ans = 'R';
            }
        }
        printf("Case #%d: %c\n",T, ans);
    }
}