#include <bits/stdc++.h>

using namespace std;

char s[10];
int cnt[100];

bool check(bool done2,int S) {
    if (done2 && S == 0) return true;
    int mi;
    for (int i=0;i<34;i++) {
        if (cnt[i]) {
            mi = i;
            break;
        }
    }
    
    if (!done2 && cnt[mi] >= 2) {
        cnt[mi] -= 2;
        bool ok = check(1, S - 2);
        cnt[mi] += 2;
        if (ok) return true;
    }
    if (cnt[mi] >= 3) {
        cnt[mi] -= 3;
        bool ok = check(done2, S - 3);
        cnt[mi] += 3;
        if (ok) return true;
    }
    if (mi < 27 && mi % 9 <= 6) {
        if (cnt[mi + 1] && cnt[mi + 2]) {
            for (int i=0;i<3;i++)cnt[mi+i]--;
            bool ok = check(done2, S - 3);
            for (int i=0;i<3;i++)cnt[mi+i]++;
            if (ok) return true;
        }
    }
    return false;
}

int trans() {
    int num = s[0] - '1';
    char tp = s[1];
    if (tp == 'm') return num;
    if (tp == 's') return num + 9;
    if (tp == 'p') return num + 18;
    return num + 27;
}

void print(int x) {
    if (x < 9) {
        printf("%dm",x + 1);
        return;
    }
    if (x < 18) {
        printf("%ds",x + 1 - 9);
        return;
    }
    if (x < 27) {
        printf("%dp",x + 1 - 18);
        return;
    }
    printf("%dz",x + 1 - 27);
}



int main() {
    while(scanf("%s",s) != EOF) {
        int t = trans();
        memset(cnt,0,sizeof(cnt));
        cnt[t]++;
        
        for (int i=2;i<=13;i++) {
            scanf("%s",s);
            int t = trans();
            cnt[t]++;
        }
        for (int i=0;i<34;i++) {
            if (cnt[i] == 4) continue;
            cnt[i]++;
            if (check(0,14)) {
                print(i);
                puts("");
            }
            cnt[i]--;
        }
    }
}