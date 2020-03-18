#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int notifications = 0, relativeCounter = 1, incoming, outgoing;
    float median;
    map<int, int> mymap;
    map<int, int>::iterator it;

    // frequency map initialization
    for(int i = 0; i < d; i++) { 
        mymap[expenditure[i]]++;
    }

    // set iterator, relativeCounter to the right values
    it = mymap.begin();
    for(int i = 0; i < d / 2; i++) {
        for(int j = 2; j <= it->second && i < d / 2; j++, i++){
            relativeCounter++;
        }
        if(i < d / 2) {
            it++;
            relativeCounter = 1;
        }
    }

    for(int i = d; i < expenditure.size(); i++) {
        incoming = expenditure[i]; // incoming value
        outgoing = expenditure[i - d]; // outgoing value

        median = it->first;
        if(d % 2 == 0) { // if d even, we need the previous element too
            if(relativeCounter == 1) { // go to the previous number
                it--;
                while(it->second == 0) { // skip "dead" elements
                    it--;
                }
                median += it->first;
                it++;
                while(it->second == 0) { // skip "dead" elements
                    it++;
                }
            }
            if(relativeCounter > 1) { // another instance of the same number
                median += it->first;
            }
            median /= 2;
        }
        if(2 * median <= expenditure[i]) {
            notifications++;
        }

        // this step is done, time to prepare the next step
        // we have to update iterator, relativeCounter and frequency map
        // first, we determine what happens to relativeCounter
        if(outgoing < it->first && incoming >= it->first) {
            relativeCounter++;
        }
        if(outgoing >= it->first && incoming < it->first) {
            relativeCounter--;
        }
        if(outgoing == it->first && incoming > it->first) {
            if((relativeCounter == 1 && it->second == 1) || 
                (relativeCounter == it->second && it->second > 1)) {
                relativeCounter++;
            }
        }

        // updating frequency map
        mymap[expenditure[i]]++;
        mymap[expenditure[i - d]]--;

        // updating iterator, must be AFTER updating relativeCounter
        if(relativeCounter < 1) {
            it--;
            while(it->second == 0) {
                it--;
            }
            relativeCounter = it->second;
        }
        else if(relativeCounter > it->second) {
            it++;
            while(it->second == 0) {
                it++;
            }
            relativeCounter = 1;
        }
    }

    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
