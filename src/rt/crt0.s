.text
.global _start
_start:
	xor %rbp, %rbp
	movq %rsp, %rdi
	andq $-16, %rsp
	call start_linux

