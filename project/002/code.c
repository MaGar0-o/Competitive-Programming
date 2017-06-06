#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char name[100];
	struct Node * next, *prev;
}nd;
typedef nd* ndptr;

void chap(nd * head)
{
	nd * current = head;
	current = head->next;
	while (current != NULL)
	{
		printf("%s\n",(current->name));
		current = current->next;
	}
}

nd* new_node(nd *tail){
	nd* ret = (nd*) malloc(sizeof(nd));
	ret->next = NULL;
	ret->prev = tail;
	return ret;
}

nd* find_pos(char* esm, nd* head){
	int len = strlen(esm) + 1;
	head = head->next;
	while(head != NULL){
		if(!memcmp(esm, head->name, len))
			return head;
		head = head->next;
	}
	return NULL;
}

void Swap(ndptr *p1, ndptr *p2){
	nd* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int main ()
{
	int n;
	scanf("%d",&n);
	nd * head = NULL,* tail = NULL;
	int i;
	nd * temp = new_node(NULL);
	head = temp;
	tail = head;
	for (i = 0; i < n; i++)
	{
		tail->next = new_node(tail);
		tail = tail->next;
		scanf("%s",tail->name);
	}
	char d[30],esm[110], esm2[100];
	for (i = 0; i < 110; i++)
		d[i] = '\0';
	while (1 == 1)
	{
		scanf("%s", d);
		int len = strlen(d);
		if(d[0] == 'a' && d[1] == 'd')
		{
			tail->next = new_node(tail);
			tail = tail->next;
			scanf("%s",tail->name);
		}
		else if(d[0] == 'd')
		{
			scanf("%s", esm);
			nd* pos = find_pos(esm, head);
			if(pos == NULL)
				continue;
			if(pos == tail)
				tail = pos->prev;
			nd* prv = pos->prev;
			nd* nxt = pos->next;
			if(prv != NULL)
				prv->next = nxt;
			if(nxt != NULL)
				nxt->prev = prv;
			free(pos);
		}
		else if(d[0] == 'a')
		{
			scanf("%s", esm);
			nd* pos = find_pos(esm, head);
			if(pos->next == NULL)
				printf("%s is the last TA\n", esm);
			else
				printf("%s\n", pos->next->name);
		}
		else if(d[0] == 'b')
		{
			scanf("%s", esm);
			nd* pos = find_pos(esm, head);
			if(pos->prev == head)
				printf("%s is the first TA\n", esm);
			else
				printf("%s\n", pos->prev->name);
		}
		else if(d[0] == 'r')
		{
			scanf("%s%s", esm, esm2);
			if(memcmp(esm, esm2, strlen(esm) + 1))
			{
				nd* p1 = find_pos(esm, head);
				nd* p2 = find_pos(esm2, head);
				nd* p = find_pos(esm2, p1);
				if(p == NULL)
					Swap(&p1, &p2);
				if(p2 == tail)
					tail = p1;
				nd* p3;
				if(p1->prev != NULL)
					p1->prev->next = p2;
				if(p2->next != NULL)
					p2->next->prev = p1;
				Swap(&p1->prev, &p2->next);
				for(p3 = p1; p3 != p2; p3 = p3->prev)
					Swap(&p3->next, &p3->prev);
				Swap(&p2->next, &p2->prev);
			}
		}
		else if(d[0] == 'w')
		{
			scanf("%s%s", esm, esm2);
			chap(head);
		}
		else
			break;
	}
}
