int** transpose(int** matrix, int matrixSize, int* matrixColSize, 
                int* returnSize, int** returnColumnSizes) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];

    // Transposed matrix will have cols rows
    *returnSize = cols;

    // Allocate column sizes array
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    for(int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;
    }

    // Allocate memory for result matrix
    int** result = (int**)malloc(cols * sizeof(int*));
    for(int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
    }

    // Fill transpose
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}
