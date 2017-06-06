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

map<string, int> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	mp["Alice"] = mp["Ariel"] = mp["Aurora"] = mp["Phil"] = mp["Peter"] = mp["Olaf"] = mp["Phoebus"] = mp["Ralph"] = mp["Robin"] = 0;
	mp["Bambi"] = mp["Belle"] = mp["Bolt"] = mp["Mulan"] = mp["Mowgli"] = mp["Mickey"] = mp["Silver"] = mp["Simba"] = mp["Stitch"] = 1;
	mp["Dumbo"] = mp["Genie"] = mp["Jiminy"] = mp["Kuzko"] = mp["Kida"] = mp["Kenai"] = mp["Tarzan"] = mp["Tiana"] = mp["Winnie"] = 2;
	int n;
	cin >> n;
	int ans = 0,
		pos = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		ans += abs(pos - mp[s]);
		pos = mp[s];
	}
	cout << ans << endl;
	return 0;
}
