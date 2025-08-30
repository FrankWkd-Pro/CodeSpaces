#include <bits/stdc++.h>
using namespace std;
#define int long long
string ones[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

string tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string digs[] = {
    "zero", "ichi", "ni", "san", "yon", "go", "roku", "nana", "hachi", "kyuu"};

string conver_thr(int num) {
    if (num == 0)
        return "";
    int hundreds = num / 100;
    int post = num % 100;
    string res = "";
    if (hundreds > 0)
        res += ones[hundreds] + " hundred";

    if (post > 0) {
        if (!res.empty())
            res += " ";
        if (post < 20)
            res += ones[post];
        else {
            int tens_dig = post / 10;
            int ones_dig = post % 10;
            res += tens[tens_dig];
            if (ones_dig > 0)
                res += "-" + ones[ones_dig];
        }
    }
    return res;
}

string to_eng(long long num) {
    if (num == 0)
        return "zero";
    vector<int> gro(4, 0);
    gro[0] = num % 1000;
    num /= 1000;
    gro[1] = num % 1000;
    num /= 1000;
    gro[2] = num % 1000;
    num /= 1000;
    gro[3] = num % 1000;

    string res = "";
    const string units[] = {"", "thousand", "million", "billion"};
    for (int i = 3; i >= 0; i--) {
        if (gro[i] == 0)
            continue;
        string part = conver_thr(gro[i]);
        if (!res.empty()) {
            res += " ";
        }
        res += part;
        if (!units[i].empty())
            res += " " + units[i];
    }
    return res;
}
string convert_four(int num) {
    if (num == 0)
        return "";
    int thousands = num / 1000;
    int hundreds = (num % 1000) / 100;
    int tens_dig = (num % 100) / 10;
    int ones_dig = num % 10;
    string res = "";

    if (thousands > 0) {
        if (thousands == 1)
            res += "sen";
        else if (thousands == 3)
            res += "sanzen";
        else if (thousands == 8)
            res += "hassen";
        else
            res += digs[thousands] + "sen";
    }

    if (hundreds > 0) {
        if (hundreds == 1)
            res += "hyaku";
        else if (hundreds == 3)
            res += "sanbyaku";
        else if (hundreds == 6)
            res += "roppyaku";
        else if (hundreds == 8)
            res += "happyaku";
        else
            res += digs[hundreds] + "hyaku";
    }
    if (tens_dig > 0) {
        if (tens_dig == 1)
            res += "juu";
        else
            res += digs[tens_dig] + "juu";
    }

    if (ones_dig > 0) {
        res += digs[ones_dig];
    }
    return res;
}

string to_jap(long long num) {
    if (num == 0)
        return "zero";
    vector<long long> gro(3, 0);
    gro[0] = num % 10000;
    num /= 10000;
    gro[1] = num % 10000;
    num /= 10000;
    gro[2] = num % 10000;

    string res = "";
    const string units[] = {"", "man", "oku"};
    for (int i = 2; i >= 0; i--) {
        if (gro[i] == 0)
            continue;
        string pwu;
        if (i >= 1 && gro[i] == 1000)
            pwu = "issen" + units[i];
        else {
            string part = convert_four(gro[i]);
            if (part.empty())
                continue;
            pwu = (units[i].empty()) ? part : part + units[i];
        }
        if (res.empty())
            res = pwu;
        else
            res += pwu;
    }
    return res;
}

signed main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int T;
    char L;
    cin >> T >> L;

    while (T--) {
        long long N;
        cin >> N;
        if (L == 'E')
            cout << to_eng(N) << "\n";
        else if (L == 'J')
            cout << to_jap(N) << "\n";
    }
    return 0;
}