	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"01.option-E.c"
	.global	gv1
	.data
	.align	2
	.type	gv1, %object
	.size	gv1, 4
gv1:
	.word	10
	.global	gv2
	.align	2
	.type	gv2, %object
	.size	gv2, 4
gv2:
	.word	20
	.comm	gv3,4,4
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Main Start..\000"
	.align	2
.LC1:
	.ascii	"lv1:%d, lv2:%d, lv3:%d\012\000"
	.align	2
.LC2:
	.ascii	"Main End...\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #16
	mov	r3, #1
	str	r3, [fp, #-8]
	mov	r3, #2
	str	r3, [fp, #-12]
	ldr	r0, .L3
	bl	puts
	mov	r3, #1000
	str	r3, [fp, #-16]
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-12]
	ldr	r1, [fp, #-8]
	ldr	r0, .L3+4
	bl	printf
	ldr	r0, .L3+8
	bl	puts
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L4:
	.align	2
.L3:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.size	main, .-main
	.ident	"GCC: (Raspbian 6.3.0-18+rpi1+deb9u1) 6.3.0 20170516"
	.section	.note.GNU-stack,"",%progbits
