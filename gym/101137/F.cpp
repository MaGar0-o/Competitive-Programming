#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

bool mark[300], sn[300];
string s;

string getMin(string a, string b){
	if (a.size() < b.size()) return a;
	if (a.size() > b.size()) return b;
	if (a < b)
		return a;
	return b;
}

string get(){
	string ret;
	for (int i = 32; i <= 126;){
		if (mark[i] && !sn[i]){
			i++;
			continue;
		}
		int j = i;
		int cnt = 0;
		int lst = -1, fs = -1;
		while (j <= 126 && (!mark[j] || sn[j])){
			if (sn[j]){
				cnt++, lst = j;
				if (fs == -1)
					fs = j;
			}
			j++;
		}

		if (cnt){
			if (cnt == 1){
				ret += char(lst);
			}
			else if (cnt == 2){
				ret += char(fs);
				ret += char(lst);
			}
			else{
				ret += char(i);
				ret += '-';
				ret += char(lst);
			}
		}
		i = j;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	mark[32] = 1;
	for (int i = '0'; i <= '9'; i++) mark[i] = 1;
	for (int i = 'A'; i <= 'Z'; i++) mark[i] = 1;
	for (int i = 'a'; i <= 'z'; i++) mark[i] = 1;
	getline(cin, s);
	for (char c:s) sn[c] = 1;

	string ans1 = get();
	for (int i = 0; i < 300; i++)
		if (mark[i])
			sn[i] = !sn[i];
	string ans2 = "^" + get();
	string ans = getMin(ans1, ans2);
	cout << "%[" << ans << "]" << "\n";
	return 0;
}
