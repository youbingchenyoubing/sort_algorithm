# include "inssert_sort.h"
# include "shell_sort.h"
# include "select_sort.h"
# include "heap_sort.h"
# include  "bubble_sort.h"
# include "merge_sort.h"
# include "quick_sort.h"
/**/

int main()
{

    int a[8] = {3, 1, 5, 7, 2, 4, 9, 6};
    cout << "运行直接插入排序算法" << endl;
    insertSort* test =  new insertSort( a, 8 );
    test->sort();
    test->test();
    delete test;
    test = nullptr;
    cout << "运行希尔排序算法" << endl;
    shellSort* test2 = new shellSort( a, 8 );
    test2->sort();
    test2->test();
    delete test2;
    test2  = nullptr;
    cout << "运行简单选择排序算法" << endl;
    selectSort* test3 = new selectSort( a, 8 );
    test3->sort();
    test3->test();
    delete test3;
    test3 = nullptr;
    cout << "运行基于二元选择-简单选择排序算法" << endl;
    selectSort* test4 = new selectSort( a, 8 );
    test4->sort2();
    test4->test();
    delete test4;
    test4 = nullptr;
    cout << "开始运行堆排序算法" << endl;
    heapSort* test5 = new heapSort( a, 8 );
    test5->sort();
    test5->test();
    delete  test5;
    test5 =  nullptr;
    cout << "开始运行冒泡排序算法" << endl;
    bubbleSort* test6 = new bubbleSort( a, 8 );
    test6->sort();
    test6->test();
    delete  test6;
    test6 = nullptr;
    cout << "开始运行改进冒泡排序算法1" << endl;
    bubbleSort* test7 = new bubbleSort( a, 8 );
    test7->sort2();
    test7->test();
    delete  test7;
    test7 = nullptr;
    cout << "开始运行改进冒泡排序算法2" << endl;
    bubbleSort* test8 = new bubbleSort( a, 8 );
    test8->sort3();
    test8->test();
    delete  test8;
    test8 = nullptr;
    cout << "开始运行归并排序算法" << endl;
    mergeSort* test9 = new mergeSort( a, 8 );
    test9->sort();
    test9->test();
    delete test9;
    test9 = nullptr;
    cout << "开始运行快速排序算法" << endl;
    quickSort* test10 = new quickSort( a, 8 );
    test10->sort();
    test10->test();
    delete test10;
    test10 = nullptr;
    return 0;
}


