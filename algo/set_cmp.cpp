//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

struct cmp{
	bool operator()(const int &i, const int &j) const{
		return i > j;
	}
};

set<int, cmp> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 10; i++)
		s.insert(i * 2 + 5);
	cout << *s.begin() << endl;
	cout << *s.lower_bound(14) << endl;
	return 0;
}
