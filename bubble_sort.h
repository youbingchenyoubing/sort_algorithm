#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
# include <iostream>
using namespace std;
class bubbleSort
{
    public:
    	bubbleSort(int  data[],int dataSize):length(dataSize)
    	{
                this->data = new int[dataSize];

                for(int i=0;i<dataSize;++i)
                {
                	this->data[i] = data[i];
                }
    	}
    	~bubbleSort()
    	{
    		if(data)
    		{
    			delete [] data;
    			data = nullptr;
    		}
    	}
    	void sort()
    	{
           int flag = true;
           for(int i =0;i<length&&flag;++i)
           {
           	    flag = false;
           	    for(int j=0;j<length-i-1;j++)
           	    {
           	    	if(data[j]>data[j+1])
           	    		{
           	    			int temp = data[j];
           	    			data[j] = data[j+1];
           	    			data[j+1] =  temp;
           	    			flag =true;
           	    		}
           	    }
           }
    	}
    	/*改进冒泡算法1*/
    	void sort2()
    	{
            int i = length-1;

            while(i>0)
            {
            	int pos = 0;
            	for(int j = 0;j<i;++j)
            	{
            		if(data[j]>data[j+1])
            		{
                        pos = j;
                        int temp = data[j];
                        data[j] = data[j+1];
                        data[j+1] = temp;

            		}
            	}
            	i = pos;
            }
    	}
    	void sort3()
    	{
    		int low = 0;
    		int high = length -1;
    		while(low<high)
    		{
    			for(int i = low;i<high;++i)
    			{
    				if(data[i]>data[i+1])
    				{
    					int temp = data[i];
    					data[i] = data[i+1];
    					data[i+1] = temp;
    				}

    			}
    			--high;
    			for(int j=high;j>low;--j)
    			{
    				if(data[j]<data[j-1])
    				{
    					int temp = data[j];
    					data[j] = data[j-1];
    					data[j-1] = temp;
    				}
    			}
    			++low;
    		}
    	}
    	void test()
    	{
    		for(int i=0;i<length;++i)
    		{
    			cout<<data[i]<<" ";
    		}
    		cout<<endl;
    	}
    private:
    	int *data;
    	int length;
};
#endif