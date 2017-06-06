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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	if(a <= 0 and b >= 0){
		cout << "Zero" << endl;
		return 0;
	}
	if(a > 0){
		cout << "Positive" << endl;
		return 0;
	}
	if(b > 0){
		a = -a;
		if(a & 1)
			cout << "Negative" << endl;
		else
			cout << "Positive" << endl;
		return 0;
	}
	a += b+1;
		if(a & 1)
			cout << "Negative" << endl;
		else
			cout << "Positive" << endl;
	return 0;
}
