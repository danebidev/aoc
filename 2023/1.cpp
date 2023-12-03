#include <bits/stdc++.h>

#include <cctype>
#include <string>

using namespace std;

int main() {
    ifstream in("input");

    int ans1 = 0;
    int ans2 = 0;
    string line;

    while (getline(in, line)) {
        string first1 = "";
        string last1 = "";
        string first2 = "";
        string last2 = "";

        for (int i = 0; i < line.size(); i++) {
            string num = "";

            if (isdigit(line[i])) {
                num = line[i];
                if (first1 == "") first1 = num;
                if (first2 == "") first2 = num;
                last1 = num;
                last2 = num;
                continue;
            }

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
            if (first2 == "") first2 = num;
            last2 = num;
        }

        ans1 += stoi(first1 + last1);
        ans2 += stoi(first2 + last2);
    }

    cout << "Part 1: " << ans1 << endl;
    cout << "Part 2: " << ans2 << endl;

    return 0;
}
