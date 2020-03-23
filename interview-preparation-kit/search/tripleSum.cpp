#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

map<long, int> vectorToMap(vector<long> &a) {
    map<long, int> res;
    for(int i : a) {
        res[i]++;
    }
    return res;
}

vector<long> mapToVector(map<long, int> &map) {
    vector<long> res;
    for(auto it : map) {
        res.push_back(it.first);
    }
    return res;
}

long long binarySearch(vector<long> &v, int l, int r, long val, int &memory) {
    if(l <= r) {
        int m = l + (r - l) / 2;
        if(v[m] < val) {
            memory = m;
            return binarySearch(v, m + 1, r, val, memory);
        }
        else if(v[m] > val) {
            return binarySearch(v, l, m - 1, val, memory);
        }
        else {
            return m;
        }
    }
    return max(-1, memory);
}

// Complete the triplets function below.
long long triplets(vector<long> a, vector<long> b, vector<long> c) {
    map<long, int> map1, map2, map3;
    long long res = 0;
    long long items1, items3;
    int memory;

    map1 = vectorToMap(a); map2 = vectorToMap(b); map3 = vectorToMap(c);

    vector<long> v1(map1.size()), v2(map2.size()), v3(map3.size());
    v1 = mapToVector(map1); v2 = mapToVector(map2); v3 = mapToVector(map3);

    for(int i = 0; i < v2.size(); i++) {
        memory = -1;
        items1 = binarySearch(v1, 0, v1.size() - 1, v2[i], memory) + 1;

        memory = -1;
        items3 = binarySearch(v3, 0, v3.size() - 1, v2[i], memory) + 1;

        res += items1 * items3;
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<long> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stol(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<long> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stol(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<long> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stol(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long long ans = triplets(arra, arrb, arrc);

    fout << ans << "\n";

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
