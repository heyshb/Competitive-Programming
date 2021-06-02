#include<bits/stdc++.h>
#define N 100005
#define M 1055
using namespace std;
struct Type{int price,len,r,w;}h[M];
int Event,type,id,i,opt,p,punish,flag;
vector<int>person[M];
int preid[N],prest[N];
int main(){
	scanf("%d%d",&Event,&type);
	h[id=0].price=1e9;
	for (i=1;i<=type;i++){
		scanf("%d%d%d%d",&h[i].price,&h[i].len,&h[i].r,&h[i].w);
		if (h[i].price<h[id].price) id=i;
  }
  scanf("%d",&punish);flag=0;
  printf("p b %d\n",0);
	while (Event--){
		puts("g");fflush(stdout);
	  scanf("%d%d",&opt,&id);
	  if (opt<=1) scanf("%d",&p);
	  if (opt==0) {
			if (flag==0) printf("p b %d\n",0),flag++;
			printf("p s -1 -1\n");
			
	  }
	  else if (opt==1) printf("p i -1 -1\n");
	}
	puts("end");fflush(stdout);
} 
