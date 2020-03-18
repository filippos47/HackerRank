#include <bits/stdc++.h>

using namespace std;

int handleDeletions(map<char, int>::iterator &it1, 
    map<char, int>::iterator &it2, int &deletions) {
        if(it1->first < it2->first) {
            deletions += it1->second;
            return 1;
        }
        else if(it1->first > it2->first) {
            deletions += it2->second;
            return -1;
        }
        else {
            deletions += abs(it1->second - it2->second);
            return 0;
        }
}

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char, int> map1, map2;
    int deletions = 0, hlp;
    map<char, int>::iterator it1, it2;

    for(char c : a) {
        map1[c]++;
    }
    for(char c : b) {
        map2[c]++;
    }

    it1 = map1.begin();
    it2 = map2.begin();
    while(it1 != map1.end() && it2 != map2.end()) {
                    cout << "It1: " << it1->first << ", " << it1->second << " :: It2: " <<
                it2->first << ", " << it2->second <<  ":: Deletions: " << 
                deletions << endl;
            hlp = handleDeletions(it1, it2, deletions);

            if(hlp > 0) {
                it1++;
            }
            else if(hlp < 0) {
                it2++;
            }
            else {
                it1++;
                it2++;
            }
    }
    
    if(it1 == map1.end()) {
        while(it2 != map2.end()) {
            cout << "It1: " << it1->first << ", " << it1->second << " :: It2: " <<
                it2->first << ", " << it2->second <<  ":: Deletions: " <<
                deletions << endl; 
            deletions += it2->second;
            it2++;
        }
    }
    else {
        while(it1 != map1.end()) {
            cout << "It1: " << it1->first << ", " << it1->second << " :: It2: " <<
                it2->first << ", " << it2->second <<  ":: Deletions: " <<
                deletions << endl; 
            deletions += it1->second;
            it1++;
        }
    }
            cout << "It1: " << it1->first << ", " << it1->second << " :: It2: " <<
                it2->first << ", " << it2->second <<  ":: Deletions: " <<
                deletions << endl; 
    return deletions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
