#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct init{
	char *name;
	int score_mid;
	int score_end;
};

struct init *root =NULL;

int compare(const void *nu1, const void *nu2){
	return strcmp(((struct init *)nu1)->name,((struct init *)nu2)->name);
}

void print_init(const void *nodeptr, VISIT order, int level){
	if(order == preorder || order == leaf)
		printf("\n 이름 : %-20s\n 중간 점수 : %d\n 기말 점수 : %d\n",(*(struct init**)nodeptr)->name,(*(struct init**)nodeptr)->score_mid,(*(struct init**)nodeptr)->score_end);
}

void main(){
	struct init **ret;
	int student, i=0;

	printf("학생 수를 입력하세요 : ");
	scanf("%d",&student);
	printf("\n");

	char nametable[student];
	struct init nodetable[student];

	char *nameptr = nametable;
	struct init *nodeptr =nodetable;

	nodeptr = (struct init*)malloc(sizeof(struct init));
	
	while (scanf("%s %d %d", nameptr, &nodeptr->score_mid,&nodeptr->score_end) !=EOF && i++ < student){
	nodeptr->name =nameptr;

	ret = (struct init **)tsearch((void*)nodeptr, (void **)&root, compare);

	printf("\"%s\" 가", (*ret)->name );
	if(*ret == nodeptr)
		printf("추가되었습니다. \n\n");
	else 
		printf("이미 존재합니다.\n\n");
	nameptr += strlen(nameptr) +i;
	nodeptr++;
	}
	twalk((void*)root,print_init);

	free(nodeptr);
}
