//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>
#include "testlib.h"

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

const int maxn = 100;
vector<string> word[maxn][maxn],
	dict[maxn],
	all;
int cnt[maxn];

int main(int argc, char *argv[]){
	registerGen(argc, argv, 1);

	char ord[26];
	for (int i = 0; i < 26; i++)
		ord[i] = 'a' + i;
	shuffle(ord, ord + 26);

	int n = rnd.next(1, 50);
	int m = rnd.next(1, 50);
	int r = rnd.wnext(1, 26, 2);
	cout << n << ' ' << m << ' ' << r << '\n';

	for (int i = 0; i < m; i++) {
		int wcnt = rnd.wnext(1, 100, 2);
		memset(cnt, 0, sizeof cnt);
		for (int j = 0; j < wcnt; j++)
			cnt[rnd.next(26)]++;

		for (int j = 0; j < 26; j++)
			for (int k = 0; k < cnt[j]; k++) {
				word[i][j].PB(char('a' + j) + rnd.next("[a-z]{0,9}"));
				dict[i].PB(word[i][j].back());
				all.PB(dict[i].back());
			}
		
		shuffle(all(dict[i]));
		for(int j = 0; j < sz(dict[i]); j++)
			cout << dict[i][j] << " \n"[j == sz(dict[i]) - 1];
	}
	shuffle(all(all));
	for (int i = 0; i < r; i++) {
		cout << ord[i] << '\n';
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				int id = rnd.next(0, sz(word[k][ord[i] - 'a']));
				if (id == sz(word[k][ord[i] - 'a']))
					cout << (rnd.next(2) ? all[rnd.next(sz(all))] : "EMPTY");
				else
					cout << word[k][ord[i] - 'a'][id];
				cout << " \n"[k == m - 1];
			}

	}
	return 0;
}
