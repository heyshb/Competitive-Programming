#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d",&N);
    for (int i=0;i<N;i++) {
        printf("%d %d\n",i*2%N + 1, (i*2+1)%N + 1);
    }
}