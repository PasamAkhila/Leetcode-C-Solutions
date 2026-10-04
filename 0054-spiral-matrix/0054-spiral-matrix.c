/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int top = 0 , bottom = matrixSize - 1, left = 0 , right = matrixColSize[0] - 1;
    
    int *ans = (int*)malloc(matrixSize * matrixColSize[0] * sizeof(int));
    *returnSize = matrixSize * matrixColSize[0];
    
    int index = 0;
    while(top <= bottom && left <= right)
    {
        for ( int i = left ; i <= right ; i++ )
            ans[index++] = matrix[top][i];
        top++;

        for(int j = top ; j <= bottom ; j++ )
            ans[index++] = matrix[j][right];
        right--;

        if(top <= bottom)
        {
            for(int k = right ; k >= left ; k-- )
                ans[index++] = matrix[bottom][k];
            bottom--;
        }

        if(left <= right)
        {
            for(int l = bottom ; l >= top ; l--)
                ans[index++] = matrix[l][left];
            left++;
        }
    }
    return ans;

}
