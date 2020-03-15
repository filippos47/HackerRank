#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long div = n / s.size(), rem = n % s.size();
    long occurencesInString = 0, occurencesInSubstring = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') {
            occurencesInString++;
            if(i < rem) {
                occurencesInSubstring++;
            }
        }
    }

    return div * occurencesInString + occurencesInSubstring;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

