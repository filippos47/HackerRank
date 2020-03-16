#include <bits/stdc++.h>
#include <algorithm>
#include <pthread.h>

using namespace std;

vector<string> split_string(string);

void merge(vector<string> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<string> L(n1), R(n2);

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
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        k++;
        i++;
    }

    while(j < n2) {
        arr[k] = R[j];
        k++;
        j++;
    }
}

void mergeSort(vector<string> &arr, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int binarySearch(vector<string> &arr, int l, int r, string str) {
    if(l <= r) {
        int m = l + (r - l) / 2;

        if(arr[m] < str) {
            return binarySearch(arr, m + 1, r, str);
        }
        else if(arr[m] > str) {
            return binarySearch(arr, l, m - 1, str);
        }
        else {
            return m;
        }
    }
    return -1;
}

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    bool condition, watcher = true;
    int hlp;

    mergeSort(magazine, 0, magazine.size() - 1);

    for(string notee : note) {
        condition = false;
        if((hlp = binarySearch(magazine, 0, magazine.size(), notee)) != -1) {
            condition = true;
            magazine.erase(magazine.begin() + hlp);
        }
        if(!condition) {
            watcher = false;
            break;
        }
    }

    if(watcher) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

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
