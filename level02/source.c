#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *pass_file = fopen("/home/users/level03/.pass","r");
	char password_buffer[112];
	char pass_buffer[48];
	char username_buffer[100];

	memset(username_buffer, 0, sizeof(username_buffer));
	memset(pass_buffer, 0, sizeof(pass_buffer));
	memset(password_buffer, 0, sizeof(password_buffer));
	if (!pass_file) {                                     
    	fwrite("ERROR: failed to open password file\n",1,0x24,stderr);
		exit(1);
	}
	int read_size = fread(pass_buffer, 1, 41, pass_file);
	int pass_len = strcspn(pass_buffer, "\n");
	pass_buffer[pass_len] = '\0';
	if (read_size != 41) {
    	fwrite("ERROR: failed to read password file\n",1,0x24,stderr);
		exit(1);
	}
	fclose(pass_file);                        
	puts("===== [ Secure Access System v1.0 ] =====");
	puts("/***************************************\\");
	puts("| You must login to access this system. |");
	puts("\\**************************************/");
	printf("--[ Username: ");
	fgets(username_buffer, 100, stdin);
	username_buffer[strcspn(username_buffer, "\n")] = '\0';
	printf("--[ Password: ");
	fgets(password_buffer, 100, stdin);
	password_buffer[strcspn(password_buffer, "\n")] = '\0';
	puts("*****************************************");
	if (strncmp(password_buffer, pass_buffer, 41) == 0) {
		printf("Greetings, %s!\n", username_buffer);
		system("/bin/sh");
		return 0;
	}
	printf(username_buffer); // exploit this!
	puts(" does not have access!");
	exit(1);
}