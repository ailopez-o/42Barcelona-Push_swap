#include "../inc/defines.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/gui.h"
#include <stdio.h>
#include <stdlib.h>

int easy_short(t_meta *meta)
{
    int     numelems;

    numelems = meta->stack_size / 2;
    while(numelems)
    {
        pb(&(meta->stack_a), &(meta->stack_b));
        if (meta->gui)
		    draw_push_swap(meta);
        numelems--;
    }
	return (1);
}