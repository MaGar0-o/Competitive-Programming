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

const int maxn = 50,
	  maxm = 50,
	  maxk = 26,
	  sigma = 26;
string s[maxn][maxm];
set<string> words[maxm][sigma];
int score[maxn];
int n, m, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	cin.ignore();

	//get dictionaries
	for (int i = 0; i < m; i++) {
		string line;
		getline(cin, line);
		string word;
		line += ' ';
		for (auto c : line) {
			if (c == ' ') {
				words[i][word[0] - 'a'].insert(word);
				word = "";
			}
			else
				word += c;
		}

	}

	//get descriptions and evaluate scores
	while (k--) {
		char c;
		cin >> c;
		c -= 'a';

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> s[i][j];

		for (int j = 0; j < m; j++){
			map<string, int> cnt;

			for (int i = 0; i < n; i++)
				cnt[s[i][j]]++;

			for (int i = 0; i < n; i++){
				int current_score;
				if (s[i][j] == "EMPTY" or
						words[j][(int)c].find(s[i][j]) == words[j][(int)c].end())
					current_score = 0;
				else if (cnt[s[i][j]] == 1)
					current_score = 10;
				else
					current_score = 5;
				score[i] += current_score;
			}

		}

	}

	for (int i = 0; i < n; i++)
		cout << score[i] << " \n"[i == n - 1];

	return 0;
}
