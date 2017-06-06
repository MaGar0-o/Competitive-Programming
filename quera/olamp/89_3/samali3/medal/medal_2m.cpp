#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#define FOR(i,x,n) for(__typeof(x) i = (x); i != (n); i++)
#define FR(i,n) FOR(i,0,n)
#define FRI(it,v) FOR(it,v.begin(),v.end())
#define SZ size()
#define MP make_pair
#define show(x) cerr<<#x<<"="<<x<<endl;
#define ALL(v) v.begin(),v.end()
#define RS random_shuffle
#define PB push_back
#define isin(v,x) (v.find(x) != v.end())
#define sqr(x) ( (x) * (x) )
#define X first
#define Y second
using namespace std;

const int MAX_N = 100*1000 + 13;
typedef pair<int,int> PII;

int n, m;
int a[MAX_N];
PII b[MAX_N];

int main() {
  int testn; cin>>testn;
  FR(testi,testn) {
    cin >> n;
    FR(i,n) { cin >> a[i]; a[i] &= 1; }
    cin >> m;
    FR(i,m) { cin >> b[i].X >> b[i].Y; b[i].X--; b[i].Y--; }

    int t[MAX_N];
    int best = 0;
    FR(mask, (1<<m)) {
      FR(i,n) t[i] = a[i];
      FR(j,m) if ((mask>>j) & 1)
	for (int k = b[j].X; k<=b[j].Y; k++)
	  t[k] ^= 1;
      int c = 0;
      FR(i,n) if (t[i] & 1) c++;
      best = max(best, c);
    }
    cout << best << endl;
  }

  return 0;
}
