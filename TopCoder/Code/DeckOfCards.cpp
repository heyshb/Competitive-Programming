// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#line 7 "DeckOfCards.cpp"  
#include <bits/stdc++.h> 
using namespace std;  
  
typedef long long LL;  
  
class DeckOfCards  
{  
        public:  
        string IsValid(int n, vector <int> value, string suit)  
        {  
        	for (int i=0;i<n;i++)
        		for (int j=i+1;j<n;j++)
        		if (suit[i]==suit[j] && value[i]==value[j])
        			return "Not perfect";
        	for (int i=0;i<n;i++)
        		for (int j=0;j<n;j++)
        		if (i != j)
        		{
        			bool ok = false;
        			for (int k=0;k<n;k++)
        				ok |= (suit[k] == suit[i] && value[k] == value[j]);
        			if (!ok) return "Not perfect";
				}
			return "Perfect";
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "z"; string Arg3 = "Perfect"; verify_case(0, Arg3, IsValid(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "hhh"; string Arg3 = "Perfect"; verify_case(1, Arg3, IsValid(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {2,3,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "hcch"; string Arg3 = "Perfect"; verify_case(2, Arg3, IsValid(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "hch"; string Arg3 = "Not perfect"; verify_case(3, Arg3, IsValid(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "hhcc"; string Arg3 = "Not perfect"; verify_case(4, Arg3, IsValid(Arg0, Arg1, Arg2)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
        DeckOfCards ___test;  
        ___test.run_test(-1);  
        return 0;  
}  
// END CUT HERE  
