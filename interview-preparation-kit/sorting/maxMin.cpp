#include <bits/stdc++.h>
#include <climits>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;;
    vector<int> L(n1), R(n2);

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

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int res = INT_MAX, hlp;

    mergeSort(arr, 0, arr.size() - 1);
    for(int i = k - 1, j = 0; i < arr.size(); i++, j++) {
        if((hlp = arr[i] - arr[j]) < res) {
            res = hlp;
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

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
