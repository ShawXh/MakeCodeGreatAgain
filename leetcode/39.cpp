#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        vector<vector<int> > ss;
        vector<int> s;
        vector<int> idx;
        s.push_back(candidates[0]);
        idx.push_back(0);

        int curi;
        int sum = candidates[0];
        while (!s.empty()) {
            curi = idx[idx.size()-1];
            sum += 

        
        }


    }
};

int main() {
}
