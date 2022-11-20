// Algorithm.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CTest.h"
#include "MTSort.h"
#define MAXVAL 10000
#define TESTSCALE 100
int main()
{
    CTest testObj;
   /* cout << "问题规模为：" << TESTSCALE << "; 随机数最大值为："<< MAXVAL << endl;
    testObj.testSelectSort(TESTSCALE, MAXVAL);
    testObj.testMergeSort(TESTSCALE, MAXVAL);
    testObj.testQuickSort(TESTSCALE, MAXVAL);
    testObj.testShellSort(TESTSCALE, MAXVAL);
    testObj.testRadixSort(TESTSCALE, MAXVAL);*/
   


    //大数排序部分
    /*cout << "大数排序-问题规模为：" << TESTSCALE << "; 随机位数最大值为：" << 99 << endl;
    testObj.testSelectSort_BigInt(TESTSCALE);
    testObj.testMergeSort_BigInt(TESTSCALE);
    testObj.testQuickSort_BigInt(TESTSCALE);
    testObj.testShellSort_BigInt(TESTSCALE);
    testObj.testRadixSort_BigInt(TESTSCALE);*/

    //多线程排序
    //MTSort(1, 1e7);
    cout << "多线程排序-问题规模为：" << 2e7 << endl;
    for (int i = 1;i < 25;i += 1)
    {
        MTSort(i, 2e7);
    }

    char ch = getchar();
    //std::cout << "Hello World!\n";
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
