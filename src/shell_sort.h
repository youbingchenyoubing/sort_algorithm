#ifndef SHELLSORT_H
#define SHELLSORT_H
# include <iostream>

using namespace std;

/*希尔排序*/
class shellSort
{
public:
    shellSort( int data[], int dataSize ): length( dataSize )
    {
        this->data = new int[dataSize];
        for ( int i = 0; i < dataSize; ++i )
        {
            this->data[i] = data[i];
        }

    }
    ~shellSort()
    {
        if ( data )
        {
            delete []  data;
            data = nullptr;
        }
    }
    void sort()
    {
        int dk = length / 2; //这里的增量可以自定义，我这里采用的是dk = n/2开始
        while ( dk >= 1 )
        {
            shellInsertSort( dk );
            dk = dk >> 1;
        }
    }
    void test()
    {
        for ( int i = 0; i < length; ++i )
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
private:
    int* data;
    int length;
    void shellInsertSort( int dk )
    {
        int temp;  //根插入排序一样也是哨兵
        for ( int i = dk; i < length; ++i )
        {
            int j = i - dk;

            temp = data[i];
            for ( ; j >= 0; j = j - dk )
            {
                if ( data[j] > temp )
                {
                    data[j + dk] = data[j];
                }
                else
                {
                    break;
                }
            } //end for
            data[j + dk] = temp;
        }// for(int i = dk;i < length;++i)
    }// end void shellInsertSort()
};

#endif