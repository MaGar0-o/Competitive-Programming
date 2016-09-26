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

set<int> s;

bool isprime(int x){
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("A.out");
	ofstream fout("A2.cpp");
	fout << "#include<bits/stdc++.h>\n"
		<< "using namespace std;\n"
		<< "int a[1000] = {";
	int x = 0;
	do{
		fout << x << ",";
	}while(fin >> x);
	fout << x << "};\n"
		<< "int main(){\n"
		<< "int n; cin >> n; cout << a[n] << endl; return 0;}\n";
	return 0;
}
