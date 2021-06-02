#include <bits/stdc++.h>

using namespace std;

void print(bool flag, char ed = ' ') {
    if (flag) {
        printf("Ya");
    } else {
        printf("Tidak");
    }
    putchar(ed);
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int A,B,C,D;
        scanf("%d%d%d%d",&A,&B,&C,&D);
        bool large, small, pos, neg;
        large = (A || D);
        small = (B || C);
        pos = (A + B) % 2 == 0;
        neg = !pos;
        print(large && neg);
        print(small && neg);
        print(small && pos);
        print(large && pos, '\n');
    }
}