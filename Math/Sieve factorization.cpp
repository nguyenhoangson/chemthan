#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
bool flag[MAXN];
int sp[MAXN];
void Sieve() {
	for (int i = 2; i < MAXN; i += 2) sp[i] = 2;
	for (int i = 3; i < MAXN; i += 2) if (!flag[i]) {
		sp[i] = i;
		for (int j = i; 1LL * i * j < MAXN; j += 2) if (!flag[i * j]) {
			flag[i * j] = 1;
			sp[i * j] = i;
		}
	}
}
int Euler(int n) {
	int res = 1, prev = 1;
	while (n > 1) {
		if (sp[n] != prev) res *= sp[n] - 1;
		else res *= sp[n];
		prev = sp[n];
		n /= sp[n];
	}
	return res;
}

int main() {
	Sieve();
	printf("%d\n", sp[101 * 103]);
	printf("%d", Euler(12345));
	return 0;
}

