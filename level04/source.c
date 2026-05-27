#include <sys/ptrace.h>
#include <stdlib.h>

int main(void) {
	char user_input[128];

	int fork_res = fork();
	memset(user_input, 0, sizeof(user_input));
	if (fork_res == 0) {                      
    	prctl(1,1);
		ptrace(PTRACE_TRACEME, 0, NULL, NULL); // prevents execve, custom shellcode still usable, just open pass file and print content
		puts("Give me some shellcode, k");
		gets(user_input); // overflow and change eip
	}
	else {
		int ptrace_result = 0;
		int wait_res;
		while (ptrace_result != 11) {
			wait(&wait_res);
			if (((wait_res & 0x7f) == 0) || ((wait_res & 0x7f) == 0x7f)) {
				puts("child is exiting");
				return 0;
			}
			ptrace_result = ptrace(PTRACE_PEEKUSER, fork_res, 44, 0);
		}
		puts("no exec() for you");
		kill(fork_res, 9);
	}
	return 0;
}