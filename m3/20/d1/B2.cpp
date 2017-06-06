#include <iostream>
#include <set>
using namespace std;

typedef long long LL;

const string paterns[] = {"abbbccc",
	"aaabccc", "aaabbbc", "aabbccc",
	"aabbbcc", "aaabbcc", "abababa"};
LL delta;

int main(int argc, char *argv[]) {
	delta = atoi(argv[1]);
	int np = sizeof(paterns) / sizeof(paterns[1]);

	set<string> myset;

	int d[3];
	for (d[0] = 0; d[0] <= 9; d[0]++)
		for (d[1] = 0; d[1] <= 9; d[1]++)
			for (d[2] = 0; d[2] <= 9; d[2]++)
				for (int k=0; k<np; k++) {
					string s = paterns[k];
					for (int i=0; i<(int)s.length(); i++)
						s[i] = '0'+d[s[i]-'a'];
					if (s < "7801389" && s[0] != '0')
						myset.insert(s);
				}

	LL cnt = myset.size();
	cout << (cnt*cnt) % delta << endl;

	return 0;
}
