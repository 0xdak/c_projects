//working about hashing
#include<stdio.h>

struct user {
	int id;
	char nick[10];
	int age;
};

void print_users(struct user[], int);
void place_users_id(struct user[], int);
void insert_user(struct user, int);
int HASH(int, int);
void reset_users();

struct user users_db[10];

int main(void){
	struct user users[10] = { 0, "nickone",  20,
				  0, "nicktwo",  15,
				  0, "nickthree",   11,
				  0, "nickfour", 65,
				  0, "nickfive",  15,
				  0, "nicksix", 22,
				  0, "nickseven", 44,
				  0, "nickeight",12,
				  0, "nicknine",28,
				  0, "nickten",   35
			 	};
	reset_users();
	print_users(users,10);
	place_users_id(users,10);
	print_users(users_db,10);	
	return 0;
}

void print_users(struct user users[], int L){
	int i = 0;
	printf("------------------\n");
	while(i < L){
		printf("|%3d|%9s|%2d|\n",users[i].id,users[i].nick,users[i].age);
		i++;
	}
	printf("------------------\n");
}

void place_users_id(struct user users[], int L){
	int i = 0;
	while(i < L){
		insert_user(users[i], 0);
		i++;
	}		
}

void insert_user(struct user user, int i){
	int key = HASH(user.age, i);
	if(users_db[key].id != 0){
		insert_user(user, i + 1);
	}
	else {
	user.id = key;
	users_db[key] = user;
	//print_users(users_db,10);
	}
}

int HASH(int x, int i){
	return ((x % 13) + i*(7 - (x % 7))) % 10;
}

void reset_users(){
	int i = 0;
	while(i < 10){
		users_db[i].id = 0;
		i++;
	}
}

