#include "Sorting.h"


Sorting::Sorting(int s)
{
	Size = s;
}


Sorting::~Sorting(void)
{
}

void Sorting::quickSort(int arr[],int l,int r){
    int i=l,j=r,temp;
    int piv=arr[(l+r)/2];
    
    while(i<=j){
        while(arr[i]<piv){i++;}
        while(arr[j]>piv){j--;}
        if(i<=j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    if(l<j){quickSort(arr,l,j);}
    if(i<r){quickSort(arr,i,r);}
}

void Sorting::startMerge(int arr[],int tempArr[],int arrSize){
	mergeSort(arr,tempArr,0,arrSize-1);
}

void Sorting::merge(int arr[],int tempArr[],int x,int mid,int y){
	int left=(mid-1),tempPos=x;
    while((x<=left) && (mid<=y)){
        if(arr[x]<=arr[mid]){
            tempArr[tempPos]=arr[x];
            tempPos++;
            x++;
        }else{
            tempArr[tempPos]=arr[mid];
            tempPos++;
            mid++;
        }
    }
    while(x<=left){
        tempArr[tempPos]=arr[x];
        x++;
        tempPos++;
    }
    while(mid<=y){
        tempArr[tempPos]=arr[mid];
        mid++;
        tempPos++;
    }
    for(int i=0;i<Size;i++){
        arr[y]=tempArr[y];
        y--;
    }
}

void Sorting::mergeSort(int arr[],int tempArr[],int x,int y){
	int piv;
    if(x<y){
        piv=(x+y)/2;
        mergeSort(arr,tempArr,x,piv);
        mergeSort(arr,tempArr,piv+1,y);
        merge(arr,tempArr,x,piv+1,y);
    }
}

void Sorting::insertionSort(int arr[],int arrLength){
	int j,temp;
    for(int i=1;i<arrLength;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }
}

void Sorting::selectionSort(int arr[],int arrSize){
	int index,temp;
    for(int i=0;i<arrSize-1;i++){
        index=i;
        for(int j=i+1;j<arrSize;j++){
            if(arr[j]<arr[index]){index=j;}
        }
        if(index!=i){
            temp=arr[i];
            arr[i]=arr[index];
            arr[index]=temp;
        }
    }
}

void Sorting::setSize(int s)
{
	Size = s;
}

void Sorting::iterMerge(int arr[], int size){
	int inc,left,leftMax,right,rightMax,cur;
    int *temp = new int[size];
    inc=1;
    while(inc<size){
        left=0;
        right=inc;
        leftMax=right-1;
        rightMax=(leftMax+inc<size)?leftMax+inc:size-1;
        cur=0;
        while(cur<size){
            while(left<=leftMax && right<=rightMax){
                if(arr[right]<arr[left]){temp[cur]=arr[right++];}
                else{temp[cur]=arr[left++];}
                cur++;
            }
            while(right<=rightMax){temp[cur++]=arr[right++];}
            while(left<=leftMax){temp[cur++]=arr[left++];}
            left=right;
            right+=inc;
            leftMax=right-1;
            rightMax=(leftMax+inc<size)?leftMax+inc:size-1;
        }
        inc*=2;
        for(int i=0;i<size;i++){arr[i]=temp[i];}
    }
}