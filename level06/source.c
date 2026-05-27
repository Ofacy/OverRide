#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <stdlib.h> 

int auth(char *s, int number)
{
  int result;
  int len;

  s[strcspn(s, "\n")] = 0;
  len = strnlen(s, 32);
  if ( len <= 5 )
    return 1;
  if ( ptrace(PTRACE_TRACEME, 0, 1, 0) == -1 )
  {
    puts("\x1B[32m.---------------------------.");
    puts("\x1B[31m| !! TAMPERING DETECTED !!  |");
    puts("\x1B[32m'---------------------------'");
    return 1;
  }
  else
  {
    result = (s[3] ^ 0x1337) + 6221293;
    for ( int i = 0; i < len; ++i )
    {
      if ( s[i] <= 31 )
        return 1;
      result += (result ^ (unsigned int)s[i]) % 0x539;
    }
    return number != result;
  }
}


int main(int argc, const char **argv, const char **envp)
{
  int number;
  char s[28];

  puts("***********************************");
  puts("*\t\tlevel06\t\t  *");
  puts("***********************************");
  printf("-> Enter Login: ");
  fgets(s, 32, stdin);
  puts("***********************************");
  puts("***** NEW ACCOUNT DETECTED ********");
  puts("***********************************");
  printf("-> Enter Serial: ");
  scanf("%d", &number);
  if ( auth(s, number) )
    return 1;
  puts("Authenticated!");
  system("/bin/sh");
  return 0;
}