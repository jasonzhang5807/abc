#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

string findMostFrequentSubstring(const string& s) {
    unordered_map<string, int> substringCount;
    int n = s.size();

    // Generate all non-empty substrings
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + j <= n; ++j) {
            string sub = s.substr(i, j);
            ++substringCount[sub];
        }
    }

    string mostFrequentSubstring;
    int maxCount = 0;

    for (const auto& entry : substringCount) {
        const string& sub = entry.first;
        int count = entry.second;

        if (count > maxCount) {
            maxCount = count;
            mostFrequentSubstring = sub;
        } else if (count == maxCount) {
            if (sub.size() > mostFrequentSubstring.size() ||
                (sub.size() == mostFrequentSubstring.size() && sub > mostFrequentSubstring)) {
                mostFrequentSubstring = sub;
            }
        }
    }

    return mostFrequentSubstring;
}

int main() {
    freopen("bride.in","r",stdin);
    freopen("bride.out","w",stdout);
    string s;
    cin >> s;
    string result = findMostFrequentSubstring(s);
    cout << result << endl;

    return 0;
}
