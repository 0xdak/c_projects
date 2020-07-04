//have many ways are there to place a black and a white knight on an n*m chessboard
//such that they do not attack each other?
//this is a "geeksforgeeks" practice
#include<stdio.h>

struct test {
	int n;
	int m;
};

int numbers_of_placed_knights(int, int);
int n, m;
int main(void){
	int ways = 0;
	scanf("%d %d", &n, &m);
	for(int x = 1; x <= n; x++){
		for(int y = 1; y <= m; y++){
			// at the beginning, empty spaces = n*m
			// the knight = 1
			// places that the knight can go = numbers_of_places_knights
			ways += n * m - 1 - numbers_of_placed_knights(x, y);
		}
	}
	printf("%d\n",ways);
	return 0;
}


//when we moved the knight, if the knight are within the borders
//other knight can't placed there.
//a knight can move 8 different places
//so we find the places where the knight can go
//then we substract "places where the knight can go" out of 8 
int numbers_of_placed_knights(int x, int y){
	int res = 8;	
	if(x + 2 >   n || y + 1 >   m) res -= 1;
	if(x + 1 >   n || y + 2 >   m) res -= 1;
	if(x + 2 >   n || y - 1 <=  0) res -= 1;
	if(x + 1 >   n || y - 2 <=  0) res -= 1;
	if(x - 1 <=  0 || y - 2 <=  0) res -= 1;
	if(x - 2 <=  0 || y - 1 <=  0) res -= 1;
	if(x - 1 <=  0 || y + 2 >   m) res -= 1;
	if(x - 2 <=  0 || y + 1 >   m) res -= 1;
	return res;
}
