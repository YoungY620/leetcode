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
## 堆排序
关键在于维护 “堆” 这个数据结构

有两个关键的操作：
- 构建堆，即统一遍历调整(向下调整)
- 向下调整，在**构建**时和**顶出堆顶值**
- 向上调整，（可选）主要在添加新元素时。
 
**构建：**

当堆大小固定时（如寻找第k大值），只需堆满时利用“向下调整”调整一轮即可。
```C
/**
 * P.S. 堆顶索引为1
*/
void build_heap(int *vheap, int *iheap, int heapsize){
    int  i;
    for(i = heapsize/2;i>0;i--){
        adjustHead(vheap, iheap, heapsize, i);
    }
}
```

但在[力扣-1631](1631.最小体力消耗路径-堆优化最短路径.c)中，堆用于在Dijstra算法中维护一个距离表，如果每次加入新值都全局调整就开销太大了。

**向下调整（大顶堆）：**
```C
/**
 * nums: 堆数组
 * int: 堆大小
 * k: 要调整的子树顶索引
 */
void adjustHead(int *nums, int size, int k){
    int i;
    int tmp = nums[k];
    for(i = k*2+1; i<size; i=i*2+1){
        if(i+1<size && nums[i+1]>nums[i]){
            i++;
        }                       // i现在是k子节点中最大的
        if(tmp<nums[i]){
            nums[k] = nums[i];  // 将i的值上拉到k处
            k = i;              // k下移到i处
        }else break;            // 找到了k为放置tmp的位置
    }
    nums[k] = tmp;
}
```
**向上调整：**

from 例题[1631.堆优化的最短路径](1631.最小体力消耗路径-堆优化最短路径.c)
```C
/**
 * 插入值v，同时向上调整
 * 实质上是向上调整找到v的插入点
*/
void push(int *xheap, int *hpptr, int v){
    (*hpptr)++;
    int i;
                                // 父节点比当前节点大时，进入loop
    for(i = (*hpptr);vheap[i/2]>v;i/=2){
        xheap[i] = xheap[i/2];  // 将父节点的值拉取下来
    }
    xheap[i] = v;
}
```