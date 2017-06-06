//sobskdrbhveck
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long long LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LD> point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define x real()
#define y imag()

const int maxn = 100;
const LD Eps = 1e-5,
	Inf = 1e9;
int a[maxn],
	b[maxn],
	n;
vector<pair<point,int> > vec;
vector<pii > ans;

LL zcross(point a,point b){
	return a.x * b.y - a.y * b.x;
}

int sign(point a,point b)
{
	LL c = zcross(a, b);
	if (c < 0) return -1;
	if (c > 0) return +1;
	return 0;
}

bool ch(vector<point> vec, int a, int b)
{
	int n = vec.size();
	if (a == b || (a + 1) % n == b || (b + 1) % n == a) return false;
	for (int i = 0; i < n; i++) 
		if (i != a && (i + 1) % n != a && i != b && (i + 1) % n != b)
		{
			int j = (i + 1) % n;
			if (sign(vec[a] - vec[j], vec[b] - vec[j]) and sign(vec[a] - vec[i],vec[b] - vec[i]) and sign(vec[a] - vec[j], vec[b] - vec[j]) != sign(vec[a] - vec[i], vec[b] - vec[i]) and sign(vec[i] - vec[a], vec[j] - vec[a]) != sign(vec[i] - vec[b], vec[j] - vec[b]))
				return false;
		}
	for (int i = 0; i < n; i++)
		if (i != a && i != b and !sign(vec[i] - vec[a], vec[i] - vec[b]) and vec[i].x <= max(vec[a].x, vec[b].x) and vec[i].x >= min(vec[a].x, vec[b].x) and vec[i].y <= max(vec[a].y, vec[b].y) and vec[i].y >= min(vec[a].y, vec[b].y)) 
			return false;
	long double tmp = 0;
	complex<long double> c, d, e;
	c = {(vec[a].x + vec[b].x) / 2.0, (vec[a].y + vec[b].y) / 2.0};
	for (int i = 0; i < n; i++){
		d = {vec[i].x * 1.0, vec[i].y * 1.0};
		e = {vec[(i + 1) % n].x * 1.0, vec[(i + 1) % n].y * 1.0};
		tmp += arg((d - c) / (e - c));
	}
	return abs(tmp) > 1;
}

vector<pii> cal(vector<pair<point,int> > vec){
	int n = sz(vec);
	vector<pii> ans, l, r;
	vector<pair<point,int> > le, ri;
	if (n == 3) return ans;
	pii sm = {Inf, Inf}, k;
	vector<point> u;
	for (int i = 0; i < n; i++) u.PB(vec[i].first);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ch(u,i,j) && sm > make_pair(vec[i].second,vec[j].second))
				sm = {vec[i].second, vec[j].second}, k = {i, j};
	for (int i = 0; i < n; i++){
		if (i <= k.first || i >= k.second)
			le.PB(vec[i]);
		if (i >= k.first && i <= k.second) 
			ri.PB(vec[i]);
	}

	l = cal(le), r = cal(ri);
	ans.PB(sm);
	if (l<r){
		for (auto i: l)
			ans.PB(i);
		for (auto i: r)
			ans.PB(i);
	}
	else{
		for (auto i: r)
			ans.PB(i);
		for (auto i: l)
			ans.PB(i);	
	}
	return ans;	
}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) cin>>b[i],vec.PB({{a[i],b[i]},i});
	ans = cal(vec);
	sort(ans.begin(), ans.end());
	for (auto i:ans) cout << i.first << " " << i.second << '\n';
	return 0;
}

