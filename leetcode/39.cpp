#include<vector>
#include<unordered_map>
#include<iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {  
        vector<vector<int> > s;
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        func(s, t, candidates, 0, target);
        return s;
    }

    void func(vector<vector<int> > & s, vector<int> & t, vector<int> & candidates, int i, int target) {
        if (i+1>candidates.size()) return;
        if (target == candidates[i]) {
            t.push_back(candidates[i]);
            s.push_back(t);
            t.pop_back();
            return;
        }
        if (target < candidates[i]) {
            return;
        }
        t.push_back(candidates[i]);
        func(s, t, candidates, i, target-candidates[i]);
        t.pop_back();
        func(s, t, candidates, i + 1, target);
    }
};

int main() {
}
