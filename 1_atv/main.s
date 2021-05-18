;
; 1_individual_work.asm
;
; Created: 01/05/2021 14:40:54
; Author : MarcosVAdS (On GitHub)
;

start:
	;First, we need to save our array size m
	LDI R16,0x05 ;m value
	MOV R0, R16 ;move R16 value to R0

	;Now, we will save our a and b values
	LDI R17,0x02 ;a value
	LDI R18,0x01 ;b value
	MOV R1, R17 ;move R17 value to R1
	MOV R2, R18 ;move R18 value to R2

	CLR R16
	CLR R17 ;clear data
	CLR R18

	LDI R20, 0x00 ;Create a pointer of array size
	;All initial values are defined

	RCALL func

func:
	;Let's create a pointer to next position of our array
	;LDI R19, 900 ;Here we save our initial value of memory as 900 in decimal. 
	;MOV R3, R19
	;CLR	R19
	;That way we can only add 1 to the next position

	MOV R18, R0 ;get m value
	MOV R19, R1 ;get a value
	MOV R20, R2 ;get b value

	;Let's multiply a * n
	MUL R19,R20




	;And finally, save our array value, which is given by: x[n]= a * n + b
	RET ;Function return and exit
loop:
	RJMP loop