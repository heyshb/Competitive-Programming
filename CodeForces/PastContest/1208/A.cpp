#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,a,b,T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&a,&b,&N);
        int v[3] = {a,b,a^b};
        printf("%d\n",v[N%3]);
    }    
}