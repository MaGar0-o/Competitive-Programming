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

pii fnd[10] = {MP(3, 1),
	MP(0, 0), MP(0, 1), MP(0, 2),
	MP(1, 0), MP(1, 1), MP(1, 2),
	MP(2, 0), MP(2, 1), MP(2, 2)};

bool can(int num){
	vector<int> dig;
	while(num)
		dig.PB(num%10), num /= 10;
	reverse(all(dig));
	pii pos(0, 0);
	for(auto d : dig){
		pii tmp = fnd[d];
		if(tmp.L < pos.L or tmp.R < pos.R)
			return false;
		pos = tmp;
	}
	return true;
}

void solve(void){
	int n;
	cin >> n;
	int tmp = n;
	if(can(n)){
		cout << n << endl;
		return;
	}
	while(n--){
		tmp++;
		if(can(n)){
			cout << n << endl;
			return;
		}
		else if(can(tmp)){
			cout << tmp << endl;
			return;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
