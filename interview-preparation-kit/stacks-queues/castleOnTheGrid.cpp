#include <bits/stdc++.h>
#include <utility>

using namespace std;

vector<string> split_string(string);

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    stack<pair<pair<int, int>, int>> mystack;
    pair<int, int> goal(goalX, goalY);
    pair<pair<int, int>, int> current;
    int x, y, moves, n = grid.size(), saveX, saveY;
    int distance[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            distance[i][j] = INT_MAX;
        }
    }

    mystack.push(make_pair(make_pair(startX, startY), 0));
    distance[startX][startY] = 0;

    while(!mystack.empty()) {
        current = mystack.top();
        mystack.pop();
        x = current.first.first;
        saveX = x;
        y = current.first.second;
        saveY = y;
        moves = current.second;

        while(y < n - 1) {
            if(grid[x][y + 1] != 'X' && distance[x][y + 1] >= moves + 1) { // right
                mystack.push(make_pair(make_pair(x, y + 1), moves + 1));
                distance[x][y + 1] = moves + 1;
                y++;
            }
            else {
                break;
            }
        }
        y = saveY;
        while(x > 0) {
            if(grid[x - 1][y] != 'X' && distance[x - 1][y] >= moves + 1) { // up
                mystack.push(make_pair(make_pair(x - 1, y), moves + 1));
                distance[x - 1][y] = moves + 1;
                x--;
            }
            else {
                break;
            }
        }
        x = saveX;
        while(y > 0) {
            if(grid[x][y - 1] != 'X' && distance[x][y - 1] >= moves + 1) { // left
                mystack.push(make_pair(make_pair(x, y - 1), moves + 1));
                distance[x][y - 1] = moves + 1;
                y--;
            }
            else {
                break;
            }
        }
        y = saveY;
        while(x < n - 1) {
            if(grid[x + 1][y] != 'X' && distance[x + 1][y] >= moves + 1) { // down
                mystack.push(make_pair(make_pair(x + 1, y), moves + 1));
                distance[x + 1][y] = moves + 1;
                x++;
            }
            else {
                break;
            }
        }
        x = saveX;
    }

    return distance[goalX][goalY];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

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
