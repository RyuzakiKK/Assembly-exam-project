#include <stdio.h>

/*Convert a number to ASCII characters string.*/

void main()
{
	int Num = 10;
	char Result[12];
	__asm {
		XOR ECX,ECX
		MOV EBX,10
		MOV EAX,Num
		CMP EAX,0
		JGE Y1
		NEG EAX
Y1:		XOR EDX,EDX
		DIV EBX
		ADD EDX,48
		PUSH EDX
		INC ECX
		CMP EAX,0
		JNZ Y1
		XOR EBX,EBX
		CMP Num,0
		JGE POP1
		MOV Result[EBX],45
		INC EBX
POP1:	POP DWORD PTR Result[EBX]
		INC EBX
		LOOP POP1
		MOV Result[EBX],0
	}
	printf("The number %d is %s \n", Num,Result);
}
