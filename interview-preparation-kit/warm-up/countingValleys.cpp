#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int currentLevel = 0, valleys = 0;
    bool belowSea = false;

    for(char item : s) {
        if(item == 'U') {
            currentLevel++;
        }
        else {
            currentLevel--;
        }
        if(currentLevel < 0 && belowSea == false) {
            belowSea = true;
        }
        if(currentLevel == 0 && belowSea == true) {
            belowSea = false;
            valleys++;
        }
    }
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}


