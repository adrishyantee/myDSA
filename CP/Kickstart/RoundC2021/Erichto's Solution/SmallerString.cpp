#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

const int mod = 1e9 + 7;
const int nax = 1e5 + 5;
char s[nax];

void test_case() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	int dp[2][3]; // prefix_smaller=1, suffix_smaller=2, eq=1, bigger=0
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < 3; ++j) {
			dp[i][j] = 0;
		}
	}
	dp[0][1] = 1;
	for(int pos = 0; pos < (n + 1) / 2; ++pos) {
		int new_dp[2][3];
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 3; ++j) {
				new_dp[i][j] = 0;
			}
		}
		for(int c = 0; c < k; c++) {
			for(int pref = 0; pref < 2; ++pref) {
				for(int suf = 0; suf < 3; ++suf) {
					int new_pref;
					if(pref == 0) { // equal
						if(c < s[pos] - 'a') {
							new_pref = 1; // smaller
						}
						else if(c == s[pos] - 'a') {
							new_pref = 0; // equal
						}
						else {
							continue;
						}
					}
					else {
						new_pref = pref;
					}
					int new_suf;
					if(c == s[n-1-pos] - 'a') {
						new_suf = suf;
					}
					else if(c < s[n-1-pos] - 'a') {
						new_suf = 2;
					}
					else {
						new_suf = 0;
					}
					new_dp[new_pref][new_suf] += dp[pref][suf];
					if(new_dp[new_pref][new_suf] >= mod) {
						new_dp[new_pref][new_suf] -= mod;
					}
				}
			}
		}
		if(pos == 0) {
			debug() << imie(new_dp[1][0]) imie(new_dp[1][1]) imie(new_dp[1][2]);
		}
		for(int i = 0; i < 2; ++i) {
			for(int j = 0; j < 3; ++j) {
				dp[i][j] = new_dp[i][j];
			}
		}
	}
	int answer = 0;
	for(int pref = 0; pref < 2; ++pref) {
		for(int suf = 0; suf < 3; ++suf) {
			if(pref == 0 && suf != 2) {
				continue;
			}
			answer = (answer + dp[pref][suf]) % mod;
		}
	}
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int z = 1; z <= T; z++) {
		printf("Case #%d: ", z);
		test_case();
	}
}
