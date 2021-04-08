# 二分算法

## 概述 + 模板

比较简单

两个关键:
- **比较条件**, 获取区间判定条件 (中点是在 `target` 的左侧还是右侧?)
  - 能否用二分法就看有无一致的判定条件, 例如无序数组一定无法用二分来搜索
- **区间更新** (`right=mid` 还是 `right=mid+1` 这类)
  - **是易错点 !** 
  - 区间更新的关键为 `right` 和 `left` 的极限, 即能否取到 `mid`
  - 两种**区间更新方式**对应两种**比较条件**: 判定上界 / 判定下界:
    - **判定上界**: `target` 包含在上半区间, 中点为 `target` 下确界

        ```java
        while(left<right>){
            int mid = (left+right+1)>>1; // 向上取整, 避免死循环!!
            if (nums[mid]<=target){
                left = mid;     
            }else{
                right = mid - 1;
                // target 此时一定在 n[mid] 左侧了
            }
        }
        return left;
        ```
    - **判定下界**: `target` 包含在下半区间, 中点为 `target` 的上确界:

        ```java
        while(left<right){
            int mid = (left+right)>>1;
            if (nums[mid]>=target){
                right = mid;     
            }else{
                left = mid + 1;
                // target 此时一定在 n[mid] 右侧了
            }
        }
        return left;
        ```

## 例题

1. [**81.搜索旋转数组ii**](81.搜索旋转排序数组-ii.java)

    这道题是在[33.搜索旋转数组](33.搜索旋转排序数组.java)引申而来的

    不同在于, 81 题中存在重复数组, 这使得原来的区间判定条件可能失效. 例如输入:

    ```text
    [1,0,0,1,1,1]
    0
    ```

    `nums[0]` 和 `nums[n-1]` 相等, 无法判断 `nums[mid]` 是在旋转点的左侧还是右侧. 因此在程序一开始首先排除两侧相等的情况:

    ```java
    while (right > left 
    && nums[left] == nums[right]) {
        right--;
    }
    while (left < right) {
        int mid = (right + left + 1) >> 1;
        if (nums[mid] >= nums[0]) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    ```

    **这道题的经验**: 思路顺序:
    - 首先检查判定条件, 如果可能失效, 只从判定条件本身出发进行排除

        ```java
        // 一开始的错误代码
        while (left < right) {
            while (right > left && nums[left] == nums[right]) {
                // 这里没有意义. 判断条件只与nums[0]有关
                right--;
            }
            int mid = (right + left + 1) >> 1;
            if (nums[mid] >= nums[0]) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        ```