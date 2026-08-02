#include<stdio.h>
 
 

void  bubbleOptimized(int arr[],int n)
{
    int comp=0;

    for(int i=0;i<n-1;i++)
    {
        int swapCnt=0;
        for(int j=0;j<n-i-1;j++)
        {
            comp++;

            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapCnt=1;
            }
        }

        if(swapCnt==0)
            break;
    }

    printf("Optimized Comparisons = %d\n",comp);
}

void bubbleNormal(int arr[],int n)
{
    int comp=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            comp++;

            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Normal Comparisons = %d\n",comp);
}

int main()
{
    int n;

    printf("Enter size of Array: ");
    scanf("%d",&n);

    int arr1[n],arr2[n];
    printf("Enter Element of Array:") ;
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
        arr2[i]=arr1[i];
    }
    

    bubbleOptimized(arr1,n);
    bubbleNormal(arr2,n);

    return 0;
}