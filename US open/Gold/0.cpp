#include<bits/stdc++.h>
using namespace std;
int a[111111];
int n = 10;
int gao(){
	random_shuffle(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' '; cout << endl;
	int flag = 0, cnt = 0;
	while (!flag){
		flag = 1;
		cnt++;
		for (int i = 1; i < n; i++)
			if (a[i+1] < a[i])
				swap(a[i], a[i+1]);
		for (int i = n-1; i >= 1; i--)
			if (a[i+1] < a[i])
				swap(a[i], a[i+1]);
		for (int i = 1; i < n; i++)
			if (a[i+1] < a[i])
				flag = 0;
	}
	cout << cnt << endl;
	return cnt;
}
int main(){
   // freopen("lemonade.in", "r", stdin);
   // freopen("lemonade.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    //cin >> n;
    for (int i = 1; i <= n; i++)
    	a[i] = i;
    srand(time(NULL));
    for (int i = 1; i <= 10; i++)
    	gao();
	return 0;
}