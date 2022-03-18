class Solution {
public:
    int romanToInt(string s) {
        stack<char> myset;
        char temp = 'n';
        char var = 'n';
        for (int i = 0; i < s.size(); i++) {
            myset.push(s.at(i));
        }
        int count = 0;
        while(!myset.empty()) {
            var = myset.top();
            switch (var) {
                case 'I':
                    count += 1;
                    break;
                case 'V':
                    count += 5;
                    break;
                case 'X':
                    count += 10;
                    break;
                case 'L':
                    count += 50;
                    break;
                case 'C':
                    count += 100;
                    break;
                case 'D':
                    count += 500;
                    break;
                case 'M':
                    count += 1000;
                    break;
            }
            if ((temp == 'V' || temp == 'X') && var == 'I') {
                count -= 2;
            } else if (var == 'X') {
                if (temp == 'L' || temp == 'C') {
                    count -= 20;
                }
            } else if (var == 'C') {
                if (temp == 'D' || temp == 'M') {
                    count -= 200;
                }
            }
            temp = myset.top();
            myset.pop();
        }
        return count;   
    }
};