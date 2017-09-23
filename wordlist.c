#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Wordlist Generator */
int main(int argc, char *argv[]) {
	char c, buffer[100];
	int len, id, i;
	if(argc != 3) {
		printf("[ERROR] Usage:  %s <string> <length>\n", argv[0]);
		exit(1);
	}
	if((len = atoi(argv[2])) == NULL) {
		printf("Second parameter is invalid...\n");
		exit(2);
	}
	printf("Length: %d\n", len);
	id = len;
	printf("Starting test for %s\n", argv[1]);
	memset(buffer, 49, sizeof(buffer));
	while(id >= 0) {
		if((id != (len - 1)) && (buffer[id] != 122)) {
			c = buffer[id];
			memset(buffer[id], c++, 1);
			id = (len - 1);
		}
		printf("Debug: 1");
		else if((id != (len - 1)) && (buffer[id] == 122)) {
			memset(buffer[id], 49, 1);
			id--;
		}
		else if((id == (len - 1)) && (buffer[id] == 122))
			id--;
		else if(id == (len - 1)) {
			for(buffer[id] = 49; buffer[id] <= 122; buffer[id]++) {
				printf("%s\n", buffer);
				if(strcmp(buffer, argv[1]) == 0) {
					printf("Found code: %s\n", buffer);
					return 0;
				}
			}
		}
		if(strcmp(buffer, argv[1]) == 0) {
			printf("Found code: %s\n", buffer);
			return 0;
		}
	}
	printf("Code not found.\n");
	return 1;
}
