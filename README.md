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
| 10 | 0.1236s | 1.41s | 26.45s |
| 25 | 0.1425s | 1.53s | 19.45s |
| 50 | 0.1802s | 1.87s | 20.19s |
| 100 | 0.2534s | 2.57s | 26.42s |
| 200 | 0.3845s | 3.89s | 39.70s |
| 希尔排序 | 0.3652s | 5.42s | 78.34s |
| 快速排序 | 0.1185s | 2.31s |  |
| 归并排序 | 0.3658s | 3.78s |  |

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

