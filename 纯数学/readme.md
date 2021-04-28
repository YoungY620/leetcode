# 纯数学

[toc]

## 费马平方和定理

- 一个非负整数 $c$ 如果能够表示为两个整数的平方和，当且仅当 $c$ 的所有形如 $4k + 3$ 的质因子的幂均为偶数。
- 费马:

  >我确实发现了一个美妙的证明，但这里空白太小写不下。
- 代码: [原型题](https://leetcode-cn.com/problems/sum-of-square-numbers/)

    ```java
    public class Solution {
        public boolean judgeSquareSum(int c) {
            for (int i = 2; i * i <= c; i++) {
                int cnt = 0;
                while (c % i == 0) {
                    cnt++;
                    c /= i;
                }
                if (i % 4 == 3 && cnt % 2 != 0) return false;
            }
            return c % 4 != 3;
        }
    }
    // 作者：AC_OIer
    // 链接：https://leetcode-cn.com/problems/sum-of-square-numbers/solution/gong-shui-san-xie-yi-ti-san-jie-mei-ju-s-7qi5/
    ```
## 质因数分解

