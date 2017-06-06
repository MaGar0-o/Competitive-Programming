#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "grader.h"

using namespace std;

static const char *secret = "8a87120bd5122e261c90";

static int n, k, T, weights_id, compare_calls;
static long long **sets;

inline int popcount(unsigned int a)
{
    int res;
    for (res = 0; a; res += (a & 1), a >>= 1);
    return res;
}

int compare(int first, int second) {
    compare_calls++;
    if (!(popcount((unsigned int) first) + popcount((unsigned int) second) <= n &&
                (first & second) == 0))
    {
        printf("%s\n-2\n", secret);
        exit(0);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
        if ((first >> i) & 1)
            sum += sets[weights_id][i];
    for (int i = 0; i < n; i++)
        if ((second >> i) & 1)
            sum -= sets[weights_id][i];
    return (sum == 0 ? 0 : (sum < 0 ? -1 : 1));
}

int main(){
    compare_calls = 0;
    scanf("%d %d %d %d", &n, &k, &T, &weights_id);
    sets = new long long*[k];
    for (int i = 0; i < k; i++) {
        sets[i] = new long long[n];
        for (int j = 0; j < n; j++)
            scanf("%lld", &sets[i][j]);
    }
    int ans = identify_set(n, k, sets);
    printf("%s\n%d\n%d\n", secret, ans, compare_calls);

    for (int i = 0; i < k; i++)
        delete [] sets[i];
    delete [] sets;

    return 0;
}
