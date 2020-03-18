#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    map<char, int> mymap;
    map<int, int> mymapInverted, helper;
    int validityCount = 0, savedCount;
    map<char, int>::iterator it;
    map<int, int>::iterator it2;

    for(char c : s) {
        if(mymap[c] > 0) {
            helper[mymap[c]]--;
        }
        mymap[c]++;
        helper[mymap[c]]++;
    }

    for(auto i : helper) { // eliminating elements with zero occurences
        if(i.second > 0) {
            mymapInverted[i.first] = i.second;
        }
    }

    for(it2 = mymapInverted.begin(); it2 != mymapInverted.end(); it2++) {
        savedCount = it2->first;
        validityCount = 0;
        it = mymap.begin();

        while(it != mymap.end()) {
            if(it->second > savedCount) {
                validityCount += it->second - savedCount;
            }
            if(it->second < savedCount) {
                validityCount += it->second;
            }
            it++;
            if(validityCount > 1) {
                break;
            }
        }
        if(validityCount < 2) {
            break;
        }
    }

    if(validityCount < 2) {
        return "YES";
    }
    else {
        return "NO";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
