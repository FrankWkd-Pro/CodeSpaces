#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    if (N == 1) {
        cout << "End" << endl;
        return 0;
    }

    while (N != 1) {
        if (N % 2 == 0) {
            cout << N << " / 2 = " << N / 2 << endl;
            N /= 2;
        } else {
            cout << N << " * 3 + 1 = " << N * 3 + 1 << endl;
            N = N * 3 + 1;
        }
    }

    cout << "End" << endl;
    return 0;
}