# 插入排序
## 简单插入排序
模板:
1. 正向遍历元素
2. 取出该元素，反向便利寻找位置
3. 一边查找，一边向后错位
```C
int cmp(int **i, int **j){
    return (*i)[0]-(*j)[0];
}

void sort(int **intervals, int size){
    int i;
    for(i=1;i<size;i++){
        if(cmp(&intervals[i],&intervals[i-1])<0){
            int j;
            int *tmp = intervals[i];
            for(j=i;j>0 && cmp(&intervals[j-1], &tmp)>0;j--){
                intervals[j] = intervals[j-1];
            }
            intervals[j] = tmp;
        }
    }
}
```
