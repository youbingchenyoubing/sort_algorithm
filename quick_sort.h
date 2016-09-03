#ifndef QUICK_SORT_H
#define QUICK_SORT_H
# include <iostream>
# include <ctime>

using namespace std;
class quickSort
{
public:
	quickSort(int data[],int dataSize):length(dataSize)
	{
		 this->data = new int[dataSize];
		 for(int i = 0;i<length;++i)
		 {
		 	this->data[i] = data[i];
		 }
	}
	~quickSort()
	{
		if(data)
		{
			delete [] data;
			data = nullptr;
		}
	}
	void sort()
	{
		srand(unsigned(time(0)));
        quick_sort(0,length-1);
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
	void quick_sort(int begin,int end)
	{
		if(begin<end)
		{
			int priv = partion(begin,end);
			quick_sort(begin,priv-1);
			quick_sort(priv+1,end);
		}

	}
	int partion(int begin,int end)
	{
      int index = (rand()%(end-begin))+begin;

      int temp = data[begin];

      data[begin] = data[index];

      data[index] = temp;

      temp = data[begin];
      while(begin<end){

      	while(begin<end&&data[end]>=temp) --end;
      	data[begin] = data[end];
        while(begin<end&&data[begin]<=temp) ++begin;
        data[end] = data[begin];
      }
      data[begin] = temp;

      return begin;
	}

};
#endif