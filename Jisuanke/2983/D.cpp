#include <bits/stdc++.h>

using namespace std;

char s[5000010];
int K,N;
vector<int>pos[26];
int node[26];


int main() {
    scanf("%s",s);
    N = strlen(s);
    for (int i=0;i<N;i++) {
        pos[s[i] - 'a'].push_back(i);
        //printf("%d %d\n",s[i],i);
    }
    scanf("%d",&K);
    for (int i=0;i<26;i++) node[i] = 0;
    int now = -1;
    for (int i=1;i<=K;i++) {
        //puts("fuck");
        for (int j=0;j<26;j++) {
            while(node[j] < pos[j].size() && pos[j][node[j]] <= now) {
                node[j]++;
            }
            if (node[j] == pos[j].size()) continue;
            if (pos[j][node[j]] >= N - (K - i)) continue;
            now = pos[j][node[j]];
            putchar('a' + j);
            break;
        }
    }
}