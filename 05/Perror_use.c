#include <errno.h>
#include <stdio.h>
#include <string.h>
extern int errno;

void my_perror(char *str){
	if (str !=NULL){
		strcat(str, " : ");
	}else{
		str= "";
	}
	
	switch (errno){
	case 1:
		printf("%s Operation not permitted \n",str);
		break;
	case 2:
		printf("%s No such file or directory \n",str);
		break;
	case 3:
		printf("%s No such process \n",str);
		break;
	case 4:
		printf("%s interrupted system call \n",str);
		break;
	case 5:
		printf("%s I/O error \n",str);
		break;
	}
}
