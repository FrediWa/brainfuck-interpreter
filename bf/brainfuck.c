#include <stdio.h>
#include <stdlib.h>

#include "bf.h"

void execute(int* tape, int* cell_pointer, int next_instruction)
{
    if( next_instruction == NOOP)
    {
        return;
    }
    else if( next_instruction == MOVE_RIGHT)
    {
        *cell_pointer++;
    }
    else if( next_instruction == MOVE_LEFT)
    {
        *cell_pointer--;
    }
    else if( next_instruction == INCREMENT)
    {
        tape[*cell_pointer]++;
    }
    else if( next_instruction == DECREMENT)
    {
        tape[*cell_pointer]--;
    }
    else if( next_instruction == OUTPUT)
    {
        printf("%c", tape[*cell_pointer]);
    }
}

void fetch(char* program, int program_counter, int* next_instruction)
{
    char instruction = program[program_counter];

    printf("Instruction %c\n", instruction);

    switch( instruction )
    {
        case '<':
            *next_instruction = MOVE_LEFT;
            break;
        case '>':
            *next_instruction = MOVE_RIGHT;
            break;
        case '+':
            *next_instruction = INCREMENT;
            break;
        case '-':
            *next_instruction = DECREMENT;
            break;
        case '.':
            *next_instruction = OUTPUT;
            break;
        default:
            *next_instruction = NOOP;
            break;
    }
}

void get_program(char* path, char* buffer, int* size)
{
    FILE* file = fopen(path, "rb");

    // Attempt to read
    if (file) {
        int c;
        int i = 0;
        while ((c = fgetc(file)) != EOF) {
            buffer[i] = c;
            i++;
        }
        *size = i;
    }
    fclose(file);
}
