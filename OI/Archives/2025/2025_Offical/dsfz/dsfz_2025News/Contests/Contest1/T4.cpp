#include<bits/stdc++.h>
using namespace std;
const int N = 1010, MOD = 1e9+7;
int ans[1000010];//桶被覆盖代表前端线段被覆盖。
int n;
struct timetable {
	int start, end;
} a[5010];
int maxxt = 0, minnt = INT_MAX;
int max_long_N, max_long_Y;
int long_N, long_Y;
bool contin_N, contin_Y;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].start >> a[i].end;
		ans[a[i].start]++, ans[a[i].end]--;
		maxxt = max(maxxt, a[i].end), minnt = min(minnt, a[i].start);
	}
	for (int i = minnt; i <= maxxt; i++) ans[i] += ans[i - 1];

	if (ans[minnt] == 0) contin_N = 1;
	else contin_Y = 1;
	for (int i = minnt; i <= maxxt; i++) {
		if (contin_N) {
			if (ans[i] != 0) {
				contin_Y = 1;
				contin_N = 0;
				long_Y = 1;
				max_long_N = max(max_long_N, long_N);
				long_N = 0;
			} else {
				long_N++;
				max_long_N = max(max_long_N, long_N);
			}
		} else if (contin_Y) {
			if (ans[i] == 0) {
				contin_N = 1;
				contin_Y = 0;
				long_N = 1;
				max_long_Y = max(max_long_Y,long_Y);
				long_Y = 0;
			}else{
				long_Y++;
				max_long_Y = max(max_long_Y,long_Y);
			}
		}
	}
	printf("%d %d",max_long_Y,max_long_N);//Important!!

	return 0;
}
