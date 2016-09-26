//sobskdrbhvk
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

const int maxn = 20;
string s[maxn];
int mon[maxn],
	mon2[maxn];
int n;

int F(string str){
	return find(s, s + n, str) - s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++){
		string name;
		int k, id;
		cin >> name;
		cin >> mon[id = F(name)] >> k;
		for(int i = 0; i < k; i++){
			string name2;
			cin >> name2;
			int id2 = F(name2);
			mon2[id2] += mon[id] / k;
		}
		if(k) mon2[id] += mon[id] % k;
	}
	for(int i = 0; i < n; i++)
		cout << s[i] << ' ' << mon2[i] - mon[i] << '\n';
	return 0;
}
