#include <bits/stdc++.h>

using namespace std;

unordered_map<string,bool>vis;

/*
..MN..	
..OP..
IJABEF
KLCDGH   
..QR..
..ST..
..UV..
..WX..

..MB..	
..OD..
IJARGE
KLCTHF
..QV..
..SX..
..UN..
..WP..

..KI..	
..OP..
SJABEM
TLCDGN
..QR..
..HF..
..VX..
..UW..

..MN..	
..OP..
IJABEF
VUKLCD
..SQ..
..TR..
..HG..
..WX..
*/
int pos[26];
string rotateR(string s)
{
	string tmp = "ARCTGEHFIJKLMBODQVSXUNWP";
	string res = "????????????????????????";
	for (int i=0;i<24;i++)
		res[i] = s[tmp[i] - 'A'];
	return res;
}

string rotateD(string s)
{
	string tmp = "ABCDEMGNSJTLKIOPQRHFVXUW";
	string res = "????????????????????????";
	for (int i=0;i<24;i++)
		res[i] = s[tmp[i] - 'A'];
	return res;
}

string rotateF(string s)
{
	string tmp = "ABKLEFCDIJVUMNOPSQTRHGWX";
	string res = "????????????????????????";
	for (int i=0;i<24;i++)
		res[i] = s[tmp[i] - 'A'];
	return res;
}

bool check[26];
int sum[25];
int tmpcnt = 0; 
void calc(string s)
{
	memset(check,false,sizeof(check));
	int SS = 0;
	for (int i=0;i<24;i++)
	if (!check[i])
	{
		SS++;
		int j = i;
		while(!check[j])
		{
			check[j] = true;
			j = s[j] - 'A';
		}
	}
	if (++tmpcnt <= 10)
	{
		cout<<s<<endl;
		printf("%d\n",SS);
	}
	sum[SS]++;
}


queue<string>q;
void bfs(string st)
{
	q.push(st);
	string s;
	string tmp;
	//printf("%d\n",vis.size()); 
	vis[st] = true;
	int cnt;
	while(!q.empty())
	{
		s = q.front();
		//cout<<s<<endl;
		calc(s);
		q.pop();
		
		tmp = rotateR(s);
		if (!vis[tmp])
		{
			vis[tmp] = true;
			q.push(tmp);
		}
		
		tmp = rotateD(s);
		if (!vis[tmp])
		{
			vis[tmp] = true;
			q.push(tmp);
		}
		
		tmp = rotateF(s);
		if (!vis[tmp])
		{
			vis[tmp] = true;
			q.push(tmp);
		}
	}
}

int main()
{
	//freopen("599.txt","w",stdout);
	string start = "ABCDEFGHIJKLMNOPQRSTUVWX";
	/*
	for (int i=0;i<4;i++)
	{
		start = rotateF(start);
		cout<<start<<endl;
	}*/
	bfs(start);
	int N = vis.size();
	for (int i=1;i<=24;i++)printf("%d %d\n",i,sum[i]);
	printf("%d\n",vis.size());
}
