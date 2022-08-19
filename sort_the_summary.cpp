#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'groupSort' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
bool freqsort(const vector<int>& v1, const vector<int>& v2)
{
    if(v1[1]==v2[1]){
        return v1[0] < v2[0];
    }
    return v1[1] > v2[1];
}
vector<vector<int>> groupSort(vector<int> arr) {
    vector<vector<int>>  result ;
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        if(mpp.find(arr[i])==mpp.end()){
            mpp[arr[i]]=1;
        }
        else{
            mpp[arr[i]]++;
        }
    }
    map<int,int>:: iterator imp;
    for(imp=mpp.begin(); imp!=mpp.end();imp++){
        result.push_back({imp->first, imp->second});
    }
    sort(result.begin(), result.end(), freqsort);
    // sort(result.begin(), result.end(), sort);
    return result;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    vector<vector<int>> result = groupSort(arr);

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
