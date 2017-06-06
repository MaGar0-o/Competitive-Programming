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

string s[100];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i + 1 < n; i++){
		cout << s[i] << " to " << s[i + 1] << ": ke ba in dar agar dar bande dar manand, dar manand.\n";
		for(int j = i + 1; j - 1 >= 0; j--)
			cout << s[j] << " to " << s[j - 1] << ": dar manand?\n";
		for(int j = 0; j <= i; j++)
			cout << s[j] << " to " << s[j + 1] << ": dar manand.\n";
	}
	return 0;
} 
