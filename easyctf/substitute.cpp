#include <bits/stdc++.h>

using namespace std;

int cnt[26];
char pass[200];

int main()
{
	freopen("substitute.in","r",stdin);
	for (int i=1;i<=128;i++)pass[i] = i;
	pass['C'] = 'e';
	pass['A'] = 'a';
	pass['L'] = 's';
	pass['F'] = 'y';
	pass['W'] = 'c';
	pass['E'] = 't';
	pass['N'] = 'f';
	pass['I'] = 'o';//?
	pass['G'] = 'u';
	pass['P'] = 'h';
	pass['J'] = 'i';
	pass['S'] = 'l'; 
	char c = getchar();
	char ans[200];
	int len = 0;
	while(c != '\n' && c != -1)
	{
		if (c>='A' && c<='Z')
			cnt[c-'A']++;
		ans[++len] = pass[c];
		//ans[++len] = c;
		c = getchar();
	}
	
	printf("%s\n",ans);
	
	//for (int i=0;i<26;i++)printf("%c %d\n",'A'+i,cnt[i]);
}
