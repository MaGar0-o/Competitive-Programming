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

const int maxtrie = 1e7,
	  maxn = 4e5,
	  maxl = 3;
int go[maxtrie][2],
	freenode[maxtrie],
	lidx[maxtrie],
	freenodesz,
	trie_rptr;
int path[maxl + 1],
	path2[maxl + 1],
	stat[maxl][2];
int sufxor[maxn + 1],
	rmost[maxn],
	a[maxn],
	n, q;

bool nist(int u) {
	return u == -1 or lidx[u] == -1;
}

void trie_delete(int num, int id) {
	int u = 0;
	for (int i = maxl - 1; i >= 0; i--) {
		path2[i] = u;
		u = go[u][(num>>i)&1];
	}
	if (lidx[u] == id)
		lidx[u] = -1;
	for (int i = 0; i < maxl; i++) {
		int v = path2[i];
		if (nist(go[v][0]) or nist(go[v][1]))
			continue;
		int mv = lidx[go[v][0]] > lidx[go[v][1]];
		stat[i][mv]--;
	}
	for (int i = 0; i < maxl; i++) {
		int v = path2[i];
		if (lidx[v] == id)
			lidx[v] = -1;
	}
	for (int i = 0; i < maxl; i++) {
		int v = path2[i];
		pii lg = get_good(go[v][0]),
			rg = get_good(go[v][1]);
		if (min(lg.L, rg.L) == -1)
			good[v].L = -1, good[v].R = 0;
		else if (lg.L + lg.R == 0 or rg.L + rg.R == 0)
			good[v] = max(lg, rg);
		else {
			int mv = lidx[go[v][0]] > lidx[go[v][1]];
			good[v].L = good
			if (lg.R == rg.R and ((~lg.R) & lg.L) == ((~rg.R) & rg.L))
				good[v].L = -1, good[v].R = 0;
			else {
				
			}
		}
	}
}

int get_free(void) {
	return ++freenodesz;
}

void trie_insert(int num, int id) {
	int u = 0;
	for (int i = maxl - 1; i >= 0; i--) {
		path[i] = u;
		int c = (num >> i) & 1;
		int &v = go[u][c];
		if (v == -1)
			v = get_free();
		u = v;
	}
	for (int i = 0; i < maxl; i++) {
		int v = path[i];
		int &le = lidx[v];
		while (le > id + 1 and trie_rptr > -5)
			trie_delete(sufxor[trie_rptr + 1], trie_rptr), trie_rptr--;
		le = id;
	}
	lidx[u] = id;
	for (int i = 0; i < maxl; i++) {
		int v = path[i];
		if (nist(go[v][0]) or nist(go[v][1]))
			continue;
		if (nist(go[v][0]) or nist(go[v][1]))
			continue;
		int mv = lidx[go[v][0]] > lidx[go[v][1]];
		while (stat[i][1 - mv])
			trie_delete(sufxor[trie_rptr + 1], trie_rptr), trie_rptr--;
		if (id == 0 and i == 0)
			cout << "HI" << mv << endl;
		stat[i][mv]++;
	}

	//LOG
	cout << id << ": ";
	for (int i = 0; i < maxl; i++)
		cout << stat[i][0] << '/' << stat[i][1] << ' ';
	cout << endl;
	for (int i = 0; i <= freenodesz; i++)
		cout << lidx[i] << ' ';
	cout << endl;
	cout << "rptr " << trie_rptr << endl;
	cout << "num " << num << endl;
}

int get_rmost(int haste) {
	int ret = trie_rptr;
	for (int i = maxl - 1; i >= 0; i--) {
		if (stat
	}
}

void partOne(void) {
	memset(stat, 0, sizeof stat);
	memset(lidx, -1, sizeof lidx);
	memset(go, -1, sizeof go);
	trie_rptr = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		cout << "processing " << i << endl;
		trie_insert(sufxor[i + 1], i);
		sufxor[i] = sufxor[i] ^ a[i];
		rmost[i] = get_rmost(sufxor[i]);
		cout << rmost[i] << endl;
	}
	//build();
}

LL partTwo(int l, int r) {
	//LL ret = part_rmost[r + 1] - part_rmost[l];
	//LL ret = get_ans(l, r);
	//return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	partOne();
	int q;
	cin >> q;
	LL prv = 0;
	for (int i = 0; i < q; i++) {
		int fi, se;
		cin >> fi >> se;
		fi = (fi + prv) % n;
		se = (se + prv) % n;
		int prv;
		//prv = partTwo(fi, se);
		cout << prv << '\n';
	}
	return 0;
}
