#include<iostream>
#include<unordered_map>
using namespace std;

int max(int i, int j){
    return i>j ? i : j;
}

class Solution {
public:
    int* lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0;
        int r = 0;
        int res = 0;
        int *ress = new int [3];
        for (int i=0; i<s.size(); i++) m[s[i]] = -1;
        for (int i=0; i<s.size(); i++){
            if (m[s[i]] >= 0) {
                if (m[s[i]] >= l) l = m[s[i]] + 1;
            }
            m[s[i]] = i;
            if (i - l + 1 > res) {
                r = i;
                res = i - l + 1;
                ress[0] = l;
                ress[1] = r;
                ress[2] = res;
            }
            cout << i << " " << l << " " << r << endl;
        }
        return ress;
    }
};


int main(){
    Solution solut;

    //string s1 = "abcabcbb";
    string s1 = "a";
    int* res1 = solut.lengthOfLongestSubstring(s1);
    cout << res1[0] << " " << res1[1] << " " << res1[2] << endl;

    return 0;
}
