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

const int maxn = 1000 + 85 - 69;
string s[maxn];
int n, m, sup[maxn], has[maxn][3], func[128], ord[maxn];;

void naa(void){
	cout << "Let's go to the park\n";
	exit(0);
	return;
}

void check(void){
	for(int j = 0; j < m; j++){
		int mx = -1;
		for(int i = n - 1; i >= 0; i--)
			if(s[i][j] == 's'){
				if(mx > 1)
					naa();
				else mx = 1;
			}
			else if(s[i][j] == 'n'){
				if(mx > 2) naa();
				else mx = 2;
			}
			else if(s[i][j] == 't') mx = 3;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	func['s'] = 0, func['n'] = 1, func['t'] = 2;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> s[i];
	int lo, no, hi;
	cin >> lo >> no >> hi;
	check();
	fill(sup, sup + m, n);
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			if(s[i][j] == 's'){
				sup[j] = i;
				break;
			}
	for(int j = 0; j < m; j++)
		for(int i = sup[j]; i < n; i++)
			if(s[i][j] == '#' and lo)
				s[i][j] = 's', lo--;
	while(lo){
		int tmp = lo;
		for(int j = 0; j < m; j++){
			int id = sup[j];
			if((sup[j] and s[sup[j] - 1][j] == '#') and lo)
				s[--sup[j]][j] = 's', lo--;
		}
		if(tmp == lo) naa();
	}
	fill(sup, sup + m, n);
	for(int j = 0; j < m; j++)
		for(int i = 0; i < n; i++)
			if(s[i][j] == 's' or s[i][j] == 'n'){
				sup[j] = i;
				break;
			}
	for(int j = 0; j < m; j++)
		for(int i = sup[j]; i < n; i++)
			if(s[i][j] == '#' and no)
				s[i][j] = 'n', no--;
	while(no){
		int tmp = no;
		for(int j = 0; j < m; j++){
			if((sup[j] and s[sup[j] - 1][j] == '#') and no)
				s[--sup[j]][j] = 'n', no--;
		}
		if(tmp == no) naa();
	}
	memset(sup, 0, sizeof sup);
	for(int j = 0; j < m; j++)
		for(int i = sup[j]; i < n; i++)
			if(s[i][j] == '#' and hi)
				s[i][j] = 't', hi--;
	check();
	if(lo or no or hi) naa();
	for(int i = 0; i < n; i++)
		cout << s[i] << '\n';
	return 0;
}
