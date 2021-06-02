#include <bits/stdc++.h>  
using namespace std;  
typedef long long LL;  
struct Node{  
    LL t,w;  
    Node(LL t = 0,LL w =0):t(t),w(w){}  
    friend bool operator < (Node a,Node b)
	{  
        return a.t < b.t || (a.t == b.t && a.w > b.w);  
    }  
};  

priority_queue<LL,vector<LL>,greater<LL> >q1;  
priority_queue<Node>q2;  

int main(){  
    LL t1,w1;  
    int n;  
    scanf("%d",&n);  
    scanf("%I64d%I64d",&t1, &w1);  
    for (int i=1;i<n;i++)
	{  
        LL t,w;  
        scanf("%I64d%I64d",&t,&w);  
        if (t>t1) q1.push(w-t);  
        else q2.push(Node(t,w));  
    }  
    LL ans = q1.size()+1;  
    while(!q1.empty() && q1.top() + 1 <= t1)
	{  
        t1 -= q1.top() + 1;  
        q1.pop();  
        while(!q2.empty() && q2.top().t > t1)
		{  
            Node u = q2.top();
			q2.pop();  
            LL tt = u.w-u.t;  
                q1.push(tt);  
        }  
        ans = min(ans,LL(q1.size()+1));  
    }  
    printf("%I64d\n",ans);  
    return 0;  
}  


