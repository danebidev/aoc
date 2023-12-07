#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

int main() {
    ifstream in("input");

    int ans = 0;
    string line;

    while (getline(in, line)) {
        line = split(line, ':')[1];
    }

    cout << ans;

    return 0;
}
