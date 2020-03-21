#include <bits/stdc++.h>

using namespace std;

int treeHeight(vector<vector<int>> &indexes, int index) {
    int leftChild = indexes[index][0], rightChild = indexes[index][1];
    int lDepth, rDepth;

    if(leftChild > 0) {
        lDepth = treeHeight(indexes, leftChild - 1);
    }
    else {
        lDepth = 0;
    }

    if(rightChild > 0) {
        rDepth = treeHeight(indexes, rightChild - 1);
    }
    else {
        rDepth = 0;
    }

    return max(lDepth, rDepth) + 1;
}

void calculateLevels(vector<vector<int>> &indexes, vector<int> &levelGuide) {
    int levelEndsAt = 1, i = 0, currentLevel = 0, n = indexes.size();
    int nextLevelEndsAt = 0;

    levelGuide[0] = 0;

    while(i < n) {
        while(i < levelEndsAt) {
            nextLevelEndsAt = max(nextLevelEndsAt, indexes[i][0]);
            nextLevelEndsAt = max(nextLevelEndsAt, indexes[i][1]);
            i++;
        }
        currentLevel++;
        levelGuide[currentLevel] = levelEndsAt;
        if(levelEndsAt == n) {
            break;
        }
        levelEndsAt = nextLevelEndsAt;
    }
}

void inOrderTraversal(vector<vector<int>> &indexes, int index, vector<int> &res) {
    int leftChild = indexes[index][0], rightChild = indexes[index][1];    
    if(leftChild > 0) {
        inOrderTraversal(indexes, leftChild - 1, res);
    }

    res.push_back(index + 1);

    if(rightChild > 0) {
        inOrderTraversal(indexes, rightChild - 1, res);
    }
    
}

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    int height = treeHeight(indexes, 0), step;
    vector<vector<int>> res(queries.size());
    vector<int> levelGuide(height + 1);

    calculateLevels(indexes, levelGuide);

    for(int i = 0; i < queries.size(); i++) {
        step = queries[i];
        for(int j = step - 1; j < height; j+= step) {
            for(int k = levelGuide[j]; k < levelGuide[j + 1]; k++) {
                swap(indexes[k][0], indexes[k][1]);
            }
        }
        inOrderTraversal(indexes, 0, res[i]);
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
