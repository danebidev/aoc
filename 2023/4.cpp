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

int getWinningNumbers(string numbers) {
    vector<int> winning;
    vector<string> nums = split(numbers, '|');

    for (string num : split(nums[0], ' ')) {
        if (!num.empty()) winning.push_back(stoi(num));
    }

    int res = 0;
    for (string num : split(nums[1], ' ')) {
        if (!num.empty() && find(winning.begin(), winning.end(), stoi(num)) != winning.end()) res++;
    }

    return res;
}

int main() {
    ifstream in("input");

    int ans1 = 0;
    int ans2 = 0;
    map<int, int> scratchchards;
    int cur = 1;
    string line;

    while (getline(in, line)) {
        int winning = getWinningNumbers(split(line, ':')[1]);
        ans1 += pow(2, winning - 1);

        scratchchards[cur] += 1;
        while (winning > 0) {
            scratchchards[cur + winning] += scratchchards[cur];
            winning--;
        }

        ans2 += scratchchards[cur];

        cur++;
    }

    cout << "Part 1: " << ans1 << endl;
    cout << "Part 2: " << ans2 << endl;

    return 0;
}
