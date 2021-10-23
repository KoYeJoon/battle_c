	.arch armv6
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"02.option-S.c"
	.global	a
	.data
	.align	2
	.type	a, %object
	.size	a, 4
a:
	.word	10
	.comm	b,4,4
	.global	a2
	.align	2
	.type	a2, %object
	.size	a2, 4
a2:
	.word	20
	.comm	b2,4,4
	.text
	.align	2
	.global	f1
	.type	f1, %function
f1:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	f1, .-f1
	.section	.rodata
	.align	2
.LC0:
	.ascii	"hello\000"
	.align	2
.LC1:
	.ascii	"a:%d, a2:%d, b:%d, b2:%d, c:%d, c2:%d\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #32
	mov	r3, #100
	str	r3, [fp, #-8]
	ldr	r3, .L5
	str	r3, [fp, #-12]
	ldr	r3, .L5+4
	ldr	r1, [r3]
	ldr	r3, .L5+8
	ldr	r2, [r3]
	ldr	r3, .L5+12
	ldr	ip, [r3]
	ldr	r3, .L5+16
	ldr	r3, [r3]
	str	r3, [sp]
	ldr	r3, [fp, #-8]
	str	r3, [sp, #4]
	ldr	r3, [fp, #-16]
	str	r3, [sp, #8]
	ldr	r0, .L5+20
	mov	r3, ip
	bl	printf
	ldr	r3, .L5+4
	ldr	r3, [r3]
	mov	r0, r3
	bl	f1
	mov	r2, r0
	ldr	r3, .L5+12
	str	r2, [r3]
	ldr	r3, .L5+8
	ldr	r3, [r3]
	mov	r0, r3
	bl	f2
	mov	r2, r0
	ldr	r3, .L5+16
	str	r2, [r3]
	ldr	r0, [fp, #-8]
	bl	f1
	str	r0, [fp, #-16]
	ldr	r3, .L5+4
	ldr	r1, [r3]
	ldr	r3, .L5+8
	ldr	r2, [r3]
	ldr	r3, .L5+12
	ldr	ip, [r3]
	ldr	r3, .L5+16
	ldr	r3, [r3]
	str	r3, [sp]
	ldr	r3, [fp, #-8]
	str	r3, [sp, #4]
	ldr	r3, [fp, #-16]
	str	r3, [sp, #8]
	ldr	r0, .L5+20
	mov	r3, ip
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, pc}
.L6:
	.align	2
.L5:
	.word	.LC0
	.word	a
	.word	a2
	.word	b
	.word	b2
	.word	.LC1
	.size	main, .-main
	.align	2
	.global	f2
	.type	f2, %function
f2:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	ldr	r3, [fp, #-8]
	sub	r3, r3, #1
	str	r3, [fp, #-8]
	ldr	r3, [fp, #-8]
	mov	r0, r3
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	f2, .-f2
	.ident	"GCC: (Raspbian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",%progbits
