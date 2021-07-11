#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'applicationPairs' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER deviceCapacity
 *  2. 2D_INTEGER_ARRAY foregroundAppList
 *  3. 2D_INTEGER_ARRAY backgroundAppList
 */

vector<vector<int>> applicationPairs(int deviceCapacity, vector<vector<int>> foregroundAppList, vector<vector<int>> backgroundAppList) {    
    vector<vector<int>> ans;
    int acc = 0;
    
    for(int i=0; i<foregroundAppList.size(); i++) {
        for(int j=0; j<backgroundAppList.size(); j++) {
            int sum = foregroundAppList[i][i] + backgroundAppList[i][j];
            if(sum > acc && sum < deviceCapacity) {
                ans.clear();
                ans[foregroundAppList[i][i]][backgroundAppList[i][j]];
            }else if(sum == acc && sum < deviceCapacity) {
                ans[foregroundAppList[i][i]][backgroundAppList[i][j]];
            }
        }
    }
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string deviceCapacity_temp;
    getline(cin, deviceCapacity_temp);

    int deviceCapacity = stoi(ltrim(rtrim(deviceCapacity_temp)));

    string foregroundAppList_rows_temp;
    getline(cin, foregroundAppList_rows_temp);

    int foregroundAppList_rows = stoi(ltrim(rtrim(foregroundAppList_rows_temp)));

    string foregroundAppList_columns_temp;
    getline(cin, foregroundAppList_columns_temp);

    int foregroundAppList_columns = stoi(ltrim(rtrim(foregroundAppList_columns_temp)));

    vector<vector<int>> foregroundAppList(foregroundAppList_rows);

    for (int i = 0; i < foregroundAppList_rows; i++) {
        foregroundAppList[i].resize(foregroundAppList_columns);

        string foregroundAppList_row_temp_temp;
        getline(cin, foregroundAppList_row_temp_temp);

        vector<string> foregroundAppList_row_temp = split(rtrim(foregroundAppList_row_temp_temp));

        for (int j = 0; j < foregroundAppList_columns; j++) {
            int foregroundAppList_row_item = stoi(foregroundAppList_row_temp[j]);

            foregroundAppList[i][j] = foregroundAppList_row_item;
        }
    }

    string backgroundAppList_rows_temp;
    getline(cin, backgroundAppList_rows_temp);

    int backgroundAppList_rows = stoi(ltrim(rtrim(backgroundAppList_rows_temp)));

    string backgroundAppList_columns_temp;
    getline(cin, backgroundAppList_columns_temp);

    int backgroundAppList_columns = stoi(ltrim(rtrim(backgroundAppList_columns_temp)));

    vector<vector<int>> backgroundAppList(backgroundAppList_rows);

    for (int i = 0; i < backgroundAppList_rows; i++) {
        backgroundAppList[i].resize(backgroundAppList_columns);

        string backgroundAppList_row_temp_temp;
        getline(cin, backgroundAppList_row_temp_temp);

        vector<string> backgroundAppList_row_temp = split(rtrim(backgroundAppList_row_temp_temp));

        for (int j = 0; j < backgroundAppList_columns; j++) {
            int backgroundAppList_row_item = stoi(backgroundAppList_row_temp[j]);

            backgroundAppList[i][j] = backgroundAppList_row_item;
        }
    }

    vector<vector<int>> result = applicationPairs(deviceCapacity, foregroundAppList, backgroundAppList);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


