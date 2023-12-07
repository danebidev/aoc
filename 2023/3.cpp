#include <bits/stdc++.h>

using namespace std;

bool hasAdjChar(vector<string> input, int i, int j) {
    int up = max(i - 1, 0);
    int down = min(i + 1, (int)input.size() - 1);
    int left = max(j - 1, 0);
    int right = min(j + 1, (int)input[0].size() - 1);

    vector<pair<int, int>> coords { { up, left }, { up, j }, { up, right }, { i, left }, { i, right }, { down, left }, { down, j }, { down, right } };

    for (auto coord : coords) {
        if (!isdigit(input[coord.first][coord.second]) && input[coord.first][coord.second] != '.') return true;
    }

    return false;
}

int main() {
    ifstream in("input");

    long long ans1 = 0;
    string line;

    vector<string> input;

    while (getline(in, line)) {
        input.push_back(line);
    }

    for (int i = 0; i < input.size(); i++) {
        string cur = "";
        bool adj = false;
        for (int j = 0; j < input[i].size(); j++) {
            if (isdigit(input[i][j])) {
                cur += input[i][j];
                if (hasAdjChar(input, i, j)) adj = true;
            }
            if (!isdigit(input[i][j]) || j == input[i].size() - 1) {
                if (adj) ans1 += stoi(cur);
                cur = "";
                adj = false;
            }
        }
    }

    cout << "Part 1: " << ans1 << endl;

    return 0;
}
