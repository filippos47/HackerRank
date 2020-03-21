#include <bits/stdc++.h>
#include <pthread.h>

using namespace std;

vector<string> split_string(string);

void merge(vector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = j = 0;
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
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int binarySearch(vector<int> &arr, int l, int r, int val) {
    if(l <= r) {
        int m = l + (r - l) / 2;
        if(arr[m] < val) {
            return binarySearch(arr, m + 1, r, val);
        }
        else if(arr[m] > val) {
            return binarySearch(arr, l, m - 1, val);
        }
        else {

            return m;            
        }
    }
    return -1;
}

int linearSearch(vector<int> &arr, int wantedValue, int myIndex) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == wantedValue && i != myIndex) {
            return i;
        }
    }
    return -1;
}

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    int cnt = 0, n = cost.size(), wantedValue;
    int firstId, secondId, hlp;
    vector<int> copy(n);

    for(int i : cost) { // save cost vector before modification
        copy[cnt] = i;
        cnt++;
    }

    mergeSort(cost, 0, n - 1);

    for(int i = 0; i < n; i++) {
        if((wantedValue = money - copy[i]) < 1) {
            continue;
        }
        if((hlp = binarySearch(cost, 0, n - 1, wantedValue)) > -1) {
            if(wantedValue != copy[i] || 
                (wantedValue == copy[i] && 
                (cost[hlp] == cost[hlp - 1] || cost[hlp] == cost[hlp + 1]))) {
                firstId = i + 1;
                secondId = linearSearch(copy, wantedValue, i) + 1;
                break;
            }
        }
    }

    if(firstId < secondId) {
        cout << firstId << " " << secondId << endl;
    }
    else {
        cout << secondId << " " << firstId << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
