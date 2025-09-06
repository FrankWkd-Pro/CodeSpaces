#include <bits/stdc++.h>
using namespace std;

vector<long long> height;
int l[1010010];
int r[1010101];
stack<long long> area;
stack<int> order;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 0;
	long long h = 0;

	cin >> n;
	int t = n;
	while  (t--) {
		long long max = 0;

		for ( int i = 0 ; i < n ; i++ ) {
			cin >> h;
			height.push_back(h);
		}


		for ( int i = 0 ; i < n ; i++ ) {


			while ( !area.empty() && height[i] < area.top() ) {
				r[order.top()] = i;

				area.pop();
				order.pop();
			}
			area.push(height[i]);
			order.push(i);
		}

		while ( !order.empty() ) {
			r[order.top()] = n;
			order.pop();
			area.pop();
		}



		for ( int i = n - 1 ; i >= 0 ; i-- ) {


			while ( !area.empty() && height[i] < area.top() ) {
				l[order.top()] = i;

				area.pop();
				order.pop();
			}
			area.push(height[i]);
			order.push(i);
		}

		while ( !order.empty() ) {
			l[order.top()] = -1;
			order.pop();
			area.pop();
		}

		for ( int i = 0 ; i < n ; i++ ) {
			if ( height[i] * (r[i] - l[i] - 1) > max )
				max = height[i] * (r[i] - l[i] - 1);
		}

		cout << max << endl;

		return 0;
	}

}

