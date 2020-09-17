#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int layer = 1;
        string s = f(num, layer);
        return s;
    }
    
    string f(int& num, int& layer) {
        string s;
        switch (layer) {
            case 1:
                for (int i=0; i<num/1000; i++)
                    s.append("M");
                num = num % 1000;
            case 2:
                for (int i=0; i<num/900; i++)
                    s.append("CM");
                num = num % 900;
            case 3:
                for (int i=0; i<num/500; i++)
                    s.append("D");
                num = num % 500;
            case 4:
                for (int i=0; i<num/400; i++)
                    s.append("CD");
                num = num % 400;
            case 5:
                for (int i=0; i<num/100; i++)
                    s.append("C");
                num = num % 100;
            case 6:
                for (int i=0; i<num/90; i++)
                    s.append("XC");
                num = num % 90;
            case 7:
                for (int i=0; i<num/50; i++)
                    s.append("L");
                num = num % 50;
            case 8:
                for (int i=0; i<num/40; i++)
                    s.append("XL");
                num = num % 40;
            case 9:
                for (int i=0; i<num/10; i++)
                    s.append("X");
                num = num % 10;
            case 10:
                for (int i=0; i<num/9; i++)
                    s.append("IX");
                num = num % 9;
            case 11:
                for (int i=0; i<num/5; i++)
                    s.append("V");
                num = num % 5;
            case 12:
                for (int i=0; i<num/4; i++)
                    s.append("IV");
                num = num % 4;
            case 13:
                for (int i=0; i<num/1; i++)
                    s.append("I");
                num = 0;
        }
        layer++;
        if (!num) {
            string later = f(layer, num);
            s.append(later);
        }
        return s;
    }
};

int main() {
    Solution s;
    string ss = s.intToRoman(3987);
    cout << ss << endl;
    return 0;
}
