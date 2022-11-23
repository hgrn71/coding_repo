#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

vector<vector<int>> cluster(const vector<int> input) {
    vector<vector<int>> cluster_res;
    if (input.size() <=1 ) {
        cluster_res.push_back(input);
        return cluster_res;
    } 
    vector<int> temp_vec;
    temp_vec.push_back(input[0]);
    for (int i=1;i< input.size();i++) {
        if (input[i] - input[i-1] > 1) {
            cluster_res.push_back(temp_vec);
            temp_vec.clear();
        }
        temp_vec.push_back(input[i]);
    }
    cluster_res.push_back(temp_vec);
    return cluster_res;
}

int main() {
    vector<vector<int>> A;
    //vector<int> B = {1,1,1,1,1};
    vector<int> B = {1,2,3,6,8,10};
    A = cluster(B);
    cout << "A info:\n";
    for (int i=0;i< A.size();i++) {
        for (int j=0; j< A[i].size();j++) {
            cout << A[i][j] << " , ";
        }
        cout << endl;
    }
    return 0;
}
