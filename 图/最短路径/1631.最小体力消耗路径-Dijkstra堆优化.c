/*
 * @lc app=leetcode.cn id=1631 lang=c
 *
 * [1631] 最小体力消耗路径
 *
 * https://leetcode-cn.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (35.55%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    18K
 * Total Submissions: 36.6K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights ，其中 heights[row][col] 表示格子
 * (row, col) 的高度。一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) （注意下标从
 * 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动，你想要找到耗费 体力 最小的一条路径。
 * 
 * 一条路径耗费的 体力值 是路径上相邻格子之间 高度差绝对值 的 最大值 决定的。
 * 
 * 请你返回从左上角走到右下角的最小 体力消耗值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：heights = [[1,2,2],[3,8,2],[5,3,5]]
 * 输出：2
 * 解释：路径 [1,3,5,3,5] 连续格子的差值绝对值最大为 2 。
 * 这条路径比路径 [1,2,2,2,5] 更优，因为另一条路径差值最大值为 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：heights = [[1,2,3],[3,8,4],[5,3,5]]
 * 输出：1
 * 解释：路径 [1,2,3,4,5] 的相邻格子差值绝对值最大为 1 ，比路径 [1,3,5,3,5] 更优。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * 输出：0
 * 解释：上图所示路径不需要消耗任何体力。
 * 
 * 
 * 提示：
 * 
 * 
 * rows == heights.length
 * columns == heights[i].length
 * 1 
 * 1 
 * 
 */

// @lc code=start

#define ABS(B) (B>0?B:(-1*B))
#define MAX(A,B) (A>B?A:B)

void assign(int *x, int *y, int *v, int fx, int fy, int fv){
    if(x == NULL || y == NULL || v == NULL) return;
    (*x) = fx;
    (*y) = fy;
    (*v) = fv;
}
void push(int *xheap, int *yheap, int *vheap, int *hpptr, int x, int y, int v){
    (*hpptr)++;
    int i;
    for(i = (*hpptr);vheap[i/2]>v;i/=2){
        assign(&xheap[i], &yheap[i], &vheap[i], xheap[i/2], yheap[i/2], vheap[i/2]);
    }
    assign(&xheap[i], &yheap[i], &vheap[i], x, y, v);
}
void pop(int *xheap, int *yheap, int *vheap, int *hpptr, int *x, int *y, int *v){
    assign(x, y, v, xheap[1], yheap[1],vheap[1]);
    int tx = xheap[(*hpptr)], ty = yheap[(*hpptr)], tv = vheap[(*hpptr)];
    (*hpptr)--;
    int i;
    int r = 1;
    for(i=2;i<=(*hpptr);i*=2){
        if(i+1<=(*hpptr)&&vheap[i+1]<vheap[i]){
            i++;
        }
        if(vheap[i]<tv){
            assign(&xheap[r], &yheap[r], &vheap[r], xheap[i], yheap[i], vheap[i]);
            r = i;
        }else {
            break;
        }
    }
    assign(&xheap[r], &yheap[r], &vheap[r], tx, ty, tv);
}

int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize){
    if(heightsSize == 0 || heightsColSize[0] == 0){
        return 0;
    }
    int i;
    int dist[heightsSize][heightsColSize[0]];
    int xheap[heightsSize*heightsColSize[0]+1];
    int yheap[heightsSize*heightsColSize[0]+1];
    int vheap[heightsSize*heightsColSize[0]+1];
    int hpptr = 0;
    xheap[0] = -1;
    yheap[0] = -1;
    vheap[0] = -1;

    if(heightsSize == 1 && heightsColSize[0] == 1){
        return 0;
    }
    for(i=0;i<heightsSize;i++){
        int j;
        for(j=0;j<heightsColSize[0];j++){
            if(i == 0 && j == 0){
                dist[i][j] = -2;
            }else if(i + j == 1){
                int v = ABS((heights[0][0]-heights[i][j]));
                dist[i][j] = v;
                push(xheap, yheap, vheap, &hpptr, i, j, v);
            }else {
                dist[i][j] = -1;
            }
        }
    }
    int times = heightsSize*heightsColSize[0]-2;
    while(1){
        int x = -1,y = -1, v;
        pop(xheap, yheap, vheap, &hpptr, &x, &y, &v);

        if(dist[x][y] != v){
            continue;
        }
        if(x == heightsSize-1 && y == heightsColSize[0]-1){
            return v;
        }

        int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(i=0;i<4;i++){
            int xx = x+step[i][0],yy = y + step[i][1];
            if(xx>=0 && xx<heightsSize && yy>=0 && yy<heightsColSize[0]){
                int pass_dis = MAX(dist[x][y], ABS((heights[x][y]-heights[xx][yy])));
                if(dist[xx][yy] == -1 || dist[xx][yy]>pass_dis){
                    dist[xx][yy] = pass_dis;
                    push(xheap, yheap, vheap, &hpptr, xx, yy, pass_dis);
                }
            }
        }
        dist[x][y] = -2;
    }
}
// @lc code=end

