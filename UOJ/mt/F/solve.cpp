#include <bits/stdc++.h>

using namespace std;

#define N 1000
int a[N];
int n;

int weight[] = {
    293309062,96701749,694916487,371591203,450903345,936470975,360036365,596019536,362870120,978299587,72615453,677215478,297218049,296795024,703206614,117310233,243106488,303113802,602459530,151925105,47183452,590812021,886995042,967943647,1040249104,802320701,554202194,839697519,607415572,770010993
};

int getans(int pos,int w){
        if (w==0) return 0;
        if (w&1) return getans(pos+1,w>>1)^weight[pos];
        return getans(pos+1,w>>1);
}

int main() {
    int tp;
    cin >> tp;
    if (tp == 1) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
                cin >> a[i];
        }
        int result = 0;
        for (int i = 1; i <= n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                        if (a[i] > a[j]) {
                                result += (i ^ j);
                        }
                }
        }
        cout << result << endl;
    } else {
        int t,w;
        std::cin>>t;
        for (;t;t--){
                std::cin>>w;
                std::cout<<getans(0,w)<<std::endl;
        }
    }
}