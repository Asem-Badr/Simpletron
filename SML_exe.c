#include "SML_exe.h"
#include <stdio.h>

void Run()
{
    word_t memory[MEMORY_SIZE] = {0};
    registers_t registers = {0, 0, 0};
    instruction_set_t instruction_set ;
    word_t opCode = 0;
    word_t operand = 0;

    Recieve_Instructions(memory);
    while(opCode != HALT)
    {
        Fetch(memory, &registers);
        Decode(&opCode, &operand,&registers);
        Execute(memory, opCode, operand,&registers);
    }
}

void Recieve_Instructions(word_t *memory)
{
    word_t instruction = 0;
    int location = 0;
    while(instruction != -99999)
    {
        printf("%2d ?", location);
        scanf("%d", &instruction);
      // if(Instruction_Is_Valid(instruction))
       // {
            memory[location] = instruction;
            location++;
       // }*/
    }
}
int Instruction_Is_Valid(word_t instruction)
{
// get operation
    word_t op = instruction / 100;
// check validity
/**switch**/
/**use enum**/

        switch (op) {
        case READ:
            return 1;
        case WRITE:
            return 1;
        case ADD:
            return 1;
        case SUBTRACT :
            return 1;
        case DIVIDE :
            return 1;
        case MULTIPLY :
            return 1;
        case LOAD :
            return 1;
        case STORE :
            return 1;
        case BRANCH :
            return 1;
        case BRANCHNEG :
            return 1;
        case BRANCHZERO :
            return 1;
        default :
            return 0;
        }
}

void Fetch(word_t *memory, registers_t *SMLRegisters)
{
    SMLRegisters->instructionRegister = memory[SMLRegisters->instructionCounter];
    SMLRegisters->instructionCounter++;
}

void Decode( word_t *opCode, word_t *operand, registers_t *SMLRegisters)
{
    *opCode = (SMLRegisters->instructionRegister / 100);
    *operand = (SMLRegisters->instructionRegister % 100);
}

void Execute(word_t *memory, word_t opCode, word_t operand,registers_t *SMLRegisters)
{
    int x =opCode;
     switch (x) {
        case READ:
            Read(operand,&SMLRegisters,&memory);
            break;
        case WRITE:
            Write(operand,&SMLRegisters,&memory);
            break;
        case ADD:
            Add(operand,&SMLRegisters,&memory);
            break;
        case SUBTRACT :
            Sup(operand,&SMLRegisters,&memory);
            break;
        case DIVIDE :
            Div(operand,&SMLRegisters,&memory);
            break;
        case MULTIPLY :
            Mul(operand,&SMLRegisters,&memory);
            break;
        case LOAD :
            Load(operand,&SMLRegisters,&memory);
            break;
        case STORE :
            Store(operand,&SMLRegisters,&memory);
            break;
        case BRANCH :
            Branch(operand,&SMLRegisters);
            break;
        case BRANCHNEG :
            Branch_Neg(operand,&SMLRegisters);
            break;
        case BRANCHZERO :
            Branch_Zero(operand,&SMLRegisters);
            break;
        //default :
          //  printf("wrong Entry\n");
           // break;
        }
}
//function pointers ??
void Read (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    word_t user_Input;
    scanf("%d",&user_Input);
    memory[operand]= user_Input;
}
void Write (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    printf("%d\n",memory[operand]);
}

void Load (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    SMLRegisters->accumulator = memory[operand];
}
void Store (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    memory[operand]=SMLRegisters->accumulator ;
}

void Add (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    //adding to accumulator
    SMLRegisters->accumulator +=  memory[operand];

}

void Sup (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    //subtracting from accumulator
    SMLRegisters->accumulator -= memory [operand];

}
void Div(word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    // accumulator / operand
    if(memory[operand]!=0)
    SMLRegisters->accumulator /= operand;
    else
        printf("dividing by zero");
}
void Mul (word_t operand , registers_t *SMLRegisters,word_t *memory)
{
    //multiplying by accumulator
    SMLRegisters->accumulator *= memory [operand];

}

void Branch(word_t operand , registers_t *SMLRegisters)
{
    SMLRegisters->instructionCounter = operand ;
}
void Branch_Neg (word_t operand , registers_t *SMLRegisters)
{
    if(SMLRegisters->accumulator<0)
    {
        SMLRegisters->instructionCounter = operand ;
    }
}
void Branch_Zero (word_t operand , registers_t *SMLRegisters)
{
    if(SMLRegisters->accumulator==0)
    {
        SMLRegisters->instructionCounter = operand ;
    }
}
