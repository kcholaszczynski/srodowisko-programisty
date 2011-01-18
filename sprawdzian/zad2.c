#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NUM_DOMAINS 6
#define NUM_USERS 8

char *domains[] = {"gmail.com", "wp.pl", "poczta.onet.pl", 
"buziaczek.pl", "sigma.ug.edu.pl", "microsoft.com"};
char *users[] = {"jkowalski", "nieja", "gosiaczek69", "spamer", 
"rumcjas", "johny.bravo", "bill.gates", "cj"};

char* get_random_addr() {
	char* domain = domains[rand()%NUM_DOMAINS];
        char* user = users[rand()%NUM_USERS];
	int len = strlen(domain)+strlen(user)+2;
        char* addr = calloc(sizeof(char), len);
        sprintf(addr, "%s@%s",user,domain);
        return addr; 
}


void print_random_line() {
        static int line_num = 1;
	char *from = get_random_addr();
	char *to = get_random_addr();
	printf("%d -- [INFO] - [message id: %d from: %s, to: %s]\n",line_num, rand(), from, to);
	free(from); free(to);
        line_num++;
}

int main(int argc, char **argv) {
        int i;
        int mesg_count = 1000;

	srand((int)time(NULL));

	if(argc>1) mesg_count = atoi(argv[1]);
        for(i=0;i<mesg_count;i++)
		print_random_line();

	return(0);
}
