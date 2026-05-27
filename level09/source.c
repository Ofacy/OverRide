#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 

int secret_backdoor()
{
  char s[128];

  fgets(s, 128, stdin);
  return system(s);
}

char *set_msg(char* msg)
{
  char s[1024];

  memset(s, 0, sizeof(s));
  puts(">: Msg @Unix-Dude");
  printf(">>: ");
  fgets(s, 1024, stdin);
  return strncpy((char *)msg, s, *(int *)(msg + 180));
}

int set_username(char* username)
{
  char s[140];
  int i;

  memset(s, 0, 128);
  puts(">: Enter your username");
  printf(">>: ");
  fgets(s, 128, stdin);
  for ( i = 0; i <= 40 && s[i]; ++i )
    username[i + 140] = s[i];
  return printf(">: Welcome, %s", (const char *)(username + 140));
}

int handle_msg()
{
  char buff[140];

  set_username(buff);
  set_msg(buff);
  return puts(">: Msg sent!");
}



int main(int argc, const char **argv, const char **envp)
{
  puts(
    "--------------------------------------------\n"
    "|   ~Welcome to l33t-m$n ~    v1337        |\n"
    "--------------------------------------------");
  handle_msg();
  return 0;
}