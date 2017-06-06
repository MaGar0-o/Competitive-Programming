//including!!
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
	node* go[26];
	int x;
};

int main(){
	const int sz = sizeof(int);
	char a[10];
	while(scanf("%s", a)){
		for(int i = 0; i < 10; i++)
			printf("%d ", (int)a[i]);
		printf("\n");
		printf("%d\n", strlen(a));
	}
	return 0;
}
