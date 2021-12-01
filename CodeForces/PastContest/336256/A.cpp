#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n;

int main() {
    scanf("%d",&n);
    vector<int> pos, neg;
    char ch[2];
    for (int i = 1; i <= n; i++) {
        scanf("%s", ch);
        int val;
        scanf("%d",&val);
        if (ch[0] == '+') pos.push_back(val);
        else neg.push_back(val);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    LL sum = 0;
    int node = -1;
    LL m = neg.size();
    LL mp = pos.size();
    for (int i = 0; i < pos.size(); i++) {
        while(node + 1 < m && neg[node + 1] < pos[i]) node++;
        sum += node + 1;
    }
    printf("%.10lf\n",1.0 * sum / (m * mp));
}