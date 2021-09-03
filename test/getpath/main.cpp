#include <unistd.h>
#include <stdio.h>

int main()
{
   printf("Current working dir: %s\n", get_current_dir_name());
   return 0;
}