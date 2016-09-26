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

const int maxn = 2e5 + 85 - 69;
int wei[maxn],
	frm[maxn],
	too[maxn],
	par[maxn],
	ord[maxn],
	lo[maxn],
	hi[maxn],
	q1[maxn],
	q2[maxn],
	n, m, q;
vector<int> vec[maxn];

bool cmp(int i, int j){
	return wei[i] < wei[j];
}

int root(int v){return par[v] < 0 ? v : par[v] = root(par[v]);}

void merge(int v, int u){
	if((v = root(v)) == (u = root(u)))
		return;
	if(par[v] > par[u]) swap(v, u);
	par[v] += par[u];
	par[u] = v;
	return;
}

void just_do_it(void){
	for(int i = 0; i < m; i++){
		merge(frm[ord[i]], too[ord[i]]);
		for(auto quer : vec[i])
			if(-par[root(q1[quer])] >= q2[quer])
				hi[quer] = i;
			else
				lo[quer] = i;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> frm[i] >> too[i] >> wei[i];
		frm[i]--, too[i]--;
		ord[i] = i;
	}
	sort(ord, ord + m, cmp);
	cin >> q;
	for(int i = 0; i < q; i++){
		lo[i] = -1, hi[i] = m;
		cin >> q1[i] >> q2[i];
		q1[i]--;
	}
	for(int i = 0; i < 20; i++){
		memset(par, -1, sizeof par);
		for(int j = 0; j <= m; j++)
			vec[j].clear();
		for(int j = 0; j < q; j++)
			if(hi[j] - lo[j] > 1)
				vec[(lo[j]+hi[j])/2].PB(j);
		just_do_it();		//You know? I'm so fun :))
	}
	for(int i = 0; i < q; i++)
		if(q2[i] == 1)
			cout << 0 << '\n';
		else
			cout << (hi[i] == m ? -1 : wei[ord[hi[i]]]) << '\n';
	return 0;
} 
