//sobskdrbhvk
//remember the flying, the bird dies ):(
//INOI 26 -- Bronze Cut Round #2 -- Problem 3 (CELERY)
#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int n;
vector<int> all;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0, c; i < n; i++){
		vector<int> vec;
		cin >> c;
		for(int j = 0, x; j < c; j++){
			cin >> x;
			vec.PB(x);
		}
		for(int j = c - 2; j >= 0; j--)
			smin(vec[j], vec[j + 1]);
		for(auto val : vec)
			all.PB(val);
	}
	sort(all(all));
	all.PB(0);
	for(int i = 0; i < sz(all); i++)
		if(all[i] < i + 1){
			cout << i << endl;
			return 0;
		}
	return 0;
}
