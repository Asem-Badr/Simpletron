#ifndef _SML_EXE_h
#define _SML_EXE_h

#define MEMORY_SIZE 100

typedef enum _istruction_set_t{
	READ = 10,
	WRITE = 11,

	LOAD = 20,
	STORE = 21,

	ADD = 30,
	SUBTRACT = 31,
	DIVIDE = 32,
	MULTIPLY = 33,

	BRANCH = 40,
	BRANCHNEG = 41,
	BRANCHZERO = 42,
	HALT = 43
}instruction_set_t;
/*******************/
typedef int word_t;
/*******************/
typedef struct _registers_t{
	word_t accumulator;
	word_t instructionCounter;
	word_t instructionRegister;
}registers_t;
/**********************************************************/
void Run();
void Recieve_Instructions(word_t *memory);
void Fetch(word_t *memory, registers_t *SMLRegisters);
void Decode( word_t *opCode, word_t *operand , registers_t *SMLRegisters);
void Execute(word_t *memory, word_t opCode, word_t operand, registers_t *SMLRegisters);
 int Instruction_Is_Valid(word_t instruction);
void Read (word_t operand , registers_t *SMLRegisters,word_t *memory);
void Write (word_t operand , registers_t *SMLRegisters,word_t *memory);
/*************/
void Load (word_t operand , registers_t *SMLRegisters,word_t *memory);
void Store (word_t operand , registers_t *SMLRegisters,word_t *memory);
/*************/
void Add (word_t operand , registers_t *SMLRegisters,word_t *memory);
void Sup (word_t operand , registers_t *SMLRegisters,word_t *memory);
void Div (word_t operand , registers_t *SMLRegisters,word_t *memory);
void Mul (word_t operand , registers_t *SMLRegisters,word_t *memory);
/************/
void Branch (word_t operand , registers_t *SMLRegisters);
void Branch_Neg (word_t operand , registers_t *SMLRegisters);
void Branch_Zero (word_t operand , registers_t *SMLRegisters);
/************/
#endif
