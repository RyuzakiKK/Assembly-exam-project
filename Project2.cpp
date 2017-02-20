#include <stdio.h>

/* Given n, generate n Fibonacci numbers */

void main()
{
	int n=0;
	int successione[50];

	__asm {
		MOV successione[0],0
		CMP n,0
		JE F1
		MOV successione[4],1
		CMP n,1
		JE F1
		XOR ECX,ECX
N1:		MOV EAX,successione[ECX*4]
		ADD EAX,successione[ECX*4+4]
		MOV successione[ECX*4+8],EAX
		INC ECX
		CMP n,ECX
F1:		JNE N1
	}

	int i;
	for(i=0;i<=n;i++) printf("%d\n",successione[i]);
}
