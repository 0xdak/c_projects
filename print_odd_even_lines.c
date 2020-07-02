//the task is to print all the odd line content of the file first
//then print all the even line content
//this is a "geeksforgeeks" example

#include<stdio.h>

int main(void){
	FILE *fp;
	char data[50]= "";
	fp = fopen("file.txt", "r");
	int i = 1;
	while(fgets(data,50,fp) != NULL){ //printing odd lines
		if((i % 2) == 0) printf("%s",data);
		i++;
	}
	i = 1;
	fclose(fp);

	printf("\n");

	fp = fopen("file.txt", "r");
	while(fgets(data,50,fp) != NULL){ // printing even lines
		if((i % 2) == 1) printf("%s",data);
		i++;
	}
	
	fclose(fp);
	return 0;
}
