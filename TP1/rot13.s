	.file	"rot13.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$18032, %esp
	.cfi_offset 3, -12
	movl	%gs:20, %eax
	movl	%eax, 18028(%esp)
	xorl	%eax, %eax
	movl	stdin, %eax
	movl	%eax, 8(%esp)
	movl	$64, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	fgets
	movl	$0, 24(%esp)
	jmp	.L2
.L6:
	leal	28(%esp), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$64, %al
	jle	.L3
	leal	28(%esp), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$90, %al
	jle	.L4
.L3:
	leal	28(%esp), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$96, %al
	jle	.L5
	leal	28(%esp), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$122, %al
	jg	.L5
.L4:
	leal	28(%esp), %edx
	movl	24(%esp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	leal	-84(%eax), %ecx
	movl	$1321528399, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	movl	%edx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	imull	$26, %eax, %eax
	movl	%ecx, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	addl	$97, %eax
	leal	28(%esp), %ecx
	movl	24(%esp), %edx
	addl	%ecx, %edx
	movb	%al, (%edx)
.L5:
	addl	$1, 24(%esp)
.L2:
	movl	24(%esp), %ebx
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	strlen
	cmpl	%eax, %ebx
	jb	.L6
	movl	stdout, %eax
	movl	%eax, 4(%esp)
	leal	28(%esp), %eax
	movl	%eax, (%esp)
	call	fputs
	movl	$10, (%esp)
	call	putchar
	movl	$0, %eax
	movl	18028(%esp), %ebx
	xorl	%gs:20, %ebx
	je	.L8
	call	__stack_chk_fail
.L8:
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
