# AlgorithmJob
Algorithm course job
> 任务要求：
  实现【排序算法：选择排序，归并排序，快速排序，希尔排序，基数排序】，对所有算法进行分析并实现,分析其在不同规模的输入下单机性能变化情况；
  同时实现对于以下两种输入的排序:
> 1. 对数值的范围在$[-10^{100},10^{100}]$ 的数组排序，此项任务只能使用C或C++完成。
> 2. 利用多线程实现大规模数据的分布式排序，输入超过100万为最低大规模要求。


# 开发环境
1. C++
2. Visual Studio 2017(V141)
3. Windows SDK 10.0.19041.0

# 计时类
# CpuTimer 实现计时功能，1.排序之前记录当前系统时间戳；2.排序完成后查询当前系统时间；3.前后时间差就是排序耗时
	CpuTimer cpuTime;
	cpuTime.Reset();
	CUtilSort::selectSortBigInt(iArray, n);
	cpuTime.Tick();
	totalTime = cpuTime.TotalTime();

# 大整数实现
## 数据结构

```C++
struct BigInt //定义大整数
{
	int Length;               //去除符号后的数字长度
	int Sign;		  //整数符号位,1为正数，-1为负数
	string Value;             //使用string保存数字部分
}
```

# 多线程排序
对输入数组分段后，使用多个线程对每段数组进行快排，然后将排序结果合并。
## 对比结果

| 线程数 | 输入规模：10^6 | 输入规模：10^7 | 输入规模：10^8 |
| --- | --- | --- | --- |
| 10(mutex) | 0.1236s | 1.41s | 26.45s |
| 25(mutex) | 0.1425s | 1.53s | 19.45s |
| 50(mutex) | 0.1802s | 1.87s | 20.19s |
| 100(mutex) | 0.2534s | 2.57s | 26.42s |
| 200(mutex) | 0.3845s | 3.89s | 39.70s |
| 10(no-mutex) | 0.0613s | 0.5403s | 7.979s |
| 25(no-mutex) | 0.1085s | 0.8002s | 8.454s |
| 50(no-mutex) | 0.1577s | 1.28s | 12.54s |
| 希尔排序 | 0.3652s | 5.42s | 78.34s |
| 快速排序 | 0.1185s | 2.31s | StackOverflow |
| 归并排序 | 0.3658s | 3.78s | StackOverflow |

* 当线程数过多时，线程的创建开销也会增大。要选择合适的线程数目。实验中发现线程数在10~15较为合适。
* 在多线程中采用互斥锁mutex会导致线程之间互相等待，增加算法耗时。由于多线程排序中每个线程的输入数组段是不同的，所以无需使用线程锁。
* 实验中，单个线程所能承载的最大数组规模为5e7，所以数组规模大于5e7后，所需的最少线程数为： $\lceil \frac{thread\ num}{5\cdot 10^7} \rceil$

## 线程数与算法耗时
当数据规模在1e6-1e7之间时：

![f9aebd96d978d54e19d66c4a4aeb733](https://user-images.githubusercontent.com/27942089/202899657-a737848a-2c91-42f8-bf73-42c2c9ae2e83.png)

当数据规模在1e7-1e8之间时：

![90c664fb7df1b1d96670b324e1c1c7e](https://user-images.githubusercontent.com/27942089/202899664-d8115f4a-3879-436f-992c-d93a2dbfbb07.png)

当数据规模在1e8-1e9之间时：

![3428e5d4183c07c234f37ca2eb434a8](https://user-images.githubusercontent.com/27942089/202899710-5fc8eb38-421b-4ecb-82d5-51e730e8af42.png)

通过计算时间消耗与线程数的导数，发现曲线最低点对应的大致线程数。当导数由负变为正时，意味着合适的线程数在当前点和前一点之间。

$$\frac{\partial thread}{\partial time}=\frac{time[i]-time[i-1]}{thread[i]-thread[i-1]}$$
当线程数过多时，线程的创建开销也会增大。要选择合适的线程数目。

# 实验结果
### 问题规模为：100; 随机数最大值为：10000
selectSort: Array size 100,sort time: 0.0000069
mergeSort:  Array size 100,sort time: 0.0000113
quickSort:  Array size 100,sort time: 0.0000032
shellSort:  Array size 100,sort time: 0.0000038
radixSort:  Array size 100,sort time: 0.0000029

### 问题规模为：1000; 随机数最大值为：10000
selectSort: Array size 1000,sort time: 0.0002051
mergeSort:  Array size 1000,sort time: 0.0001571
quickSort:  Array size 1000,sort time: 0.0000388
shellSort:  Array size 1000,sort time: 0.0000570
radixSort:  Array size 1000,sort time: 0.0000171

### 问题规模为：10000; 随机数最大值为：10000
selectSort: Array size 10000,sort time: 0.0167672
mergeSort:  Array size 10000,sort time: 0.0019541
quickSort:  Array size 10000,sort time: 0.0005846
shellSort:  Array size 10000,sort time: 0.0011863
radixSort:  Array size 10000,sort time: 0.0001930

### 问题规模为：100000; 随机数最大值为：1000000
selectSort: Array size 100000,sort time: 1.1665713
mergeSort:  Array size 100000,sort time: 0.0142607
quickSort:  Array size 100000,sort time: 0.0049592
shellSort:  Array size 100000,sort time: 0.0114264
radixSort:  Array size 100000,sort time: 0.0021082

### 问题规模为：1000000; 随机数最大值为：1000000
selectSort: Array size 1000000,sort time: 116.3093948
mergeSort:  Array size 1000000,sort time: 0.1504840
quickSort:  Array size 1000000,sort time: 0.0540525
shellSort:  Array size 1000000,sort time: 0.1452536
radixSort:  Array size 1000000,sort time: 0.0224416


### 大数排序-问题规模为：100; 随机位数最大值为：99
selectSort-big: Array size 100,sort time: 0.0004835
mergeSort-big:  Array size 100,sort time: 0.0001584
quickSort-big:  Array size 100,sort time: 0.0000927
shellSort-big:  Array size 100,sort time: 0.0001009
radixSort-big:  Array size 100,sort time: 0.0008760


### 大数排序-问题规模为：1000; 随机位数最大值为：99
selectSort-big: Array size 1000,sort time: 0.0382777
mergeSort-big:  Array size 1000,sort time: 0.0020863
quickSort-big:  Array size 1000,sort time: 0.0012881
shellSort-big:  Array size 1000,sort time: 0.0015923
radixSort-big:  Array size 1000,sort time: 0.0129399

### 大数排序-问题规模为：10000; 随机位数最大值为：99
selectSort-big: Array size 10000,sort time: 3.6881633
mergeSort-big:  Array size 10000,sort time: 0.0255843
quickSort-big:  Array size 10000,sort time: 0.0156570
shellSort-big:  Array size 10000,sort time: 0.0251719
radixSort-big:  Array size 10000,sort time: 0.0865394


### 大数排序-问题规模为：100000; 随机位数最大值为：99
selectSort-big: Array size 100000,sort time: 434.3882141
mergeSort-big:  Array size 100000,sort time: 0.4774311
quickSort-big:  Array size 100000,sort time: 0.3903215
shellSort-big:  Array size 100000,sort time: 0.8636416
radixSort-big:  Array size 100000,sort time: 2.4699812

