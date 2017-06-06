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

int a[100], n;

bool check(int a1, int a2){
	vector<int> vec;
	for(int i = a1; i < n; i++)
		if(i != a2)
			vec.PB(a[i]);
	sort(all(vec));
	for(int i = 0; i < sz(vec); i++)
		if(vec[i] > a1 + i + 1)
			return false;
	return a[a2] <= a1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < n; j++)
			if(str[j] == '1')
				a[i] = j;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << a[j] << ' ';
		cout << endl;
		int val = 0;
		for(int j = i; j < n; j++)
			if(check(i, j))
				for(int k = j; k > i; k--)
					swap(a[k], a[k - 1]), val++;
		cout << val << endl;
		ans += val;
	}
	cout << ans << '\n';
	return 0;
}
