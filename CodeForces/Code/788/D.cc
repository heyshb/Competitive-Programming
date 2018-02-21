#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 100000000;
const int nico = 2 * MAXN + 1;

int query(int x, int y){
	printf("0 %d %d\n", x, y);
	fflush(stdout);
	int k;
	scanf("%d", &k);
	return k;
}

vector<int> X, Y;

int getrand(int MM){
	ll x = rand() % 1000;
	for(int i = 1; i <= 3; i++)
		x = x * 1000 + rand() % 1000;
	return x % MM;
}

int check(int x, int flag){
	int u = getrand(nico) - MAXN;
	int v = getrand(nico) - MAXN;
	//int w = getrand(nico) - MAXN;
	if (flag == 0)
		return query(x, u) == 0 && query(x, v) == 0;// && query(x, w) == 0;
	else
		return query(u, x) == 0 && query(v, x) == 0;// && query(w, x) == 0;
}

int main(){
	srand(time(NULL));
	int x = MAXN, y = MAXN;
	int k = query(x, y);
	x -= k, y -= k;
	int fx = check(x, 0), fy = check(y, 1);
	if (fx) X.push_back(x);
	if (fy) Y.push_back(y);
	for(; x >= -MAXN && y >= -MAXN; ){
		int flag = 0;
		for(int del = 1; x - del >= -MAXN && y - del >= -MAXN; del *= 2){
			k = query(x - del, y - del);
			if (k < del){
				flag = 1;
				if (k <= del / 2){
					fx = check(x - del + k, 0);
					fy = check(y - del + k, 1);
					if (fx || fy){
						if (fx) X.push_back(x - del + k);
						if (fy) Y.push_back(y - del + k);	
						x = x - del + k;
						y = y - del + k;
					}
					else{
						fx = check(x - del - k, 0);
						fy = check(y - del - k, 1);
						if (fx) X.push_back(x - del - k);
						if (fy) Y.push_back(y - del - k);	
						x = x - del - k;
						y = y - del - k;
					}
				}
				else{
					fx = check(x - del - k, 0);
					if (fx) X.push_back(x - del - k);
					fy = check(y - del - k, 1);
					if (fy) Y.push_back(y - del - k);
					x = x - del - k;
					y = y - del - k;
				}
				break;
			}
		}
		if (flag == 0) break;
	}
	printf("1 %d %d\n", X.size(), Y.size());
	fflush(stdout);
	//puts("QvQ");
	for(int i = 0; i < X.size(); i++)
		printf("%d%c", X[i], " \n"[i + 1 == X.size()]);
	fflush(stdout);
	for(int i = 0; i < Y.size(); i++)
		printf("%d%c", Y[i], " \n"[i + 1 == Y.size()]);
	fflush(stdout);
	return 0;
}


