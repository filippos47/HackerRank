#include <bits/stdc++.h>

using namespace std;

void decrementElement(map<char, int> &mymap, char &c) {
    if(--mymap[c] == 0) {
        mymap.erase(c);
    }
}

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    map<char, int> mymap, kamikaze;
    string res = "";
    int n = s.size(), startIndex, currIndex = 0;
    bool goNext, valid;
    int rightSubstring[n][26];

    reverse(s.begin(), s.end());
    cout << s << endl;

    for(int i = 0; i < 26; i++) {
        rightSubstring[n - 1][i] = 0;
    }

    for(int i = n - 2; i > -1; i--) {
        for(int j = 0; j < 26; j++) {
            rightSubstring[i][j] = rightSubstring[i + 1][j];
        }
        rightSubstring[i][(int)(s[i + 1] - 'a')]++;
    }

    for(char c : s) {
        mymap[c]++;
    }

    for(auto it = mymap.begin(); it != mymap.end(); it++) {
        mymap[it->first] /= 2;
    }


    for(auto itt : mymap) {
        kamikaze[itt.first] = itt.second;
    }
    for(int i = 0; i < n / 2; i++) {
        
        for(auto it = mymap.begin(); it != mymap.end(); it++) {
            while(it->second == 0) {
                it++;
            }
            goNext = false;
            valid = true;


            for(int j = currIndex; j < n; j++) {
                if(s[j] == it->first) {
                    startIndex = j + 1;
                    decrementElement(kamikaze, s[j]);
                    break;
                }
                if(n - 1 - j < n / 2 - res.size()) {
                    goNext = true;
                    break;
                }
            }

            if(goNext) {
                continue;
            }
            for(int j = 0; j < 26; j++) {
                if(rightSubstring[startIndex - 1][j] < kamikaze[(char)(j + 'a')]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                mymap[s[startIndex - 1]]--;
                res += s[startIndex - 1];
                currIndex = startIndex;
                break;
            }
            else {
                kamikaze[s[startIndex - 1]]++;
            }
        }
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
