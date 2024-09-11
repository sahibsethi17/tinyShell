/*

mycounter.c - Counts from o to <n>.
usage: counter from 1 to <n>
Sleeps for <n> seconds and sends SIGTSTP to itself.
**/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv)
{
   int i, secs, counter;
   pid_t pid;

   if (argc != 2)
   {
      fprintf(stderr, "Usage: %s <n>\n", argv[0]);
      exit(0);
   }
   secs = atoi(argv[1]);
   counter = 0;

   for (i = 0; i < secs; i++)
      counter += 1;
   sleep(2);

   pid = getpid();

   if (kill(-pid, SIGTSTP) < 0)
      fprintf(stderr, "kill (tstp) error");

   exit(0);
}