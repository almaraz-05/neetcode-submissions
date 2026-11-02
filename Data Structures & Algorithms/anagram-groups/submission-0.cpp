class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string word: strs) {
            string key = word;             // tops
            sort(key.begin(), key.end());  // opst

            groups[key].push_back(word);
        }

        vector<vector<string>> result; // {{},{},{}}

        for (auto it = groups.begin(); it != groups.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};


/* groups = {
    {"opst", {"tops", "pots", "stop"}},
    {"act", {"act", "cat"}},
    {"hat", {"hat"}}
}

*/





// stop -> opst
// pots -> opst   key: opst   value: {stop, pots, tops}
// tops -> opst

// act -> act
// cat -> act     key: act    value: {act, cat}

// hat -> aht     key: hat    value: {aht}


