#include <cstdio>
#include <cstdlib>
 
 
// 这个是基数排序用到的计数排序，是稳定的。
// pDigit是基数数组,nMax是基数的上限，pData是待排序的数组， nLen是待排序数组的元素个数
// 必须pDigit和pData的下标相对应的，即pDigit[1]对应pData[1]
int RadixCountingSort(int *pDigit, int nMax,int *pData,int nLen){
 
    // 以下是计数排序
    int *pCount = new int[nMax];
    int *pSorted = new int[nLen];
 
    int i,j;
    for(i=0; i<nMax; ++i)
        pCount[i] = 0;
 
    for(i=0; i<nLen; ++i)
        ++pCount[pDigit[i]];
 
    for(i=1; i<nMax; ++i)
        pCount[i] += pCount[i-1];
 
    for(i=nLen-1; i>=0; --i){
        --pCount[pDigit[i]];
        pSorted[pCount[pDigit[i]]] = pData[i];  // z这里注意，是把待排序的数组赋值
    }
 
    for(i=0; i<nLen; ++i)
        pData[i] = pSorted[i]; 
 
    delete [] pCount;
    delete [] pSorted;
    return 1;
}
 
int RadixSort(int *pData, int nLen){
 
    int *pDigit = new int[nLen]; // 申请存放基数(某个位数)的空间
 
    int nRadixBase = 1;  
    bool flag = false;
 
    while(!flag){
        flag = true;
        nRadixBase *= 10;
         
        for(int i=0; i<nLen; ++i){
            pDigit[i] = pData[i]%nRadixBase; // 求出某位上的数当做基数
            pDigit[i] /= nRadixBase/10;
            if(pDigit[i] > 0)
                flag = false;
        }
        if(flag)
            break;
        RadixCountingSort(pDigit,10,pData,nLen);
    }
 
    delete[] pDigit;
    return 1;
}
 
 
main()
{  
    int nData[10]={43,65,34,5,8,34,23,0,45,34};;
 
    RadixSort(nData, 10);
    printf("经排序后的数列是：\n");
    for (int  i = 0; i < 10; ++i)
        printf("%d ", nData[i]);
    printf("\n");
    return 0;
}
