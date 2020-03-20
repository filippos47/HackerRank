#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int n = s1.size();
    int **DP;

    DP = (int**)malloc((n + 1)* sizeof(int*));
    for(int i = 0; i < n + 1; i++) {
        DP[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            if(i == 0 || j == 0) {
                DP[i][j] = 0; // initializing base cases
                continue;
            }

            if(s1[i - 1] == s2[j - 1]) {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else {
                DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
            }

        }
    }

    return DP[n][n];
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
