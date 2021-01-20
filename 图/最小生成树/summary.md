# 最小生成树

包括两种(正统)算法，均为离线算法:
- Prim: 基于点的添加，每次添加距离现有点集最近的邻接点
- Kruskal：基于边的添加，按权值从小到大遍历边，若不构成圈则添加

## Kruskal
判断添加边后是否构成圈使用并查集，最终结果也可以使用并查集表示  
算法模板：
1. 边排序
2. 遍历边，生成结果树
```C
struct edge{
    int i, j;
    int dist;
};
int cmp(struct edge *a, struct edge *b){
    return (a->dist) - (b->dist);
}
int combine(int *ufs, int a, int b){
    while(a != ufs[a]) a = ufs[a];
    while(b != ufs[b]) b = ufs[b];
    if(a == b) return 0;
    ufs[a] = b;
    return 1;
}
void kruskal(struct edge *struct edges, int edge_size, int point_size, int *result_ufs){
    int subset_size = point_size;
    int total_cost = 0;
    int i;

    // 初始化并查集
    result_ufs = (int*)malloc(point_size*sizeof(int));
    for(i=0;i<point_size;i++){
        result_ufs[i] = i;
    }
    // 排序
    qsort(edges,edge_size,sizeof(edges[0]),cmp);
    // 由小到大遍历边
    for(i=0;i<edge_size && subset_size>0;i++){
        if(1 == combine(result_ufs, edges[i].i, edges[i].j)){
            // 如果不构成圈
            total_cost += edges[i].dist;
            subset_size--;
        }
    }
    return total_cost;
}
```
## Prim
模板:
1. 任选一个点，通常是0号点
2. 计算其余每个点与该点的距离，使用min_dist记录
3. 从min_dist中找到距离最小且非0的点，将这个点距离置为0
4. 更新min_dist
5. 若有n个点，则反复3、4步n-1次
例题：https://leetcode-cn.com/problems/min-cost-to-connect-all-points/description/
```C

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
            }
        }
    }
    return total_cost;
}
```