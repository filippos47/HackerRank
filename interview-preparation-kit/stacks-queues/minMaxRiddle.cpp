#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    int n = arr.size(), left, right;
    vector<long> maxMin(n);
    long me;

    for(int i = 0; i < n; i++) {
        left = i - 1;
        right = i + 1;
        me = arr[i];

        while(left > -1) {
            if(arr[left] >= me) {
                left--;
            }
            else {
                break;
            }
        }
        while(right < n) {
            if(arr[right] >= me) {
                right++;
            }
            else {
                break;
            }
        }
        left++; right--;
        for(int j = 0; j <= right - left; j++) {
            //cout << "i: " << i << ", j: " << j << ", maxMin: " << maxMin[j] << ", me: " << me << endl;
            maxMin[j] = max(maxMin[j], me);
        }


    }

    return maxMin;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
