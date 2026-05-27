#include <string.h>
#include <stdio.h>

char a_user_name[100]; // only 100? (overflow? could replace got?)

int verify_user_pass(char *password) {
	return strcmp(password, "admin");
}

int verify_user_name() {
	puts("verifying username....\n");
	return strcmp(a_user_name, "dat_will");
}

int main(void) {
	char input_buffer[64];

	memset(input_buffer, 0, sizeof(input_buffer));
	puts("********* ADMIN LOGIN PROMPT *********");                   
	printf("Enter Username: ");
	fgets(a_user_name,256,stdin);
	if (verify_user_name()) {
		puts("Enter Password: ");
		fgets(input_buffer, 100, stdin); // overflow this, eip is right after
		int verify = verify_user_pass(input_buffer);
		if (verify || !verify) { // always false
			puts("nope, incorrect password...\n");
			return 1;
		}
		return 0;
	}
	puts("nope, incorrect username...\n");
	return 1;
}