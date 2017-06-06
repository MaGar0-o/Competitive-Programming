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

const int maxn = 3000 + 85 - 69;
int go[maxn][26],
	tri[maxn][26],
	siz[3],
	pos[maxn],
	ans[maxn],
	fail[maxn],
	lastpos,
	sz = 0;
queue<int> q;

string func(int x){
	string s;
	while(x)
		s += char('0' + (x % 10)), x /= 10;
	while(sz(s) < 4) s += '0';
	reverse(all(s));
	return s;
}

int merge(int u, int v){
	if(u == -1) return v;
	if(v == -1) return u;
	if(siz[u] > siz[v]) return u;
	return v;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(tri, -1, sizeof tri);
	memset(ans, -1, sizeof ans);
	for(int i = 0; i < 3; i++){
		string s;
		cin >> s;
		siz[i] = sz(s);
		int u = 0;
		for(auto c : s){
			int &v = tri[u][c - 'a'];
			if(v == -1) v = ++sz;
			u = v;
		}
		ans[u] = i;
	}
	memcpy(go, tri, sizeof go);
	int cnt = 0,
		lastpos = 9999;
	for(int i = 0; i < 26; i++)
		if(!~go[0][i])
			go[0][i] = 0;
		else
			q.push(go[0][i]);
	while(sz(q)){
		int u = q.front();
		q.pop();
		for(int i = 0; i < 26; i++)
			if(go[u][i] != -1){
				int v = go[u][i];
				fail[v] = go[fail[u]][i];
				ans[v] = merge(ans[v], ans[fail[v]]);
				q.push(v);
			}
			else
				go[u][i] = go[fail[u]][i];
	}
	for(int i = 0; i <= sz; i++){
		pos[i] = lastpos;
		cnt = 0;
		for(int j = 0; j < 26; j++)
			if(tri[i][j] != -1)
				cnt++;
		if(~ans[i])
			lastpos++;
		else
			lastpos += cnt + 2;
		if(i and lastpos >= 10000) assert(0);
		lastpos %= 10000;
	}
	lastpos = 0;
	for(int i = 0; i <= sz; i++){
		//cout << "@" << i << endl;
		lastpos = (i ? pos[i] : 0);
		if(i and !~ans[i])
			cout << func(lastpos++) << ": next" << endl;
		if(~ans[i]){
			cout << func(lastpos++) << ": exit " << ans[i] + 1 << endl;
			continue;
		}
		for(int j = 0; j < 26; j++)
			if(tri[i][j] != -1)
				cout << func(lastpos++) << ": if " << char('a' + j) << " goto " << func(pos[go[i][j]]) << endl;
		cout << func(lastpos++) << ": goto " << func((pos[fail[i]]+(i!=0)) % 10000) << endl;
	}
	cout << "9999: next\n";
	return 0;
}
