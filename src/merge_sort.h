#ifndef MERGER_H
#define MERGER_H
# include <iostream>
using namespace std;
class mergeSort
{
public:
    mergeSort( int data[], int dataSize ): length( dataSize )
    {

        this->data = new int[dataSize];
        this->copy = new int[dataSize];
        for ( int i = 0; i < dataSize; ++i )
        {
            this->data [i] = data[i];
        }

    }
    ~mergeSort()
    {
        if ( data )
        {
            delete [] data;
            data = NULL;
        }
        if ( copy )
        {
            delete [] copy;

            copy = nullptr;
        }
    }
    void sort()
    {
        mSort( 0, length - 1 );
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
    void mSort( int start, int end )
    {
        if ( start < end )
        {
            int mid = ( start + end ) / 2;
            mSort( start, mid );
            mSort( mid + 1, end );
            merge( start, mid, end );
        }
    }
    void merge( int start, int mid, int end )
    {
        int i = start;
        int j = mid + 1;
        int k = start;
        while ( i <= mid && j <= end )
        {
            if ( data[i] <= data[j] )
            {
                copy[k++] = data[i++];
            }
            else
            {
                copy[k++] = data[j++];
            }
        }

        while ( i <= mid )
        {
            copy[k++] = data[i++];
        }
        while ( j <= end )
        {
            copy[k++] = data[j++];
        }
        for ( int m = start; m <= end; ++m )
        {
            data[m] = copy[m];
        }
    }
    int* data;
    int* copy;
    int length;

};
#endif