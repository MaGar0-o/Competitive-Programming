#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+9;
int a[MAX],l=0,r=MAX-1,n,b[MAX],dp[MAX],pr[MAX],root,k;
vector<int> g[MAX];
void dfs(int v,int p=-1)
{
	dp[v]=b[v];
	for (auto u:g[v])
		if (u!=p)
		{
			dfs(u,v);
			if (pr[u]) dp[v]+=dp[u];
			else dp[v]+=max(dp[u],0);
		}
}
int build(int v,int p=-1)
{
	int ret=pr[v];
	for (auto u:g[v])
		if (u!=p)
			ret|=build(u,v);
	pr[v]=ret;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0,x;i<k;i++) cin>>x,x--,pr[x]=1,root=x;
	for (int i=1,v,u;i<n;i++) cin>>v>>u,v--,u--,g[v].push_back(u),g[u].push_back(v);
	build(root);
	while (l<r-1)
	{
		int mid=l+r>>1;
		for (int i=0;i<n;i++) 
			if (a[i]>=mid) 
				b[i]=+1;
			else
				b[i]=-1;
		dfs(root);
		if (dp[root]>=0) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
