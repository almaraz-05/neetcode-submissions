class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                unordered_set<char> seen;

                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        char num = board[row + boxRow][col + boxCol];

                        if (num == '.') {
                            continue;
                        }

                        if (seen.find(num) != seen.end()) {
                            return false;
                        }
                        for (int i = 0; i < 9; i++) {
                            unordered_set<char> rowSeen;
                            unordered_set<char> colSeen;

                            for (int j = 0; j < 9; j++) {
                                char rowNum = board[i][j];
                                char colNum = board[j][i];

                                if (rowNum != '.') {
                                    if (rowSeen.find(rowNum) != rowSeen.end()) {
                                        return false;
                                    }
                                    rowSeen.insert(rowNum);
                                }

                                if (colNum != '.') {
                                    if (colSeen.find(colNum) != colSeen.end()) {
                                        return false;
                                    }
                                    colSeen.insert(colNum);
                                }

                            }
                        }

                        seen.insert(num);
                    }
                }
            }
        }
        return true;
    }
};
