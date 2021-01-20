/*
 * @lc app=leetcode.cn id=1584 lang=c
 *
 * [1584] 连接所有点的最小费用
 * 
 */

// @lc code=start

typedef struct{
    int i, j;
    int dist;
} edge;
void cpy(const edge *from, edge *to){
    to->dist = from->dist;
    to->i = from->i;
    to->j = from->j;
}
int cmp(edge *a, edge *b){
    return (a->dist) - (b->dist);
}

int dist(int **ps, int a, int b){
    return (ps[a][0]>ps[b][0]?1:-1)*(ps[a][0]-ps[b][0])+\
            (ps[a][1]>ps[b][1]?1:-1)*(ps[a][1]-ps[b][1]);
}

int combine(int *ufs, int a, int b){
    while(a != ufs[a]) a = ufs[a];
    while(b != ufs[b]) b = ufs[b];
    if(a == b) return 0;
    ufs[a] = b;
    return 1;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    edge *edges = (edge*)malloc(sizeof(edge)*pointsSize*(pointsSize-1)/2);
    int i;
    int edge_size = 0;
    int ufs[pointsSize];
    int subset_size = pointsSize;
    int total_cost = 0;

    for(i=0;i<pointsSize;i++){
        int j;
        for(j=i+1;j<pointsSize;j++){
            edges[edge_size].dist = dist(points, i,j);
            edges[edge_size].i = i;
            edges[edge_size].j = j;
            edge_size++;
        }
    }
    // for(i=0;i<edge_size;i++){
    //     printf("%d ",edges[i].dist);
    // }
    // printf("\n");
    qsort(edges,edge_size,sizeof(edges[0]),cmp);
    // for(i=0;i<edge_size;i++){
    //     printf("%d ",edges[i].dist);
    // }
    // printf("\n");
    for(i=0;i<pointsSize;i++){
        ufs[i] = i;
    }
    for(i=0;i<edge_size && subset_size>0;i++){
        if(1 == combine(ufs, edges[i].i, edges[i].j)){
            total_cost += edges[i].dist;
            subset_size--;
            
            // int j;
            // for(j=0;j<pointsSize;j++){
            //     printf("[%d]=%d ", j, ufs[j]);
            // }
            // printf("\n");
        }
    }
    return total_cost;
}
// @lc code=end

