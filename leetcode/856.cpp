// 856. Score of Parentheses

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<char> s;
        int score = 0;
        int tmp = 0;
        for(int i=0; i<S.size(); i++) {
            if(S[i] == '(') {
                s.push(S[i]);
                tmp++;
            }
            else {
                tmp--;
                if(s.top() == '(') {
                    score += pow(2, tmp);
                }
                s.push(S[i]);
            }
        }
        return score;
    }
};

