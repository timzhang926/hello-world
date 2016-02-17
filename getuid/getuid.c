#include <stdio.h>
#include <unistd.h>

main()
{
  uid_t uid;

  uid = getuid();
  printf("The real UID is: %u\n", uid);

}
