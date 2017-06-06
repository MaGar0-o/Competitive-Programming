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

const int maxn = 2e6;
int next1[maxn],
	next2[maxn],
	n, m;

int nxt1(int ptr){return next1[ptr] == ptr ? ptr : next1[ptr] = nxt1(next1[ptr]);}
int nxt2(int ptr){return next2[ptr] == ptr ? ptr : next2[ptr] = nxt2(next2[ptr]);}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < maxn; i++)
		next1[i] = next2[i] = i;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi = nxt1(fi);
		while(fi <= se){
			next1[fi] = fi + 1;
			fi = nxt1(fi);
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi = nxt2(fi);
		while(fi <= se){
			next2[fi] = fi + 1;
			fi = nxt2(fi);
		}
	}
	for(int i = 0; i < n; i++)
		if(next2[i] != i or next1[i] == i)
			cout << i << ' ';
	cout << '\n';
	return 0;
}
