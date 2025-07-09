#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string rank[] = {
        "FZU",
        "FNU",
        "FZU",
        "FZU",
        "FAFU",
        "HQU",
        "MJU",
        "XMUT",
        "QNU",
        "JMU",
        "FZU"};

    cout << rank[n - 1] << endl;

    return 0;
}