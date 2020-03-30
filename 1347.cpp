class Solution {
public:
    int minSteps(string s, string t) {
        int result = 0;
        int size = s.length();
        
        int s_arr[26] = {0, };
        
        for(int i=0; i<size; i++) {
            int tmp = s[i];
            s_arr[tmp - 97]++;
        }
        
        for(int i=0; i<size; i++) {
            int tmp = t[i];
            s_arr[tmp - 97]--;
        }
        
        for(int i=0; i<26; i++)
            if(s_arr[i] < 0) result += abs(s_arr[i]);
        
        return result;
    }
};