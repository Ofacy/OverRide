#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <fcntl.h>

void log_wrapper(FILE *stream, const char *s1, const char *s2)
{
  char dest[264];

  strcpy(dest, s1);
  snprintf(&dest[strlen(dest)], 254 - strlen(dest), "%s", s2);
  dest[strcspn(dest, "\n")] = 0;
  fprintf(stream, "LOG: %s\n", dest);
  return;
}

int main(int argc, const char **argv, const char **envp)
{
  FILE *backup;
  FILE *stream; 
  int fd;
  char buf;
  char dest[104];

  buf = -1;
  if ( argc != 2 )
    printf("Usage: %s filename\n", *argv);
  backup = fopen("./backups/.log", "w");
  if ( !backup )
  {
    printf("ERROR: Failed to open %s\n", "./backups/.log");
    exit(1);
  }
  log_wrapper(backup, "Starting back up: ", argv[1]);
  stream = fopen(argv[1], "r");
  if ( !stream )
  {
    printf("ERROR: Failed to open %s\n", argv[1]);
    exit(1);
  }
  strcpy(dest, "./backups/");
  strncat(dest, argv[1], 99 - strlen(dest));
  fd = open(dest, 193, 432);
  if ( fd < 0 )
  {
    printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
    exit(1);
  }
  while ( 1 )
  {
    buf = fgetc(stream);
    if ( buf == -1 )
      break;
    write(fd, &buf, 1u);
  }
  log_wrapper(backup, "Finished back up ", argv[1]);
  fclose(stream);
  close(fd);
  return 0;
}