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

#define int LL

main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	vector<int> ans,
		vec[2];
	cin >> a >> b;
	if(a > b) swap(a, b);
	ans.PB(a);
	ans.PB(b);
	int p1 = a, p2 = b;
	while(p1^p2){
		if(p1 > p2) vec[0].PB(p1), p1>>=1;
		else vec[1].PB(p2), p2>>=1;
	}
	if(p1 == a){
		cout << -1 << '\n';
		return 0;
	}
	reverse(all(vec[0]));
	reverse(all(vec[1]));
	for(int i = 1; i < sz(vec[0]); i++)
		ans.PB(vec[0][i]^1);
	for(int i = 1; i < sz(vec[1]); i++)
		ans.PB(vec[1][i]^1);
	while(p1^1)ans.PB(p1^1), p1>>= 1;
	sort(all(ans));
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}
