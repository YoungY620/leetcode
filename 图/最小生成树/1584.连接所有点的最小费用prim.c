/*
 * @lc app=leetcode.cn id=1584 lang=c
 *
 * [1584] 连接所有点的最小费用
 * 
 */

// @lc code=start
#define MIN(A,B) (A<B?A:B)

int dist(int **ps, int a, int b){
    return (ps[a][0]>ps[b][0]?1:-1)*(ps[a][0]-ps[b][0])+\
            (ps[a][1]>ps[b][1]?1:-1)*(ps[a][1]-ps[b][1]);
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    int min_dist[pointsSize];
    int total_cost = 0;
    int i;

    for(i=0;i<pointsSize;i++){
        min_dist[i] = dist(points,0,i);
    }
    for(i=0;i<pointsSize-1;i++){
        int nearest = -1;
        int j;
        for(j=0;j<pointsSize;j++){
            if(min_dist[j]!=0 && nearest == -1){
                nearest = j;
            }else if(min_dist[j]!=0 &&\
                    min_dist[j]<min_dist[nearest]){
                nearest = j;
            }
        }
        if(nearest != -1){
            total_cost += min_dist[nearest];
            min_dist[nearest] = 0;
            
            int j;
            for(j=0;j<pointsSize;j++){
                if(min_dist[j] != 0){
                    min_dist[j] = MIN(min_dist[j], dist(points,nearest,j));
                }
                // printf("%d ",min_dist[j]);
            }
            // printf("\n");
        }else {
            printf("error\n");
        }
    }
    return total_cost;
}
// @lc code=end

