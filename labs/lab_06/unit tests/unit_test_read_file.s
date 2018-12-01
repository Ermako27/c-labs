	.file	"unit_test_read_file.c"
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
	.text
	.globl	read_file
	.def	read_file;	.scl	2;	.type	32;	.endef
	.seh_proc	read_file
read_file:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, 32(%rbp)
	je	.L2
	movq	32(%rbp), %rax
	movl	$0, (%rax)
.L2:
	cmpq	$0, 24(%rbp)
	je	.L3
	cmpq	$0, 32(%rbp)
	je	.L3
	cmpq	$0, 16(%rbp)
	jne	.L4
.L3:
	movl	$-1, %eax
	jmp	.L10
.L4:
	leaq	-12(%rbp), %rax
	movq	%rax, %r8
	leaq	.LC0(%rip), %rdx
	movq	16(%rbp), %rcx
	call	fscanf
	cmpl	$1, %eax
	je	.L7
	movl	$-2, %eax
	jmp	.L10
.L9:
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$99, %eax
	jg	.L8
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -8(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	movq	32(%rbp), %rax
	movl	%edx, (%rax)
	jmp	.L7
.L8:
	movl	$-3, %eax
	jmp	.L10
.L7:
	leaq	-12(%rbp), %rax
	movq	%rax, %r8
	leaq	.LC0(%rip), %rdx
	movq	16(%rbp), %rcx
	call	fscanf
	cmpl	$1, %eax
	je	.L9
	movl	$0, %eax
.L10:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "r\0"
.LC2:
	.ascii "test.1.txt\0"
.LC3:
	.ascii "test.5.txt\0"
.LC4:
	.ascii "test.2.txt\0"
.LC5:
	.ascii "test.3.txt\0"
.LC6:
	.ascii "test.4.txt\0"
.LC7:
	.ascii "test.8.txt\0"
.LC8:
	.ascii "FAILED\0"
.LC9:
	.ascii "OK\0"
.LC10:
	.ascii "%s: %s\12\0"
	.text
	.globl	test_read
	.def	test_read;	.scl	2;	.type	32;	.endef
	.seh_proc	test_read
test_read:
	pushq	%rbp
	.seh_pushreg	%rbp
	subq	$512, %rsp
	.seh_stackalloc	512
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	$0, 380(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	fopen
	movq	%rax, 368(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	fopen
	movq	%rax, 360(%rbp)
	leaq	-84(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %r8
	movq	%rax, %rdx
	movl	$0, %ecx
	call	read_file
	cmpl	$-1, %eax
	je	.L12
	addl	$1, 380(%rbp)
.L12:
	leaq	-84(%rbp), %rdx
	movq	368(%rbp), %rax
	movq	%rdx, %r8
	movl	$0, %edx
	movq	%rax, %rcx
	call	read_file
	cmpl	$-1, %eax
	je	.L13
	addl	$1, 380(%rbp)
	movq	368(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
.L13:
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	fopen
	movq	%rax, 368(%rbp)
	leaq	-80(%rbp), %rdx
	movq	368(%rbp), %rax
	movl	$0, %r8d
	movq	%rax, %rcx
	call	read_file
	cmpl	$-1, %eax
	je	.L14
	addl	$1, 380(%rbp)
	movq	368(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
.L14:
	leaq	-84(%rbp), %rcx
	leaq	-80(%rbp), %rdx
	movq	360(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	read_file
	cmpl	$-2, %eax
	je	.L15
	addl	$1, 380(%rbp)
.L15:
	leaq	.LC1(%rip), %rdx
	leaq	.LC4(%rip), %rcx
	call	fopen
	movq	%rax, 352(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC5(%rip), %rcx
	call	fopen
	movq	%rax, 344(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC6(%rip), %rcx
	call	fopen
	movq	%rax, 336(%rbp)
	leaq	.LC1(%rip), %rdx
	leaq	.LC7(%rip), %rcx
	call	fopen
	movq	%rax, 328(%rbp)
	leaq	-84(%rbp), %rcx
	leaq	-80(%rbp), %rdx
	movq	352(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	read_file
	testl	%eax, %eax
	je	.L16
	addl	$1, 380(%rbp)
.L16:
	leaq	-84(%rbp), %rcx
	leaq	-80(%rbp), %rdx
	movq	344(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	read_file
	testl	%eax, %eax
	je	.L17
	addl	$1, 380(%rbp)
.L17:
	leaq	-84(%rbp), %rcx
	leaq	-80(%rbp), %rdx
	movq	336(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	read_file
	testl	%eax, %eax
	je	.L18
	addl	$1, 380(%rbp)
.L18:
	leaq	-84(%rbp), %rcx
	leaq	-80(%rbp), %rdx
	movq	328(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	read_file
	cmpl	$-3, %eax
	je	.L19
	addl	$1, 380(%rbp)
.L19:
	movq	352(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	344(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	336(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	328(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movq	360(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	cmpl	$0, 380(%rbp)
	je	.L20
	leaq	.LC8(%rip), %rax
	jmp	.L21
.L20:
	leaq	.LC9(%rip), %rax
.L21:
	movq	%rax, %r8
	leaq	__func__.2941(%rip), %rdx
	leaq	.LC10(%rip), %rcx
	call	printf
	nop
	addq	$512, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	call	test_read
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
__func__.2941:
	.ascii "test_read\0"
	.ident	"GCC: (GNU) 6.3.0"
	.def	fscanf;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
