# T1
- **签到题**

如果不考虑替换的操作仅仅报数，那么就是输入 $n$ 输出 $n$.  
那如果加上这些奇怪的操作那输出就会比不加少。  
也就是 `Buzz` , `Fizz` , `BuzzFizz` 占用了本来的数字，导致后面的数字整体后延，最终变少。  
那么我们如果知道 $1$ 到 $n$ 中有多少个 `Buzz` , `Fizz` , `BuzzFizz`，就能够得出最终答案 $ans=n-num$ ，其中 $num$ 为`Buzz` , `Fizz` , `BuzzFizz`的数量和。  
`Buzz` 数量($Sum_{Buzz}$)：$\frac{n}{3}$ 下取整  
`Fizz` 数量($Sum_{Fizz}$)：$\frac{n}{5}$ 下取整  
`BuzzFizz` 数量($Sum_{Fizz}$)：$\frac{n}{15}$ 下取整    
**考虑到有重复计算的部分**：  
`Buzz` , `Fizz` , `BuzzFizz`的数量和：$Sum_{Buzz}+Sum_{Fizz}-Sum_{BuzzFizz}$

# T2
- 二分?T
