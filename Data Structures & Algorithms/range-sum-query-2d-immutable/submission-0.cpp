// class NumMatrix {
// public:

//     vector<vector<int>> data;
//     NumMatrix(vector<vector<int>>& matrix) {
//         data = matrix;
//     }
    
//     int sumRegion(int row1, int col1, int row2, int col2) {
        
//         int total = 0;
//         for (int i = row1; i  v<= row2; i++) {
//             for (int j = col1; j <= col2; j++) {
//                 total += data[i][j];
//             }
//         }
//         return total;
//     }
// };

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

class NumMatrix {
public:

    vector<vector<int>> sumMat;

    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        sumMat = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int r = 0; r < rows; r++) {
            int rowSum = 0;
            for (int c = 0; c < cols; c++) {
                rowSum += matrix[r][c];
                int above = sumMat[r][c + 1];
                sumMat[r + 1][c + 1] = rowSum + above;
            }
        }

    }
        
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int r1 = row1 + 1, c1 = col1 + 1, r2 = row2 + 1, c2 = col2 + 1;

        int bottomRight = sumMat[r2][c2];
        int above = sumMat[r1 - 1][c2];
        int left = sumMat[r2][c1 - 1];
        int topLeft = sumMat[r1-1][c1-1];
    
        return bottomRight - above - left + topLeft;
    }
};