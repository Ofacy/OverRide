
#include <stdlib.h>

int decrypt(char input) {
	char encrypted[] = "Q}|u`sfg~sf{}|a3";
	for (int i = 0; i < input; i++) {
		encrypted[i] ^= input;
	}
	if (strcmp(encrypted, "Congratulations!") == 0) {
		return system("/bin/sh");
	}
	return puts("\nInvalid Password");
}

int test(int param1, int param2) {
	switch(param1 - param2) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 16:
		case 17:
		case 18:
		case 19:
		case 20:
		case 21:
			return decrypt(param1 - param2);
		default:
			return decrypt(rand());
	}
}

int main() {
	int user_input;
	srand(time(NULL));                
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &user_input);
	test(user_input, 322424845);
}