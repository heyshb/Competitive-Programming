// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#line 7 "Deadfish.cpp"  
#include <bits/stdc++.h> 
using namespace std;  
  
typedef long long LL;  

queue<int>q;
const int MX = 1000000;
const int INF = 1e9;
int d[2*MX + 10];
  
class Deadfish  
{  
        public:  
        
        int st(int x)
        {
        	bool neg = false;
        	if (x < 0)
        	{
        		neg = true;
        		x = -x;
			}
        	vector<int>digit;
        	int xx = x;
        	do{
        		digit.push_back(xx%10);
        		xx/=10;
			}while(xx);
			sort(digit.begin(),digit.end());
			reverse(digit.begin(),digit.end());
			int ret = 0;
			for (int i=0;i<digit.size();i++)
				ret = ret * 10 + digit[i];
			if (neg) return -ret;
			else return ret;
		}
        
        int shortestCode(int N)  
        {  
        	for (int i=0;i<=2*MX;i++)d[i] = INF;
        	d[MX] = 0;
        	q.push(0);
        	while(!q.empty())
        	{
        		int now = q.front();
        		if (now == N) return d[now+MX];
        		q.pop();
        		
        		int nx;
        		
        		nx = now + 1;
        		if (nx <= MX && d[nx+MX] == INF)
        		{
        			//printf("add %d %d\n",now,nx);
        			d[nx+MX] = d[now+MX] + 1;
        			q.push(nx);
				}
				
				
				nx = now - 1;
				if (nx >= -MX && d[nx+MX] == INF)
				{
					d[nx+MX] = d[now+MX] + 1;
					q.push(nx);
				}
				
				if (abs(now) <= int(sqrt(MX)))
				{
					nx = now * now;
					if (nx <= MX && d[nx+MX] == INF)
	        		{
	        			d[nx+MX] = d[now+MX] + 1;
	        			q.push(nx);
					}
				}
				
				nx = st(now);
				if (nx <= MX && nx >= -MX && d[nx+MX] == INF)
        		{
        			d[nx+MX] = d[now+MX] + 1;
        			q.push(nx);
				}
			}
			return 0;
        }  
};  
  
// BEGIN CUT HERE  
int main()  
{  
        Deadfish ___test;  
        printf("%d\n",___test.shortestCode(200000));
        return 0;  
}  
// END CUT HERE  
