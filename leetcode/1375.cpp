// 1375. Bulb Switcher III

class Solution {
public:
    int right_most = 0;
    int answer = 0;
    int numTimesAllBlue(vector<int>& light) {
        for(int i=0; i<light.size(); i++) {
            right_most = max(right_most, light[i]);
            if(i + 1 == right_most) answer++;
        }
        return answer;
    }
};