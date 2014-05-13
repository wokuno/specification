#include <stdio.h>
#include <shmem.h>

int main(void)
{
   static int  race_winner = -1;
   int oldval;
   shmem_init(2);
   oldval = shmem_int_cswap(&race_winner, -1, shmem_my_pe(), 0);
   if(oldval == -1) printf("pe %d was first\n",shmem_my_pe());
   return 1;
}
