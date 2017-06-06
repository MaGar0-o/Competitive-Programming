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

const int maxn = 111 ; 

int a[maxn] , b[maxn] , cnt[2][maxn]; 

bool mark[2][110] ; 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n , m ;
	while(cin >> n >> m && n != -1 ) 
	{
		memset(mark,0,sizeof mark) ; 
		memset(cnt,0,sizeof cnt) ; 
		multiset<int> s[2] ; 
		for(int i = 0 ; i < n ; i ++ ) 
		{
			cin >> a[i] ; 
			cnt[0][a[i]]++;  
			s[a[i]&1].insert(a[i]) ; 
			if(a[i]&1){
				if(a[i]<55)mark[0][a[i]*2+2] = 1;
			}
			else 
				mark[0][a[i]] = 1; 
		}
		multiset<int> t[2] ; 
		for(int i = 0 ; i < m ; i ++ ) 
		{
			cin >> b[i] ; 
			cnt[1][b[i]]++ ; 
			t[b[i]&1].insert(b[i]) ;
			if(b[i]&1){
				if(b[i]<55)mark[1][2*b[i]+2] = 1 ;
			}
			else
				mark[1][b[i]] = 1; 
		}
		if(s[1].size()!=t[1].size())
		{
			cout<<'N'<<'\n';
			continue ; 
		}
		bool N = 0 ; 
		while(s[1].size()){
			if(*s[1].begin()!=*t[1].begin())
			{
				N = 1 ;
				break ; 
			}
			s[1].erase(s[1].begin()) ; 
			t[1].erase(t[1].begin()) ;
		}
		for(int i = 0 ; i < n ; i ++ ) 
		{
			if(cnt[0][a[i]]>cnt[1][a[i]]&&!mark[1][a[i]]) 
				N = 1 ;
		}
		for(int i = 0 ; i < m ; i ++ ) 
			if(cnt[1][b[i]]>cnt[0][b[i]]&&!mark[0][b[i]])
				N = 1 ; 
		cout<<(N?'N':'Y')<<'\n';

	}
	return 0;
}

