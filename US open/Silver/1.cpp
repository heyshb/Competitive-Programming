#include<bits/stdc++.h>
using namespace std;
pair<int, int> a[111111];
int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int n;
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, a[i].second - i);
    cout << ans + 1 << endl;
	return 0;
}