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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	s.pop_back();
	int H = count(all(s), 'H');
	int M = count(all(s), 'M');
	if(n == 1)
		cout << "HM";
	else if(H == M)
		cout << (s.back() == 'M' ? 'H' : 'M');
	else if(H > M)
		cout << 'H';
	else
		cout << 'M';
	return 0;
}
