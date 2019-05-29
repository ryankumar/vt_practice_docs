	.file	"start_end_address.c"
	.section	.rodata
.LC0:
	.string	"start address:0x%1x\n"
.LC1:
	.string	"end address:0x%1x\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$__executable_start, %eax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$__etext, %eax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	call	getchar
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.5.0-12ubuntu1~16.04) 5.5.0 20171010"
	.section	.note.GNU-stack,"",@progbits
