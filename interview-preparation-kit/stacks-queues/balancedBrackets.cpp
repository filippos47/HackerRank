#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    int n = s.size();
    stack<char> mystack;

    for(int i = 0; i < n; i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
            mystack.push(s[i]);
        }
        else {
            if(mystack.empty()) {
                return "NO";
            }

            switch (s[i]) {
            case '}':
                if(mystack.top() != '{') {
                    return "NO";
                }
                break;
            
            case ']':
                if(mystack.top() != '[') {
                    return "NO";
                }
                break;

            case ')':
                if(mystack.top() != '(') {
                    return "NO";
                }
                break;
            }
            mystack.pop();
        }
    }

    if(!mystack.empty()) {
        return "NO";
    }
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
