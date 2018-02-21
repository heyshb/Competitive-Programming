#include<bits/stdc++.h>
#define y1 olweradfas
#define y2 qweoisasdk
#define x1 poeriuweor
#define x2 poriewioru
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

int bet(int x,int y,int x1,int y1,int x2,int y2)
{
	if (x1 > x2) swap(x1,x2);
	if (y1 > y2) swap(y1,y2);
	return (x>=x1 && x<=x2 && y>=y1 && y<=y2);
}

int x1, y1, x2, y2;
int x[MAXN], y[MAXN];
int b[MAXN];

const double PI = acos(-1);

void gao1(){
	int flag = 0;
	for (int i = 1; i <= n; i++)
		if (x[i] == x1 && y1 < y[i] && y[i] < y2)
			flag++;
	printf("%.15f\n", 100 * (y2 - y1) + flag * (PI * 10 - 20));
}

#define _cp(a,b) ((a)<(b))

int subseq(int n, int a[]) {
    static int b[MAXN + 1];
	int i, l, r, m, ret = 0;
	//cout << n << endl; fflush(stdout);
    for (i = 0; i < n; b[l] = i++, ret += (l> ret)) {
        for (m = ((l = 1) + (r = ret)) >> 1; l <= r; m = (l + r) >> 1) {
            if (_cp(a[b[m]], a[i])) {
                l = m + 1;
            } else {
                r = m - 1;
            } 
        } 
    }
    return ret;
}

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	//freopen("C.in","r",stdin);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &x[i], &y[i]);
	}
	if ((x1 == x2) && (y1 == y2)){
		puts("0");
		return ;
	}
	//for (int i=1;i<=n;i++)printf("%d %d\n",x[i],y[i]);
	vector<PII> a;
	for (int i = 1; i <= n; i++){
		if (bet(x[i],y[i],x1,y1,x2,y2)){
			a.push_back(PII(abs(x[i] - x1), abs(y[i] - y1)));
		}
	}
	x2 -= x1, y2 -= y1;
	x2 = abs(x2);
	y2 = abs(y2);
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
		b[i] = a[i].second;
	int ret = subseq(a.size(), b);
	//cout << ret << endl;
	assert(ret <= min(y2,x2) + 1); 
	if (ret < min(y2, x2) + 1)
		printf("%.15f\n", 100.0 * (x2 + y2) - (20 - 5 * PI) * ret);
	else
		printf("%.15f\n", 100.0 * (x2 + y2) - (20 - 5 * PI) * ret + 5 * PI);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}
