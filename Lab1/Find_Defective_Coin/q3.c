#include <stdio.h>
#include <stdlib.h>

int compareweigh(int arr[],int r1,int l1,int r2,int l2);
int FindDefectiveCoin(int arr[],int low, int high);

int main()
{
    int n;
    
    printf("Enter the size of array(No of Coins)\n");
    scanf("%d",&n);

    int coin[n];
    printf("Enter the array elements(Weights of coins)\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&coin[i]);
    }
    
    int index=FindDefectiveCoin(coin,0,n-1);

    if(index==-1)
    {
        printf("No Defective Coin found\n");
    }

    else
    {
        printf("Index of Defective Coin = %d and Weigh is %d",index,coin[index]);
    }
    




}

int FindDefectiveCoin(int arr[], int low, int high) {
    if (low == high) {
        return low;  
    }

    if (high - low == 1) { 
        
        if (arr[low] < arr[high]) return low;
        else if (arr[high] < arr[low]) return high;
        else return -1; 
    }

    int n = high - low + 1;
    int mid = (low + high) / 2;

    if (n % 2 == 0) {
    int result;

    result = compareweigh(arr, low, mid, mid+1, high);

    if (result == -1) return FindDefectiveCoin(arr, low, mid);
    else if (result == 1) return FindDefectiveCoin(arr, mid+1, high);
    else {
        result = compareweigh(arr, low, mid-1, mid, high-1);

        if (result == -1) return FindDefectiveCoin(arr, low, mid-1);
        else if (result == 1) return FindDefectiveCoin(arr, mid, high-1);
        else {
            if (arr[high] < arr[low]) return high;
            else return -1;
        }
    }
}

}

int compareweigh(int arr[],int r1,int l1,int r2,int l2)
{
    int sum1=0;
    int sum2=0;
    for(int i=r1;i<=l1;i++)
    sum1=sum1+arr[i];
    for(int j=r2;j<=l2;j++)
    sum2=sum2+arr[j];

    if(sum1<sum2)
    {
        return -1;
    }
    if(sum1>sum2)
    {
        return 1;
    }
    return 0;
}
