class Solution {
public:
    multiset<int> ms;
    set<int> s;
    multimap<int, int> m;
    int counter = 0;
    int minSetSize(vector<int>& arr) {
        int oldSize = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<oldSize; i++) {
            ms.insert(arr[i]);
            s.insert(arr[i]);
            
            if(i + 1 < oldSize && arr[i] != arr[i + 1]) {
                m.insert(pair<int, int> (ms.count(arr[i]), arr[i]));
            } else if(i == oldSize - 1 && arr[i] != arr[i - 1]) {
                m.insert(pair<int, int> (ms.count(arr[i]), arr[i]));
            } else if(i == oldSize - 1 && arr[i] == arr[i - 1]) {
                m.insert(pair<int, int> (ms.count(arr[i]), arr[i]));
            }
        }
        
        if (s.size() == oldSize) return oldSize/2;
        else if (s.size() == 1) return 1;
        
        multimap<int, int>::reverse_iterator iter;
        for (iter = m.rbegin(); iter != m.rend(); ++iter) {
            counter++;
            if(oldSize - (*iter).first > arr.size()/2) {
                oldSize = oldSize - (*iter).first;
            } else {
                return counter;                
            }
        }
        return 0;
    }
};