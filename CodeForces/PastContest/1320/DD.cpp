#include <bits/stdc++.h>

using namespace std;

char s[100010];

int main() {
    while(true){
    scanf("%s",s);
    int N = strlen(s);
    while(true) {
        bool find = false;
        for (int i=0;i+2<N;i++) {
            if (s[i] == '0' && s[i+1] == '1' && s[i+2] == '1') {
                swap(s[i], s[i+2]);
                find = true;
                break;
            }
        }
        if (!find) break;
    }
    printf("%s\n",s);
    }
}