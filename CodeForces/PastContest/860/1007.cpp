#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[211];
int t1,t2,tests,i,j,k,f[211][211],n,nxt[211],tc,a[211],pre[3],l,r,bl,br,g[211][211],w[211][211];
int main(){
    for (scanf("%d",&tests),tc=1;tc<=tests;tc++){
        memset(f,0,sizeof(f));memset(nxt,0,sizeof(nxt));
        scanf("%s",ch);n=strlen(ch);
        for (i=pre[1]=pre[0]=0;i<n;i++){
            a[i+1]=k=ch[i]-'0';
            if (pre[k]) nxt[pre[k]]=i+1;
            pre[k]=i+1;
        }
        for (i=1;i<=n;i++)
         for (j=1;j<=n-i+1;j++){
             l=j;r=j+i-1;
             if (l==r){
                 f[l][r]=2;continue;
             }
             if (a[l+1]==a[l]) f[l][r]=1+f[l+2][r],t1=2,k=bl=l+1;else f[l][r]=2+f[l+1][r],t1=1,k=bl=l,g[l][r]=1+f[l+1][r],w[l][r]=f[l+1][r];
             for (k=nxt[k];k&&k<=r;){
                 if (nxt[k]==k+1&&k<r){
                     t2=2;br=k+2;
                 }else{
                     t2=1;br=k+1;
                     if (k<r&&a[l]!=a[l+1]) f[l][r]=min(f[l][r],f[bl+1][k-1]+g[k][r]);
                     if (a[l]!=a[l+1]) w[l][r]=min(w[l][r],f[bl+1][k-1]+f[br][r]);
                     if (k<r&&a[l]==a[l+1]) f[l][r]=min(f[l][r],f[bl+1][k-1]+w[k][r]);
                 }
                 f[l][r]=min(f[l][r],max(0,3-t1-t2)+f[bl+1][k-1]+f[br][r]);
                 if (a[l]!=a[l+1]) g[l][r]=min(g[l][r],f[bl+1][k-1]+f[br][r]);
                 if (nxt[k]==k+1&&k<r) k=nxt[nxt[k]];else k=nxt[k];
             }
             //printf("* %d %d %d\n",l,r,f[l][r]);
         }
        printf("Case #%d: %d\n",tc,f[1][n]);
    }
    return 0;
}
