#include <stdio.h>
#include <stdlib.h>

#define NOOP 0
#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define INCREMENT 3
#define DECREMENT 4
#define OUTPUT 5
#define INPUT 6
#define ENTER 7
#define JUMP 

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

// "Brainfuck leaves a lot of things up to the implementation to decide, such as array and cell size, and what happens when EOF is read. "

int main(int argc, char *argv[])
{
    int* tape = calloc(30000, sizeof(int));
    char program[10000];
    int program_size;

    int cell_pointer = 0;
    int next_instruction    = NOOP;

    get_program("test.bf", program, &program_size);
    
    for( int pc = 0; pc < program_size; pc++ )
    {

        fetch(program, pc, &next_instruction);

        execute(tape, &cell_pointer, next_instruction);
    }

    return(0);
}