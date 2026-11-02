class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> frequencyS;
        unordered_map<char, int> frequencyT;

        for (char c : s) {
            frequencyS[c]++;
        }

        for (char c : t) {
            frequencyT[c]++;
        }

        return frequencyS == frequencyT;
        
    }
};
