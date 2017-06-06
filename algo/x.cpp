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

priority_queue<int, vector<int>, less<int> > pq;
set<int, greater<int> > s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//sort(a, a + n, greater<int>());
	for(int i = 0; i < 5; i++)
		pq.push(i), s.insert(i);
	cout << pq.top() << ' ' << *s.begin() << endl;
	return 0;
}
