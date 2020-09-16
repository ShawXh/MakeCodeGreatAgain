#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<vector<int> > combine(int n ,int k){
            vector<vector<int> > result;
            vector<int> tmp;
            fillIn(result, tmp, n, k);
            print(result, k);
            return result;
        }

        void fillIn(vector<vector<int> > & result, vector<int> & tmp, int n, int k){
        int l;
        l = tmp.size();
        if (l == k) {
            result.push_back(tmp);
            return;
        }
        int start = 1;
        if (l > 0) {
            start = tmp[l-1] + 1;
            if (k-l > n-tmp[l-1]) return;
        }
        for (int i=start; i<=n; i++){
            tmp.push_back(i);
            fillIn(result, tmp, n, k);
            tmp.pop_back();
        }
        }

        void print(vector<vector<int> > & result, int k){
            for (int j=0; j<result.size(); j++){
                for (int i=0; i<k; i++){
                    printf("%d ", result[j][i]);
                }
                printf("\n");
            }
        }
};

int main(){
    Solution s;
    s.combine(5,3);
    return 0;
}
