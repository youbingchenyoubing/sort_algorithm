
#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <iostream>
using namespace std;
class heapSort{

public:
	heapSort(int data[],int dataSize):length(dataSize)
	{
		this->data = new int[dataSize];
		for(int i=0;i< dataSize;++i)
			this->data[i] = data[i];
	}
	~heapSort()
	{
		if(data)
		{
			delete [] data;
			data = nullptr;
		}
	}
	void sort()
	{ 
		// 建立 大根堆
       bulidHeap();
       for(int i = length-1;i>=0;--i)
       {
       	    int temp = data[i];
       	    data[i] = data[0];
       	    data[0] = temp;

       	    heapAdjust(0,i);
       }
	}
	void test()
	{
		for(int i = 0;i<length;++i)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
private:
	void bulidHeap()
	{
		for(int i= (length-1)/2;i>=0;--i)
		{
               heapAdjust(i,length);
		}
	}
	void heapAdjust(int parent,int last)
	{
		int temp = data[parent];
		int child = 2*parent+1; //左孩子
		while(child<last) //不要越界
		{
		    if(child+1<last&&data[child+1]>data[child]) //判断是否有右孩子，并且右孩子的数值比左孩子大
		    {
		    	child++;
		    }
		    if(data[parent]<data[child])  //如果根节点小于当前的左右孩子节点最大的那一个，说明要交换
		    {
		    	data[parent] = data[child];
		    	parent = child;
                child = 2*parent+1;
		    }
		    else break;

		    data[parent] = temp;
		}
	}
	int *data;
	int  length;
};
#endif