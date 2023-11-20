#include <stdio.h>
#include <stdlib.h>

#include "bf/bf.h"

int main(int argc, char *argv[])
{
    int* tape = calloc(30000, sizeof(int));
    char program[10000];
    int program_size;

    int cell_pointer = 0;
    int next_instruction    = NOOP;

    get_program("bf-sources/test.bf", program, &program_size);
    
    for( int pc = 0; pc < program_size; pc++ )
    {

        fetch(program, pc, &next_instruction);

        execute(tape, &cell_pointer, next_instruction);
    }

    return(0);
}