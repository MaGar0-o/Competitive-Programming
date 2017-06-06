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

const int maxn = 1000 * 100 + 10;
int a[maxn],
	q1[maxn],
	q2[maxn],
	ans[maxn],
	n, q;
deque<int> deq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < q; i++){
		cin >> q1[i] >> q2[i];
		q1[i]--, q2[i]--;
	}
	int r = -1;
	for(int i = 0; i < q; i++){
		while(r < q2[i]){
			++r;
			while(sz(deq) and a[deq.front()] < a[r])
				deq.pop_front();
			deq.push_front(r);
		}
		while(deq.back() < q1[i]) deq.pop_back();
		ans[i] = deq.back();
	}
	for(int i = 0; i< q; i++)
		cout << a[ans[i]] << ' ';
	cout << '\n';
	return 0;
}
