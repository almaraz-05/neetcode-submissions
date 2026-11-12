class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for boxRow in range(0, 9, 3):
            for boxCol in range(0, 9, 3):
                seen = set()

                for row in range(3):
                    for col in range(3):
                        num = board[row + boxRow][col + boxCol]

                        if num == '.':
                            continue
                        
                        if num in seen:
                            return False
                        
                        for i in range(9):
                            rowSeen = set()
                            colSeen = set()

                            for j in range(9):
                                rowNum = board[i][j]
                                colNum = board[j][i]

                                if rowNum != '.':
                                    if rowNum in rowSeen:
                                        return False
                                    rowSeen.add(rowNum)

                                if colNum != '.':
                                    if colNum in colSeen:
                                        return False
                                    colSeen.add(colNum)

                        seen.add(num)
        return True
        