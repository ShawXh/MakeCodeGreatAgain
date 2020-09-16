#include <iostream>
#include <vector>
using namespace std;
// 373

class Solution {
public:
    vector< pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector< pair<int, int> > res;
        int i, j, m = nums1.size(), n = nums2.size();
        vector<int> index(m,0);
        k = min(k,m*n);
        while(k-->0){
            int temp;
            int minv = 99;
            for(i=0;i<m;i++){
                if(index[i]<n&&minv>nums1[i]+nums2[index[i]]){
                    minv=nums1[i]+nums2[index[i]];
                    temp=i;
                }
            }
            res.push_back(make_pair(nums1[temp],nums2[index[temp]]));
            index[temp]++;
        }
        return res;
    }
};

int main()
{
    vector<int> nums1, nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    nums1.push_back(4);
    nums2.push_back(2);
    nums2.push_back(3);

    Solution s;
    vector< pair<int, int> > result;
    result = s.kSmallestPairs(nums1, nums2, 3);
    for (vector <pair <int,int> >::iterator iter = result.begin(); iter != result.end(); ++iter)
        cout <<(*iter).first <<" " <<(*iter).second <<endl;
    return 0;
}
