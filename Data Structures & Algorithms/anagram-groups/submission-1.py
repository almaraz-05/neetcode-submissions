class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}

        for word in strs:
            key = word
            key = "".join(sorted(word))

            if key not in groups:
                groups[key] = []
                
            groups[key].append(word)

        result = []
        for words in groups.values():
            result.append(words)

        return result