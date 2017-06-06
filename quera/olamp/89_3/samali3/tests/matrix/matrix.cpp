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
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int C1E9 = 1000*1000*1000;

int n;

VVI a[2];
map<int, int> p;

void writemat(VVI &mat) {
  FR(i,n) {
    FR(j,n) cerr << mat[i][j] << " ";
    cerr << endl;
  }
  cerr << endl;
}

int findmax(VVI &mat) {
  int mmax = 0;
  FR(i,n) mmax = max(mmax, *max_element(ALL(mat[i])));
  return mmax;
}

int findmin(VVI &mat) {
  int mmin = C1E9;
  FR(i,n) mmin = min(mmin, *min_element(ALL(mat[i])));
  return mmin;
}

void decall(VVI &mat,int x) { FR(i,n) FR(j,n) mat[i][j] -= x; }
void sqrtall(VVI &mat) { FR(i,n) FR(j,n) mat[i][j] = p[mat[i][j]]; }
bool isallsqr(VVI &mat) { 
  FR(i,n) FR(j,n) if (!isin(p, mat[i][j])) return 0; 
  return 1; 
}

int main() {
  int testn; cin >> testn;
  for (int i=0;i*i<=C1E9;i++)
    p[i*i] = i;

  FR(testi,testn) {
    cin >> n;
    // read data
    FR(t,2) {
      a[t].resize(n);
      FR(i,n) { a[t][i].resize(n); FR(j,n) cin >> a[t][i][j]; }
    }
    
    FR(t,2) {
      VVI &b = a[t];
      FR(i,n) rotate(b[i].begin(), min_element(ALL(b[i])), b[i].end());
      sort(b.begin(), b.end());

      while (findmin(b) > 0) {
	while (isallsqr(b) && findmax(b) > 1) { sqrtall(b); continue; }

	int mymax = findmax(b);
	map<int,int>::iterator best = p.lower_bound(mymax);
	if (best->first != mymax) 
	  { best--; decall(b, min(findmin(b),mymax-best->first)); continue; }

	decall(b, 1);	
      }
      while (isallsqr(b) && findmax(b) > 1) sqrtall(b);

      //writemat(b);
      //cout << endl;
    }
    cout << ( (a[0] == a[1]) ? "Yes" : "No" ) << endl;
  }
  return 0;
}
