#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

char s[10];
char tmp_s[10];
int n;

int calc(char c1, char c2) {
    if (tmp_s[n - 1] != '_' && tmp_s[n - 1] != c1) return 0;
    if (tmp_s[n] != '_' && tmp_s[n] != c2) return 0;
    tmp_s[n - 1] = c1;
    tmp_s[n] = c2;
    //printf("?? %c%c%c\n",tmp_s[1],tmp_s[2],tmp_s[3]);
    if (tmp_s[1] == '0') return 0;
    int ret = 1;
    for (int i = 1; i <= n - 2; i++) {
        if (tmp_s[i] == '_') {
            if (i == 1) ret *= 9;
            else {
                ret *= 10;
            }
        } 
    }
    return ret;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n == 1) {
        if (s[1] >= '1' && s[1] <= '9') puts("0");
        else puts("1");
        return 0;
    }
    int ans = 0;
    bool have_x = false;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'X') have_x = true;
    }
    for (char x = '0'; x <= (have_x ? '9' : '0'); x++) {
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'X') tmp_s[i] = x;
            else tmp_s[i] = s[i];
        }
        ans += calc('0', '0');
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'X') tmp_s[i] = x;
            else tmp_s[i] = s[i];
        }
        ans += calc('2', '5');
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'X') tmp_s[i] = x;
            else tmp_s[i] = s[i];
        }
        ans += calc('5', '0');
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'X') tmp_s[i] = x;
            else tmp_s[i] = s[i];
        }
        ans += calc('7', '5');
    }
    printf("%d\n",ans);
}