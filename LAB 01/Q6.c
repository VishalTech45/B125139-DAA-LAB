#include<stdio.h>
void  Duplicates(int arr[] , int n){

    for (int i = 0 ; i < n/2 ;i++){
        for(int j =i+1 ; j < n ; j++){
            if (arr[i]==arr[j]){
                printf("We are getting Duplicate numbers %d\n",arr[i]);
                break ;
            }
        }

    }
}


int main(){
    int n ;
    printf("Enter  Size of the Array : ");
    scanf("%d",&n);
    int arr[n];
    
    printf("Enter Elements of Array:");
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }

    Duplicates( arr, n) ;

    return 0 ;

}
