#include <bits/stdc++.h>

using namespace std;

struct seg
{
	int x1,y1,x2,y2;
};

bool bet(int a,int b,int c)
{
	return (a>=b && a<=c) || (a>=c && a<=b);
}

bool con(seg a,seg b)
{
	if (a.x1 == a.x2 && a.y1 == a.y2)
		return bet(a.x1,b.x1,b.x2) && bet(a.y1,b.y1,b.y2);
	if (b.x1 == b.x2 && b.y1 == b.y2)
		return bet(b.x1,a.x1,a.x2) && bet(b.y1,a.y1,a.y2);
	return (a.x1 == b.x1 && a.y1 == b.y1) || 
		   (a.x1 == b.x2 && a.y1 == b.y2) || 
		   (a.x2 == b.x1 && a.y2 == b.y1) || 
		   (a.x2 == b.x2 && a.y2 == b.y2);
}



int main()
{
	int T;
	scanf("%d",&T);
	seg a,b;
	while(T--)
	{
		bool sm = false;
		scanf("%d%d%d%d",&a.x1,&a.y1,&a.x2,&a.y2);
		scanf("%d%d%d%d",&b.x1,&b.y1,&b.x2,&b.y2);
		int type1,type2;
		type1 = (a.x1 == a.x2);
		type2 = (b.x1 == b.x2);
		if (type1 != type2)
			sm = con(a,b);
		else
		{
			if (type1)
			{
				sm = (a.x1 == b.x1) &&
					 (	
					 	bet(a.y1,b.y1,b.y2) || bet(a.y2,b.y1,b.y2) ||
					 	bet(b.y1,a.y1,a.y2) || bet(b.y2,a.y1,a.y2)
					 );
			}
			else
			{
				sm = (a.y1 == b.y1) &&
					 (	
					 	bet(a.x1,b.x1,b.x2) || bet(a.x2,b.x1,b.x2) ||
					 	bet(b.x1,a.x1,a.x2) || bet(b.x2,a.x1,a.x2)
					 );
			}
		}
		puts(sm?"yes":"no");
	}
}
