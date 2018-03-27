#include <bits/stdc++.h>

using namespace std;
using llint = long long;

const int N = 1e5 + 10, SIG = 27;

vector <int> e[N << 1];
char s[N];

struct Node {
  Node *ch[SIG], *fa;
  int sz;
  int len;
  int sg;
  Node() : len(0), fa(NULL), sz(0) ,sg(-1){
    memset(ch, 0, sizeof(ch));
  }
} pool[(N << 1) + 5], *last, *root;

void add_edge(int x, int y) {
  e[x].push_back(y);
}

namespace SAM {

int cnt;

void init() {
  if (cnt)
    for (int i = 0; i < cnt; ++i)
      pool[i] = Node(), pool[i].sg = -1;
  cnt = 1;
  root = &pool[0];
  last = root;
}

void add(int c) {
  Node *np = &pool[cnt++];
  np->sz = 1;
  np->len = last->len + 1;
  Node *p = last;
  while (p && !p->ch[c]) {
    p->ch[c] = np;
    p = p->fa;
  }
  if (!p) {
    np->fa = root;
  } else {
    Node *q = p->ch[c];
    if (q->len != p->len + 1) {
      Node *nq = &pool[cnt++];
      nq->len = p->len + 1;
      for (int i = 0; i < SIG; ++i) nq->ch[i] = q->ch[i];
      nq->fa = q->fa;
      //nq->sz should be 0 because q->fa = nq, in later code q->sz will be added to q->fa->sz i.e. nq->sz, so no nq->sz = q->sz
      //nq->sz = q->sz;
      q->fa = np->fa = nq;
      while (p && p->ch[c] == q) {
	p->ch[c] = nq;
	p = p->fa;
      }
    } else {
      np->fa = q;
    }
  }
  last = np;
}

int dfs(Node *p) {
	if (p->sg != -1) return p->sg;
	set<int>mex;
 	for (int i=0;i<26;i++)
 	{
 		Node *np;
		np = p->ch[i];
		if (np == NULL) continue;	
		//printf("%d %d\n",np->len,p->len);
		if (np->len < p->len + 1) continue;
		mex.insert(dfs(np));
	}
	for (int i=0;;i++)
	if (mex.find(i) == mex.end())
	{
		p->sg = i;
		break;
	}
	return p->sg;
}

}

int M;
char ss[100010];

int main() {
  while(scanf("%s",s) != EOF)
  {
		SAM::init();
		int m = strlen(s);
		for (int i=0;i<m;i++)SAM::add(s[i]-'a');
		//printf("%d\n",SAM::cnt);
		SAM::dfs(root);
		scanf("%d",&M);
		int ans = 0;
		for (int i=1;i<=M;i++)
		{
			scanf("%s",ss);
			int len = strlen(ss);
			Node *p = root;
			for (int j=0;j<len;j++)
			{
				p = p->ch[ss[j]-'a'];
			}
			ans ^= p->sg;
		}
		puts(ans?"Alice":"Bob");
		//return 0;
  }
}

