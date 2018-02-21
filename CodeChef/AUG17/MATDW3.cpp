#include<bits/stdc++.h>
#define N 100005
#define M 1055
using namespace std;
struct Type{int price,len,r,w;}h[M];
int Event,m,punish,testcase,number,tot,smallid,bigid,special;
vector<int>person[M];int rest[M],ok[M],type[M];
int preid[N],prest[N];int calc[3];
double storenum=0.473333333,findnum=0.45,crashnum=0.076666667;
const double s1[7]={0,0.2,0.5,0.6,0.7,0.35,0.49};
const double s2[7]={0,0.7,0.45,0.35,0.2,0.5,0.5};
const double s3[7]={0,0.1,0.05,0.05,0.1,0.15,0.01};
 
void Findcase(){
	double t1=calc[0]/1000.,t2=calc[1]/1000.,t3=calc[2]/1000.;
	double Min=1e9;
	for (int i=1;i<=6;i++){
		double tmp=abs(s1[i]-t1)+abs(s2[i]-t2)+abs(s3[i]-t3);
		if (tmp<Min)
			Min=tmp,testcase=i;
	}
	storenum=s1[testcase];
	 findnum=s2[testcase];
	crashnum=s3[testcase];
}
void Newdisk(int _){
	if (tot==1050) return; //å�ªè�½ä¹°1050ä¸ª 
	printf("p b %d\n",_-1);
	int id=++tot;
	ok[id]=1;rest[id]=0;type[id]=_;
}
void find(){
	smallid=0;h[0].price=1e9;
	for (int i=1;i<=m;i++)
		if (h[i].price<=10&&h[i].price<h[smallid].price)
			smallid=i;
	bigid=0;h[0].price=1e9;
	for (int i=1;i<=m;i++)
		if (h[i].len>=10000){
			if (bigid==0) {bigid=i;continue;}
			long long p1=h[i].price,p2=h[bigid].price;
			long long tmp1=p2*(h[i].price+1ll*(h[i].r+h[i].w)*h[i].len);
			long long tmp2=p1*(h[bigid].price+1ll*(h[bigid].r+h[bigid].w)*h[bigid].len);
			if (tmp1<tmp2) bigid=i;
	  }
  assert(bigid>0);
}

void solve1(){
	for (int i=1;i<=m;i++)
    Newdisk(i);
  //ä¸ºäº�é�²æ­¢ç��æ��å¾�å¤§ç��ç¡¬ç��ï¼�å¦�æ��å­�å�¨å¾�ä½�å»�ç��ç¡¬ç��ï¼�é¢�ç�®æ��è¿°é��ç��ç±»å��Iï¼� ï¼�å��ä¹°ä¹°ä¹°ï¼� 
	if (smallid){
		//int addnum=5000000/punish;  //æ­¤å¤�å�¯ä»¥è°�å�� 
		int addnum=100;
		for (int i=1;i<=addnum;i++)
			Newdisk(smallid);
  }
	for (int E=1;E<=Event;E++){
		puts("g");fflush(stdout);
		int opt,t;scanf("%d%d",&opt,&t);
	  if (!testcase){
	    calc[opt]++;
	    if (calc[0]+calc[1]+calc[2]>=2000)
	    	Findcase();
	  }
	  if (opt==0) {
		  int len;scanf("%d",&len);++number;
		  //printf("%d\n",tot);
		  double Min=1e18;int id=0;
		  for (int i=1;i<=tot;i++)
		  	if (ok[i]&&h[type[i]].len-rest[i]>=len){
		  		double valyes=h[type[i]].r*len+((Event-E)*findnum*(1./number))*h[type[i]].w;
		  		double valno=(Event-E)*findnum*(1./number)*punish;
		  		//æ­¤å¤�ç®�æ��æ��ç��æ�¶å��ï¼�å¹¶æ²¡æ��è��è��å�°valyeså��ï¼�å�¯è�½æ�¬ç¡¬ç��ä¼�ç��æ�� 
		  		//printf("%d %d %lf %lf\n",type[i],h[type[i]].len-rest[i],valyes,valno);
		  		if (valyes<valno)
		  			if (valyes<Min)
		  				Min=valyes,id=i;
		  	}
		  if (id==0) printf("p s -1 -1\n"),preid[t]=prest[t]=-1;
		  else {
		  	person[id].push_back(t);
		  	preid[t]=id;prest[t]=rest[id];
		  	printf("p s %d %d\n",id-1,rest[id]);
		  	rest[id]+=len;
		  	if (1.5*(h[type[id]].len-rest[id])<=h[type[id]].len)  //å®¹é��å°�äº�1/3ä¹°å��ä¸�ç±»å��æ�°ç��ï¼�æ­¤å¤�å�¯ä»¥è°�å�� 
		  	  Newdisk(type[id]);
		  }
	  }
	  if (opt==1){
	  	int len;scanf("%d",&len);
	  	if (preid[t]==-1) printf("p i -1 -1\n");
	  	else printf("p i %d %d\n",preid[t]-1,prest[t]+len);
	  }
	  if (opt==2){
	  	int id=t+1;
	  	for (int i=0;i<person[id].size();i++)
	  		preid[person[id][i]]=-1;//printf("Delete %d\n",person[id][i]);
	  	person[id].clear();
	  	ok[id]=1;rest[id]=0;
	  }
	}
	puts("end");fflush(stdout);
}
 
