/// In the name of God 
#include <bits/stdc++.h> 
//#define int long long 
using namespace std; 
typedef pair<int,int> pii; 
typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi; 
#define X first 
#define Y second 
#define all(o) o.begin(), o.end() 
#define IOS ios::sync_with_stdio(0), cin.tie(0) 
#define endl '\n' 
const int maxn = 10000 + 10; 
int a[maxn], A[maxn]; 
vi adj[maxn]; 
int ok(int v){ 
	int idx = -1, mn = 1e9; 
	for(int u : adj[v]){ 
		mn = min(mn, a[u]); 
		if(mn == a[u]) idx = u; 
	} 
	if(mn < a[v]){ 
		swap(a[idx], a[v]); 
		return ok(idx) + 1; 
	} 
	return 0; 
} 
int main(){ 
	int n; 
	cin >> n; 
	if(n > maxn - 10) return 0; 
	for(int i=0; i<n; i++){ 
		cin >> a[i]; 
		A[i] = a[i]; 
	} 
	int ans = 0; 
	for(int k=2; k<n; k++){ 
		copy(A, A + n, a); 
		for(int i=0; i<n; i++) 
			adj[i].clear(); 
		for(int i=1; i<n; i++) 
			adj[(i - 1) / k].push_back(i); 
		for(int i=n; i--; ) 
			ans += ok(i); 
	} 
	cout << ans << endl; 
} 
