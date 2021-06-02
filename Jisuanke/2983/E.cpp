#include <bits/stdc++.h>

using namespace std;

char s[1000010];
int sum[1000010],mi[1000010];
int N;

int main() {
    scanf("%s",s + 1);
    N = strlen(s + 1);
    mi[0] = N + 1;
    for (int i=1;i<=N;i++) {
        sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : - 1);
        mi[i] = min(mi[i - 1], sum[i]);
    }
    for (int i=N;i>=1;i--) {
        int num = N - i;
        if (s[i] == ')' && sum[i] + 2 >= -num && sum[i] + 2 <= num) {
            for (int j=1;j<i;j++) {
                printf("%c",s[j]);
            }
            putchar('(');
            int now = sum[i] + 2;
            for (int k=1;k<=now;k++) putchar(')');
            for (int k=1;k<=(num-now)/2;k++) printf("()");
            if ((num-now)%2) putchar(')');
            puts("");
            break;
        }
    }
    for (int i=N;i>=1;i--) {
        int num = N - i;
        if (s[i] == '(' && sum[i] - 2 >= 0 && sum[i] - 2 <= num) {
            for (int j=1;j<i;j++) {
                printf("%c",s[j]);
            }
            putchar(')');
            int now = sum[i] - 2;
            assert(now%2==num%2);
            for (int i=1;i<=(num-now)/2;i++)putchar('(');
            for (int i=1;i<=(num+now)/2;i++)putchar(')');
            puts("");
            break;
        }
    }
}
/*
(()())()((()))()
(()())()((())())
(()())()(()(()))
 */