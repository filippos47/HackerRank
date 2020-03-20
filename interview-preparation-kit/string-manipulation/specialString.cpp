#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long cnt = 0;
    vector<int> charFinder(n);   
    int i, j; 

    i = 0;
    while(i < n) {
        charFinder[i]++;
        j = 1;

        while(s[i] == s[i + j] && i + j < n) {
            charFinder[i]++;
            j++;
        }

        // 1 + ... + n = (n * (n + 1)) / 2
        cnt += (charFinder[i] * (charFinder[i] + 1)) / 2; 
        i += j;
    }

    for(i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            charFinder[i] = charFinder[i - 1];
        }
        else if(i < n - 1 && s[i - 1] == s[i + 1] &&
            s[i] != s[i - 1]) {
            cnt += min(charFinder[i - 1], charFinder[i + 1]);
        }
    }

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
