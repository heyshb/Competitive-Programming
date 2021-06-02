#include <bits/stdc++.h>

using namespace std;

map<string,string>ans;
int maxdep;
char charset[9] = "!&()xyz|";

int work(string s,int x,int y,int z)
{
    int i,a,b,cnt = 0;

    if(s.size() == 0) return -1;
    if(s.size() == 1)
    {
        if(s[0] == 'x') return x;
        else if(s[0] == 'y') return y;
        else if(s[0] == 'z') return z;
        return -1;
    }

    for(i=0;i<s.size();i++)
    {
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        else if(cnt == 0) if(s[i] == '|')
        {
            a = work(s.substr(0, i),x,y,z);
            b = work(s.substr(i+1,s.size()-i),x,y,z);
            if(a == -1 || b == -1) return -1;
            return a || b;
        }
    }
    if(cnt != 0) return -1;

    for(i=0;i<s.size();i++)
    {
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        else if(cnt == 0) if(s[i] == '&')
        {
            a = work(s.substr(0, i),x,y,z);
            b = work(s.substr(i+1,s.size()-i),x,y,z);
            if(a == -1 || b == -1) return -1;
            return a && b;
        }
    }

    if(s[0] == '!')
    {
        a = work(s.substr(1, s.size()-1),x,y,z);
        return a == -1 ? -1 : !a;
    }
    return work(s.substr(1, s.size()-2),x,y,z);
}

string check(string s)
{
    int x,y,z,t;
    string ret = "";
    for(x=0;x<=1;x++) for(y=0;y<=1;y++) for(z=0;z<=1;z++)
    {
        t = work(s,x,y,z);
        if(t == -1) return "-1";
        ret += work(s,x,y,z) + '0';
    }
    return ret;
}

//  !&()xyz|

bool ok(char last,char now)
{
	if (last == '(' || last == '&' || last == '|' || last == '!')
	{
		return (now == '!' || now == 'x' || now == 'y' || now == 'z' || now == '(');
	}
	if (last == 'x' || last == 'y' || last == 'z' || last == ')')
	{
		return (now == '&' || now == '|' || now == ')');
	}
	return true;
}

void dfs(int dep,string now,char last)
{
	//printf("dfs %d ",dep);
	//cout<<now<<endl;
	if (dep == maxdep + 1)
	{
		string res = check(now);
		if (ans.find(res) == ans.end())
			ans[res] = now;
		return;
	}
	for (int i=0;i<8;i++)
	{
		char c = charset[i];
		if (ok(last,c))
		dfs(dep+1,now+c,c);	
	}
}

int main()
{
	
	for (maxdep=1;maxdep<=15;maxdep++)
	{
		printf("maxdep = %d\n",maxdep);
		dfs(1,"",'(');
		printf("calced %d\n",ans.size());
	}
	freopen("ans.txt","w",stdout);
	printf("calced %d\n",ans.size());
	for (auto t:ans)
	{
		printf("ans[\"");
		cout<<t.first;
		printf("\"]=\"");
		cout<<t.second;
		printf("\";\n");
	}	
}
