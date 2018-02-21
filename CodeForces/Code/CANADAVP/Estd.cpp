#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef unsigned long long ULL;

int a[200005];

int main(){
    int n,m,x,f;
    set<int>v;
    scanf("%d%d",&n,&m);
    m=200000;
    memset(a,0,sizeof(a));
    a[1]=200000;
    /*
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        a[x]++;
    }*/
    for(int i=0;i<=n;i++){
        if(a[i]) v.insert(i);
    }
    if(a[n]){
        printf("Greed is good\n");
        puts("A");
        return 0;
    }
    for(int i=1;i<n;i++){
    	printf("%d\n",i);
        x=n,f=n;
        if(!a[i]) v.insert(i);
        a[i]++;
        while(x){
            set<int>::iterator p=v.upper_bound(f);
            if(p==v.begin()) break;
            p--;
            int y=(*p);
            x-=min(x/y,a[y])*y;
            f=min(y-1,x);
        }
        if(x){
            printf("%d\n",i);
            return 0;
        }
        if(!(--a[i])) v.erase(i);
    }
    printf("Greed is good\n");
}
