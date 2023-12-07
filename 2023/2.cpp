#include <bits/stdc++.h>

#include <sstream>
#include <vector>

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

    int ans1 = 0;
    int ans2 = 0;
    int cur = 1;
    string line;

    while (getline(in, line)) {
        line = split(line, ':')[1];
        int maxRed = 0, maxGreen = 0, maxBlue = 0;

        vector<string> games = split(line, ';');
        for (string game : games) {
            vector<string> colors = split(game, ',');
            for (string color : colors) {
                int num;
                stringstream(color) >> num;
                color = color.substr(color.find_last_of(' ') + 1);

                if (color == "red") maxRed = max(num, maxRed);
                if (color == "green") maxGreen = max(num, maxGreen);
                if (color == "blue") maxBlue = max(num, maxBlue);
            }
        }

        if (maxRed <= 12 && maxGreen <= 13 && maxBlue <= 14) ans1 += cur;
        ans2 += maxRed * maxGreen * maxBlue;

        cur++;
    }

    cout << "Part 1: " << ans1 << endl;
    cout << "Part 2: " << ans2 << endl;

    return 0;
}
