// 1016. Binary String With Substrings Representing 1 To N

class Solution {
public:
    string integerToBinary(int N) {
        string bin = "";
        while(1) {
            if(N == 0) break;
            if(N%2 == 1) bin += "1";
            else bin += "0";
            N /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }
    
    bool queryString(string S, int N) {
        for(int i=1; i<=N; i++) {
            string bin = integerToBinary(i);
            if(S.find(bin) == string::npos) return false;
            else continue;
        }        
        return true;
    }
};
