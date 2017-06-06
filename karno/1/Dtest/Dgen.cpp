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
	srand(time(NULL));
	int n, m, x;
	n = rand()%(100000-10)+10;
	m = rand()%100000+10;
	x = rand()%1000000000;
	cout << n << ' ' << m << ' ' << x << '\n';
	for(int i = 0; i < m; i++){
		int fi, se, th;
		fi = rand()%n, se = rand()%n, th=rand()%1000000000;
		cout << fi + 1<< ' ' << se+1<< ' ' << th << '\n';
	}
	return 0;
}
