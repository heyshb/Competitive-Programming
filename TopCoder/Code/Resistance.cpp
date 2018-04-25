// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#line 7 "Resistance.cpp"  
#include <bits/stdc++.h> 
using namespace std;  
  
typedef long long LL;  
  
class Resistance  
{  
        public:  
        vector <double> spyProbability(int P, int S, vector <string> missions)  
        {  
        	vector<int>candidate;
			candidate.clear();
        	for (int mask=0;mask<(1<<P);mask++)
        	{
        		int cnt = 0;
        		for (int i=0;i<P;i++)
        		if (mask & (1<<i)) cnt++;
        		if (cnt != S) continue;
        		bool ok = true;
        		for (int i=0;i<missions.size();i++)
        		{
        			string s = missions[i];
        			if (s[0] == 'F')
        			{
        				bool hasspy = false;
        				for (int j=0;j<P;j++)
        				if ((mask & (1<<j)) && s[j+1]=='1') hasspy = true;
        				if (!hasspy) ok = false;
					}
				}
				if (ok) candidate.push_back(mask);
			}
			vector<double>ret;
			ret.clear();
			int M = candidate.size();
			if (!M) return ret;
			for (int i=0;i<P;i++)ret.push_back(0);
			for (int i=0;i<M;i++)
			{
				int mask = candidate[i];
				for (int j=0;j<P;j++)
				if (mask & (1<<j)) ret[j] += 1.0 / M;
			}
			return ret;
        }  
};  
  
// BEGIN CUT HERE  
int main()  
{  
        Resistance ___test;  
        vector<string>fuck;
        fuck.push_back("F011110000");
        fuck.push_back("F001000010");
         fuck.push_back("F100010101");
          fuck.push_back("F100001010");
          fuck.push_back("F000100100");
        auto tmp = ___test.spyProbability(9,3,fuck);
        for (auto t:tmp) printf("%.2lf\n",t); 
        return 0;  
}  
// END CUT HERE  
