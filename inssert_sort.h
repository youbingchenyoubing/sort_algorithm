/*直接插入排序的实现方法*/
/*将一个记录插入到已排序好的有序表中，从而得到一个新序列，
记录数增1的有序表，即：先将序列第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直到整个序列有序为止*/
#ifndef SORT_H
#define SORT_H
# include <iostream>
using namespace std;
class insertSort
{
    public: 
  insertSort(int data[],int dataSize):length(dataSize){
         
         this->data = new int[dataSize];
    	for(int i = 0;i< dataSize;++i)
    	{
           this->data[i] = data [i];
    	} 
    }
  ~insertSort(){

  	if(data)
  	{
  		delete [] data;
  	}
  	data = nullptr;
  }

   void  sort(){
       
      int temp; //充当哨兵，这里没有采用课本中的data[0],为哨兵
      for(int i=1;i< length;++i)  // 为什么是从1开始，先看基本思想，遍历每一个位置
      {
           temp = data[i];
           int j = i-1;
           for(;j>=0;--j) //对于每个i位置，都去找出插入的位置 ,--j这里很容易写错
           {
               if(data[j]>temp) //前面的数比当前的数要大，往后移动
               {
                    data[j+1] = data [j];
               } 
               else break;   //找到要插入的具体位置
           }// end   for(;j>=0;--j)
          data[j+1] = temp;
      }//end for(int i=1;i< length;++i)
   }// end void sort()
   void test()
   {
   	  cout<<"输入排序后的数组"<<endl;
   	  for(int i = 0;i<length;++i)
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