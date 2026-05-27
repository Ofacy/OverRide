#include <string.h>
#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>

#define HIBYTE(x) (((x) >> 8) & 0xFF)


unsigned int get_unum()
{
    unsigned int nbr;
    scanf("%u", &nbr);
    return nbr;
}

int store_number(unsigned int* uint_arr)
{
  unsigned int unum;
  unsigned int position;

  printf(" Number: ");
  unum = get_unum();
  printf(" Index: ");
  position = get_unum();
  if ( position == 3 * (position / 3) || HIBYTE(unum) == 183 )
  {
    puts(" *** ERROR! ***");
    puts("   This index is reserved for wil!");
    puts(" *** ERROR! ***");
    return 1;
  }
  else
  {
    uint_arr[position] = unum;
    return 0;
  }
}

int read_number(unsigned int* uint_arr)
{
  unsigned int unum;

  printf(" Index: ");
  unum = get_unum();
  printf(" Number at data[%u] is %u\n", unum, uint_arr[unum]);
  return 0;
}

int main(int argc, const char **argv, const char **envp)
{
  unsigned int uint_array[400];
  int number;
  char cmd[4];

  number = 0;
  *cmd = 0;
  memset(uint_array, 0, sizeof(uint_array));
  while ( *argv )
  {
    memset((void *)*argv, 0, strlen(*argv));
    ++argv;
  }
  while ( *envp )
  {
    memset((void *)*envp, 0, strlen(*envp));
    ++envp;
  }
  puts(
    "----------------------------------------------------\n"
    "  Welcome to wil's crappy number storage service!   \n"
    "----------------------------------------------------\n"
    " Commands:                                          \n"
    "    store - store a number into the data storage    \n"
    "    read  - read a number from the data storage     \n"
    "    quit  - exit the program                        \n"
    "----------------------------------------------------\n"
    "   wil has reserved some storage :>                 \n"
    "----------------------------------------------------\n");
  while ( 1 )
  {
    printf("Input command: ");
    number = 1;
    fgets(cmd, 20, stdin);
    cmd[strlen(cmd) - 1] = 0;
    if ( !memcmp(cmd, "store", 5u) )
    {
        if (store_number(uint_array))
            printf(" Failed to do %s command\n", cmd);
        else
            printf(" Completed %s command successfully\n", cmd);
    }
    if ( !memcmp(cmd, "read", 4u) )
    {
        if (read_number(uint_array))
            printf(" Failed to do %s command\n", cmd);
        else
            printf(" Completed %s command successfully\n", cmd);
    }
    if ( !memcmp(cmd, "quit", 4u) )
      return 0;
   
    *cmd = 0;
  }
}