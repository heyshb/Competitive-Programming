#include <bits/stdc++.h>

using namespace std;

char s[1010];
int N,a[110];
bool vowel[26];

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d",&a[i]);
	memset(vowel,false,sizeof(vowel));
	vowel['a'-'a']=true;
	vowel['e'-'a']=true;
	vowel['i'-'a']=true;
	vowel['o'-'a']=true;
	vowel['u'-'a']=true;
	vowel['y'-'a']=true;
	scanf("\n");
	for (int i=1;i<=N;i++)
	{
		gets(s);
		int len=strlen(s),cnt=0;
		for (int j=0;j<len;j++)
		if (vowel[s[j]-'a']) cnt++;
		if (cnt!=a[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
