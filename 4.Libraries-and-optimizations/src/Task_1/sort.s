	.file	"sort.c"
	.text
	.globl	sort                            // -- Begin function sort
	.p2align	2
	.type	sort,@function
sort:                                   // @sort
// %bb.0:
	sub	sp, sp, #448
	stp	x28, x21, [sp, #416]            // 16-byte Folded Spill
	subs	w21, w1, #1
	stp	x29, x30, [sp, #400]            // 16-byte Folded Spill
	add	x29, sp, #400
	stp	x20, x19, [sp, #432]            // 16-byte Folded Spill
	b.lt	.LBB0_11
// %bb.1:
	mov	w20, w1
	mov	x19, x0
	mov	x0, sp
	ubfiz	x2, x20, #2, #32
	mov	x1, x19
	bl	memcpy
	mov	w8, wzr
	add	x9, x19, #4
	b	.LBB0_3
.LBB0_2:                                //   in Loop: Header=BB0_3 Depth=1
	add	w8, w8, #1
	sub	w21, w10, #1
	cmp	w8, w20
	b.eq	.LBB0_9
.LBB0_3:                                // =>This Loop Header: Depth=1
                                        //     Child Loop BB0_7 Depth 2
	sub	w10, w8, w20
	cmn	w10, #2
	mov	w10, w21
	b.gt	.LBB0_2
// %bb.4:                               //   in Loop: Header=BB0_3 Depth=1
	ldr	w11, [x19]
	mov	x12, x10
	mov	x13, x9
	b	.LBB0_7
.LBB0_5:                                //   in Loop: Header=BB0_7 Depth=2
	stp	w14, w11, [x13, #-4]
.LBB0_6:                                //   in Loop: Header=BB0_7 Depth=2
	subs	x12, x12, #1
	add	x13, x13, #4
	b.eq	.LBB0_2
.LBB0_7:                                //   Parent Loop BB0_3 Depth=1
                                        // =>  This Inner Loop Header: Depth=2
	ldr	w14, [x13]
	cmp	w11, w14
	b.gt	.LBB0_5
// %bb.8:                               //   in Loop: Header=BB0_7 Depth=2
	mov	w11, w14
	b	.LBB0_6
.LBB0_9:
	cmp	w20, #8
	mov	w8, w20
	b.hs	.LBB0_12
// %bb.10:
	mov	x9, xzr
	mov	w0, wzr
	b	.LBB0_15
.LBB0_11:
	mov	w0, wzr
	b	.LBB0_17
.LBB0_12:
	movi	v0.2d, #0000000000000000
	movi	v1.2d, #0000000000000000
	and	x9, x8, #0x7ffffff8
	mov	x11, sp
	add	x10, x19, #16
	mov	x12, x9
	add	x11, x11, #16
.LBB0_13:                               // =>This Inner Loop Header: Depth=1
	ldp	q2, q3, [x10, #-16]
	subs	x12, x12, #8
	ldp	q4, q5, [x11, #-16]
	add	x10, x10, #32
	add	x11, x11, #32
	cmeq	v2.4s, v2.4s, v4.4s
	cmeq	v3.4s, v3.4s, v5.4s
	mvn	v2.16b, v2.16b
	mvn	v3.16b, v3.16b
	sub	v0.4s, v0.4s, v2.4s
	sub	v1.4s, v1.4s, v3.4s
	b.ne	.LBB0_13
// %bb.14:
	add	v0.4s, v1.4s, v0.4s
	cmp	x9, x8
	addv	s0, v0.4s
	fmov	w0, s0
	b.eq	.LBB0_17
.LBB0_15:
	lsl	x11, x9, #2
	mov	x10, sp
	sub	x8, x8, x9
	add	x10, x10, x11
	add	x11, x19, x11
.LBB0_16:                               // =>This Inner Loop Header: Depth=1
	ldr	w9, [x11], #4
	ldr	w12, [x10], #4
	cmp	w9, w12
	cinc	w0, w0, ne
	subs	x8, x8, #1
	b.ne	.LBB0_16
.LBB0_17:
	ldp	x20, x19, [sp, #432]            // 16-byte Folded Reload
	ldp	x28, x21, [sp, #416]            // 16-byte Folded Reload
	ldp	x29, x30, [sp, #400]            // 16-byte Folded Reload
	add	sp, sp, #448
	ret
.Lfunc_end0:
	.size	sort, .Lfunc_end0-sort
                                        // -- End function
	.ident	"clang version 20.1.8"
	.section	".note.GNU-stack","",@progbits
