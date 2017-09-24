#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Bruteforce Cracktester */
int main(int argc, char *argv[]) {
	char c, buffer[100], mode;
	int len, id, i;
	mode = '\0';
	if(argc < 4) {
		printf("[ERROR] Usage: %s <length> <password>\n", argv[0]);
		exit(1);
	} else if (argc == 4) {
		mode = '\n';
	}
	if((len = atoi(argv[1])) == NULL) {
		printf("Invalid argument: Length must be a number.\n");
		exit(2);
	}
	if(len >= 100) {
		printf("Max-Length: 99\n");
		exit(1);
	}
	printf("Length: %d\n", len);
	id = (len - 1);
	printf("Starting test for %s\n", argv[1]);
	memset(&buffer, '\0', sizeof(buffer));
	memset(&buffer, 49, len);
	while(id >= 0) {
		if((id != (len - 1)) && (buffer[id] != 'z')) {
			c = buffer[id];
			memset(&buffer[id], c + 1, 1);
			id = (len - 1);
		}
		else if((id != (len - 1)) && (buffer[id] == 'z')) {
			memset(&buffer[id], 49, 1);
			id--;
		}
		else if((id == (len - 1)) && (buffer[id] == 'z'))
			id--;
		else if(id == (len - 1)) {
			for(buffer[id] = 49; buffer[id] <= 'z'; buffer[id]++) {
				printf("%s%c", buffer, mode);
				if(strcmp(buffer, argv[2]) == 0) {
					printf("\nYeeah!!!!! I've found it. Your code is %s\n", buffer);
					return 0;
				}
			}
			id--;
		}
	}
	printf("\nI didn't find your password...\n");
	if(strlen(argv[2]) != len) {
		printf("The length is invalid!\n");
		exit(1);
	}
	printf("Password's got invalid characters.\n");
	return 1;
}
