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

const int maxn = 1000 + 10;
string name[maxn],
	   s[maxn];
int ord[maxn],n;

bool cmp(int i, int j){
	return (s[i] != s[j]) ? s[i] > s[j] : name[i] < name[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> name[i];
		name[i].pop_back();
		string str;
		while(cin >> str and str != "class")
			s[i] += str[0];
		reverse(all(s[i]));
		while(sz(s[i]) < 60)
			s[i] += 'm';
	}
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	for(int i = 0; i < n; i++)
		cout << name[ord[i]] << '\n';
	return 0;
}
