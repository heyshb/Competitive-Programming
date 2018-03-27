#include<bits/stdc++.h>
using namespace std;
int a[111111];
int main(){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int n;
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 1; i++)
        if (a[n - i] < i){
            cout << i << endl;
            return 0;
        }
    cout << n << endl;
	return 0;
}