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
	if (tot==1050) return; //æ°?é??é?°î?¢î??æ?·é??ç?²é¹¿æ?³1050ç?²èµ?é?? 
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
  //ç?²èµ?æ½?ç?²æ½?é??ç?«â??æ?·è??å¿?é¢?å??è?½é??æ?¤æ?·å¿?é??æ?¤æ?·æ°?æ?®é??ç?«ã??ã?¢î?¡Ñ?æ?·é??ç?«î? Ã·î??Ñ?æ?·é??ç?«î?·ç¡·æ?·æ°?å¨?é??ç?«ï¸¼æ?·é??ç?«ã??î?¨æ?·æ°?é??é?°î??ã??æ??æ?·ç?²é??é??ç?«ã??ä¼?æ?·è?½é??æ?¤æ?·è?½é??å?¢è?½é??æ?¤æ?·è??å½?é??ç?«â??î?®æ?·è?½é??é?°î??ï¸¼æ?·é??ç?«î??æ?¯æ??â??æ?·é??ç?«Ñ?æ?·é??ç?«î? ç?­å¹»ã?¯æ?·é??çµ?è??å½?é???è??å½?é??ç?«ã?¯æ?·é??ç?«ã?¢å­¤æ??ã?¢å­¤æ??ã?¢å­¤æ??î?·ç¡·æ?· 
	if (smallid){
		//int addnum=5000000/punish;  //å¿?é¢?é??æ°?é??é??ç?«ã?¯æ?·ç??ç?²ç¦?æ¥¼ç?«æ?³é??ç?«ã?¯æ?·é???
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
		  		//å¿?é¢?é??æ°?é??é??ç?«î? î??æ?·å¿?é??æ?¤æ?·å¿?é??æ?¤æ?·è?½é??æ?¤æ?·å¿?é??é?°ç?¹ã?¯æ?·é??ç?«î?·ç¡·æ?·æ°?é¹¿é?²å¿?è??é??å¿?é??æ?¤æ?·ç?«é??æ?¤æ?·ç?«é??æ?¤æ?·æ°?é??é?°ç??alyesæ°?é??æ?¤æ?·è??å½?é??ç?«ã?¯æ?·ç??ç?«é??é?°ç?«ï¸¼æ?·å?¢è?½é??å?¢è?½é??æ?¤æ?·ç?²å½?é??ç?«Ñ?æ?·é??ç?«ï¸¼æ?·é???
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
		  	if (1.5*(h[type[id]].len-rest[id])<=h[type[id]].len)  //æ°?åº?é¹¿è??é??æ?¤æ?·æ°?æ?³é??ç?«ã?¢ç?´æ?·1/3ç?²é¹¿æ?³æ°?é??æ?¤æ?·ç?²èµ?é??ç?«î? ç?­å¹»ã?¯æ?·é??ç?«ï¸¼æ?·æ?³è?½é??æ?¤æ?·è??å½?é??ç?«Î²î?»ã?£ã??ã??æ?·æ°?é??é?°î?¸ã?¢å®¦ã??î??å¸®æ?·æ°?é??æ?¤æ?· 
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
		//assert(tot+1<900);è?½ç¦?é??ç?«Î²ï½?æ?·å¿?ç¢?é??ç?«î?·ç¡·æ?·æ°?é??æ??è?½é??å?¢è?½é??æ?¤æ?·ç?²èµ?é??ç?«î??è®¹æ?·ç?«é©´é???00ç?²èµ?é?? 
		return ++tot;
  }
	return 0;
}
void solve2(){
	tot=0;Type u=h[bigid];//*Stack=0;
	if (smallid){
		//int addnum=5000000/punish;  //å¿?é¢?é??æ°?é??é??ç?«ã?¯æ?·ç??ç?²ç¦?æ¥¼ç?«æ?³é??ç?«ã?¯æ?·é???
		int addnum=120;
		for (int i=1;i<=addnum;i++)
			printf("p b %d\n",smallid-1);
	  tot=addnum;
  }
	Newid();Newid();
	Link[tot-1]=tot;
	Link[tot]=tot-1;
	int now=tot;
	int A=Newid(),B=Newid();
  for (int E=1;E<=Event;E++){
		puts("g");fflush(stdout);
		int opt,t;scanf("%d%d",&opt,&t);
	  if (opt==0){
		  int len,tmp,used=0;scanf("%d",&len);
		  assert(A);
		  if ((u.len-rest[now]>=len)||A){
		  	if (u.len-rest[now]<len){
					now=A;tmp=B;used=1;
					Link[now]=tmp,Link[tmp]=now;
			  }else tmp=Link[now];
		  	preid[t]=now;prest[t]=rest[now];
		  	person[now].push_back(t);
		  	printf("p s %d %d\n",now-1,rest[now]);
		  	printf("p cp %d %d %d %d %d\n",now-1,rest[now],len,tmp-1,rest[now]);
		  	rest[now]+=len;rest[tmp]+=len;//assert(rest[now]==rest[tmp]);
		  }
		  else printf("p s -1 -1\n"),prest[t]=preid[t]=-1;
		  if (used) A=Newid(),B=Newid();
	  }
	  if (opt==1){
	  	int len;scanf("%d",&len);
	  	if (preid[t]==-1) printf("p i -1 -1\n");//assert(0);
	  	else printf("p i %d %d\n",preid[t]-1,prest[t]+len);
	  }
	  if (opt==2){
	  	int id=t+1,tmp=Link[t+1];
	  	assert(rest[tmp]==rest[id]);
			if (rest[tmp] && E<=0.85*Event)
				printf("p cp %d %d %d %d %d\n",tmp-1,0,rest[tmp],id-1,0);
			else
			{
				if (tmp != -1) Link[tmp] = -1;
				for (auto tt:person[id]) preid[tt] = tmp;
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
  special=(h[bigid].price+1.*h[bigid].len*(h[bigid].r+h[bigid].w))<=(h[bigid].len/5000.)*punish;
  //fprintf(stderr,special?"Special!!!":"Normal"); 
  if (!special) solve1();  //å¿?é¢?æ?¢æ°?èµ?èµ? 
  			 else   solve2();  //è?½é??é??ç?«â??æ?·é??ç?«î??å?¡æ?·è??è?¦é??ç?«î?·ç¡·æ?·å¿?ç??é??ç?«Î²î??î?©opyå¿?é??é?°ã??ã?¢å?¡æ?·ç?«ç??é??ç?«î??î?·â??â??æ?·åº?ç?²èµ?é??ç?«ã?¯æ?·é??ç?«ã?¢ç?´æ?· 
} 
