#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 64 + 7;

string res;
ll dp[N][N];
int n;
ll k;

bool borderless(string s)
{
	int n = s.size();
	for (int i=1; i<n; i++)
	{
		bool flag = true;
		for (int j=0; j<i; j++)
			if (s[j] != s[n-i+j])
				flag = false;
		if (flag)
			return false;
	}
	return true;
}

void update(int i)
{
	for (int j=i; j<=n; j++)
	{
		// dp[i][j];
		dp[i][j] = 1LL << (j - i);
		for (int k=1; k<=j/2; k++)
			if (k <= i)
			{
				bool flag = true;
				for (int l=0; l<k; l++)
					if (j-k+l < i && res[l] != res[j-k+l])
						flag = false;
				if (borderless(res.substr(0, k)) && flag)
				{
					dp[i][j] -= 1LL << max(0, j - k - max(i, k));
				}
			}
			else
			{
				dp[i][j] -= dp[i][k] * (1LL << (j - 2 * k));
			}
		//cout << i << " " << j << " : " << " " << res << " " << dp[i][j] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);

	//freopen("borderless.in", "r", stdin);
	//freopen("borderless.out", "w", stdout);


	cin >> n;
	while(cin >> n >> k && n && k)
	{
		res.clear();
		memset(dp, 0, sizeof dp);
		for (int i=1; i<=n; i++)
		{
			//cout << k << " ~~\n";
			res.push_back('a');
			update(i);
			if (dp[i][n] < k)
			{
				k -= dp[i][n];
				res.pop_back();
				res.push_back('b');
			}
		}
		cout << res << "\n";
	}
	return 0;
}
