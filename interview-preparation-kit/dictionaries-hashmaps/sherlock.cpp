#include <bits/stdc++.h>

using namespace std;

bool map_compare(map<char, int> &map1, map<char, int> &map2) {
    return map1.size() == map2.size() && 
        equal(map1.begin(), map1.end(), map2.begin());
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    vector<map<char, int>> substrings;
    int anagrams = 0;
    bool condition;

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < s.size() + 1 - i; j++) {
            map<char, int> hlp;
            for(int k = 0; k < i; k++) {
                hlp[s[j + k]]++;
            }
            substrings.push_back(hlp);
        }
    }

    for(int i = 0; i < substrings.size(); i++) {
        for(int j = i + 1; j < substrings.size(); j++) {
            if(map_compare(substrings[i], substrings[j])) {
                anagrams++;
            }
        }
    }
    return anagrams;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        cout << result << "\n";
    }

    return 0;
}
