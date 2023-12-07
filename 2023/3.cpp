#include <bits/stdc++.h>

#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> getAdjCoords(vector<string> input, int i, int j) {
    int up = max(i - 1, 0);
    int down = min(i + 1, (int)input.size() - 1);
    int left = max(j - 1, 0);
    int right = min(j + 1, (int)input[0].size() - 1);

    return { { up, left }, { up, j }, { up, right }, { i, left }, { i, right }, { down, left }, { down, j }, { down, right } };
}

bool hasAdjSymbol(vector<string> input, int i, int j) {
    for (auto coord : getAdjCoords(input, i, j)) {
        if (!isdigit(input[coord.first][coord.second]) && input[coord.first][coord.second] != '.') return true;
    }

    return false;
}

tuple<int, int, int, bool> readNum(vector<string> input, int i, int j) {
    stringstream num;
    bool adj = false;

    while (j > 0 && isdigit(input[i][j - 1])) j--;
    int first = j;

    while (j < input[i].size() && isdigit(input[i][j])) {
        num << input[i][j];
        if (!adj && hasAdjSymbol(input, i, j)) adj = true;
        j++;
    }

    return { first, j - 1, stoi(num.str()), adj };
}

int getGearValue(vector<string> input, int i, int j) {
    pair<tuple<int, int, int, bool>, tuple<int, int, int, bool>> nums = { { -1, -1, -1, false }, { -1, -1, -1, false } };
    for (auto coord : getAdjCoords(input, i, j)) {
        if (isdigit(input[coord.first][coord.second])) {
            auto num = readNum(input, coord.first, coord.second);
            if (nums.first == num || nums.second == num) continue;
            if (get<2>(nums.second) != -1) return 0;

            if (get<2>(nums.first) == -1)
                nums.first = num;
            else
                nums.second = num;
        }
    }

    if (get<2>(nums.second) != -1) return get<2>(nums.first) * get<2>(nums.second);
    return 0;
}

int main() {
    ifstream in("input");

    long long ans1 = 0;
    long long ans2 = 0;
    string line;

    vector<string> input;

    while (getline(in, line)) {
        input.push_back(line);
    }

    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (isdigit(input[i][j])) {
                tuple<int, int, int, bool> num = readNum(input, i, j);
                j = get<1>(num);
                if (get<3>(num)) ans1 += get<2>(num);
            }
            if (input[i][j] == '*') {
                ans2 += getGearValue(input, i, j);
            }
        }
    }

    cout << "Part 1: " << ans1 << endl;
    cout << "Part 2: " << ans2 << endl;

    return 0;
}
