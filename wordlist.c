#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Wordlist Generator */
int main(int argc, char *argv[]) {
	char c, buffer[100];
	int len, id, i;
	if(argc != 2) {
		printf("[ERROR] Usage: %s <length>\n", argv[0]);
		exit(1);
	}
	if((len = atoi(argv[1])) == NULL) {
		printf("Second parameter is invalid...\n");
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
				printf("%s\n", buffer);
			}
			id--;
		}
	}
	return 0;
}
