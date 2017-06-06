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
	int a[2][3];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++)
			cin >> a[i][j];
		sort(a[i], a[i] + 3);
	}
	for(int j = 0; j < 3; j++)
		if(a[0][j] ^ a[1][j]){
			cout << "NO";
			return 0;
		}
	if(a[0][0] * a[0][0] + a[1][1] * a[1][1] == a[0][2] * a[0][2])
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
