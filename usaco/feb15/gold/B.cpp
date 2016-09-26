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
#define next Next

const int maxn = 1e5 + 85 - 80,
	  maxsq = 500;
vector<string> boz, coc;
vector<int> func[26][maxn / maxsq + 5];
int match[maxn/maxsq + 5][maxn],
	next[maxn/maxsq + 5][maxn],
	adj[maxn][26];
int agab[maxn], jolo[maxn];
bool iscomp[maxn];
string s;
int n, sz = 1;

void build_func(int id){
	for(int i = 1; i < sz(boz[id]); i++)
		for(int j = 0; j < 26; j++){
			if(boz[id][i] == 'a' + j)
				func[j][id][i] = i;
			else
				func[j][id][i] = func[j][id][next[id][i - 1]];
		}
	return;
}

void make_match(int id, int i1, int i2){
	if(i1 == -1)
		match[id][i2] = (boz[id][0] == s[i2]);
	else
		match[id][i2] = func[s[i2] - 'a'][id][match[id][i1]] + (s[i2] == boz[id][func[s[i2] - 'a'][id][match[id][i1]]]);
	return;
}

int nextof(int id){return jolo[id];}
int backof(int id){return agab[id];}

void remove(int id, int cnt){
	int id2 = nextof(id);
	for(int i = 0; i < cnt; i++){
		//cout << "Removing: " << agab[id2] << endl;
		agab[id2] = agab[agab[id2]];
	}
	if(~agab[id2])
		jolo[agab[id2]] = id2;
	return;
}

int find_max(int id){
	int ret = -1,
		ptr = 0,
		h = 0;
	while(~ptr and ~id){
		h++;
		ptr = adj[ptr][s[id] - 'a'];
		if(~ptr and iscomp[ptr]) ret = h;
		id = agab[id];
	}
	return ret;
}

int main(){
	ifstream cin("censor.in");
	ofstream cout("censor.out");
	memset(adj, -1, sizeof adj);
	for(int i = 0; i < maxn; i++)
		jolo[i] = i + 1, agab[i] = i - 1;
	cin >> s
		>> n;
	for(int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		if(sz(tmp) > maxsq)
			boz.PB(tmp);
		else
			coc.PB(tmp);
	}
	for(auto &str : coc){
		int ptr = 0;
		for(int i = sz(str) - 1; i >= 0; i--){
			int id = str[i] - 'a';
			if(adj[ptr][id] == -1)
				adj[ptr][id] = sz++;
			ptr = adj[ptr][id];
		}
		iscomp[ptr] = true;
	}
	for(int i = 0; i < sz(boz); i++){
		for(int j = 0; j < 26; j++)
			func[j][i].resize(sz(boz[i]));
		int mch = 0;
		for(int j = 1; j < sz(boz[i]); j++){
			while(mch and boz[i][j] != boz[i][mch])
				mch = next[i][mch - 1];
			mch += boz[i][j] == boz[i][mch];
			next[i][j] = mch;
		}
		build_func(i);
	}
	int cur = 0;
	bool found;
	do{
		found = false;
		for(int i = cur; i < sz(s); i = nextof(i)){
			int len = -1;
			for(int j = 0; j < sz(boz); j++){
				make_match(j, backof(i), i);
				if(match[j][i] == sz(boz[j]))
					smax(len, sz(boz[j]));
			}
			smax(len, find_max(i));
			if(~len){
				//cout << i << ' ' << len << endl;
				cur = nextof(i);
				remove(i, len);
				found = true;
				break;
			}
		}
	}while(found);
	cur = sz(s);
	string ret;
	do{
		cur = backof(cur);
		if(~cur) ret += s[cur];
	}while(~cur);
	reverse(all(ret));
	cout << ret << endl;
	return 0;
}
