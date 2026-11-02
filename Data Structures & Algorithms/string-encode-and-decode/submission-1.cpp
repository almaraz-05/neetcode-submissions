class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (string word: strs) {
            int length = word.size();

            result += to_string(length) + "#" + word;
        }
        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            
            while (s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i)); // length = 11

            string word = s.substr(j + 1, length);

            result.push_back(word);

            i = j + 1 + length;

        }
        return result;
    }
};


/*

    strs = ["Hello", "World"]

    result = 5#hello5#hello
    
    1 1 # h e l l o 5 # h  e  l  l   o
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    i
        j
*/
