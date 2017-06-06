//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int MAXN = 2*101 * 1001 ; 

int from[MAXN] , to[MAXN] , cap[MAXN] , prv[MAXN] , head[MAXN] , ecnt ; 
int pos[MAXN];

vector<pair<int,int> > yal ; 

void add_edge(int v , int u , int c )
{
	from[ecnt] = v , to[ecnt] = u , cap[ecnt] = c , prv[ecnt] = head[v] , head[v] = ecnt++  ;
	from[ecnt] = u , to[ecnt] = v , cap[ecnt] = 0 , prv[ecnt] = head[u] , head[u] = ecnt++  ;
}

int n , m ,s , t , c ; 

int d[MAXN]; 

bool bfs(int s , int t)
{
	queue<int> q ;
	q.push(s) ; 
	memset(d,0,n*4) ; 
	d[s] = 1 ;
	while(q.size())
	{
		int x = q.front() ; q.pop() ; 
		if(x==t)return 1 ;
		for(int e = head[x] ; e != -1 ; e = prv[e])
		{
			if(cap[e]){
				int u = to[e] ; 
				if(!d[u])q.push(u),d[u] = d[x] + 1 ; 
			}
		}
	}
	return 0 ; 
}

int dfs(int s , int t , int flow = c ) 
{
	if(s==t) return flow ; 
	int ans = 0 ; 

	for(int &e = pos[s] ; e > -1 ; e = prv[e] )
	{
		int u = to[e] , ca = cap[e] ; 
		if(d[u]==d[s]+1&&ca)
		{
			int x = min(dfs(u,t,min(flow, ca)),ca) ;
			x = min(x,flow) ; 
			ans += x ;
			flow -= x ; 
			cap[e] -= x ;
			cap[e^1] += x ;
			if(!flow)
				return ans ; 
		}
	}
	return ans ; 

}

int F ; 

bool check(int x)
{
	ecnt = 0 ; 
	memset(head,-1,n*4) ; 
	for(int i = 0 ; i < sz(yal) ; i ++ ) 
		add_edge(yal[i].L,yal[i].R,x) ; 
	F = 0 ; 
	while(bfs(s,t)){
		//cout << "HI" << endl;
		memcpy(pos, head, n * 4);
		F += dfs(s,t,c) ; 
		//cout << "Bye" << endl;
	}
	//cout<<'*'<<F<<' '<<c<<'\n';
	return F>=c ; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	int n , m ,s , t , c ; 
	while(cin >> n >> m >> s >> t >> c&&n)
	{
		s--,t--;
		yal.clear() ; 
		for(int i = 0 ; i < m ; i ++ ) 
		{
			int x , y ;
			cin >> x >> y ; 
			x--,y--;
			yal.PB(MP(x,y)) ; 
		}	
		int l = -1 , r = c ;
		//cout<<"@" <<check(3)<<' ' ;
		//cout << F << endl;
		while(r-l>1)
		{
			int mid = (r+l) / 2 ;
			if(check(mid))
				r = mid ; 
			else
				l = mid ;
		}
		check(r) ;
		int e = F / r ; 
		cout<<1LL * (F-c) * l * l * l + 1LL * (e-F+c)*r*r*r <<'\n'; 
	}

}

