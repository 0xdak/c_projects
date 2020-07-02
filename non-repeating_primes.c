// given an array containing repetitive prime and nonprime numbers,
// the task is to find the prime numbers occuring only once.
// this is a "geeksforgeeks" example.

#include<stdio.h>
#include<math.h>
int is_prime(int num);

int main(void){
	//it moves in the array one by one
	//if the number is prime, it checks the number is repeating
	//if it dont, that's the number we searching. 
	
	int arr[] = {17,19,7,5,29,5,2,2,7,17,19};
	int arr_count = 11, res, is_repeating = 0;
	for(int i = 0; i < arr_count; i++){
		if(is_prime(arr[i])) {	//if number is prime
			res = arr[i];	
			is_repeating = 0;
			for(int j = 0; j < arr_count; j++){
				//printf("i = %d, j = %d\n",i,j);
				if(j == i) continue;
				if(arr[j] == arr[i]){
					//printf("%d is repeating\n",arr[i]);
					is_repeating = 1;
					break;
				}
			}
			if(is_repeating == 0) break;
			
		}
	}
	printf("%d",res);
	return 0;
}

int is_prime(int num){
	for(int j = 2; j <= sqrt(num); j++){
		//printf("%d %d\n",num,j);
		if(num % j == 0)
			return 0;
	}	
	return 1;
}
