//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long long ll ; 


#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define TOF 150

const int MAXN = 301 * 1001 ; 

int par[MAXN] , mn[MAXN] , mx[MAXN] , a[MAXN] , b[MAXN] , dsu[MAXN] ;

vector<pair<int,pair<int,int>>> edge , mst ; 

int root(int x, int *arr = par)
{
	return (arr[x]<0?x:arr[x]=root(arr[x]));
}

bool merge(int u, int v){
	if((u=root(u, dsu)) == (v=root(v, dsu)))
		return false;
	if(dsu[u] > dsu[v]) swap(u, v);
	dsu[u] += dsu[v];
	dsu[v] = u;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dsu, -1, sizeof dsu);
	int n,m; 
	cin >> n >> m ; 
	for(int i = 0 ; i < n ; i ++ ) 
		cin >> a[i] >> b[i] , mn[i] = b[i] , mx[i] = a[i] , par[i] = -1 ;
	for(int i = 0 ; i < m ; i ++ ) 
	{
		int x,y,c;
		cin >> x >> y >> c ;  
		x--,y--;
		c = max({c,a[x],a[y]}) ; 
		edge.PB({c,{x,y}}) ; 
	}
	sort(edge.begin(),edge.end()) ; 
	for(auto e : edge)
		if(merge(e.S.F, e.S.S))
			mst.PB(e);
	srand(time(0));
	ll ansall = 1e18;
	for(int _ = 0 ; _ < TOF ; _ ++ )
	{
		for(int i = 0; i < n; i++)
			mn[i] = b[i], mx[i] = a[i], par[i] = -1;
		for(int __ = 0; __ < 20; __++) for(auto u : mst)
		{
			int x = u.S.F , y = u.S.S , c = u.F ; 
			x = root(x) , y = root(y) ; 
			if(x==y)
				continue ; 
			ll c1 = 1LL * mn[x] * mx[x] + 1LL * mn[y] * mx[y] ; 
			ll c2 = 1LL * min(mn[x],mn[y]) * max({mx[x],mx[y],c}) ; 
			if(c2>c1)
				continue ; 
			if(par[x] > par[y]) swap(x, y);
			mn[x] = min(mn[x],mn[y]);
			mx[x] = max({mx[x],mx[y],c}) ; 
			par[x] += par[y];
			par[y] = x ;
		}
		ll ans = 0 ; 
		for(int i = 0 ; i < n ; i ++ )
			if(par[i]>>31)
				ans += 1LL * mn[i] * mx[i] ; 
		smin(ansall, ans);
		random_shuffle(all(mst));
	}
	cout << ansall << endl;
	return 0;
}
