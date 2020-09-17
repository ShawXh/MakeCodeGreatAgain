#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int min(int a, int b) {
    return a<b ? a : b;
}

int max(int a, int b) {
    return a>b ? a : b;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        double result;
        
        // make sure l1 <= l2;
        if (l1 > l2) return findMedianSortedArrays(nums2, nums1);
        if (l1 == 0) return (double) (nums2[l2/2] + nums2[(l2 - 1)/2]) * 0.5;

        int i = (l1 + 1)/2; // length = i
        // range of i: [0, l1]
        int j = (l1 + l2 + 1)/2 - i; // length = j
        // range of j: [0, l2]
        int move = (l1 + 1) / 2;
        cout << "move\ti\tj" << endl;
        while (1) {
            cout << move << "\t" << i << "\t" << j << endl;
            if (move == 0) return get_result(nums1, nums2, i, j, l1, l2);

            move = check(nums1, nums2, i, j, l1, l2, move);
            i = max(0, min(l1, i + move));
            j = max(0, min(l2, j - move));
        }
    }

    int check(vector<int> &nums1, vector<int>& nums2, int i, int j, int l1, int l2, int move) {
        if (i == l1) {
            if (nums1[i - 1] <= nums2[j]) return 0;
            else return - ((int) abs(move) + 1) / 2;
        }
        else if (i == 0) {
            if (nums1[i] >= nums2[j-1]) return 0;
            else return ((int) abs(move) + 1) / 2;
        }
        else {
            if (nums1[i] >= nums2[j-1] && nums1[i-1] > nums2[j]) {
                return - ((int) abs(move) + 1) / 2;
            }
            else if (nums1[i-1] <= nums2[j] && nums1[i] < nums2[j-1])
                return ((int) abs(move) + 1) / 2;
            else return 0;
        }
    }
    
    double get_result(vector<int> &nums1, vector<int>& nums2, int i, int j, int l1, int l2) {
        double left, right;
        if ((l1 + l2) % 2) {
            if (i) return (double) max(nums1[i-1], nums2[j-1]);
            else return (double) nums2[j-1];
        }
        else {
            if (i) 
                if (j) left = (double) max(nums1[i-1], nums2[j-1]);
                else left = (double) nums1[i-1];
            else left = (double) nums2[j-1];
            if (l1-i) 
                if (l2 - j) right = (double) min(nums1[i], nums2[j]);
                else right = (double) nums1[i];
            else right = (double) nums2[j];
            return 0.5 * (left + right);
        }
    }
};

int main(){
    int n1[1] = {1};
    int n2[1] = {2};

    vector<int> vn1 (n1, n1+1);
    vector<int> vn2 (n2, n2+1);
    
    for (int i=0; i<vn1.size(); i++) cout << vn1[i] << " ";
    cout << endl;
    for (int i=0; i<vn2.size(); i++) cout << vn2[i] << " ";
    cout << endl;

    Solution s;
    cout << s.findMedianSortedArrays(vn1, vn2) << endl;

    return 0;
}
