#include<stdio.h>
void check_1(int arr[] , int n){
    int low = 0 , high = n-1 ;

    while(low <= high){
       int mid= low +(high - low)/2;

        if(arr[mid]==0){
             low = mid +1 ;
        }else{
            high = mid -1 ;
        }
    }
  printf("1 Occurrence at %d index.",low + 1) ;  

}

int main(){
      int n ;
    printf("Enter  Size of the Array : ");
    scanf("%d",&n);

    int arr[n];
    
    printf("Enter Elements of Array (0 and 1): ");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    check_1(arr, n) ;

    return 0 ;

}
