// 桶排序

#include <stdio.h>
#include <string.h>


#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

void BucketSort(int *pData, int size){
    vector<int>Bucket[11];
    //memset(Bucket,0,sizeof(0));
    int i,j,k,pos,key;
    for(i=0; i<size; ++i){ // 将每个元素插入到相应的桶中
	key=pData[i];
	pos = key/10;  // 求出该元素在哪个桶
	j=Bucket[pos].size()-1;
	Bucket[pos].push_back(key);  // 把该元素放入某个桶中
	while(j>=0 && Bucket[pos][j]>key){ // 用插入排序在某个桶里排序
	    swap(Bucket[pos][j],Bucket[pos][j+1]);
	    --j;
	}
    }
    k=0;
    for(i=0; i<11; ++i){
	for(j=0; j<Bucket[i].size(); ++j)
	    pData[k++] = Bucket[i][j];
    }
}

int main()
{
    int arr[]={3,5,45,34,2,78,0,67,34,56,98};
    BucketSort(arr,10);
    for(int i=0; i<10; ++i)
	printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
