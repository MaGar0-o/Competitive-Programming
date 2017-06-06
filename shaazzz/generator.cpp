#include <bits/stdc++.h>    
using namespace std;    
typedef long long ll;

const int N = 1e6 + 7;

ll random(ll a, ll b)
{
	return 1LL * rand() * rand() % (b-a+1) + a;
}

void random_tree(int n, int *a, int *b)
{
	vector<int> p(n);
	for(int i=1; i<n; i++)
		p[i] = random(0, i-1);
	vector<int> perm(n);
	for (int i=0; i<n; i++)
		perm[i] = i;
	random_shuffle(perm.begin(), perm.end());
	vector<pair<int,int> > edges;
	for (int i = 1; i < n; i++)
		if (random(0, 1))
			edges.push_back(make_pair(perm[i], perm[p[i]]));
		else
			edges.push_back(make_pair(perm[p[i]], perm[i]));
	random_shuffle(edges.begin(), edges.end());
	for (int i = 0; i + 1 < n; i++)
		a[i] = edges[i].first + 1, b[i] = edges[i].second + 1;
}

void random_array(int n, int x, int y, int* a)
{
	for (int i=0; i<n; i++)
		a[i] = random(x, y);
}

void array_sum(int n, int sum, int *a)
{
	sum -= n;
	for (int i=0; i+1<n; i++)
	{
		int th = random(0, sum);
		a[i] = th + 1;
		sum -= th;
	}
	a[n-1] = sum + 1;
}

string random_str(int n, char a, char b)
{
	string s;
	s.resize(n);
	for (int i=0; i<n; i++)
		s[i] = random(a, b);
	return s;
}

void random_perm(int n, int *a)
{
	for (int i=0; i<n; i++)
		a[i] = i + 1;
	random_shuffle(a, a+n);
}

void random_per(int n, bool t)
{
	int a[N];
	for (int i=0; i<n; i++)
		a[i] = (i^1) + 1;
	if (t)
		reverse(a, a+n);
	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

void random_shit_perm(int n, int x)
{
	int a[N];
	for (int i=0; i<n; i++)
		a[i] = i + 1;
	for (int i=0; i<x; i++)
	{
		int s = random(0, n-1);
		int t = random(s+1, n);
		reverse(a+s, a+t);
	}
	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

ll arr[] = {0, 2, 2, 4, 6, 12, 20, 40, 74, 148, 284, 568, 1116, 2232, 4424, 8848, 17622, 35244, 70340, 140680, 281076, 562152, 1123736, 2247472, 4493828, 8987656, 17973080, 35946160, 71887896, 143775792, 287542736, 575085472, 1150153322, 2300306644, 4600578044, 9201156088, 18402241836, 36804483672, 73608826664, 147217653328, 294435025580, 588870051160, 1177739540168, 2355479080336, 4710957036936, 9421914073872, 18843825900272, 37687651800544, 75375299107260, 150750598214520, 301501187441384, 603002374882768, 1206004731792456, 2412009463584912, 4824018891223664, 9648037782447328, 19296075493006760, 38592150986013520, 77184301828251248, 154368603656502496, 308737207025462256, 617474414050924512, 1234948827526763552, 1999999999999999999, 1999999999999999999};

int main(int argc , char** argv )
{
	if (!argc)
		return 0;
	int c = atoi(argv[1]);
	int x = atoi(argv[2]);
	int t = atoi(argv[3]);
	srand(c*100+x+t);
	cout << t << endl;
	for(int i = 0; i < t; i++){
		int n = random(1, 15);
		ll k = random(1, arr[n]);
		cout << n << ' ' << k << endl;
	}
	return 0;
}
