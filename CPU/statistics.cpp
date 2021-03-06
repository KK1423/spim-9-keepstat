//Added 4/26/03 for performance measuring with Cool
//based on code by (I think) Douglas Hauge.
//Copied 8/21/06 by MMS.  I got a copy of this code from Francis Hsu.
//I am making it work with spim-7.2.1.
//4/9/2021 Karthik here. Patching onto qtspim 9.

#include "statistics.h"

void statistics_reset(statistics_t *s)
{
   *s = statistics_t({0});
}

void statistics_print(statistics_t *s, port fp)
{
   int other_instructions =
       s->instruction_count - (s->num_reads + s->num_writes + s->num_branches);
   write_output(fp,
                "Stats -- #instructions : %d\n"
                "         #reads : %d  #writes %d  #branches %d  #other %d\n",
                s->instruction_count,
                s->num_reads, s->num_writes, s->num_branches, other_instructions);
}

void statistics_inc_instruction_count(statistics_t *s)
{
   s->instruction_count += 1;
}

void statistics_inc_reads(statistics_t *s)
{
   s->num_reads += 1;
}

void statistics_inc_writes(statistics_t *s)
{
   s->num_writes += 1;
}

void statistics_inc_branches(statistics_t *s)
{
   s->num_branches += 1;
}

statistics_t global_stats;
bool keep_stats = 0;
