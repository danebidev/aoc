#include <bits/stdc++.h>

#include <cctype>
#include <string>

using namespace std;

int main() {
    ifstream in("input");

    int ans = 0;
    string line;

    while (getline(in, line)) {
        string first = "";
        string last = "";

        for (int i = 0; i < line.size(); i++) {
            string num = "";

            if (isdigit(line[i])) num = line[i];
            // I hate this. It's slow, it's ugly, and it's slow
            if (i >= 2 && line.substr(i - 2, 3) == "one") num = "1";
            if (i >= 2 && line.substr(i - 2, 3) == "two") num = "2";
            if (i >= 4 && line.substr(i - 4, 5) == "three") num = "3";
            if (i >= 3 && line.substr(i - 3, 4) == "four") num = "4";
            if (i >= 3 && line.substr(i - 3, 4) == "five") num = "5";
            if (i >= 2 && line.substr(i - 2, 3) == "six") num = "6";
            if (i >= 4 && line.substr(i - 4, 5) == "seven") num = "7";
            if (i >= 4 && line.substr(i - 4, 5) == "eight") num = "8";
            if (i >= 3 && line.substr(i - 3, 4) == "nine") num = "9";

            if (num == "") continue;
            if (first == "") first = num;
            last = num;
        }

        ans += stoi(first + last);
    }

    cout << ans;

    return 0;
}
