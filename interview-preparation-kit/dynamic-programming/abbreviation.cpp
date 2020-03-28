#include <bits/stdc++.h>

using namespace std;



// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int n1 = a.size(), n2 = b.size(), DP[n1 + 1][n2 + 1];
    int i, j;

    DP[0][0] = 1;
    for(i = 1; i <= n2; i++) {
        DP[0][i] = 0;
    }
    for(i = 1; i <= n1; i++) {
        DP[i][0] = DP[i - 1][0] & (a[i - 1] > 96);
    }


    for(i = 1; i <= n1; i++) {
        for(j = 1; j <= n2; j++) {
            if(a[i - 1] == b[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1];
            }
            else if((char)(a[i - 1] - 32) == b[j - 1]) {
                DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
            }
            else if(a[i - 1] < 97) {
                DP[i][j] = 0;
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    return DP[n1][n2] == true ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
