// BEGIN CUT HERE  
/* 
 
*/  
// END CUT HERE  
#line 7 "CubeStackingGame.cpp"  
#include <bits/stdc++.h> 
using namespace std;  
  
typedef long long LL;  

int col[100][4];
int ans = 0;

bool check(int N)
{
	for (int k=0;k<4;k++)
		for (int i=0;i<=N;i++)
			for (int j=i+1;j<=N;j++)
			if (col[i][k] == col[j][k]) return false;
	return true;
}

void dfs(int dep,vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4,int md)
{
	if (dep == md) return;
	col[dep][0] = c1[dep]; col[dep][1] = c2[dep]; col[dep][2] = c3[dep]; col[dep][3] = c4[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	col[dep][0] = c2[dep]; col[dep][1] = c3[dep]; col[dep][2] = c4[dep]; col[dep][3] = c1[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	col[dep][0] = c3[dep]; col[dep][1] = c4[dep]; col[dep][2] = c1[dep]; col[dep][3] = c2[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	col[dep][0] = c4[dep]; col[dep][1] = c1[dep]; col[dep][2] = c2[dep]; col[dep][3] = c3[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	
	
	col[dep][0] = c4[dep]; col[dep][1] = c3[dep]; col[dep][2] = c2[dep]; col[dep][3] = c1[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	col[dep][0] = c3[dep]; col[dep][1] = c2[dep]; col[dep][2] = c1[dep]; col[dep][3] = c4[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	col[dep][0] = c2[dep]; col[dep][1] = c1[dep]; col[dep][2] = c4[dep]; col[dep][3] = c3[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
	col[dep][0] = c1[dep]; col[dep][1] = c4[dep]; col[dep][2] = c3[dep]; col[dep][3] = c2[dep];
	if (check(dep))
	{
		ans = max(ans,dep+1);
		dfs(dep+1,c1,c2,c3,c4,md);
	}
}
  
class CubeStackingGame  
{  
        public:  
        int MaximumValue(int n, vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4)  
        {  
        	ans = 0;
        	dfs(0,c1,c2,c3,c4,n);
			return ans;
        }  
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(0, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(1, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(2, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(3, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {2,1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 2; verify_case(4, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 4; int Arr1[] = {1,1,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,3,3,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1,4,3,4}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(5, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 4; int Arr1[] = {1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,2,2,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,3,3,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4,4,4,2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 4; verify_case(6, Arg5, MaximumValue(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
  
};  
  
// BEGIN CUT HERE  
int main()  
{  
        CubeStackingGame ___test;  
        ___test.run_test(-1);  
        return 0;  
}  
// END CUT HERE  
