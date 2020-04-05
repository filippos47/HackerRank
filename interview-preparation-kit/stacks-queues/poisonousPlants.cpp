#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the poisonousPlants function below.
int poisonousPlants(vector<long> p) {
    int n = p.size(), res = 0, j;
    vector<int> marker(n);
    long prev, limit;

    for(int i = n - 2; i > -1; i--) {
        j = i + 1;
        if(p[j] > p[i]) {
            limit = prev = p[j];
            if(marker[j] == 0) {
                marker[i] = 1;
            }
            else {
                marker[i] = marker[j];
                marker[j] = 0;
            }
        }
        else {
            continue;
        }

        j++;
        while(j < n) {
            if(p[j] > p[i]) {
                if(p[j] <= prev && p[j] <= limit) {
                    if(marker[j] == 0) {
                        marker[i]++;
                    }
                    else if(marker[i] < marker[j]) {
                        marker[i] = marker[j];
                    }
                    else if(marker[i] == marker[j]) {
                        marker[i]++;
                    }
                    else {
                        marker[i]++;
                    }
                    marker[j] = 0;
                    limit = p[j];
                }
                prev = p[j];
                j++;
            }
            else {
                break;
            }
        }

        if(marker[i] > res) {
            res = marker[i];
        }
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<long> p(n);

    for (int i = 0; i < n; i++) {
        long p_item = stol(p_temp[i]);

        p[i] = p_item;
    }

    long result = poisonousPlants(p);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

