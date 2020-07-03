// it hides the entered password 
// while user is entering password, the password's letters show up '*'
// this is an example in "geeksforgeeks" example

#include<stdio.h>
#include<conio.h>

int main(void){
	char pwd[9];
	int i = 0;
	while(i < 9){
		pwd[i] = getch();
		printf("*");
		i++;
	}
	printf("\n%s\n",pwd);
	return 0;
}
