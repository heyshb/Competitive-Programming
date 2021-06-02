#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<char>s[1000010];
char tmp[1000010];

int main() {
    scanf("%d%d",&N,&M);
    for (int i=0;i<N;i++) {
        s[i].resize(M);
        scanf("%s",tmp);
        for (int j=0;j<M;j++) {
            s[i][j] = tmp[j];
        }
    }
}