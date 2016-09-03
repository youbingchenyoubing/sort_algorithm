#ifndef SELECT_SORH_H
#define SELECT_SORH_H
class selectSort
{
public:
    selectSort( int  data[], int dataSize ): length( dataSize )
    {
        this->data = new int[dataSize];
        for ( int  i = 0; i < length; ++i )
        {
            this->data[i] = data[i];
        }

    }
    ~selectSort()
    {

        if ( data )
        {
            delete [] data;
            data = nullptr;
        }
    }
    /*最普通的方法*/
    void sort()
    {
        for ( int i = 0; i < length; ++i )
        {
            int min = i;
            for ( int j = i + 1; j < length; ++j )
            {
                if ( data[j] < data[min] )
                {
                    min = j;
                }
            } // end for(int j=i+1;j<length;++j)

            if ( min != i )
            {
                int temp = data[i];
                data[i] = data[min];
                data[min] = temp;
            }
        }//end for ( int i=0;i<length;++i)
    }
    /*简单选择排序的改进——二元选择排序,*/
    void sort2()
    {
        for ( int i = 0; i <= length / 2; ++i )
        {
            int max = i;
            int min = i;

            for ( int j = i + 1; j < length - i; ++j )
            {
                if ( data[j] < data[min] )
                {
                    min = j;
                    continue;
                }
                if ( data[j] > data[max] )
                {
                    max = j;
                }
            }
            if ( min != i )
            {
                int temp =  data[i];
                data[i] =  data[min];
                data[min]  = temp;
            }
            if ( max != ( length - i - 1 ) )
            {
                int  temp = data[length - i - 1];
                data[length - i - 1]  = data[max];
                data[max] =  temp;
            }
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
};
#endif