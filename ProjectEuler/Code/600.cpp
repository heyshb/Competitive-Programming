#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL cntev(LL l,LL r)
{
	if (r % 2 == 0) r++;
	if (l % 2 == 0) l--;
	return (r - l) / 2;
}

int main()
{
	LL n = 55106;
	LL ans = 0;
	for (LL L=3;L<=n/2;L++)
		for (LL a=1;a<=L/3;a++)
		{
			//b + c <= L - a
			//b + c >= 3L - a - n
			
			LL bmin = (3*L - a - n) / 2;
			if (bmin < a)
				ans += (L - a + 1 - (a + (L-a)/2)) * ((L - a)/2 - a + 1);
			else if (bmin <= (L - a) / 2)
				ans += (n - 2*L + 1) * (bmin - a + 1) + (L - a + 1 - (bmin + 1 + (L-a)/2)) * ((L-a)/2 - bmin);
			else
				ans += (n - 2*L + 1) * ((L-a)/2 - a + 1); 
			
		}
	printf("%lld\n",ans);
}
