#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long merge(vector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;;
    vector<int> L(n1), R(n2);
    long swaps = 0;

    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            swaps += n1 - i;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return swaps;
}

void mergeSort(vector<int> &arr, int l, int r, long &swaps) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, swaps);
        mergeSort(arr, m + 1, r, swaps);

        swaps += merge(arr, l, m, r);
    }
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    long swaps = 0;

    mergeSort(arr, 0, arr.size() - 1, swaps);
    return swaps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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
