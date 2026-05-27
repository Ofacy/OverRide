#include <stdio.h>
#include <stdlib.h>

# define PASSWORD 5276

int main(void) {
	int user_input;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &user_input);
	if (user_input != PASSWORD) {
		puts("\nInvalid password");
	} else {
		puts("\nAuthenticated!");
		system("/bin/sh");
	}

	return user_input != PASSWORD;
}