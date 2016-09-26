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
	cin >> k >> n;
	for(int i = 0; i < k; i++)
		cin >> ax[i] >> ay[i];
	for(int i = 0; i < n; i++)
		cin >> bx[i] >> by[i];
	for(int j = 0; j < k; j++)
		ord[j] = j;
	for(int i = 0; i < n; i++){
		do{
			int id = find_id(ord[k - 1], i);
			int iid = find_pos(id, i);
			int kid = idof[ord[k - 1]][id];
			if(abs(iid - kid) > k)
				continue;
			for(int j = k - 1;
		}while(next_permutation(ord, ord + k));
	}
	return 0;
} 
