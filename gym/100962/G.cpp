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

bool isprime(int x){
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k = 0;
	//cin >> k;
	int n = 10000;
	cout << n << '\n';
	for(int i = n / 2; i < n - 100; i++)
		if(isprime(i) and isprime(n - i)){
			//for(int j = 0; j < n - 1; j++)
			//	cout << (j * i)%n + 1 << ' ' << ((j + 1) * i)%n + 1 << '\n';
			k++;
		}
	cout << k << endl;
	return 0;
}
