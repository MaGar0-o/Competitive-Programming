#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+9;
int n,q,v[MAX],u[MAX],b[MAX],c[MAX],w[MAX],res[MAX],ans,p[MAX],f[MAX];
struct trie{
	vector<pair<int,int> > c;
	vector<int> d;
	int cnt=1;
	void add(int v)
	{
		int p=0;
		d.push_back(v);
		for (int i=30;i>=0;i--)
			if (v>>i&1)
			{
				if (c[p].second==-1) c[p].second=cnt++,c.push_back({-1,-1});
				p=c[p].second;
			}
			else
			{
				if (c[p].first==-1) c[p].first=cnt++,c.push_back({-1,-1});
				p=c[p].first;	
			}
	}
	int get(int v)
	{
		int p=0,k=0;
		for (int i=30;i>=0;i--)
			if ((!(v>>i&1)) && c[p].second!=-1)
				p=c[p].second,k+=(1<<i);
			else
			if ((v>>i&1) && c[p].first!=-1)
				p=c[p].first;
			else
			if (c[p].first!=-1)
				p=c[p].first;
			else
				p=c[p].second,k+=(1<<i);
		return v^k;
	}
}t[MAX];
int root(int v){return f[v]<0?v:f[v]=root(f[v]);}
void merge(int v,int u,int w)
{
	if (t[root(v)].d.size()<t[root(u)].d.size()) swap(v,u);
	for (auto uu:t[u].d) p[uu]=p[uu]^p[u]^w^p[v],t[root(v)].add(p[uu]),ans=max(ans,t[root(v)].get(p[uu]));
	f[root(u)]=root(v);
}
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0),memset(f,-1,sizeof f);
	cin>>n>>q;
	for (int i=0;i<n;i++) t[i].c.push_back({-1,-1}),t[i].add(0);
	for (int i=1;i<n;i++) cin>>v[i]>>u[i]>>w[i],v[i]--,u[i]--;
	for (int i=0;i<q;i++) cin>>b[i],c[b[i]]=1;
	for (int i=1;i<n;i++) if (!c[i]) merge(v[i],u[i],w[i]);
	for (int i=q-1;i>=0;i--) merge(v[b[i]],u[b[i]],w[b[i]]),res[i]=ans;
	for (int i=0;i<q;i++) cout<<res[i]<<'\n';
}
