/*Write a program (use signal system call)
i. which calls a signal handler on SIGINT signal and then reset the default action of the
SIGINT signal
ii. Which ignores SIGINT signal and then reset the default action of SIGINT signal*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void callback()
{
  printf("Interrupt Received !\n");
  (void)signal(SIGINT, SIG_DFL);
}

int main()
{
  int ch, i = 0;
  printf("Enter choice 1: call handler and default\n2: ignore first time and default\n");
  scanf("%d", &ch);

  switch (ch)
  {
  case 1:
    (void)signal(SIGINT, callback);
    break;

  case 2:
    (void)signal(SIGINT, SIG_IGN);
    break;
  }
  while (1)
  {
    sleep(1);
    printf("Press CTRL+C ...\n");
    i++;
    if (i == 10 && ch == 2)
      (void)signal(SIGINT, SIG_DFL);
  }
  return 0;
}
