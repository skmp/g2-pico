/* KallistiOS ##version##

   hello.c
   Copyright (C) 2001 Megan Potter
*/

#include <kos.h>

/* These macros tell KOS how to initialize itself. All of this initialization
   happens before main() gets called, and the shutdown happens afterwards. So
   you need to set any flags you want here. Here are some possibilities:

   INIT_NONE        -- don't do any auto init
   INIT_IRQ         -- Enable IRQs
   INIT_NET         -- Enable networking (including sockets)
   INIT_MALLOCSTATS -- Enable a call to malloc_stats() right before shutdown

   You can OR any or all of those together. If you want to start out with
   the current KOS defaults, use INIT_DEFAULT (or leave it out entirely). */
KOS_INIT_FLAGS(INIT_DEFAULT | INIT_MALLOCSTATS);
volatile uint32_t *modem_base = (uint32_t*)0xa0600400;

/* Your program's main entry point */
int main(int argc, char **argv) {
    /* The requisite line */

    printf("\nHello g2-modem!\n\n");

   for(;;) {
      for (int reg = 0; reg < 256; reg++) {
         printf("reg: %d, %lX\n", reg, modem_base[reg]);
         uint32_t nv = rand();
         modem_base[reg] = nv;
         printf(">reg: %d, %lX=%lX\n", reg, modem_base[reg], nv);
      }
   }

    return 0;
}
