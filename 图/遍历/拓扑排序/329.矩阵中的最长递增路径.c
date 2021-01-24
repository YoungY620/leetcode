/*
 * @lc app=leetcode.cn id=329 lang=c
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (46.33%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    40K
 * Total Submissions: 86.4K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 * 
 * 示例 1:
 * 
 * 输入: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2:
 * 
 * 输入: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 */

// @lc code=start
#define IN(x,y) (x>=0 && y>=0 && x<matrixSize && y<matrixColSize[0])

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize==0 || matrixColSize[0]==0) return 0;
    
    int in_degrees[matrixSize][matrixColSize[0]];
    int i;
    int stack[matrixSize*matrixColSize[0]][2];
    int stk_ptr = 0;
    int max_len = 0;
    int steps[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};


    for(i=0;i<matrixSize;i++){
        int j;
        for(j=0;j<matrixColSize[0];j++){
            int q;
            in_degrees[i][j]=0;
            for(q=0;q<4;q++){
                in_degrees[i][j] += IN(i+steps[q][0],j+steps[q][1]) \
                    && matrix[i+steps[q][0]][j+steps[q][1]]<matrix[i][j];
            }
        }
    }
    while(1){
        stk_ptr = 0;
        for(i=0;i<matrixSize;i++){
            int j;
            for(j=0;j<matrixColSize[0];j++){
                if(in_degrees[i][j] == 0){
                    stack[stk_ptr][0] = i;
                    stack[stk_ptr++][1] = j;
                }
            }
        }
        if(stk_ptr == 0) break;
        int j;
        for(j=0;j<stk_ptr;j++){
            in_degrees[stack[j][0]][stack[j][1]] = -1;
            int q;
            for(q=0;q<4;q++){
                int stpx=stack[j][0]+steps[q][0], stpy=stack[j][1]+steps[q][1];
                if(IN(stpx, stpy) && in_degrees[stpx][stpy] > 0 
                && matrix[stpx][stpy]>matrix[stack[j][0]][stack[j][1]]){
                    in_degrees[stpx][stpy]--;
                }
            }
        }
        max_len++;
        for(j=0;j<stk_ptr;j++){
            printf("%d-%d ", stack[j][0], stack[j][1]);
        }
        printf("%d\n", max_len);
    }
    return max_len;
}
// @lc code=end

