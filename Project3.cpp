#include <stdio.h>

/* Compress to a run-length a bytes sequence. */

void main()
{
	#define MaxLen 1024
	int Len = 258;
	unsigned char Buffer[MaxLen] = {97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,255};
	#define MaxLenComp (MaxLen*2+1)
	unsigned char BufComp[MaxLenComp];

	__asm {
		XOR ECX,ECX // Index old array
		XOR EDX,EDX // Index new array
S1:		CMP ECX,Len
		JE F1
		XOR EBX,EBX // Index equal numbers
		MOV AL,Buffer[ECX]
E1:		CMP EBX,255
		JE N1
		INC ECX
		INC EBX
		CMP AL,Buffer[ECX]
		JE E1
N1:		MOV BufComp[EDX],BL
		MOV BufComp[EDX+1],AL
		ADD EDX,2
		JMP S1
F1:		MOV BufComp[EDX],0
	}

	int i;
	for(i=0;i<Len;i++) printf("%02X ",Buffer[i]);
	printf("\n");
	for (i=0;BufComp[i];) {
		printf("%3d ",BufComp[i++]);
		printf("%02X ",BufComp[i++]);
	}
	printf("\n");
}
