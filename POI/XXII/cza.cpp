#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
int N,K,a[MAXN],b[MAXN],P;
int v[MAXN];
bool dislike[MAXN][6];
int f[MAXN][2][8];

bool dl(int x,int y) {
    int delta = y - x;
    if (delta < -3 || delta > 3 || delta == 0) assert(false);
    if (delta < 0) return dislike[x][delta + 3];
    else return dislike[x][delta + 2];
}

void upd(int &x,int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    scanf("%d%d%d",&N,&K,&P);
    for (int i=1;i<=K;i++) {
        scanf("%d%d",&a[i],&b[i]);
        if (abs(b[i] - a[i]) > 3) continue;
        int delta = b[i] - a[i];
        if (delta < 0) {
            dislike[a[i]][delta + 3] = true;
        } else {
            dislike[a[i]][delta + 2] = true;
        }
    }
    if (P == 0) {
        puts(N == 1 ? "1" : "0");
        return 0;
    }
    if (P == 1) {
        if (N == 1) {
            puts("1");
        } else if (N == 2) {
            puts(K > 0 ? "0" : "1");
        } else {
            puts("0");
        }
        return 0;
    }
    if (P == 2) {
        if (N == 1) {
            puts("1");
            return 0;
        }
        if (N == 2) {
            puts(K > 0 ? "0" : "1");
            return 0;
        }
        int ans = 0;
        int M;
        bool ok;

        v[1] = N;
        M = 2;
        for (int i=N-1;i>0;i-=2) v[M++] = i;
        M = N;
        for (int i=N-2;i>0;i-=2) v[M--] = i;
        ok = !dl(v[N],N);
        for (int i=1;i<N;i++) {
            ok &= (!dl(v[i],v[i + 1]));
        }
        ans += ok;

        v[1] = N;
        M = 2;
        for (int i=N-2;i>0;i-=2) v[M++] = i;
        M = N;
        for (int i=N-1;i>0;i-=2) v[M--] = i;
        ok = !dl(v[N],N);
        for (int i=1;i<N;i++) {
            ok &= (!dl(v[i],v[i + 1]));
        }
        ans += ok;

        printf("%d\n",ans);
        return 0;
    }
    assert(P == 3);
    if (N == 1) return 0 * puts("1");
    if (N == 2) return 0 * puts(K > 0 ? "0" : "1");
    /*
        f[i][j][k]
        after i, i+1, ... , N has been placed
        j([0,1]) describes the order of (i, i+1, i+2) clockwise   if j == 0, (i, i+1, i+2). if j == 1, (i, i+2, i+1)
        k([0,7]) 3 bits to describe adjacent condition between (i, i+1, i+2). adj(i, i+1) | adj(i+1, i+2) | adj(i+2, i)
        l([0,7]) 3 bits to describe whether (i, i+1, i+2) has a disliked neighbor
        after i is placed, i + 3 can't have a disliked neighbor
    */
    f[N - 2][0][7] = f[N - 2][1][7] = 1;
    int ans = 0;
    // insert i
    for (int i=N-3;i>=1;i--) {
        for (int k=0;k<8;k++) {
            // j = 0,  i+1 i+2 i+3
            int x, y, z;
            bool ok;
            x = (k & 4) ? 1 : 0;
            y = (k & 2) ? 1 : 0;
            z = (k & 1) ? 1 : 0;
            //printf("%d %d %d %d %d\n",i+1,k,x,y,z);
            if (f[i+1][0][k]) {
                if (x) { //between i+1 and i+2
                    
                    //    (i+1)---1---(i+2)---y---(i+3)---z---(i+1)
                    // -->(i+1)---1---(i)---1---(i+2)---0---(i+1)
                    ok = true;
                    if (y && dl(i+2,i+3)) ok = false;
                    if (z && dl(i+3,i+1)) ok = false;
                    if(ok)upd(f[i][1][5],f[i+1][0][k]);
                    //if (ok) puts("fuck1");
                }
                
                if (y) { //between i+2 and i+3
                    //    (i+1)---x---(i+2)---1---(i+3)---z---(i+1)
                    // -->(i+1)---x---(i+2)---1---(i)---0---(i+1)
                    ok = true;
                    if (dl(i, i+3)) ok = false;
                    if (z && dl(i+3,i+1)) ok = false;
                    if(ok)upd(f[i][0][x * 2 + 1],f[i+1][0][k]);
                    //if (ok) puts("fuck2");
                }
                
                if (z) { //between i+3 and i+1
                    //    (i+1)---x---(i+2)---y---(i+3)---1---(i+1)
                    // -->(i+1)---x---(i+2)---0---(i)---1---(i+1)
                    ok = true;
                    if (y && dl(i+2,i+3)) ok = false;
                    if (dl(i+3, i)) ok = false;
                    if(ok)upd(f[i][0][4 + x * 2], f[i+1][0][k]);
                     //if (ok) puts("fuck3");
                }
               
            }

            // j = 1, i+1 i+3 i+2
           // printf("?? %d %d %d\n",x,y,z);
            if (f[i+1][1][k]) {
                if (x) { 
                    //   (i+1)---1---(i+3)---y---(i+2)---z---(i+1)
                    //-->(i+1)---1---(i)---0---(i+2)---z---(i+1)
                    ok = true;
                    if (dl(i,i+3)) ok = false;
                    if (y && dl(i+3,i+2)) ok = false;
                    if(ok)upd(f[i][1][z * 2 + 1],f[i+1][1][k]);
                    //if (ok) puts("fuck4");
                }
                
                if (y) {
                    //   (i+1)---x---(i+3)---1---(i+2)---z---(i+1)
                    //-->(i+1)---0---(i)---1---(i+2)---z---(i+1)
                    ok = true;
                    if (dl(i+3,i)) ok = false;
                    if (x && dl(i+1,i+3)) ok = false;
                    if(ok)upd(f[i][1][4 + 2 * z],f[i+1][1][k]);
                    //if (ok) puts("fuck5");
                }
                
                if (z) {
                    //   (i+1)---x---(i+3)---y---(i+2)---1---(i+1)
                    //-->(i+1)---0---(i+2)---1---(i)---1---(i+1)
                    ok = true;
                    if (x && dl(i+1,i+3)) ok = false;
                    if (y && dl(i+3,i+2)) ok = false;
                    if(ok)upd(f[i][0][5],f[i+1][1][k]);
                    // if (ok) puts("fuck6");
                }
               
            }
        }
        if (i == 1) {
            for (int k=0;k<8;k++) {
                int x,y,z;
                x = (k & 4) ? 1 : 0;
                y = (k & 2) ? 1 : 0;
                z = (k & 1) ? 1 : 0;
                if (!((x && dl(i,i+1)) || (y && dl(i+1,i+2)) || (z && dl(i+2,i)))) {
                    upd(ans, f[i][0][k]);
                }
                if (!((x && dl(i,i+2)) || (y && dl(i+2,i+1)) || (z && dl(i+1,i)))) {
                    upd(ans, f[i][1][k]);
                }
            }
        }

        /*
        for (int k=0;k<8;k++) {
            printf("f[%d][0][%d] = %d\n",i,k,f[i][0][k]);
            printf("f[%d][1][%d] = %d\n",i,k,f[i][1][k]);
        }
        */
    }
    printf("%d\n",ans);
}