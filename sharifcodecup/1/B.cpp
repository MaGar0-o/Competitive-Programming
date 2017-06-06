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

const int maxval = 1000 * 1000 * 10;
bool isprime[maxval];
LL P[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i < 10; i++)
		P[i] = P[i - 1] * 10;
	memset(isprime, true, sizeof isprime);
	isprime[0] = isprime[1] = false;
	for(int i = 0; i * i < maxval; i++)
		if(isprime[i])
			for(int j = i * i; j < maxval; j += i)
				isprime[j] = false;
	string s;
	while(cin >> s and s != "0"){
		if(s == "10000000"){
			cout << "non-circular prime\n";
			return 0;
		}
		int num = 0;
		for(int i = 0; i < sz(s); i++)
			s[i] -= '0', num = num * 10 + s[i];
		bool isp = true;
		for(int i = 0; i < sz(s); i++){
			if(!isprime[num])
				isp = false;
			num = num * 10 - s[i] * P[sz(s)] + s[i];
		}
		if(isp)
			cout << "circular prime\n";
		else
			cout << "non-circular prime\n";
	}
	return 0;
}
