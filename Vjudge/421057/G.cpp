#include <bits/stdc++.h>

using namespace std;

int T, x;

int fuck(int x) {
    int tx = x;
    if (x < 10) {
        return x - 1;
    }
    int ans = 9;
    int p = 10;
    int len = 2;
    while(p * 10 <= x) {
        ans += len * 10 - 1;
        p = p * 10;
        len++;
    }
    vector<int> digit;
    while(x) {
        digit.push_back(x % 10);
        x /= 10;
    }
    assert(digit.size() == len);
    reverse(digit.begin(), digit.end());
    int diff = 0;
    int sum = 0;
    bool have1 = false;
    bool allzero = true;
    for (int i=0;i<len;i++) {
        int delta = digit[i] - (i == 0 ? 1 : 0);
        if (delta > 0 && i < len - 1) diff++;
        if (i > 0 && i < len - 1 && digit[i] == 1) {
            have1 = true;
        }
        if (i > 0 && digit[i] > 0) allzero = false;
        sum += delta;
    }
    //printf("%d %d\n",diff,sum);
    if (allzero) {
        return fuck(tx - 1) + 1;
    } 
    ans += diff + sum;
    if (have1 && digit[0] > 1) ans--;
    return ans;
}

int main() {
    scanf("%d",&T);
    int TX = 0;
    while(T--) {
        scanf("%d",&x);
        int ans = fuck(x);
        printf("%d\n",ans);
    }
}