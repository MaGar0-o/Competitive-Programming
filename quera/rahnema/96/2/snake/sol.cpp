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

string chr = "^>v<";

const int maxt = 500,
	  maxn = 10;
deque<pii> dq;
string s[maxn];
int tim[maxt],
	remp[maxt],
	cemp[maxt];
char com[maxt];
bool mark[maxt];
int n, m, p, q, T, dir, sx, sy;

void get_food(int &cur) {
	for (int j = 0; j < p; j++)
		if (!mark[j] and s[remp[j]][cemp[j]] == '.') {
			cur = j;
			mark[j] = true;
			s[remp[j]][cemp[j]] = 'A';
			break;
		}
	return;
}

void print(int turn) {
	pii pos(dq.front());
	s[pos.L][pos.R] = chr[dir];
	cout << turn << endl;
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	s[pos.L][pos.R] = '#';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> T
		>> sx >> sy;
	sx--, sy--;
	cin >> p;
	for (int i = 0; i < p; i++) {
		cin >> remp[i] >> cemp[i];
		remp[i]--, cemp[i]--;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
		cin >> com[i] >> tim[i];

	int dx[] = {n - 1, n + 0, n + 1, n - 0},
		dy[] = {m - 0, m + 1, m + 0, m - 1};

	for (int i = 0; i < n; i++)
		s[i].resize(m, '.');
	s[sx][sy] = '#';
	dq.push_back({sx, sy});
	int ptr = 0,
		curemp = -1;
	get_food(curemp);
	print(0);
	for (int i = 1; i <= T; i++) {
		
		if (ptr < q and tim[ptr] == i){
			dir = (dir + 4 + (com[ptr] == 'L' ? -1 : +1)) & 3;
			ptr++;
		}

		pii pos(dq.front());
		pii npos((pos.L + dx[dir]) % n, (pos.R + dy[dir]) % m);
		
		if (s[npos.L][npos.R] == 'A')
			curemp = -1;
		else {
			pii tail(dq.back());
			s[tail.L][tail.R] = '.';
			dq.pop_back();
		}

		if (s[npos.L][npos.R] == '#')
			return 0;

		if (curemp == -1)
			get_food(curemp);
		dq.push_front(npos);
		print(i);
	}
	return 0;
}
