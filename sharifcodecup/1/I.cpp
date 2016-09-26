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

map<string, string> mp1, mp2, mp3;

string Tab1(string str){
	if(mp1.find(str) == mp1.end())
		return str;
	return mp1[str];
}

string Tab2(string str){
	if(mp2.find(str) == mp2.end())
		return str;
	return mp2[str];
}

void solve(void){
	string str, s1, s2, s3;
	stringstream ss;
	getline(cin, str);
	ss << str;
	if(count(all(str), ' ') != 2 or str.back() != '.'){
		cout << "Not Supported Yet!\n";
		return;
	}
	ss >> s1 >> s3 >> s2;
	if(s2 == ""){
		cout << "Not Supported Yet!\n";
		return;
	}
	s2.pop_back();
	for(auto &c : s2)
		if(c >= 'A' and c <= 'Z')
			c += 'a' - 'A';
	if(mp3.find(s3) == mp3.end()){
		cout << str << '\n';
		return;
	}
	cout << Tab1(s1) << ' ' << Tab2(s2) << ' ' << mp3[s3];
	if(s3 == "are"){
		if(s1 == "You")
			cout << "id";
		else if(s1 == "They")
			cout << "and";
		else if(s1 == "We")
			cout << "im";
		else
			cout << "...";
	}
	cout << ".\n";
	return;
}

void build(void){
	mp1["I"] = "Man";
	mp1["You"] = "Shoma";
	mp1["We"] = "Ma";
	mp1["They"] = "Anha";
	mp1["She"] = "Oo";
	mp1["He"] = "Oo";
	mp2["stupid"] = "nadan";
	mp2["excellent"] = "aali";
	mp2["noob"] = "mobtadi";
	mp2["geek"] = "khafan";
	mp2["student"] = "daneshju";
	mp2["professor"] = "ostad";
	mp3["is"] = "ast";
	mp3["am"] = "hastam";
	mp3["are"] = "hast";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	build();
	int t;
	cin >> t;
	string str;
	getline(cin, str);
	while(t--) solve();
	return 0;
}
