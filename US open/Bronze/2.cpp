#include<bits/stdc++.h>
using namespace std;
int vis[111], f[111], a[111];
int main(){
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    int flag = 0;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    	if (a[i] == 1)
    		flag = 1;
	}
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        f[y] = x;
        vis[x] = y;
    }
    if (flag == 0){
	    for (int i = n, j = m; i >= 1; i--){
	        if (f[i] == 0){
	            if (j && vis[a[j]] == 0){
	                f[i] = a[j];
	                vis[a[j]] = i;
	                j--;
	            }
	        }
	        else{
	            if (j && f[i] == a[j])
	                j--;
	        }
	    }
		if (vis[1])
		    cout << vis[1] << endl;
		else
		    for (int i = 1; i <= n; i++)
		        if (f[i] == 0){
		            cout << i << endl;
		            return 0;
		        }
	}
    else{
    	for (int i = 1, j = 1; i <= n; i++){
            if (f[i] == 0){
                if (j <= m && vis[a[j]] == 0){
                    f[i] = a[j];
                    vis[a[j]] = i;
                    j++;
                }
            }
            else{
                if (j <= m && f[i] == a[j])
                    j++;
            }
        }
		if (vis[1])
		    cout << vis[1] << endl;
	}
    
    /*
    int j = m;
    for (int i = n; i >= 1; i--){
        if (j && a[j] == 1) break;
        if (f[i] == 0){
            if (j && vis[a[j]] == 0){
                f[i] = a[j];
                vis[a[j]] = i;
                j--;
            }
        }
        else{
            if (j && f[i] == a[j])
                j--;
        }
    }
    if (j && a[j] == 1){
        j = 1;
        for (int i = 1; i <= n; i++){
            if (j <= m && a[j] == 1) break;
            if (f[i] == 0){
                if (j <= m && vis[a[j]] == 0){
                    f[i] = a[j];
                    vis[a[j]] = i;
                    j++;
                }
            }
            else{
                if (j <= m && f[i] == a[j])
                    j++;
            }
        }
    }*/
	return 0;
}
