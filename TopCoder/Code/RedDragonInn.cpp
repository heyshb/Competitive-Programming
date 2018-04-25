// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE   
#include <bits/stdc++.h> 
using namespace std;  
  
typedef long long LL;  
  
class RedDragonInn  
{  
        public:  
        int maxGold(int N, int X)  
        {  
        	int tmp = N * (X + 1) - 1;
        	return tmp * 2 + 1;
        }  
};  
  
// BEGIN CUT HERE  
int main()  
{  
        RedDragonInn ___test;  
        printf("%d\n",___test.maxGold(42,1234));
        return 0;  
}  
// END CUT HERE  