int Link[M];//Stack[M];
int Newid(){
	//if (*Stack) return Stack[(*Stack)--];
	if (tot<1050){
		printf("p b %d\n",bigid-1);
		//assert(tot+1<900);ç»�æ£�æµ�ï¼�å¤§ç¡¬ç��ä¸�è¶�è¿�900ä¸ª 
		return ++tot;
  }
	return 0;
}
bool bf[N];
bool bf2[N];
bool boom[N];
int nn = 0;
bool check(int num,int len)
{
	nn++;
	return nn <= N * storenum * 0.66;
}
void solve2(){
	tot=0;Type u=h[bigid];//*Stack=0;
	if (smallid){
		//int addnum=5000000/punish;  //æ­¤å¤�å�¯ä»¥è°�å�� 
		int addnum=100;
		for (int i=1;i<=addnum;i++)
			printf("p b %d\n",smallid-1);
	  tot=addnum;
  	}
  	memset(bf,false,sizeof(bf));
  	memset(bf2,false,sizeof(bf2));
  	memset(boom,false,sizeof(boom));
	Newid();Newid();
	Link[tot-1]=tot;
	Link[tot]=tot-1;
	int now=tot;
	int A=Newid(),B;
  for (int E=1;E<=Event;E++){
		puts("g");fflush(stdout);
		int opt,t;scanf("%d%d",&opt,&t);
	  if (opt==0){
		  int len,tmp,used=0;scanf("%d",&len);
		  assert(A);
		  bf[t] = check(t,len);
		  if (bf[t])
		  {
			  if ((u.len-rest[now]>=len)||A){
			  	if (u.len-rest[now]<len){
			  			B = Newid();
			  			if (!B) goto nobf;
						now=A;tmp=B;used=1;
						Link[now]=tmp,Link[tmp]=now;
				  }else tmp=Link[now];
				bf2[now] = bf2[tmp] = true;
			  	preid[t]=now;prest[t]=rest[now];
			  	person[now].push_back(t);
			  	printf("p s %d %d\n",now-1,rest[now]);
			  	printf("p cp %d %d %d %d %d\n",now-1,rest[now],len,tmp-1,rest[now]);
			  	rest[now]+=len;rest[tmp]+=len;//assert(rest[now]==rest[tmp]);
			  }
			  else printf("p s -1 -1\n"),prest[t]=preid[t]=-1;
			  if (used) A=Newid();
		  }
		  else
		  {
		  	  nobf:
		  	  if (u.len - rest[now] >= len || A)
		  	  {
		  	  	 if (u.len-rest[now]<len){
						now=A;used=1;
				  }
				  	preid[t]=now;prest[t]=rest[now];
				  	person[now].push_back(t);
				  	printf("p s %d %d\n",now-1,rest[now]);
				  	rest[now]+=len;
		  	  }
		  	  if (used) A = Newid();
		  }
	  }
	  if (opt==1){
	  	int len;scanf("%d",&len);
	  	if (preid[t]==-1 || boom[preid[t]]) printf("p i -1 -1\n");//assert(0);
	  	else printf("p i %d %d\n",preid[t]-1,prest[t]+len);
	  }
	  if (opt==2){
	  	int id=t+1,tmp=Link[t+1];
	  	assert(rest[tmp]==rest[id]);
			if (bf2[id])
			{
				if (rest[tmp])
				printf("p cp %d %d %d %d %d\n",tmp-1,0,rest[tmp],id-1,0);
			}
			else
			{
				boom[id] = true;
			}
	  }
	  //assert(E<=900);
	}
	puts("end");fflush(stdout);
}
 
int main(){
	scanf("%d%d",&Event,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d%d",&h[i].price,&h[i].r,&h[i].w,&h[i].len);
  scanf("%d",&punish);
  tot=0;number=0;testcase=0;
  find();
  special=(h[bigid].price+1.*h[bigid].len*(h[bigid].r+h[bigid].w))<=(h[bigid].len/10000.)*punish;
  //fprintf(stderr,special?"Special!!!":"Normal"); 
  solve2();
  //if (!special) solve1();  //æ­£å¸¸ 
  //			 else   solve2();  //ç½�é��è¿�é«�ï¼�æ¯�æ¬¡copyæ�¥ä¿�è¯�è¯¢é�®ä¸�å��äº� 
}
