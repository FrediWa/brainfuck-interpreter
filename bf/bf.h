#ifndef BRNFCK_H
#define BRNFCK_H

#define NOOP 0
#define MOVE_RIGHT 1
#define MOVE_LEFT 2
#define INCREMENT 3
#define DECREMENT 4
#define OUTPUT 5
#define INPUT 6
#define ENTER 7
#define JUMP 

void fetch(char* program, int program_counter, int* next_instruction);

void execute(int* tape, int* cell_pointer, int next_instruction);

void get_program(char* path, char* buffer, int* size);

#endif