
build.hex:     file format ihex


Disassembly of section .sec1:

00000000 <.sec1>:
   0:	0c 94 2b 00 	jmp	0x56	;  0x56
   4:	0c 94 53 00 	jmp	0xa6	;  0xa6
   8:	0c 94 53 00 	jmp	0xa6	;  0xa6
   c:	0c 94 53 00 	jmp	0xa6	;  0xa6
  10:	0c 94 53 00 	jmp	0xa6	;  0xa6
  14:	0c 94 53 00 	jmp	0xa6	;  0xa6
  18:	0c 94 53 00 	jmp	0xa6	;  0xa6
  1c:	0c 94 53 00 	jmp	0xa6	;  0xa6
  20:	0c 94 53 00 	jmp	0xa6	;  0xa6
  24:	0c 94 53 00 	jmp	0xa6	;  0xa6
  28:	0c 94 53 00 	jmp	0xa6	;  0xa6
  2c:	0c 94 53 00 	jmp	0xa6	;  0xa6
  30:	0c 94 53 00 	jmp	0xa6	;  0xa6
  34:	0c 94 53 00 	jmp	0xa6	;  0xa6
  38:	0c 94 53 00 	jmp	0xa6	;  0xa6
  3c:	0c 94 53 00 	jmp	0xa6	;  0xa6
  40:	0c 94 53 00 	jmp	0xa6	;  0xa6
  44:	0c 94 53 00 	jmp	0xa6	;  0xa6
  48:	0c 94 53 00 	jmp	0xa6	;  0xa6
  4c:	0c 94 53 00 	jmp	0xa6	;  0xa6
  50:	0c 94 53 00 	jmp	0xa6	;  0xa6
  54:	af 03       	fmulsu	r18, r23
  56:	11 24       	eor	r1, r1
  58:	1f be       	out	0x3f, r1	; 63
  5a:	cf e5       	ldi	r28, 0x5F	; 95
  5c:	d4 e0       	ldi	r29, 0x04	; 4
  5e:	de bf       	out	0x3e, r29	; 62
  60:	cd bf       	out	0x3d, r28	; 61
  62:	12 e0       	ldi	r17, 0x02	; 2
  64:	a0 e6       	ldi	r26, 0x60	; 96
  66:	b0 e0       	ldi	r27, 0x00	; 0
  68:	ea e3       	ldi	r30, 0x3A	; 58
  6a:	fd e0       	ldi	r31, 0x0D	; 13
  6c:	02 c0       	rjmp	.+4      	;  0x72
  6e:	05 90       	lpm	r0, Z+
  70:	0d 92       	st	X+, r0
  72:	a6 3e       	cpi	r26, 0xE6	; 230
  74:	b1 07       	cpc	r27, r17
  76:	d9 f7       	brne	.-10     	;  0x6e
  78:	12 e0       	ldi	r17, 0x02	; 2
  7a:	a6 ee       	ldi	r26, 0xE6	; 230
  7c:	b2 e0       	ldi	r27, 0x02	; 2
  7e:	01 c0       	rjmp	.+2      	;  0x82
  80:	1d 92       	st	X+, r1
  82:	a7 3e       	cpi	r26, 0xE7	; 231
  84:	b1 07       	cpc	r27, r17
  86:	e1 f7       	brne	.-8      	;  0x80
  88:	10 e0       	ldi	r17, 0x00	; 0
  8a:	c6 e5       	ldi	r28, 0x56	; 86
  8c:	d0 e0       	ldi	r29, 0x00	; 0
  8e:	04 c0       	rjmp	.+8      	;  0x98
  90:	22 97       	sbiw	r28, 0x02	; 2
  92:	fe 01       	movw	r30, r28
  94:	0e 94 b6 03 	call	0x76c	;  0x76c
  98:	c4 35       	cpi	r28, 0x54	; 84
  9a:	d1 07       	cpc	r29, r17
  9c:	c9 f7       	brne	.-14     	;  0x90
  9e:	0e 94 90 03 	call	0x720	;  0x720
  a2:	0c 94 9b 06 	jmp	0xd36	;  0xd36
  a6:	0c 94 00 00 	jmp	0	;  0x0
  aa:	85 b3       	in	r24, 0x15	; 21
  ac:	15 ba       	out	0x15, r1	; 21
  ae:	41 30       	cpi	r20, 0x01	; 1
  b0:	79 f4       	brne	.+30     	;  0xd0
  b2:	95 98       	cbi	0x12, 5	; 18
  b4:	96 9a       	sbi	0x12, 6	; 18
  b6:	65 bb       	out	0x15, r22	; 21
  b8:	94 9a       	sbi	0x12, 4	; 18
  ba:	8a e1       	ldi	r24, 0x1A	; 26
  bc:	8a 95       	dec	r24
  be:	f1 f7       	brne	.-4      	;  0xbc
  c0:	00 c0       	rjmp	.+0      	;  0xc2
  c2:	94 98       	cbi	0x12, 4	; 18
  c4:	8a e1       	ldi	r24, 0x1A	; 26
  c6:	8a 95       	dec	r24
  c8:	f1 f7       	brne	.-4      	;  0xc6
  ca:	00 c0       	rjmp	.+0      	;  0xcc
  cc:	94 9a       	sbi	0x12, 4	; 18
  ce:	08 95       	ret
  d0:	44 23       	and	r20, r20
  d2:	71 f4       	brne	.+28     	;  0xf0
  d4:	95 98       	cbi	0x12, 5	; 18
  d6:	96 98       	cbi	0x12, 6	; 18
  d8:	65 bb       	out	0x15, r22	; 21
  da:	94 9a       	sbi	0x12, 4	; 18
  dc:	8a e1       	ldi	r24, 0x1A	; 26
  de:	8a 95       	dec	r24
  e0:	f1 f7       	brne	.-4      	;  0xde
  e2:	00 c0       	rjmp	.+0      	;  0xe4
  e4:	94 98       	cbi	0x12, 4	; 18
  e6:	8a e1       	ldi	r24, 0x1A	; 26
  e8:	8a 95       	dec	r24
  ea:	f1 f7       	brne	.-4      	;  0xe8
  ec:	00 c0       	rjmp	.+0      	;  0xee
  ee:	94 9a       	sbi	0x12, 4	; 18
  f0:	08 95       	ret
  f2:	60 58       	subi	r22, 0x80	; 128
  f4:	40 e0       	ldi	r20, 0x00	; 0
  f6:	0e 94 55 00 	call	0xaa	;  0xaa
  fa:	08 95       	ret
  fc:	ff 92       	push	r15
  fe:	0f 93       	push	r16
 100:	1f 93       	push	r17
 102:	cf 93       	push	r28
 104:	df 93       	push	r29
 106:	ec 01       	movw	r28, r24
 108:	04 2f       	mov	r16, r20
 10a:	61 50       	subi	r22, 0x01	; 1
 10c:	66 30       	cpi	r22, 0x06	; 6
 10e:	30 f4       	brcc	.+12     	;  0x11c
 110:	e6 2f       	mov	r30, r22
 112:	f0 e0       	ldi	r31, 0x00	; 0
 114:	e1 52       	subi	r30, 0x21	; 33
 116:	fd 4f       	sbci	r31, 0xFD	; 253
 118:	10 81       	ld	r17, Z
 11a:	01 c0       	rjmp	.+2      	;  0x11e
 11c:	10 e0       	ldi	r17, 0x00	; 0
 11e:	f1 2e       	mov	r15, r17
 120:	f2 94       	swap	r15
 122:	8f e0       	ldi	r24, 0x0F	; 15
 124:	f8 22       	and	r15, r24
 126:	ce 01       	movw	r24, r28
 128:	66 eb       	ldi	r22, 0xB6	; 182
 12a:	40 e0       	ldi	r20, 0x00	; 0
 12c:	0e 94 55 00 	call	0xaa	;  0xaa
 130:	6f 2d       	mov	r22, r15
 132:	60 61       	ori	r22, 0x10	; 16
 134:	ce 01       	movw	r24, r28
 136:	40 e0       	ldi	r20, 0x00	; 0
 138:	0e 94 55 00 	call	0xaa	;  0xaa
 13c:	61 2f       	mov	r22, r17
 13e:	6f 70       	andi	r22, 0x0F	; 15
 140:	ce 01       	movw	r24, r28
 142:	40 e0       	ldi	r20, 0x00	; 0
 144:	0e 94 55 00 	call	0xaa	;  0xaa
 148:	ce 01       	movw	r24, r28
 14a:	60 2f       	mov	r22, r16
 14c:	41 e0       	ldi	r20, 0x01	; 1
 14e:	0e 94 55 00 	call	0xaa	;  0xaa
 152:	df 91       	pop	r29
 154:	cf 91       	pop	r28
 156:	1f 91       	pop	r17
 158:	0f 91       	pop	r16
 15a:	ff 90       	pop	r15
 15c:	08 95       	ret
 15e:	21 e0       	ldi	r18, 0x01	; 1
 160:	62 27       	eor	r22, r18
 162:	6a 55       	subi	r22, 0x5A	; 90
 164:	40 e0       	ldi	r20, 0x00	; 0
 166:	0e 94 55 00 	call	0xaa	;  0xaa
 16a:	08 95       	ret
 16c:	0f 93       	push	r16
 16e:	1f 93       	push	r17
 170:	cf 93       	push	r28
 172:	df 93       	push	r29
 174:	8c 01       	movw	r16, r24
 176:	c6 2f       	mov	r28, r22
 178:	d0 e0       	ldi	r29, 0x00	; 0
 17a:	be 01       	movw	r22, r28
 17c:	94 e0       	ldi	r25, 0x04	; 4
 17e:	75 95       	asr	r23
 180:	67 95       	ror	r22
 182:	9a 95       	dec	r25
 184:	e1 f7       	brne	.-8      	;  0x17e
 186:	60 61       	ori	r22, 0x10	; 16
 188:	c8 01       	movw	r24, r16
 18a:	40 e0       	ldi	r20, 0x00	; 0
 18c:	0e 94 55 00 	call	0xaa	;  0xaa
 190:	be 01       	movw	r22, r28
 192:	6f 70       	andi	r22, 0x0F	; 15
 194:	70 70       	andi	r23, 0x00	; 0
 196:	c8 01       	movw	r24, r16
 198:	40 e0       	ldi	r20, 0x00	; 0
 19a:	0e 94 55 00 	call	0xaa	;  0xaa
 19e:	df 91       	pop	r29
 1a0:	cf 91       	pop	r28
 1a2:	1f 91       	pop	r17
 1a4:	0f 91       	pop	r16
 1a6:	08 95       	ret
 1a8:	60 6b       	ori	r22, 0xB0	; 176
 1aa:	40 e0       	ldi	r20, 0x00	; 0
 1ac:	0e 94 55 00 	call	0xaa	;  0xaa
 1b0:	08 95       	ret
 1b2:	70 e0       	ldi	r23, 0x00	; 0
 1b4:	62 55       	subi	r22, 0x52	; 82
 1b6:	7f 4f       	sbci	r23, 0xFF	; 255
 1b8:	40 e0       	ldi	r20, 0x00	; 0
 1ba:	0e 94 55 00 	call	0xaa	;  0xaa
 1be:	08 95       	ret
 1c0:	0f 93       	push	r16
 1c2:	1f 93       	push	r17
 1c4:	df 93       	push	r29
 1c6:	cf 93       	push	r28
 1c8:	0f 92       	push	r0
 1ca:	cd b7       	in	r28, 0x3d	; 61
 1cc:	de b7       	in	r29, 0x3e	; 62
 1ce:	8c 01       	movw	r16, r24
 1d0:	65 36       	cpi	r22, 0x65	; 101
 1d2:	08 f0       	brcs	.+2      	;  0x1d6
 1d4:	64 e6       	ldi	r22, 0x64	; 100
 1d6:	c8 01       	movw	r24, r16
 1d8:	49 83       	std	Y+1, r20	; 0x01
 1da:	0e 94 b6 00 	call	0x16c	;  0x16c
 1de:	49 81       	ldd	r20, Y+1	; 0x01
 1e0:	64 2f       	mov	r22, r20
 1e2:	47 30       	cpi	r20, 0x07	; 7
 1e4:	08 f0       	brcs	.+2      	;  0x1e8
 1e6:	66 e0       	ldi	r22, 0x06	; 6
 1e8:	c8 01       	movw	r24, r16
 1ea:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 1ee:	0f 90       	pop	r0
 1f0:	cf 91       	pop	r28
 1f2:	df 91       	pop	r29
 1f4:	1f 91       	pop	r17
 1f6:	0f 91       	pop	r16
 1f8:	08 95       	ret
 1fa:	64 31       	cpi	r22, 0x14	; 20
 1fc:	48 f4       	brcc	.+18     	;  0x210
 1fe:	46 30       	cpi	r20, 0x06	; 6
 200:	38 f4       	brcc	.+14     	;  0x210
 202:	26 2f       	mov	r18, r22
 204:	22 0f       	add	r18, r18
 206:	22 0f       	add	r18, r18
 208:	26 0f       	add	r18, r22
 20a:	62 2f       	mov	r22, r18
 20c:	0e 94 e0 00 	call	0x1c0	;  0x1c0
 210:	08 95       	ret
 212:	60 e0       	ldi	r22, 0x00	; 0
 214:	40 e0       	ldi	r20, 0x00	; 0
 216:	0e 94 fd 00 	call	0x1fa	;  0x1fa
 21a:	08 95       	ret
 21c:	60 e0       	ldi	r22, 0x00	; 0
 21e:	0e 94 b6 00 	call	0x16c	;  0x16c
 222:	08 95       	ret
 224:	6f 92       	push	r6
 226:	7f 92       	push	r7
 228:	8f 92       	push	r8
 22a:	9f 92       	push	r9
 22c:	af 92       	push	r10
 22e:	bf 92       	push	r11
 230:	cf 92       	push	r12
 232:	df 92       	push	r13
 234:	ef 92       	push	r14
 236:	ff 92       	push	r15
 238:	0f 93       	push	r16
 23a:	1f 93       	push	r17
 23c:	df 93       	push	r29
 23e:	cf 93       	push	r28
 240:	0f 92       	push	r0
 242:	cd b7       	in	r28, 0x3d	; 61
 244:	de b7       	in	r29, 0x3e	; 62
 246:	8c 01       	movw	r16, r24
 248:	e6 2e       	mov	r14, r22
 24a:	a6 2f       	mov	r26, r22
 24c:	b7 2f       	mov	r27, r23
 24e:	fd 01       	movw	r30, r26
 250:	01 90       	ld	r0, Z+
 252:	00 20       	and	r0, r0
 254:	e9 f7       	brne	.-6      	;  0x250
 256:	31 97       	sbiw	r30, 0x01	; 1
 258:	ea 1b       	sub	r30, r26
 25a:	fb 0b       	sbc	r31, r27
 25c:	ce 2e       	mov	r12, r30
 25e:	df 2e       	mov	r13, r31
 260:	85 e1       	ldi	r24, 0x15	; 21
 262:	c8 16       	cp	r12, r24
 264:	d1 04       	cpc	r13, r1
 266:	1c f0       	brlt	.+6      	;  0x26e
 268:	54 e1       	ldi	r21, 0x14	; 20
 26a:	c5 2e       	mov	r12, r21
 26c:	d1 2c       	mov	r13, r1
 26e:	c8 01       	movw	r24, r16
 270:	60 ee       	ldi	r22, 0xE0	; 224
 272:	40 e0       	ldi	r20, 0x00	; 0
 274:	79 83       	std	Y+1, r23	; 0x01
 276:	0e 94 55 00 	call	0xaa	;  0xaa
 27a:	79 81       	ldd	r23, Y+1	; 0x01
 27c:	8e 2c       	mov	r8, r14
 27e:	97 2e       	mov	r9, r23
 280:	aa 24       	eor	r10, r10
 282:	bb 24       	eor	r11, r11
 284:	25 e0       	ldi	r18, 0x05	; 5
 286:	27 c0       	rjmp	.+78     	;  0x2d6
 288:	f4 01       	movw	r30, r8
 28a:	31 91       	ld	r19, Z+
 28c:	4f 01       	movw	r8, r30
 28e:	30 52       	subi	r19, 0x20	; 32
 290:	83 2f       	mov	r24, r19
 292:	90 e0       	ldi	r25, 0x00	; 0
 294:	3c 01       	movw	r6, r24
 296:	66 0c       	add	r6, r6
 298:	77 1c       	adc	r7, r7
 29a:	66 0c       	add	r6, r6
 29c:	77 1c       	adc	r7, r7
 29e:	68 0e       	add	r6, r24
 2a0:	79 1e       	adc	r7, r25
 2a2:	8f ef       	ldi	r24, 0xFF	; 255
 2a4:	90 e0       	ldi	r25, 0x00	; 0
 2a6:	68 0e       	add	r6, r24
 2a8:	79 1e       	adc	r7, r25
 2aa:	32 9f       	mul	r19, r18
 2ac:	70 01       	movw	r14, r0
 2ae:	11 24       	eor	r1, r1
 2b0:	e4 e0       	ldi	r30, 0x04	; 4
 2b2:	f1 e0       	ldi	r31, 0x01	; 1
 2b4:	ee 0e       	add	r14, r30
 2b6:	ff 1e       	adc	r15, r31
 2b8:	f3 01       	movw	r30, r6
 2ba:	61 91       	ld	r22, Z+
 2bc:	3f 01       	movw	r6, r30
 2be:	c8 01       	movw	r24, r16
 2c0:	41 e0       	ldi	r20, 0x01	; 1
 2c2:	29 83       	std	Y+1, r18	; 0x01
 2c4:	0e 94 55 00 	call	0xaa	;  0xaa
 2c8:	29 81       	ldd	r18, Y+1	; 0x01
 2ca:	6e 14       	cp	r6, r14
 2cc:	7f 04       	cpc	r7, r15
 2ce:	a1 f7       	brne	.-24     	;  0x2b8
 2d0:	08 94       	sec
 2d2:	a1 1c       	adc	r10, r1
 2d4:	b1 1c       	adc	r11, r1
 2d6:	ac 14       	cp	r10, r12
 2d8:	bd 04       	cpc	r11, r13
 2da:	b4 f2       	brlt	.-84     	;  0x288
 2dc:	c8 01       	movw	r24, r16
 2de:	6e ee       	ldi	r22, 0xEE	; 238
 2e0:	40 e0       	ldi	r20, 0x00	; 0
 2e2:	0e 94 55 00 	call	0xaa	;  0xaa
 2e6:	c8 01       	movw	r24, r16
 2e8:	0e 94 0e 01 	call	0x21c	;  0x21c
 2ec:	0f 90       	pop	r0
 2ee:	cf 91       	pop	r28
 2f0:	df 91       	pop	r29
 2f2:	1f 91       	pop	r17
 2f4:	0f 91       	pop	r16
 2f6:	ff 90       	pop	r15
 2f8:	ef 90       	pop	r14
 2fa:	df 90       	pop	r13
 2fc:	cf 90       	pop	r12
 2fe:	bf 90       	pop	r11
 300:	af 90       	pop	r10
 302:	9f 90       	pop	r9
 304:	8f 90       	pop	r8
 306:	7f 90       	pop	r7
 308:	6f 90       	pop	r6
 30a:	08 95       	ret
 30c:	0f 93       	push	r16
 30e:	1f 93       	push	r17
 310:	cf 93       	push	r28
 312:	df 93       	push	r29
 314:	8c 01       	movw	r16, r24
 316:	c0 e0       	ldi	r28, 0x00	; 0
 318:	d0 e0       	ldi	r29, 0x00	; 0
 31a:	c8 01       	movw	r24, r16
 31c:	6c 2f       	mov	r22, r28
 31e:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 322:	c8 01       	movw	r24, r16
 324:	60 e6       	ldi	r22, 0x60	; 96
 326:	70 e0       	ldi	r23, 0x00	; 0
 328:	0e 94 12 01 	call	0x224	;  0x224
 32c:	21 96       	adiw	r28, 0x01	; 1
 32e:	c6 30       	cpi	r28, 0x06	; 6
 330:	d1 05       	cpc	r29, r1
 332:	99 f7       	brne	.-26     	;  0x31a
 334:	df 91       	pop	r29
 336:	cf 91       	pop	r28
 338:	1f 91       	pop	r17
 33a:	0f 91       	pop	r16
 33c:	08 95       	ret
 33e:	cf 93       	push	r28
 340:	df 93       	push	r29
 342:	ec 01       	movw	r28, r24
 344:	62 ee       	ldi	r22, 0xE2	; 226
 346:	40 e0       	ldi	r20, 0x00	; 0
 348:	0e 94 55 00 	call	0xaa	;  0xaa
 34c:	8f ef       	ldi	r24, 0xFF	; 255
 34e:	99 e6       	ldi	r25, 0x69	; 105
 350:	a8 e1       	ldi	r26, 0x18	; 24
 352:	81 50       	subi	r24, 0x01	; 1
 354:	90 40       	sbci	r25, 0x00	; 0
 356:	a0 40       	sbci	r26, 0x00	; 0
 358:	e1 f7       	brne	.-8      	;  0x352
 35a:	00 c0       	rjmp	.+0      	;  0x35c
 35c:	00 00       	nop
 35e:	ce 01       	movw	r24, r28
 360:	61 ea       	ldi	r22, 0xA1	; 161
 362:	40 e0       	ldi	r20, 0x00	; 0
 364:	0e 94 55 00 	call	0xaa	;  0xaa
 368:	ce 01       	movw	r24, r28
 36a:	62 ea       	ldi	r22, 0xA2	; 162
 36c:	40 e0       	ldi	r20, 0x00	; 0
 36e:	0e 94 55 00 	call	0xaa	;  0xaa
 372:	ce 01       	movw	r24, r28
 374:	6c e2       	ldi	r22, 0x2C	; 44
 376:	40 e0       	ldi	r20, 0x00	; 0
 378:	0e 94 55 00 	call	0xaa	;  0xaa
 37c:	ce 01       	movw	r24, r28
 37e:	6e e2       	ldi	r22, 0x2E	; 46
 380:	40 e0       	ldi	r20, 0x00	; 0
 382:	0e 94 55 00 	call	0xaa	;  0xaa
 386:	ce 01       	movw	r24, r28
 388:	6f e2       	ldi	r22, 0x2F	; 47
 38a:	40 e0       	ldi	r20, 0x00	; 0
 38c:	0e 94 55 00 	call	0xaa	;  0xaa
 390:	ce 01       	movw	r24, r28
 392:	66 ea       	ldi	r22, 0xA6	; 166
 394:	40 e0       	ldi	r20, 0x00	; 0
 396:	0e 94 55 00 	call	0xaa	;  0xaa
 39a:	ce 01       	movw	r24, r28
 39c:	6f e8       	ldi	r22, 0x8F	; 143
 39e:	40 e0       	ldi	r20, 0x00	; 0
 3a0:	0e 94 55 00 	call	0xaa	;  0xaa
 3a4:	ce 01       	movw	r24, r28
 3a6:	64 ea       	ldi	r22, 0xA4	; 164
 3a8:	40 e0       	ldi	r20, 0x00	; 0
 3aa:	0e 94 55 00 	call	0xaa	;  0xaa
 3ae:	ce 01       	movw	r24, r28
 3b0:	6f ea       	ldi	r22, 0xAF	; 175
 3b2:	40 e0       	ldi	r20, 0x00	; 0
 3b4:	0e 94 55 00 	call	0xaa	;  0xaa
 3b8:	ce 01       	movw	r24, r28
 3ba:	60 e4       	ldi	r22, 0x40	; 64
 3bc:	40 e0       	ldi	r20, 0x00	; 0
 3be:	0e 94 55 00 	call	0xaa	;  0xaa
 3c2:	ce 01       	movw	r24, r28
 3c4:	0e 94 86 01 	call	0x30c	;  0x30c
 3c8:	df 91       	pop	r29
 3ca:	cf 91       	pop	r28
 3cc:	08 95       	ret
 3ce:	21 b3       	in	r18, 0x11	; 17
 3d0:	28 67       	ori	r18, 0x78	; 120
 3d2:	21 bb       	out	0x11, r18	; 17
 3d4:	2f ef       	ldi	r18, 0xFF	; 255
 3d6:	24 bb       	out	0x14, r18	; 20
 3d8:	93 98       	cbi	0x12, 3	; 18
 3da:	2f ef       	ldi	r18, 0xFF	; 255
 3dc:	30 e7       	ldi	r19, 0x70	; 112
 3de:	42 e0       	ldi	r20, 0x02	; 2
 3e0:	21 50       	subi	r18, 0x01	; 1
 3e2:	30 40       	sbci	r19, 0x00	; 0
 3e4:	40 40       	sbci	r20, 0x00	; 0
 3e6:	e1 f7       	brne	.-8      	;  0x3e0
 3e8:	00 c0       	rjmp	.+0      	;  0x3ea
 3ea:	00 00       	nop
 3ec:	93 9a       	sbi	0x12, 3	; 18
 3ee:	2f ef       	ldi	r18, 0xFF	; 255
 3f0:	30 e7       	ldi	r19, 0x70	; 112
 3f2:	42 e0       	ldi	r20, 0x02	; 2
 3f4:	21 50       	subi	r18, 0x01	; 1
 3f6:	30 40       	sbci	r19, 0x00	; 0
 3f8:	40 40       	sbci	r20, 0x00	; 0
 3fa:	e1 f7       	brne	.-8      	;  0x3f4
 3fc:	00 c0       	rjmp	.+0      	;  0x3fe
 3fe:	00 00       	nop
 400:	0e 94 9f 01 	call	0x33e	;  0x33e
 404:	8f ef       	ldi	r24, 0xFF	; 255
 406:	90 e7       	ldi	r25, 0x70	; 112
 408:	a2 e0       	ldi	r26, 0x02	; 2
 40a:	81 50       	subi	r24, 0x01	; 1
 40c:	90 40       	sbci	r25, 0x00	; 0
 40e:	a0 40       	sbci	r26, 0x00	; 0
 410:	e1 f7       	brne	.-8      	;  0x40a
 412:	00 c0       	rjmp	.+0      	;  0x414
 414:	00 00       	nop
 416:	08 95       	ret
 418:	60 e0       	ldi	r22, 0x00	; 0
 41a:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 41e:	08 95       	ret
 420:	96 9a       	sbi	0x12, 6	; 18
 422:	94 9a       	sbi	0x12, 4	; 18
 424:	95 9a       	sbi	0x12, 5	; 18
 426:	8f e7       	ldi	r24, 0x7F	; 127
 428:	9a e1       	ldi	r25, 0x1A	; 26
 42a:	a6 e0       	ldi	r26, 0x06	; 6
 42c:	81 50       	subi	r24, 0x01	; 1
 42e:	90 40       	sbci	r25, 0x00	; 0
 430:	a0 40       	sbci	r26, 0x00	; 0
 432:	e1 f7       	brne	.-8      	;  0x42c
 434:	00 c0       	rjmp	.+0      	;  0x436
 436:	00 00       	nop
 438:	96 98       	cbi	0x12, 6	; 18
 43a:	94 98       	cbi	0x12, 4	; 18
 43c:	95 98       	cbi	0x12, 5	; 18
 43e:	8f e7       	ldi	r24, 0x7F	; 127
 440:	9a e1       	ldi	r25, 0x1A	; 26
 442:	a6 e0       	ldi	r26, 0x06	; 6
 444:	81 50       	subi	r24, 0x01	; 1
 446:	90 40       	sbci	r25, 0x00	; 0
 448:	a0 40       	sbci	r26, 0x00	; 0
 44a:	e1 f7       	brne	.-8      	;  0x444
 44c:	00 c0       	rjmp	.+0      	;  0x44e
 44e:	00 00       	nop
 450:	08 95       	ret
 452:	bc 01       	movw	r22, r24
 454:	86 ee       	ldi	r24, 0xE6	; 230
 456:	92 e0       	ldi	r25, 0x02	; 2
 458:	0e 94 12 01 	call	0x224	;  0x224
 45c:	08 95       	ret
 45e:	0f 93       	push	r16
 460:	1f 93       	push	r17
 462:	df 93       	push	r29
 464:	cf 93       	push	r28
 466:	cd b7       	in	r28, 0x3d	; 61
 468:	de b7       	in	r29, 0x3e	; 62
 46a:	65 97       	sbiw	r28, 0x15	; 21
 46c:	0f b6       	in	r0, 0x3f	; 63
 46e:	f8 94       	cli
 470:	de bf       	out	0x3e, r29	; 62
 472:	0f be       	out	0x3f, r0	; 63
 474:	cd bf       	out	0x3d, r28	; 61
 476:	2d b7       	in	r18, 0x3d	; 61
 478:	3e b7       	in	r19, 0x3e	; 62
 47a:	28 50       	subi	r18, 0x08	; 8
 47c:	30 40       	sbci	r19, 0x00	; 0
 47e:	0f b6       	in	r0, 0x3f	; 63
 480:	f8 94       	cli
 482:	3e bf       	out	0x3e, r19	; 62
 484:	0f be       	out	0x3f, r0	; 63
 486:	2d bf       	out	0x3d, r18	; 61
 488:	ed b7       	in	r30, 0x3d	; 61
 48a:	fe b7       	in	r31, 0x3e	; 62
 48c:	31 96       	adiw	r30, 0x01	; 1
 48e:	8e 01       	movw	r16, r28
 490:	0f 5f       	subi	r16, 0xFF	; 255
 492:	1f 4f       	sbci	r17, 0xFF	; 255
 494:	ad b7       	in	r26, 0x3d	; 61
 496:	be b7       	in	r27, 0x3e	; 62
 498:	12 96       	adiw	r26, 0x02	; 2
 49a:	1c 93       	st	X, r17
 49c:	0e 93       	st	-X, r16
 49e:	11 97       	sbiw	r26, 0x01	; 1
 4a0:	25 e7       	ldi	r18, 0x75	; 117
 4a2:	30 e0       	ldi	r19, 0x00	; 0
 4a4:	33 83       	std	Z+3, r19	; 0x03
 4a6:	22 83       	std	Z+2, r18	; 0x02
 4a8:	75 83       	std	Z+5, r23	; 0x05
 4aa:	64 83       	std	Z+4, r22	; 0x04
 4ac:	97 83       	std	Z+7, r25	; 0x07
 4ae:	86 83       	std	Z+6, r24	; 0x06
 4b0:	0e 94 ba 03 	call	0x774	;  0x774
 4b4:	2d b7       	in	r18, 0x3d	; 61
 4b6:	3e b7       	in	r19, 0x3e	; 62
 4b8:	28 5f       	subi	r18, 0xF8	; 248
 4ba:	3f 4f       	sbci	r19, 0xFF	; 255
 4bc:	0f b6       	in	r0, 0x3f	; 63
 4be:	f8 94       	cli
 4c0:	3e bf       	out	0x3e, r19	; 62
 4c2:	0f be       	out	0x3f, r0	; 63
 4c4:	2d bf       	out	0x3d, r18	; 61
 4c6:	86 ee       	ldi	r24, 0xE6	; 230
 4c8:	92 e0       	ldi	r25, 0x02	; 2
 4ca:	b8 01       	movw	r22, r16
 4cc:	0e 94 12 01 	call	0x224	;  0x224
 4d0:	65 96       	adiw	r28, 0x15	; 21
 4d2:	0f b6       	in	r0, 0x3f	; 63
 4d4:	f8 94       	cli
 4d6:	de bf       	out	0x3e, r29	; 62
 4d8:	0f be       	out	0x3f, r0	; 63
 4da:	cd bf       	out	0x3d, r28	; 61
 4dc:	cf 91       	pop	r28
 4de:	df 91       	pop	r29
 4e0:	1f 91       	pop	r17
 4e2:	0f 91       	pop	r16
 4e4:	08 95       	ret
 4e6:	0f 93       	push	r16
 4e8:	1f 93       	push	r17
 4ea:	df 93       	push	r29
 4ec:	cf 93       	push	r28
 4ee:	cd b7       	in	r28, 0x3d	; 61
 4f0:	de b7       	in	r29, 0x3e	; 62
 4f2:	65 97       	sbiw	r28, 0x15	; 21
 4f4:	0f b6       	in	r0, 0x3f	; 63
 4f6:	f8 94       	cli
 4f8:	de bf       	out	0x3e, r29	; 62
 4fa:	0f be       	out	0x3f, r0	; 63
 4fc:	cd bf       	out	0x3d, r28	; 61
 4fe:	2d b7       	in	r18, 0x3d	; 61
 500:	3e b7       	in	r19, 0x3e	; 62
 502:	2a 50       	subi	r18, 0x0A	; 10
 504:	30 40       	sbci	r19, 0x00	; 0
 506:	0f b6       	in	r0, 0x3f	; 63
 508:	f8 94       	cli
 50a:	3e bf       	out	0x3e, r19	; 62
 50c:	0f be       	out	0x3f, r0	; 63
 50e:	2d bf       	out	0x3d, r18	; 61
 510:	ed b7       	in	r30, 0x3d	; 61
 512:	fe b7       	in	r31, 0x3e	; 62
 514:	31 96       	adiw	r30, 0x01	; 1
 516:	8e 01       	movw	r16, r28
 518:	0f 5f       	subi	r16, 0xFF	; 255
 51a:	1f 4f       	sbci	r17, 0xFF	; 255
 51c:	ad b7       	in	r26, 0x3d	; 61
 51e:	be b7       	in	r27, 0x3e	; 62
 520:	12 96       	adiw	r26, 0x02	; 2
 522:	1c 93       	st	X, r17
 524:	0e 93       	st	-X, r16
 526:	11 97       	sbiw	r26, 0x01	; 1
 528:	2a e7       	ldi	r18, 0x7A	; 122
 52a:	30 e0       	ldi	r19, 0x00	; 0
 52c:	33 83       	std	Z+3, r19	; 0x03
 52e:	22 83       	std	Z+2, r18	; 0x02
 530:	55 83       	std	Z+5, r21	; 0x05
 532:	44 83       	std	Z+4, r20	; 0x04
 534:	97 83       	std	Z+7, r25	; 0x07
 536:	86 83       	std	Z+6, r24	; 0x06
 538:	71 87       	std	Z+9, r23	; 0x09
 53a:	60 87       	std	Z+8, r22	; 0x08
 53c:	0e 94 ba 03 	call	0x774	;  0x774
 540:	2d b7       	in	r18, 0x3d	; 61
 542:	3e b7       	in	r19, 0x3e	; 62
 544:	26 5f       	subi	r18, 0xF6	; 246
 546:	3f 4f       	sbci	r19, 0xFF	; 255
 548:	0f b6       	in	r0, 0x3f	; 63
 54a:	f8 94       	cli
 54c:	3e bf       	out	0x3e, r19	; 62
 54e:	0f be       	out	0x3f, r0	; 63
 550:	2d bf       	out	0x3d, r18	; 61
 552:	86 ee       	ldi	r24, 0xE6	; 230
 554:	92 e0       	ldi	r25, 0x02	; 2
 556:	b8 01       	movw	r22, r16
 558:	0e 94 12 01 	call	0x224	;  0x224
 55c:	65 96       	adiw	r28, 0x15	; 21
 55e:	0f b6       	in	r0, 0x3f	; 63
 560:	f8 94       	cli
 562:	de bf       	out	0x3e, r29	; 62
 564:	0f be       	out	0x3f, r0	; 63
 566:	cd bf       	out	0x3d, r28	; 61
 568:	cf 91       	pop	r28
 56a:	df 91       	pop	r29
 56c:	1f 91       	pop	r17
 56e:	0f 91       	pop	r16
 570:	08 95       	ret
 572:	1f 93       	push	r17
 574:	cf 93       	push	r28
 576:	df 93       	push	r29
 578:	28 2f       	mov	r18, r24
 57a:	46 2f       	mov	r20, r22
 57c:	c6 ee       	ldi	r28, 0xE6	; 230
 57e:	d2 e0       	ldi	r29, 0x02	; 2
 580:	ce 01       	movw	r24, r28
 582:	62 2f       	mov	r22, r18
 584:	0e 94 e0 00 	call	0x1c0	;  0x1c0
 588:	14 ba       	out	0x14, r1	; 20
 58a:	ce 01       	movw	r24, r28
 58c:	6e ee       	ldi	r22, 0xEE	; 238
 58e:	40 e0       	ldi	r20, 0x00	; 0
 590:	0e 94 55 00 	call	0xaa	;  0xaa
 594:	96 9a       	sbi	0x12, 6	; 18
 596:	95 9a       	sbi	0x12, 5	; 18
 598:	94 9a       	sbi	0x12, 4	; 18
 59a:	94 98       	cbi	0x12, 4	; 18
 59c:	94 9a       	sbi	0x12, 4	; 18
 59e:	83 b3       	in	r24, 0x13	; 19
 5a0:	94 9a       	sbi	0x12, 4	; 18
 5a2:	94 98       	cbi	0x12, 4	; 18
 5a4:	94 9a       	sbi	0x12, 4	; 18
 5a6:	13 b3       	in	r17, 0x13	; 19
 5a8:	8f ef       	ldi	r24, 0xFF	; 255
 5aa:	84 bb       	out	0x14, r24	; 20
 5ac:	96 98       	cbi	0x12, 6	; 18
 5ae:	95 98       	cbi	0x12, 5	; 18
 5b0:	ce 01       	movw	r24, r28
 5b2:	6e ee       	ldi	r22, 0xEE	; 238
 5b4:	40 e0       	ldi	r20, 0x00	; 0
 5b6:	0e 94 55 00 	call	0xaa	;  0xaa
 5ba:	81 2f       	mov	r24, r17
 5bc:	df 91       	pop	r29
 5be:	cf 91       	pop	r28
 5c0:	1f 91       	pop	r17
 5c2:	08 95       	ret
 5c4:	0e 94 b9 02 	call	0x572	;  0x572
 5c8:	08 95       	ret
 5ca:	ff 92       	push	r15
 5cc:	0f 93       	push	r16
 5ce:	1f 93       	push	r17
 5d0:	08 2f       	mov	r16, r24
 5d2:	85 36       	cpi	r24, 0x65	; 101
 5d4:	08 f0       	brcs	.+2      	;  0x5d8
 5d6:	04 e6       	ldi	r16, 0x64	; 100
 5d8:	16 2f       	mov	r17, r22
 5da:	61 33       	cpi	r22, 0x31	; 49
 5dc:	08 f0       	brcs	.+2      	;  0x5e0
 5de:	10 e3       	ldi	r17, 0x30	; 48
 5e0:	f1 2e       	mov	r15, r17
 5e2:	f6 94       	lsr	r15
 5e4:	f6 94       	lsr	r15
 5e6:	f6 94       	lsr	r15
 5e8:	86 ee       	ldi	r24, 0xE6	; 230
 5ea:	92 e0       	ldi	r25, 0x02	; 2
 5ec:	60 2f       	mov	r22, r16
 5ee:	4f 2d       	mov	r20, r15
 5f0:	0e 94 e0 00 	call	0x1c0	;  0x1c0
 5f4:	80 2f       	mov	r24, r16
 5f6:	6f 2d       	mov	r22, r15
 5f8:	0e 94 b9 02 	call	0x572	;  0x572
 5fc:	17 70       	andi	r17, 0x07	; 7
 5fe:	61 e0       	ldi	r22, 0x01	; 1
 600:	70 e0       	ldi	r23, 0x00	; 0
 602:	02 c0       	rjmp	.+4      	;  0x608
 604:	66 0f       	add	r22, r22
 606:	77 1f       	adc	r23, r23
 608:	1a 95       	dec	r17
 60a:	e2 f7       	brpl	.-8      	;  0x604
 60c:	68 2b       	or	r22, r24
 60e:	86 ee       	ldi	r24, 0xE6	; 230
 610:	92 e0       	ldi	r25, 0x02	; 2
 612:	41 e0       	ldi	r20, 0x01	; 1
 614:	0e 94 55 00 	call	0xaa	;  0xaa
 618:	86 ee       	ldi	r24, 0xE6	; 230
 61a:	92 e0       	ldi	r25, 0x02	; 2
 61c:	0e 94 0e 01 	call	0x21c	;  0x21c
 620:	86 ee       	ldi	r24, 0xE6	; 230
 622:	92 e0       	ldi	r25, 0x02	; 2
 624:	0e 94 0c 02 	call	0x418	;  0x418
 628:	1f 91       	pop	r17
 62a:	0f 91       	pop	r16
 62c:	ff 90       	pop	r15
 62e:	08 95       	ret
 630:	0f 93       	push	r16
 632:	1f 93       	push	r17
 634:	df 93       	push	r29
 636:	cf 93       	push	r28
 638:	cd b7       	in	r28, 0x3d	; 61
 63a:	de b7       	in	r29, 0x3e	; 62
 63c:	65 97       	sbiw	r28, 0x15	; 21
 63e:	0f b6       	in	r0, 0x3f	; 63
 640:	f8 94       	cli
 642:	de bf       	out	0x3e, r29	; 62
 644:	0f be       	out	0x3f, r0	; 63
 646:	cd bf       	out	0x3d, r28	; 61
 648:	00 d0       	rcall	.+0      	;  0x64a
 64a:	00 d0       	rcall	.+0      	;  0x64c
 64c:	00 d0       	rcall	.+0      	;  0x64e
 64e:	ed b7       	in	r30, 0x3d	; 61
 650:	fe b7       	in	r31, 0x3e	; 62
 652:	31 96       	adiw	r30, 0x01	; 1
 654:	8e 01       	movw	r16, r28
 656:	0f 5f       	subi	r16, 0xFF	; 255
 658:	1f 4f       	sbci	r17, 0xFF	; 255
 65a:	ad b7       	in	r26, 0x3d	; 61
 65c:	be b7       	in	r27, 0x3e	; 62
 65e:	12 96       	adiw	r26, 0x02	; 2
 660:	1c 93       	st	X, r17
 662:	0e 93       	st	-X, r16
 664:	11 97       	sbiw	r26, 0x01	; 1
 666:	25 e8       	ldi	r18, 0x85	; 133
 668:	30 e0       	ldi	r19, 0x00	; 0
 66a:	33 83       	std	Z+3, r19	; 0x03
 66c:	22 83       	std	Z+2, r18	; 0x02
 66e:	95 83       	std	Z+5, r25	; 0x05
 670:	84 83       	std	Z+4, r24	; 0x04
 672:	0e 94 ba 03 	call	0x774	;  0x774
 676:	8d b7       	in	r24, 0x3d	; 61
 678:	9e b7       	in	r25, 0x3e	; 62
 67a:	06 96       	adiw	r24, 0x06	; 6
 67c:	0f b6       	in	r0, 0x3f	; 63
 67e:	f8 94       	cli
 680:	9e bf       	out	0x3e, r25	; 62
 682:	0f be       	out	0x3f, r0	; 63
 684:	8d bf       	out	0x3d, r24	; 61
 686:	86 ee       	ldi	r24, 0xE6	; 230
 688:	92 e0       	ldi	r25, 0x02	; 2
 68a:	b8 01       	movw	r22, r16
 68c:	0e 94 12 01 	call	0x224	;  0x224
 690:	65 96       	adiw	r28, 0x15	; 21
 692:	0f b6       	in	r0, 0x3f	; 63
 694:	f8 94       	cli
 696:	de bf       	out	0x3e, r29	; 62
 698:	0f be       	out	0x3f, r0	; 63
 69a:	cd bf       	out	0x3d, r28	; 61
 69c:	cf 91       	pop	r28
 69e:	df 91       	pop	r29
 6a0:	1f 91       	pop	r17
 6a2:	0f 91       	pop	r16
 6a4:	08 95       	ret
 6a6:	cf 93       	push	r28
 6a8:	df 93       	push	r29
 6aa:	c6 ee       	ldi	r28, 0xE6	; 230
 6ac:	d2 e0       	ldi	r29, 0x02	; 2
 6ae:	ce 01       	movw	r24, r28
 6b0:	61 e0       	ldi	r22, 0x01	; 1
 6b2:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 6b6:	ce 01       	movw	r24, r28
 6b8:	6f e8       	ldi	r22, 0x8F	; 143
 6ba:	70 e0       	ldi	r23, 0x00	; 0
 6bc:	0e 94 12 01 	call	0x224	;  0x224
 6c0:	ce 01       	movw	r24, r28
 6c2:	62 e0       	ldi	r22, 0x02	; 2
 6c4:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 6c8:	ce 01       	movw	r24, r28
 6ca:	65 ea       	ldi	r22, 0xA5	; 165
 6cc:	70 e0       	ldi	r23, 0x00	; 0
 6ce:	0e 94 12 01 	call	0x224	;  0x224
 6d2:	ce 01       	movw	r24, r28
 6d4:	63 e0       	ldi	r22, 0x03	; 3
 6d6:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 6da:	ce 01       	movw	r24, r28
 6dc:	6b eb       	ldi	r22, 0xBB	; 187
 6de:	70 e0       	ldi	r23, 0x00	; 0
 6e0:	0e 94 12 01 	call	0x224	;  0x224
 6e4:	ce 01       	movw	r24, r28
 6e6:	64 e0       	ldi	r22, 0x04	; 4
 6e8:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 6ec:	ce 01       	movw	r24, r28
 6ee:	61 ed       	ldi	r22, 0xD1	; 209
 6f0:	70 e0       	ldi	r23, 0x00	; 0
 6f2:	0e 94 12 01 	call	0x224	;  0x224
 6f6:	ce 01       	movw	r24, r28
 6f8:	65 e0       	ldi	r22, 0x05	; 5
 6fa:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 6fe:	ce 01       	movw	r24, r28
 700:	60 ee       	ldi	r22, 0xE0	; 224
 702:	70 e0       	ldi	r23, 0x00	; 0
 704:	0e 94 12 01 	call	0x224	;  0x224
 708:	ce 01       	movw	r24, r28
 70a:	66 e0       	ldi	r22, 0x06	; 6
 70c:	0e 94 d4 00 	call	0x1a8	;  0x1a8
 710:	ce 01       	movw	r24, r28
 712:	6e ee       	ldi	r22, 0xEE	; 238
 714:	70 e0       	ldi	r23, 0x00	; 0
 716:	0e 94 12 01 	call	0x224	;  0x224
 71a:	df 91       	pop	r29
 71c:	cf 91       	pop	r28
 71e:	08 95       	ret
 720:	cf 93       	push	r28
 722:	df 93       	push	r29
 724:	86 ee       	ldi	r24, 0xE6	; 230
 726:	92 e0       	ldi	r25, 0x02	; 2
 728:	0e 94 09 01 	call	0x212	;  0x212
 72c:	86 ee       	ldi	r24, 0xE6	; 230
 72e:	92 e0       	ldi	r25, 0x02	; 2
 730:	62 e1       	ldi	r22, 0x12	; 18
 732:	0e 94 79 00 	call	0xf2	;  0xf2
 736:	c0 e0       	ldi	r28, 0x00	; 0
 738:	d0 e0       	ldi	r29, 0x00	; 0
 73a:	8c 2f       	mov	r24, r28
 73c:	6c 2f       	mov	r22, r28
 73e:	0e 94 e5 02 	call	0x5ca	;  0x5ca
 742:	21 96       	adiw	r28, 0x01	; 1
 744:	c0 33       	cpi	r28, 0x30	; 48
 746:	d1 05       	cpc	r29, r1
 748:	c1 f7       	brne	.-16     	;  0x73a
 74a:	8f ef       	ldi	r24, 0xFF	; 255
 74c:	90 e7       	ldi	r25, 0x70	; 112
 74e:	a2 e0       	ldi	r26, 0x02	; 2
 750:	81 50       	subi	r24, 0x01	; 1
 752:	90 40       	sbci	r25, 0x00	; 0
 754:	a0 40       	sbci	r26, 0x00	; 0
 756:	e1 f7       	brne	.-8      	;  0x750
 758:	00 c0       	rjmp	.+0      	;  0x75a
 75a:	00 00       	nop
 75c:	e3 cf       	rjmp	.-58     	;  0x724
 75e:	86 ee       	ldi	r24, 0xE6	; 230
 760:	92 e0       	ldi	r25, 0x02	; 2
 762:	0e 94 e7 01 	call	0x3ce	;  0x3ce
 766:	08 95       	ret
 768:	ee 0f       	add	r30, r30
 76a:	ff 1f       	adc	r31, r31
 76c:	05 90       	lpm	r0, Z+
 76e:	f4 91       	lpm	r31, Z+
 770:	e0 2d       	mov	r30, r0
 772:	09 94       	ijmp
 774:	ae e0       	ldi	r26, 0x0E	; 14
 776:	b0 e0       	ldi	r27, 0x00	; 0
 778:	e0 ec       	ldi	r30, 0xC0	; 192
 77a:	f3 e0       	ldi	r31, 0x03	; 3
 77c:	0c 94 72 06 	jmp	0xce4	;  0xce4
 780:	0d 89       	ldd	r16, Y+21	; 0x15
 782:	1e 89       	ldd	r17, Y+22	; 0x16
 784:	86 e0       	ldi	r24, 0x06	; 6
 786:	8c 83       	std	Y+4, r24	; 0x04
 788:	1a 83       	std	Y+2, r17	; 0x02
 78a:	09 83       	std	Y+1, r16	; 0x01
 78c:	8f ef       	ldi	r24, 0xFF	; 255
 78e:	9f e7       	ldi	r25, 0x7F	; 127
 790:	9e 83       	std	Y+6, r25	; 0x06
 792:	8d 83       	std	Y+5, r24	; 0x05
 794:	9e 01       	movw	r18, r28
 796:	27 5e       	subi	r18, 0xE7	; 231
 798:	3f 4f       	sbci	r19, 0xFF	; 255
 79a:	ce 01       	movw	r24, r28
 79c:	01 96       	adiw	r24, 0x01	; 1
 79e:	6f 89       	ldd	r22, Y+23	; 0x17
 7a0:	78 8d       	ldd	r23, Y+24	; 0x18
 7a2:	a9 01       	movw	r20, r18
 7a4:	0e 94 dd 03 	call	0x7ba	;  0x7ba
 7a8:	ef 81       	ldd	r30, Y+7	; 0x07
 7aa:	f8 85       	ldd	r31, Y+8	; 0x08
 7ac:	e0 0f       	add	r30, r16
 7ae:	f1 1f       	adc	r31, r17
 7b0:	10 82       	st	Z, r1
 7b2:	2e 96       	adiw	r28, 0x0e	; 14
 7b4:	e4 e0       	ldi	r30, 0x04	; 4
 7b6:	0c 94 8e 06 	jmp	0xd1c	;  0xd1c
 7ba:	ac e0       	ldi	r26, 0x0C	; 12
 7bc:	b0 e0       	ldi	r27, 0x00	; 0
 7be:	e3 ee       	ldi	r30, 0xE3	; 227
 7c0:	f3 e0       	ldi	r31, 0x03	; 3
 7c2:	0c 94 64 06 	jmp	0xcc8	;  0xcc8
 7c6:	6c 01       	movw	r12, r24
 7c8:	1b 01       	movw	r2, r22
 7ca:	8a 01       	movw	r16, r20
 7cc:	fc 01       	movw	r30, r24
 7ce:	17 82       	std	Z+7, r1	; 0x07
 7d0:	16 82       	std	Z+6, r1	; 0x06
 7d2:	83 81       	ldd	r24, Z+3	; 0x03
 7d4:	81 ff       	sbrs	r24, 1
 7d6:	d1 c1       	rjmp	.+930    	;  0xb7a
 7d8:	2e 01       	movw	r4, r28
 7da:	08 94       	sec
 7dc:	41 1c       	adc	r4, r1
 7de:	51 1c       	adc	r5, r1
 7e0:	f6 01       	movw	r30, r12
 7e2:	93 81       	ldd	r25, Z+3	; 0x03
 7e4:	f1 01       	movw	r30, r2
 7e6:	93 fd       	sbrc	r25, 3
 7e8:	85 91       	lpm	r24, Z+
 7ea:	93 ff       	sbrs	r25, 3
 7ec:	81 91       	ld	r24, Z+
 7ee:	1f 01       	movw	r2, r30
 7f0:	88 23       	and	r24, r24
 7f2:	09 f4       	brne	.+2      	;  0x7f6
 7f4:	be c1       	rjmp	.+892    	;  0xb72
 7f6:	85 32       	cpi	r24, 0x25	; 37
 7f8:	39 f4       	brne	.+14     	;  0x808
 7fa:	93 fd       	sbrc	r25, 3
 7fc:	85 91       	lpm	r24, Z+
 7fe:	93 ff       	sbrs	r25, 3
 800:	81 91       	ld	r24, Z+
 802:	1f 01       	movw	r2, r30
 804:	85 32       	cpi	r24, 0x25	; 37
 806:	29 f4       	brne	.+10     	;  0x812
 808:	90 e0       	ldi	r25, 0x00	; 0
 80a:	b6 01       	movw	r22, r12
 80c:	0e 94 da 05 	call	0xbb4	;  0xbb4
 810:	e7 cf       	rjmp	.-50     	;  0x7e0
 812:	ee 24       	eor	r14, r14
 814:	ff 24       	eor	r15, r15
 816:	20 e0       	ldi	r18, 0x00	; 0
 818:	20 32       	cpi	r18, 0x20	; 32
 81a:	b0 f4       	brcc	.+44     	;  0x848
 81c:	8b 32       	cpi	r24, 0x2B	; 43
 81e:	69 f0       	breq	.+26     	;  0x83a
 820:	8c 32       	cpi	r24, 0x2C	; 44
 822:	28 f4       	brcc	.+10     	;  0x82e
 824:	80 32       	cpi	r24, 0x20	; 32
 826:	51 f0       	breq	.+20     	;  0x83c
 828:	83 32       	cpi	r24, 0x23	; 35
 82a:	71 f4       	brne	.+28     	;  0x848
 82c:	0b c0       	rjmp	.+22     	;  0x844
 82e:	8d 32       	cpi	r24, 0x2D	; 45
 830:	39 f0       	breq	.+14     	;  0x840
 832:	80 33       	cpi	r24, 0x30	; 48
 834:	49 f4       	brne	.+18     	;  0x848
 836:	21 60       	ori	r18, 0x01	; 1
 838:	2c c0       	rjmp	.+88     	;  0x892
 83a:	22 60       	ori	r18, 0x02	; 2
 83c:	24 60       	ori	r18, 0x04	; 4
 83e:	29 c0       	rjmp	.+82     	;  0x892
 840:	28 60       	ori	r18, 0x08	; 8
 842:	27 c0       	rjmp	.+78     	;  0x892
 844:	20 61       	ori	r18, 0x10	; 16
 846:	25 c0       	rjmp	.+74     	;  0x892
 848:	27 fd       	sbrc	r18, 7
 84a:	2c c0       	rjmp	.+88     	;  0x8a4
 84c:	38 2f       	mov	r19, r24
 84e:	30 53       	subi	r19, 0x30	; 48
 850:	3a 30       	cpi	r19, 0x0A	; 10
 852:	98 f4       	brcc	.+38     	;  0x87a
 854:	26 ff       	sbrs	r18, 6
 856:	08 c0       	rjmp	.+16     	;  0x868
 858:	8e 2d       	mov	r24, r14
 85a:	88 0f       	add	r24, r24
 85c:	e8 2e       	mov	r14, r24
 85e:	ee 0c       	add	r14, r14
 860:	ee 0c       	add	r14, r14
 862:	e8 0e       	add	r14, r24
 864:	e3 0e       	add	r14, r19
 866:	15 c0       	rjmp	.+42     	;  0x892
 868:	8f 2d       	mov	r24, r15
 86a:	88 0f       	add	r24, r24
 86c:	f8 2e       	mov	r15, r24
 86e:	ff 0c       	add	r15, r15
 870:	ff 0c       	add	r15, r15
 872:	f8 0e       	add	r15, r24
 874:	f3 0e       	add	r15, r19
 876:	20 62       	ori	r18, 0x20	; 32
 878:	0c c0       	rjmp	.+24     	;  0x892
 87a:	8e 32       	cpi	r24, 0x2E	; 46
 87c:	21 f4       	brne	.+8      	;  0x886
 87e:	26 fd       	sbrc	r18, 6
 880:	78 c1       	rjmp	.+752    	;  0xb72
 882:	20 64       	ori	r18, 0x40	; 64
 884:	06 c0       	rjmp	.+12     	;  0x892
 886:	8c 36       	cpi	r24, 0x6C	; 108
 888:	11 f4       	brne	.+4      	;  0x88e
 88a:	20 68       	ori	r18, 0x80	; 128
 88c:	02 c0       	rjmp	.+4      	;  0x892
 88e:	88 36       	cpi	r24, 0x68	; 104
 890:	49 f4       	brne	.+18     	;  0x8a4
 892:	f1 01       	movw	r30, r2
 894:	93 fd       	sbrc	r25, 3
 896:	85 91       	lpm	r24, Z+
 898:	93 ff       	sbrs	r25, 3
 89a:	81 91       	ld	r24, Z+
 89c:	1f 01       	movw	r2, r30
 89e:	88 23       	and	r24, r24
 8a0:	09 f0       	breq	.+2      	;  0x8a4
 8a2:	ba cf       	rjmp	.-140    	;  0x818
 8a4:	98 2f       	mov	r25, r24
 8a6:	95 54       	subi	r25, 0x45	; 69
 8a8:	93 30       	cpi	r25, 0x03	; 3
 8aa:	18 f0       	brcs	.+6      	;  0x8b2
 8ac:	90 52       	subi	r25, 0x20	; 32
 8ae:	93 30       	cpi	r25, 0x03	; 3
 8b0:	28 f4       	brcc	.+10     	;  0x8bc
 8b2:	0c 5f       	subi	r16, 0xFC	; 252
 8b4:	1f 4f       	sbci	r17, 0xFF	; 255
 8b6:	ff e3       	ldi	r31, 0x3F	; 63
 8b8:	f9 83       	std	Y+1, r31	; 0x01
 8ba:	0d c0       	rjmp	.+26     	;  0x8d6
 8bc:	83 36       	cpi	r24, 0x63	; 99
 8be:	31 f0       	breq	.+12     	;  0x8cc
 8c0:	83 37       	cpi	r24, 0x73	; 115
 8c2:	71 f0       	breq	.+28     	;  0x8e0
 8c4:	83 35       	cpi	r24, 0x53	; 83
 8c6:	09 f0       	breq	.+2      	;  0x8ca
 8c8:	60 c0       	rjmp	.+192    	;  0x98a
 8ca:	22 c0       	rjmp	.+68     	;  0x910
 8cc:	f8 01       	movw	r30, r16
 8ce:	80 81       	ld	r24, Z
 8d0:	89 83       	std	Y+1, r24	; 0x01
 8d2:	0e 5f       	subi	r16, 0xFE	; 254
 8d4:	1f 4f       	sbci	r17, 0xFF	; 255
 8d6:	42 01       	movw	r8, r4
 8d8:	71 e0       	ldi	r23, 0x01	; 1
 8da:	a7 2e       	mov	r10, r23
 8dc:	b1 2c       	mov	r11, r1
 8de:	16 c0       	rjmp	.+44     	;  0x90c
 8e0:	62 e0       	ldi	r22, 0x02	; 2
 8e2:	66 2e       	mov	r6, r22
 8e4:	71 2c       	mov	r7, r1
 8e6:	60 0e       	add	r6, r16
 8e8:	71 1e       	adc	r7, r17
 8ea:	f8 01       	movw	r30, r16
 8ec:	80 80       	ld	r8, Z
 8ee:	91 80       	ldd	r9, Z+1	; 0x01
 8f0:	26 ff       	sbrs	r18, 6
 8f2:	03 c0       	rjmp	.+6      	;  0x8fa
 8f4:	6e 2d       	mov	r22, r14
 8f6:	70 e0       	ldi	r23, 0x00	; 0
 8f8:	02 c0       	rjmp	.+4      	;  0x8fe
 8fa:	6f ef       	ldi	r22, 0xFF	; 255
 8fc:	7f ef       	ldi	r23, 0xFF	; 255
 8fe:	c4 01       	movw	r24, r8
 900:	2c 87       	std	Y+12, r18	; 0x0c
 902:	0e 94 cf 05 	call	0xb9e	;  0xb9e
 906:	5c 01       	movw	r10, r24
 908:	83 01       	movw	r16, r6
 90a:	2c 85       	ldd	r18, Y+12	; 0x0c
 90c:	2f 77       	andi	r18, 0x7F	; 127
 90e:	17 c0       	rjmp	.+46     	;  0x93e
 910:	52 e0       	ldi	r21, 0x02	; 2
 912:	65 2e       	mov	r6, r21
 914:	71 2c       	mov	r7, r1
 916:	60 0e       	add	r6, r16
 918:	71 1e       	adc	r7, r17
 91a:	f8 01       	movw	r30, r16
 91c:	80 80       	ld	r8, Z
 91e:	91 80       	ldd	r9, Z+1	; 0x01
 920:	26 ff       	sbrs	r18, 6
 922:	03 c0       	rjmp	.+6      	;  0x92a
 924:	6e 2d       	mov	r22, r14
 926:	70 e0       	ldi	r23, 0x00	; 0
 928:	02 c0       	rjmp	.+4      	;  0x92e
 92a:	6f ef       	ldi	r22, 0xFF	; 255
 92c:	7f ef       	ldi	r23, 0xFF	; 255
 92e:	c4 01       	movw	r24, r8
 930:	2c 87       	std	Y+12, r18	; 0x0c
 932:	0e 94 c4 05 	call	0xb88	;  0xb88
 936:	5c 01       	movw	r10, r24
 938:	2c 85       	ldd	r18, Y+12	; 0x0c
 93a:	20 68       	ori	r18, 0x80	; 128
 93c:	83 01       	movw	r16, r6
 93e:	23 fd       	sbrc	r18, 3
 940:	20 c0       	rjmp	.+64     	;  0x982
 942:	08 c0       	rjmp	.+16     	;  0x954
 944:	80 e2       	ldi	r24, 0x20	; 32
 946:	90 e0       	ldi	r25, 0x00	; 0
 948:	b6 01       	movw	r22, r12
 94a:	2c 87       	std	Y+12, r18	; 0x0c
 94c:	0e 94 da 05 	call	0xbb4	;  0xbb4
 950:	fa 94       	dec	r15
 952:	2c 85       	ldd	r18, Y+12	; 0x0c
 954:	8f 2d       	mov	r24, r15
 956:	90 e0       	ldi	r25, 0x00	; 0
 958:	a8 16       	cp	r10, r24
 95a:	b9 06       	cpc	r11, r25
 95c:	98 f3       	brcs	.-26     	;  0x944
 95e:	11 c0       	rjmp	.+34     	;  0x982
 960:	f4 01       	movw	r30, r8
 962:	27 fd       	sbrc	r18, 7
 964:	85 91       	lpm	r24, Z+
 966:	27 ff       	sbrs	r18, 7
 968:	81 91       	ld	r24, Z+
 96a:	4f 01       	movw	r8, r30
 96c:	90 e0       	ldi	r25, 0x00	; 0
 96e:	b6 01       	movw	r22, r12
 970:	2c 87       	std	Y+12, r18	; 0x0c
 972:	0e 94 da 05 	call	0xbb4	;  0xbb4
 976:	2c 85       	ldd	r18, Y+12	; 0x0c
 978:	f1 10       	cpse	r15, r1
 97a:	fa 94       	dec	r15
 97c:	08 94       	sec
 97e:	a1 08       	sbc	r10, r1
 980:	b1 08       	sbc	r11, r1
 982:	a1 14       	cp	r10, r1
 984:	b1 04       	cpc	r11, r1
 986:	61 f7       	brne	.-40     	;  0x960
 988:	f1 c0       	rjmp	.+482    	;  0xb6c
 98a:	84 36       	cpi	r24, 0x64	; 100
 98c:	11 f0       	breq	.+4      	;  0x992
 98e:	89 36       	cpi	r24, 0x69	; 105
 990:	49 f5       	brne	.+82     	;  0x9e4
 992:	27 ff       	sbrs	r18, 7
 994:	08 c0       	rjmp	.+16     	;  0x9a6
 996:	f8 01       	movw	r30, r16
 998:	60 81       	ld	r22, Z
 99a:	71 81       	ldd	r23, Z+1	; 0x01
 99c:	82 81       	ldd	r24, Z+2	; 0x02
 99e:	93 81       	ldd	r25, Z+3	; 0x03
 9a0:	0c 5f       	subi	r16, 0xFC	; 252
 9a2:	1f 4f       	sbci	r17, 0xFF	; 255
 9a4:	09 c0       	rjmp	.+18     	;  0x9b8
 9a6:	f8 01       	movw	r30, r16
 9a8:	60 81       	ld	r22, Z
 9aa:	71 81       	ldd	r23, Z+1	; 0x01
 9ac:	88 27       	eor	r24, r24
 9ae:	77 fd       	sbrc	r23, 7
 9b0:	80 95       	com	r24
 9b2:	98 2f       	mov	r25, r24
 9b4:	0e 5f       	subi	r16, 0xFE	; 254
 9b6:	1f 4f       	sbci	r17, 0xFF	; 255
 9b8:	4f e6       	ldi	r20, 0x6F	; 111
 9ba:	b4 2e       	mov	r11, r20
 9bc:	b2 22       	and	r11, r18
 9be:	97 ff       	sbrs	r25, 7
 9c0:	09 c0       	rjmp	.+18     	;  0x9d4
 9c2:	90 95       	com	r25
 9c4:	80 95       	com	r24
 9c6:	70 95       	com	r23
 9c8:	61 95       	neg	r22
 9ca:	7f 4f       	sbci	r23, 0xFF	; 255
 9cc:	8f 4f       	sbci	r24, 0xFF	; 255
 9ce:	9f 4f       	sbci	r25, 0xFF	; 255
 9d0:	f0 e8       	ldi	r31, 0x80	; 128
 9d2:	bf 2a       	or	r11, r31
 9d4:	a2 01       	movw	r20, r4
 9d6:	2a e0       	ldi	r18, 0x0A	; 10
 9d8:	30 e0       	ldi	r19, 0x00	; 0
 9da:	0e 94 06 06 	call	0xc0c	;  0xc0c
 9de:	78 2e       	mov	r7, r24
 9e0:	74 18       	sub	r7, r4
 9e2:	45 c0       	rjmp	.+138    	;  0xa6e
 9e4:	85 37       	cpi	r24, 0x75	; 117
 9e6:	31 f4       	brne	.+12     	;  0x9f4
 9e8:	3f ee       	ldi	r19, 0xEF	; 239
 9ea:	b3 2e       	mov	r11, r19
 9ec:	b2 22       	and	r11, r18
 9ee:	2a e0       	ldi	r18, 0x0A	; 10
 9f0:	30 e0       	ldi	r19, 0x00	; 0
 9f2:	25 c0       	rjmp	.+74     	;  0xa3e
 9f4:	99 ef       	ldi	r25, 0xF9	; 249
 9f6:	b9 2e       	mov	r11, r25
 9f8:	b2 22       	and	r11, r18
 9fa:	8f 36       	cpi	r24, 0x6F	; 111
 9fc:	c1 f0       	breq	.+48     	;  0xa2e
 9fe:	80 37       	cpi	r24, 0x70	; 112
 a00:	20 f4       	brcc	.+8      	;  0xa0a
 a02:	88 35       	cpi	r24, 0x58	; 88
 a04:	09 f0       	breq	.+2      	;  0xa08
 a06:	b5 c0       	rjmp	.+362    	;  0xb72
 a08:	0d c0       	rjmp	.+26     	;  0xa24
 a0a:	80 37       	cpi	r24, 0x70	; 112
 a0c:	21 f0       	breq	.+8      	;  0xa16
 a0e:	88 37       	cpi	r24, 0x78	; 120
 a10:	09 f0       	breq	.+2      	;  0xa14
 a12:	af c0       	rjmp	.+350    	;  0xb72
 a14:	02 c0       	rjmp	.+4      	;  0xa1a
 a16:	20 e1       	ldi	r18, 0x10	; 16
 a18:	b2 2a       	or	r11, r18
 a1a:	b4 fe       	sbrs	r11, 4
 a1c:	0b c0       	rjmp	.+22     	;  0xa34
 a1e:	84 e0       	ldi	r24, 0x04	; 4
 a20:	b8 2a       	or	r11, r24
 a22:	08 c0       	rjmp	.+16     	;  0xa34
 a24:	b4 fe       	sbrs	r11, 4
 a26:	09 c0       	rjmp	.+18     	;  0xa3a
 a28:	e6 e0       	ldi	r30, 0x06	; 6
 a2a:	be 2a       	or	r11, r30
 a2c:	06 c0       	rjmp	.+12     	;  0xa3a
 a2e:	28 e0       	ldi	r18, 0x08	; 8
 a30:	30 e0       	ldi	r19, 0x00	; 0
 a32:	05 c0       	rjmp	.+10     	;  0xa3e
 a34:	20 e1       	ldi	r18, 0x10	; 16
 a36:	30 e0       	ldi	r19, 0x00	; 0
 a38:	02 c0       	rjmp	.+4      	;  0xa3e
 a3a:	20 e1       	ldi	r18, 0x10	; 16
 a3c:	32 e0       	ldi	r19, 0x02	; 2
 a3e:	b7 fe       	sbrs	r11, 7
 a40:	08 c0       	rjmp	.+16     	;  0xa52
 a42:	f8 01       	movw	r30, r16
 a44:	60 81       	ld	r22, Z
 a46:	71 81       	ldd	r23, Z+1	; 0x01
 a48:	82 81       	ldd	r24, Z+2	; 0x02
 a4a:	93 81       	ldd	r25, Z+3	; 0x03
 a4c:	0c 5f       	subi	r16, 0xFC	; 252
 a4e:	1f 4f       	sbci	r17, 0xFF	; 255
 a50:	07 c0       	rjmp	.+14     	;  0xa60
 a52:	f8 01       	movw	r30, r16
 a54:	60 81       	ld	r22, Z
 a56:	71 81       	ldd	r23, Z+1	; 0x01
 a58:	80 e0       	ldi	r24, 0x00	; 0
 a5a:	90 e0       	ldi	r25, 0x00	; 0
 a5c:	0e 5f       	subi	r16, 0xFE	; 254
 a5e:	1f 4f       	sbci	r17, 0xFF	; 255
 a60:	a2 01       	movw	r20, r4
 a62:	0e 94 06 06 	call	0xc0c	;  0xc0c
 a66:	78 2e       	mov	r7, r24
 a68:	74 18       	sub	r7, r4
 a6a:	ff e7       	ldi	r31, 0x7F	; 127
 a6c:	bf 22       	and	r11, r31
 a6e:	b6 fe       	sbrs	r11, 6
 a70:	0b c0       	rjmp	.+22     	;  0xa88
 a72:	2e ef       	ldi	r18, 0xFE	; 254
 a74:	b2 22       	and	r11, r18
 a76:	7e 14       	cp	r7, r14
 a78:	38 f4       	brcc	.+14     	;  0xa88
 a7a:	b4 fe       	sbrs	r11, 4
 a7c:	07 c0       	rjmp	.+14     	;  0xa8c
 a7e:	b2 fc       	sbrc	r11, 2
 a80:	05 c0       	rjmp	.+10     	;  0xa8c
 a82:	8f ee       	ldi	r24, 0xEF	; 239
 a84:	b8 22       	and	r11, r24
 a86:	02 c0       	rjmp	.+4      	;  0xa8c
 a88:	a7 2c       	mov	r10, r7
 a8a:	01 c0       	rjmp	.+2      	;  0xa8e
 a8c:	ae 2c       	mov	r10, r14
 a8e:	8b 2d       	mov	r24, r11
 a90:	90 e0       	ldi	r25, 0x00	; 0
 a92:	b4 fe       	sbrs	r11, 4
 a94:	0d c0       	rjmp	.+26     	;  0xab0
 a96:	fe 01       	movw	r30, r28
 a98:	e7 0d       	add	r30, r7
 a9a:	f1 1d       	adc	r31, r1
 a9c:	20 81       	ld	r18, Z
 a9e:	20 33       	cpi	r18, 0x30	; 48
 aa0:	19 f4       	brne	.+6      	;  0xaa8
 aa2:	e9 ee       	ldi	r30, 0xE9	; 233
 aa4:	be 22       	and	r11, r30
 aa6:	09 c0       	rjmp	.+18     	;  0xaba
 aa8:	a3 94       	inc	r10
 aaa:	b2 fe       	sbrs	r11, 2
 aac:	06 c0       	rjmp	.+12     	;  0xaba
 aae:	04 c0       	rjmp	.+8      	;  0xab8
 ab0:	86 78       	andi	r24, 0x86	; 134
 ab2:	90 70       	andi	r25, 0x00	; 0
 ab4:	00 97       	sbiw	r24, 0x00	; 0
 ab6:	09 f0       	breq	.+2      	;  0xaba
 ab8:	a3 94       	inc	r10
 aba:	8b 2c       	mov	r8, r11
 abc:	99 24       	eor	r9, r9
 abe:	b3 fc       	sbrc	r11, 3
 ac0:	14 c0       	rjmp	.+40     	;  0xaea
 ac2:	b0 fe       	sbrs	r11, 0
 ac4:	0f c0       	rjmp	.+30     	;  0xae4
 ac6:	af 14       	cp	r10, r15
 ac8:	28 f4       	brcc	.+10     	;  0xad4
 aca:	e7 2c       	mov	r14, r7
 acc:	ef 0c       	add	r14, r15
 ace:	ea 18       	sub	r14, r10
 ad0:	af 2c       	mov	r10, r15
 ad2:	08 c0       	rjmp	.+16     	;  0xae4
 ad4:	e7 2c       	mov	r14, r7
 ad6:	06 c0       	rjmp	.+12     	;  0xae4
 ad8:	80 e2       	ldi	r24, 0x20	; 32
 ada:	90 e0       	ldi	r25, 0x00	; 0
 adc:	b6 01       	movw	r22, r12
 ade:	0e 94 da 05 	call	0xbb4	;  0xbb4
 ae2:	a3 94       	inc	r10
 ae4:	af 14       	cp	r10, r15
 ae6:	c0 f3       	brcs	.-16     	;  0xad8
 ae8:	04 c0       	rjmp	.+8      	;  0xaf2
 aea:	af 14       	cp	r10, r15
 aec:	10 f4       	brcc	.+4      	;  0xaf2
 aee:	fa 18       	sub	r15, r10
 af0:	01 c0       	rjmp	.+2      	;  0xaf4
 af2:	ff 24       	eor	r15, r15
 af4:	84 fe       	sbrs	r8, 4
 af6:	0f c0       	rjmp	.+30     	;  0xb16
 af8:	80 e3       	ldi	r24, 0x30	; 48
 afa:	90 e0       	ldi	r25, 0x00	; 0
 afc:	b6 01       	movw	r22, r12
 afe:	0e 94 da 05 	call	0xbb4	;  0xbb4
 b02:	82 fe       	sbrs	r8, 2
 b04:	1f c0       	rjmp	.+62     	;  0xb44
 b06:	81 fe       	sbrs	r8, 1
 b08:	03 c0       	rjmp	.+6      	;  0xb10
 b0a:	88 e5       	ldi	r24, 0x58	; 88
 b0c:	90 e0       	ldi	r25, 0x00	; 0
 b0e:	10 c0       	rjmp	.+32     	;  0xb30
 b10:	88 e7       	ldi	r24, 0x78	; 120
 b12:	90 e0       	ldi	r25, 0x00	; 0
 b14:	0d c0       	rjmp	.+26     	;  0xb30
 b16:	c4 01       	movw	r24, r8
 b18:	86 78       	andi	r24, 0x86	; 134
 b1a:	90 70       	andi	r25, 0x00	; 0
 b1c:	00 97       	sbiw	r24, 0x00	; 0
 b1e:	91 f0       	breq	.+36     	;  0xb44
 b20:	81 fc       	sbrc	r8, 1
 b22:	02 c0       	rjmp	.+4      	;  0xb28
 b24:	80 e2       	ldi	r24, 0x20	; 32
 b26:	01 c0       	rjmp	.+2      	;  0xb2a
 b28:	8b e2       	ldi	r24, 0x2B	; 43
 b2a:	b7 fc       	sbrc	r11, 7
 b2c:	8d e2       	ldi	r24, 0x2D	; 45
 b2e:	90 e0       	ldi	r25, 0x00	; 0
 b30:	b6 01       	movw	r22, r12
 b32:	0e 94 da 05 	call	0xbb4	;  0xbb4
 b36:	06 c0       	rjmp	.+12     	;  0xb44
 b38:	80 e3       	ldi	r24, 0x30	; 48
 b3a:	90 e0       	ldi	r25, 0x00	; 0
 b3c:	b6 01       	movw	r22, r12
 b3e:	0e 94 da 05 	call	0xbb4	;  0xbb4
 b42:	ea 94       	dec	r14
 b44:	7e 14       	cp	r7, r14
 b46:	c0 f3       	brcs	.-16     	;  0xb38
 b48:	7a 94       	dec	r7
 b4a:	f2 01       	movw	r30, r4
 b4c:	e7 0d       	add	r30, r7
 b4e:	f1 1d       	adc	r31, r1
 b50:	80 81       	ld	r24, Z
 b52:	90 e0       	ldi	r25, 0x00	; 0
 b54:	b6 01       	movw	r22, r12
 b56:	0e 94 da 05 	call	0xbb4	;  0xbb4
 b5a:	77 20       	and	r7, r7
 b5c:	a9 f7       	brne	.-22     	;  0xb48
 b5e:	06 c0       	rjmp	.+12     	;  0xb6c
 b60:	80 e2       	ldi	r24, 0x20	; 32
 b62:	90 e0       	ldi	r25, 0x00	; 0
 b64:	b6 01       	movw	r22, r12
 b66:	0e 94 da 05 	call	0xbb4	;  0xbb4
 b6a:	fa 94       	dec	r15
 b6c:	ff 20       	and	r15, r15
 b6e:	c1 f7       	brne	.-16     	;  0xb60
 b70:	37 ce       	rjmp	.-914    	;  0x7e0
 b72:	f6 01       	movw	r30, r12
 b74:	26 81       	ldd	r18, Z+6	; 0x06
 b76:	37 81       	ldd	r19, Z+7	; 0x07
 b78:	02 c0       	rjmp	.+4      	;  0xb7e
 b7a:	2f ef       	ldi	r18, 0xFF	; 255
 b7c:	3f ef       	ldi	r19, 0xFF	; 255
 b7e:	c9 01       	movw	r24, r18
 b80:	2c 96       	adiw	r28, 0x0c	; 12
 b82:	e2 e1       	ldi	r30, 0x12	; 18
 b84:	0c 94 80 06 	jmp	0xd00	;  0xd00
 b88:	fc 01       	movw	r30, r24
 b8a:	05 90       	lpm	r0, Z+
 b8c:	61 50       	subi	r22, 0x01	; 1
 b8e:	70 40       	sbci	r23, 0x00	; 0
 b90:	01 10       	cpse	r0, r1
 b92:	d8 f7       	brcc	.-10     	;  0xb8a
 b94:	80 95       	com	r24
 b96:	90 95       	com	r25
 b98:	8e 0f       	add	r24, r30
 b9a:	9f 1f       	adc	r25, r31
 b9c:	08 95       	ret
 b9e:	fc 01       	movw	r30, r24
 ba0:	61 50       	subi	r22, 0x01	; 1
 ba2:	70 40       	sbci	r23, 0x00	; 0
 ba4:	01 90       	ld	r0, Z+
 ba6:	01 10       	cpse	r0, r1
 ba8:	d8 f7       	brcc	.-10     	;  0xba0
 baa:	80 95       	com	r24
 bac:	90 95       	com	r25
 bae:	8e 0f       	add	r24, r30
 bb0:	9f 1f       	adc	r25, r31
 bb2:	08 95       	ret
 bb4:	0f 93       	push	r16
 bb6:	1f 93       	push	r17
 bb8:	cf 93       	push	r28
 bba:	df 93       	push	r29
 bbc:	8c 01       	movw	r16, r24
 bbe:	eb 01       	movw	r28, r22
 bc0:	8b 81       	ldd	r24, Y+3	; 0x03
 bc2:	81 ff       	sbrs	r24, 1
 bc4:	1b c0       	rjmp	.+54     	;  0xbfc
 bc6:	82 ff       	sbrs	r24, 2
 bc8:	0d c0       	rjmp	.+26     	;  0xbe4
 bca:	2e 81       	ldd	r18, Y+6	; 0x06
 bcc:	3f 81       	ldd	r19, Y+7	; 0x07
 bce:	8c 81       	ldd	r24, Y+4	; 0x04
 bd0:	9d 81       	ldd	r25, Y+5	; 0x05
 bd2:	28 17       	cp	r18, r24
 bd4:	39 07       	cpc	r19, r25
 bd6:	64 f4       	brge	.+24     	;  0xbf0
 bd8:	e8 81       	ld	r30, Y
 bda:	f9 81       	ldd	r31, Y+1	; 0x01
 bdc:	01 93       	st	Z+, r16
 bde:	f9 83       	std	Y+1, r31	; 0x01
 be0:	e8 83       	st	Y, r30
 be2:	06 c0       	rjmp	.+12     	;  0xbf0
 be4:	e8 85       	ldd	r30, Y+8	; 0x08
 be6:	f9 85       	ldd	r31, Y+9	; 0x09
 be8:	80 2f       	mov	r24, r16
 bea:	09 95       	icall
 bec:	00 97       	sbiw	r24, 0x00	; 0
 bee:	31 f4       	brne	.+12     	;  0xbfc
 bf0:	8e 81       	ldd	r24, Y+6	; 0x06
 bf2:	9f 81       	ldd	r25, Y+7	; 0x07
 bf4:	01 96       	adiw	r24, 0x01	; 1
 bf6:	9f 83       	std	Y+7, r25	; 0x07
 bf8:	8e 83       	std	Y+6, r24	; 0x06
 bfa:	02 c0       	rjmp	.+4      	;  0xc00
 bfc:	0f ef       	ldi	r16, 0xFF	; 255
 bfe:	1f ef       	ldi	r17, 0xFF	; 255
 c00:	c8 01       	movw	r24, r16
 c02:	df 91       	pop	r29
 c04:	cf 91       	pop	r28
 c06:	1f 91       	pop	r17
 c08:	0f 91       	pop	r16
 c0a:	08 95       	ret
 c0c:	fa 01       	movw	r30, r20
 c0e:	aa 27       	eor	r26, r26
 c10:	28 30       	cpi	r18, 0x08	; 8
 c12:	51 f1       	breq	.+84     	;  0xc68
 c14:	20 31       	cpi	r18, 0x10	; 16
 c16:	81 f1       	breq	.+96     	;  0xc78
 c18:	e8 94       	clt
 c1a:	6f 93       	push	r22
 c1c:	6e 7f       	andi	r22, 0xFE	; 254
 c1e:	6e 5f       	subi	r22, 0xFE	; 254
 c20:	7f 4f       	sbci	r23, 0xFF	; 255
 c22:	8f 4f       	sbci	r24, 0xFF	; 255
 c24:	9f 4f       	sbci	r25, 0xFF	; 255
 c26:	af 4f       	sbci	r26, 0xFF	; 255
 c28:	b1 e0       	ldi	r27, 0x01	; 1
 c2a:	3e d0       	rcall	.+124    	;  0xca8
 c2c:	b4 e0       	ldi	r27, 0x04	; 4
 c2e:	3c d0       	rcall	.+120    	;  0xca8
 c30:	67 0f       	add	r22, r23
 c32:	78 1f       	adc	r23, r24
 c34:	89 1f       	adc	r24, r25
 c36:	9a 1f       	adc	r25, r26
 c38:	a1 1d       	adc	r26, r1
 c3a:	68 0f       	add	r22, r24
 c3c:	79 1f       	adc	r23, r25
 c3e:	8a 1f       	adc	r24, r26
 c40:	91 1d       	adc	r25, r1
 c42:	a1 1d       	adc	r26, r1
 c44:	6a 0f       	add	r22, r26
 c46:	71 1d       	adc	r23, r1
 c48:	81 1d       	adc	r24, r1
 c4a:	91 1d       	adc	r25, r1
 c4c:	a1 1d       	adc	r26, r1
 c4e:	20 d0       	rcall	.+64     	;  0xc90
 c50:	09 f4       	brne	.+2      	;  0xc54
 c52:	68 94       	set
 c54:	3f 91       	pop	r19
 c56:	2a e0       	ldi	r18, 0x0A	; 10
 c58:	26 9f       	mul	r18, r22
 c5a:	11 24       	eor	r1, r1
 c5c:	30 19       	sub	r19, r0
 c5e:	30 5d       	subi	r19, 0xD0	; 208
 c60:	31 93       	st	Z+, r19
 c62:	de f6       	brtc	.-74     	;  0xc1a
 c64:	cf 01       	movw	r24, r30
 c66:	08 95       	ret
 c68:	46 2f       	mov	r20, r22
 c6a:	47 70       	andi	r20, 0x07	; 7
 c6c:	40 5d       	subi	r20, 0xD0	; 208
 c6e:	41 93       	st	Z+, r20
 c70:	b3 e0       	ldi	r27, 0x03	; 3
 c72:	0f d0       	rcall	.+30     	;  0xc92
 c74:	c9 f7       	brne	.-14     	;  0xc68
 c76:	f6 cf       	rjmp	.-20     	;  0xc64
 c78:	46 2f       	mov	r20, r22
 c7a:	4f 70       	andi	r20, 0x0F	; 15
 c7c:	40 5d       	subi	r20, 0xD0	; 208
 c7e:	4a 33       	cpi	r20, 0x3A	; 58
 c80:	18 f0       	brcs	.+6      	;  0xc88
 c82:	49 5d       	subi	r20, 0xD9	; 217
 c84:	31 fd       	sbrc	r19, 1
 c86:	40 52       	subi	r20, 0x20	; 32
 c88:	41 93       	st	Z+, r20
 c8a:	02 d0       	rcall	.+4      	;  0xc90
 c8c:	a9 f7       	brne	.-22     	;  0xc78
 c8e:	ea cf       	rjmp	.-44     	;  0xc64
 c90:	b4 e0       	ldi	r27, 0x04	; 4
 c92:	a6 95       	lsr	r26
 c94:	97 95       	ror	r25
 c96:	87 95       	ror	r24
 c98:	77 95       	ror	r23
 c9a:	67 95       	ror	r22
 c9c:	ba 95       	dec	r27
 c9e:	c9 f7       	brne	.-14     	;  0xc92
 ca0:	00 97       	sbiw	r24, 0x00	; 0
 ca2:	61 05       	cpc	r22, r1
 ca4:	71 05       	cpc	r23, r1
 ca6:	08 95       	ret
 ca8:	9b 01       	movw	r18, r22
 caa:	ac 01       	movw	r20, r24
 cac:	0a 2e       	mov	r0, r26
 cae:	06 94       	lsr	r0
 cb0:	57 95       	ror	r21
 cb2:	47 95       	ror	r20
 cb4:	37 95       	ror	r19
 cb6:	27 95       	ror	r18
 cb8:	ba 95       	dec	r27
 cba:	c9 f7       	brne	.-14     	;  0xcae
 cbc:	62 0f       	add	r22, r18
 cbe:	73 1f       	adc	r23, r19
 cc0:	84 1f       	adc	r24, r20
 cc2:	95 1f       	adc	r25, r21
 cc4:	a0 1d       	adc	r26, r0
 cc6:	08 95       	ret
 cc8:	2f 92       	push	r2
 cca:	3f 92       	push	r3
 ccc:	4f 92       	push	r4
 cce:	5f 92       	push	r5
 cd0:	6f 92       	push	r6
 cd2:	7f 92       	push	r7
 cd4:	8f 92       	push	r8
 cd6:	9f 92       	push	r9
 cd8:	af 92       	push	r10
 cda:	bf 92       	push	r11
 cdc:	cf 92       	push	r12
 cde:	df 92       	push	r13
 ce0:	ef 92       	push	r14
 ce2:	ff 92       	push	r15
 ce4:	0f 93       	push	r16
 ce6:	1f 93       	push	r17
 ce8:	cf 93       	push	r28
 cea:	df 93       	push	r29
 cec:	cd b7       	in	r28, 0x3d	; 61
 cee:	de b7       	in	r29, 0x3e	; 62
 cf0:	ca 1b       	sub	r28, r26
 cf2:	db 0b       	sbc	r29, r27
 cf4:	0f b6       	in	r0, 0x3f	; 63
 cf6:	f8 94       	cli
 cf8:	de bf       	out	0x3e, r29	; 62
 cfa:	0f be       	out	0x3f, r0	; 63
 cfc:	cd bf       	out	0x3d, r28	; 61
 cfe:	09 94       	ijmp
 d00:	2a 88       	ldd	r2, Y+18	; 0x12
 d02:	39 88       	ldd	r3, Y+17	; 0x11
 d04:	48 88       	ldd	r4, Y+16	; 0x10
 d06:	5f 84       	ldd	r5, Y+15	; 0x0f
 d08:	6e 84       	ldd	r6, Y+14	; 0x0e
 d0a:	7d 84       	ldd	r7, Y+13	; 0x0d
 d0c:	8c 84       	ldd	r8, Y+12	; 0x0c
 d0e:	9b 84       	ldd	r9, Y+11	; 0x0b
 d10:	aa 84       	ldd	r10, Y+10	; 0x0a
 d12:	b9 84       	ldd	r11, Y+9	; 0x09
 d14:	c8 84       	ldd	r12, Y+8	; 0x08
 d16:	df 80       	ldd	r13, Y+7	; 0x07
 d18:	ee 80       	ldd	r14, Y+6	; 0x06
 d1a:	fd 80       	ldd	r15, Y+5	; 0x05
 d1c:	0c 81       	ldd	r16, Y+4	; 0x04
 d1e:	1b 81       	ldd	r17, Y+3	; 0x03
 d20:	aa 81       	ldd	r26, Y+2	; 0x02
 d22:	b9 81       	ldd	r27, Y+1	; 0x01
 d24:	ce 0f       	add	r28, r30
 d26:	d1 1d       	adc	r29, r1
 d28:	0f b6       	in	r0, 0x3f	; 63
 d2a:	f8 94       	cli
 d2c:	de bf       	out	0x3e, r29	; 62
 d2e:	0f be       	out	0x3f, r0	; 63
 d30:	cd bf       	out	0x3d, r28	; 61
 d32:	ed 01       	movw	r28, r26
 d34:	08 95       	ret
 d36:	f8 94       	cli
 d38:	ff cf       	rjmp	.-2      	;  0xd38
 d3a:	20 20       	and	r2, r0
 d3c:	20 20       	and	r2, r0
 d3e:	20 20       	and	r2, r0
 d40:	20 20       	and	r2, r0
 d42:	20 20       	and	r2, r0
 d44:	20 20       	and	r2, r0
 d46:	20 20       	and	r2, r0
 d48:	20 20       	and	r2, r0
 d4a:	20 20       	and	r2, r0
 d4c:	20 20       	and	r2, r0
 d4e:	00 25       	eor	r16, r0
 d50:	73 25       	eor	r23, r3
 d52:	64 00       	.word	0x0064	; ????
 d54:	25 73       	andi	r18, 0x35	; 53
 d56:	25 64       	ori	r18, 0x45	; 69
 d58:	2c 20       	and	r2, r12
 d5a:	25 64       	ori	r18, 0x45	; 69
 d5c:	20 20       	and	r2, r0
 d5e:	00 76       	andi	r16, 0x60	; 96
 d60:	61 6c       	ori	r22, 0xC1	; 193
 d62:	75 65       	ori	r23, 0x55	; 85
 d64:	3a 20       	and	r3, r10
 d66:	25 64       	ori	r18, 0x45	; 69
 d68:	00 30       	cpi	r16, 0x00	; 0
 d6a:	31 32       	cpi	r19, 0x21	; 33
 d6c:	33 34       	cpi	r19, 0x43	; 67
 d6e:	35 36       	cpi	r19, 0x65	; 101
 d70:	37 38       	cpi	r19, 0x87	; 135
 d72:	39 30       	cpi	r19, 0x09	; 9
 d74:	31 32       	cpi	r19, 0x21	; 33
 d76:	33 34       	cpi	r19, 0x43	; 67
 d78:	35 36       	cpi	r19, 0x65	; 101
 d7a:	37 38       	cpi	r19, 0x87	; 135
 d7c:	39 30       	cpi	r19, 0x09	; 9
 d7e:	00 41       	sbci	r16, 0x10	; 16
 d80:	42 43       	sbci	r20, 0x32	; 50
 d82:	44 45       	sbci	r20, 0x54	; 84
 d84:	46 47       	sbci	r20, 0x76	; 118
 d86:	48 49       	sbci	r20, 0x98	; 152
 d88:	4a 4b       	sbci	r20, 0xBA	; 186
 d8a:	4c 4d       	sbci	r20, 0xDC	; 220
 d8c:	4e 50       	subi	r20, 0x0E	; 14
 d8e:	51 52       	subi	r21, 0x21	; 33
 d90:	53 54       	subi	r21, 0x43	; 67
 d92:	55 56       	subi	r21, 0x65	; 101
 d94:	00 77       	andi	r16, 0x70	; 112
 d96:	78 79       	andi	r23, 0x98	; 152
 d98:	7a 61       	ori	r23, 0x1A	; 26
 d9a:	62 63       	ori	r22, 0x32	; 50
 d9c:	64 65       	ori	r22, 0x54	; 84
 d9e:	66 67       	ori	r22, 0x76	; 118
 da0:	68 69       	ori	r22, 0x98	; 152
 da2:	6a 6b       	ori	r22, 0xBA	; 186
 da4:	6c 6d       	ori	r22, 0xDC	; 220
 da6:	6e 6f       	ori	r22, 0xFE	; 254
 da8:	70 71       	andi	r23, 0x10	; 16
 daa:	00 20       	and	r0, r0
 dac:	20 21       	and	r18, r0
 dae:	23 24       	eor	r2, r3
 db0:	25 26       	eor	r2, r21
 db2:	27 28       	or	r2, r7
 db4:	20 29       	or	r18, r0
 db6:	40 5e       	subi	r20, 0xE0	; 224
 db8:	2d 00       	.word	0x002d	; ????
 dba:	20 20       	and	r2, r0
 dbc:	2a 2b       	or	r18, r26
 dbe:	2d 2f       	mov	r18, r29
 dc0:	3c 3e       	cpi	r19, 0xEC	; 236
 dc2:	3f 3b       	cpi	r19, 0xBF	; 191
 dc4:	3a 5b       	subi	r19, 0xBA	; 186
 dc6:	5d 00       	.word	0x005d	; ????
 dc8:	2a 20       	and	r2, r10
 dca:	41 56       	subi	r20, 0x61	; 97
 dcc:	52 20       	and	r5, r2
 dce:	72 75       	andi	r23, 0x52	; 82
 dd0:	6c 65       	ori	r22, 0x5C	; 92
 dd2:	73 20       	and	r7, r3
 dd4:	21 21       	and	r18, r1
 dd6:	20 2a       	or	r2, r16
	...
 de0:	5f 00       	.word	0x005f	; ????
 de2:	00 00       	nop
 de4:	07 00       	.word	0x0007	; ????
 de6:	07 00       	.word	0x0007	; ????
 de8:	14 7f       	andi	r17, 0xF4	; 244
 dea:	14 7f       	andi	r17, 0xF4	; 244
 dec:	14 24       	eor	r1, r4
 dee:	2a 7f       	andi	r18, 0xFA	; 250
 df0:	2a 12       	cpse	r2, r26
 df2:	23 13       	cpse	r18, r19
 df4:	08 64       	ori	r16, 0x48	; 72
 df6:	62 36       	cpi	r22, 0x62	; 98
 df8:	49 55       	subi	r20, 0x59	; 89
 dfa:	22 50       	subi	r18, 0x02	; 2
 dfc:	00 05       	cpc	r16, r0
 dfe:	03 00       	.word	0x0003	; ????
 e00:	00 00       	nop
 e02:	1c 22       	and	r1, r28
 e04:	41 00       	.word	0x0041	; ????
 e06:	00 41       	sbci	r16, 0x10	; 16
 e08:	22 1c       	adc	r2, r2
 e0a:	00 08       	sbc	r0, r0
 e0c:	2a 1c       	adc	r2, r10
 e0e:	2a 08       	sbc	r2, r10
 e10:	08 08       	sbc	r0, r8
 e12:	3e 08       	sbc	r3, r14
 e14:	08 00       	.word	0x0008	; ????
 e16:	50 30       	cpi	r21, 0x00	; 0
 e18:	00 00       	nop
 e1a:	08 08       	sbc	r0, r8
 e1c:	08 08       	sbc	r0, r8
 e1e:	08 00       	.word	0x0008	; ????
 e20:	60 60       	ori	r22, 0x00	; 0
 e22:	00 00       	nop
 e24:	20 10       	cpse	r2, r0
 e26:	08 04       	cpc	r0, r8
 e28:	02 3e       	cpi	r16, 0xE2	; 226
 e2a:	51 49       	sbci	r21, 0x91	; 145
 e2c:	45 3e       	cpi	r20, 0xE5	; 229
 e2e:	00 42       	sbci	r16, 0x20	; 32
 e30:	7f 40       	sbci	r23, 0x0F	; 15
 e32:	00 42       	sbci	r16, 0x20	; 32
 e34:	61 51       	subi	r22, 0x11	; 17
 e36:	49 46       	sbci	r20, 0x69	; 105
 e38:	21 41       	sbci	r18, 0x11	; 17
 e3a:	45 4b       	sbci	r20, 0xB5	; 181
 e3c:	31 18       	sub	r3, r1
 e3e:	14 12       	cpse	r1, r20
 e40:	7f 10       	cpse	r7, r15
 e42:	27 45       	sbci	r18, 0x57	; 87
 e44:	45 45       	sbci	r20, 0x55	; 85
 e46:	39 3c       	cpi	r19, 0xC9	; 201
 e48:	4a 49       	sbci	r20, 0x9A	; 154
 e4a:	49 30       	cpi	r20, 0x09	; 9
 e4c:	01 71       	andi	r16, 0x11	; 17
 e4e:	09 05       	cpc	r16, r9
 e50:	03 36       	cpi	r16, 0x63	; 99
 e52:	49 49       	sbci	r20, 0x99	; 153
 e54:	49 36       	cpi	r20, 0x69	; 105
 e56:	06 49       	sbci	r16, 0x96	; 150
 e58:	49 29       	or	r20, r9
 e5a:	1e 00       	.word	0x001e	; ????
 e5c:	36 36       	cpi	r19, 0x66	; 102
 e5e:	00 00       	nop
 e60:	00 56       	subi	r16, 0x60	; 96
 e62:	36 00       	.word	0x0036	; ????
 e64:	00 00       	nop
 e66:	08 14       	cp	r0, r8
 e68:	22 41       	sbci	r18, 0x12	; 18
 e6a:	14 14       	cp	r1, r4
 e6c:	14 14       	cp	r1, r4
 e6e:	14 41       	sbci	r17, 0x14	; 20
 e70:	22 14       	cp	r2, r2
 e72:	08 00       	.word	0x0008	; ????
 e74:	02 01       	movw	r0, r4
 e76:	51 09       	sbc	r21, r1
 e78:	06 32       	cpi	r16, 0x26	; 38
 e7a:	49 79       	andi	r20, 0x99	; 153
 e7c:	41 3e       	cpi	r20, 0xE1	; 225
 e7e:	7e 11       	cpse	r23, r14
 e80:	11 11       	cpse	r17, r1
 e82:	7e 7f       	andi	r23, 0xFE	; 254
 e84:	49 49       	sbci	r20, 0x99	; 153
 e86:	49 36       	cpi	r20, 0x69	; 105
 e88:	3e 41       	sbci	r19, 0x1E	; 30
 e8a:	41 41       	sbci	r20, 0x11	; 17
 e8c:	22 7f       	andi	r18, 0xF2	; 242
 e8e:	41 41       	sbci	r20, 0x11	; 17
 e90:	22 1c       	adc	r2, r2
 e92:	7f 49       	sbci	r23, 0x9F	; 159
 e94:	49 49       	sbci	r20, 0x99	; 153
 e96:	41 7f       	andi	r20, 0xF1	; 241
 e98:	09 09       	sbc	r16, r9
 e9a:	01 01       	movw	r0, r2
 e9c:	3e 41       	sbci	r19, 0x1E	; 30
 e9e:	41 51       	subi	r20, 0x11	; 17
 ea0:	32 7f       	andi	r19, 0xF2	; 242
 ea2:	08 08       	sbc	r0, r8
 ea4:	08 7f       	andi	r16, 0xF8	; 248
 ea6:	00 41       	sbci	r16, 0x10	; 16
 ea8:	7f 41       	sbci	r23, 0x1F	; 31
 eaa:	00 20       	and	r0, r0
 eac:	40 41       	sbci	r20, 0x10	; 16
 eae:	3f 01       	movw	r6, r30
 eb0:	7f 08       	sbc	r7, r15
 eb2:	14 22       	and	r1, r20
 eb4:	41 7f       	andi	r20, 0xF1	; 241
 eb6:	40 40       	sbci	r20, 0x00	; 0
 eb8:	40 40       	sbci	r20, 0x00	; 0
 eba:	7f 02       	muls	r23, r31
 ebc:	04 02       	muls	r16, r20
 ebe:	7f 7f       	andi	r23, 0xFF	; 255
 ec0:	04 08       	sbc	r0, r4
 ec2:	10 7f       	andi	r17, 0xF0	; 240
 ec4:	3e 41       	sbci	r19, 0x1E	; 30
 ec6:	41 41       	sbci	r20, 0x11	; 17
 ec8:	3e 7f       	andi	r19, 0xFE	; 254
 eca:	09 09       	sbc	r16, r9
 ecc:	09 06       	cpc	r0, r25
 ece:	3e 41       	sbci	r19, 0x1E	; 30
 ed0:	51 21       	and	r21, r1
 ed2:	5e 7f       	andi	r21, 0xFE	; 254
 ed4:	09 19       	sub	r16, r9
 ed6:	29 46       	sbci	r18, 0x69	; 105
 ed8:	46 49       	sbci	r20, 0x96	; 150
 eda:	49 49       	sbci	r20, 0x99	; 153
 edc:	31 01       	movw	r6, r2
 ede:	01 7f       	andi	r16, 0xF1	; 241
 ee0:	01 01       	movw	r0, r2
 ee2:	3f 40       	sbci	r19, 0x0F	; 15
 ee4:	40 40       	sbci	r20, 0x00	; 0
 ee6:	3f 1f       	adc	r19, r31
 ee8:	20 40       	sbci	r18, 0x00	; 0
 eea:	20 1f       	adc	r18, r16
 eec:	7f 20       	and	r7, r15
 eee:	18 20       	and	r1, r8
 ef0:	7f 63       	ori	r23, 0x3F	; 63
 ef2:	14 08       	sbc	r1, r4
 ef4:	14 63       	ori	r17, 0x34	; 52
 ef6:	03 04       	cpc	r0, r3
 ef8:	78 04       	cpc	r7, r8
 efa:	03 61       	ori	r16, 0x13	; 19
 efc:	51 49       	sbci	r21, 0x91	; 145
 efe:	45 43       	sbci	r20, 0x35	; 53
 f00:	00 00       	nop
 f02:	7f 41       	sbci	r23, 0x1F	; 31
 f04:	41 02       	muls	r20, r17
 f06:	04 08       	sbc	r0, r4
 f08:	10 20       	and	r1, r0
 f0a:	41 41       	sbci	r20, 0x11	; 17
 f0c:	7f 00       	.word	0x007f	; ????
 f0e:	00 04       	cpc	r0, r0
 f10:	02 01       	movw	r0, r4
 f12:	02 04       	cpc	r0, r2
 f14:	40 40       	sbci	r20, 0x00	; 0
 f16:	40 40       	sbci	r20, 0x00	; 0
 f18:	40 00       	.word	0x0040	; ????
 f1a:	01 02       	muls	r16, r17
 f1c:	04 00       	.word	0x0004	; ????
 f1e:	20 54       	subi	r18, 0x40	; 64
 f20:	54 54       	subi	r21, 0x44	; 68
 f22:	78 7f       	andi	r23, 0xF8	; 248
 f24:	48 44       	sbci	r20, 0x48	; 72
 f26:	44 38       	cpi	r20, 0x84	; 132
 f28:	38 44       	sbci	r19, 0x48	; 72
 f2a:	44 44       	sbci	r20, 0x44	; 68
 f2c:	20 38       	cpi	r18, 0x80	; 128
 f2e:	44 44       	sbci	r20, 0x44	; 68
 f30:	48 7f       	andi	r20, 0xF8	; 248
 f32:	38 54       	subi	r19, 0x48	; 72
 f34:	54 54       	subi	r21, 0x44	; 68
 f36:	18 08       	sbc	r1, r8
 f38:	7e 09       	sbc	r23, r14
 f3a:	01 02       	muls	r16, r17
 f3c:	08 14       	cp	r0, r8
 f3e:	54 54       	subi	r21, 0x44	; 68
 f40:	3c 7f       	andi	r19, 0xFC	; 252
 f42:	08 04       	cpc	r0, r8
 f44:	04 78       	andi	r16, 0x84	; 132
 f46:	00 44       	sbci	r16, 0x40	; 64
 f48:	7d 40       	sbci	r23, 0x0D	; 13
 f4a:	00 20       	and	r0, r0
 f4c:	40 44       	sbci	r20, 0x40	; 64
 f4e:	3d 00       	.word	0x003d	; ????
 f50:	00 7f       	andi	r16, 0xF0	; 240
 f52:	10 28       	or	r1, r0
 f54:	44 00       	.word	0x0044	; ????
 f56:	41 7f       	andi	r20, 0xF1	; 241
 f58:	40 00       	.word	0x0040	; ????
 f5a:	7c 04       	cpc	r7, r12
 f5c:	18 04       	cpc	r1, r8
 f5e:	78 7c       	andi	r23, 0xC8	; 200
 f60:	08 04       	cpc	r0, r8
 f62:	04 78       	andi	r16, 0x84	; 132
 f64:	38 44       	sbci	r19, 0x48	; 72
 f66:	44 44       	sbci	r20, 0x44	; 68
 f68:	38 7c       	andi	r19, 0xC8	; 200
 f6a:	14 14       	cp	r1, r4
 f6c:	14 08       	sbc	r1, r4
 f6e:	08 14       	cp	r0, r8
 f70:	14 18       	sub	r1, r4
 f72:	7c 7c       	andi	r23, 0xCC	; 204
 f74:	08 04       	cpc	r0, r8
 f76:	04 08       	sbc	r0, r4
 f78:	48 54       	subi	r20, 0x48	; 72
 f7a:	54 54       	subi	r21, 0x44	; 68
 f7c:	20 04       	cpc	r2, r0
 f7e:	3f 44       	sbci	r19, 0x4F	; 79
 f80:	40 20       	and	r4, r0
 f82:	3c 40       	sbci	r19, 0x0C	; 12
 f84:	40 20       	and	r4, r0
 f86:	7c 1c       	adc	r7, r12
 f88:	20 40       	sbci	r18, 0x00	; 0
 f8a:	20 1c       	adc	r2, r0
 f8c:	3c 40       	sbci	r19, 0x0C	; 12
 f8e:	30 40       	sbci	r19, 0x00	; 0
 f90:	3c 44       	sbci	r19, 0x4C	; 76
 f92:	28 10       	cpse	r2, r8
 f94:	28 44       	sbci	r18, 0x48	; 72
 f96:	0c 50       	subi	r16, 0x0C	; 12
 f98:	50 50       	subi	r21, 0x00	; 0
 f9a:	3c 44       	sbci	r19, 0x4C	; 76
 f9c:	64 54       	subi	r22, 0x44	; 68
 f9e:	4c 44       	sbci	r20, 0x4C	; 76
 fa0:	00 08       	sbc	r0, r0
 fa2:	36 41       	sbci	r19, 0x16	; 22
 fa4:	00 00       	nop
 fa6:	00 7f       	andi	r16, 0xF0	; 240
 fa8:	00 00       	nop
 faa:	00 41       	sbci	r16, 0x10	; 16
 fac:	36 08       	sbc	r3, r6
 fae:	00 08       	sbc	r0, r0
 fb0:	08 2a       	or	r0, r24
 fb2:	1c 08       	sbc	r1, r12
 fb4:	08 1c       	adc	r0, r8
 fb6:	2a 08       	sbc	r2, r10
 fb8:	08 14       	cp	r0, r8
 fba:	1f 20       	and	r1, r15
 fbc:	39 45       	sbci	r19, 0x59	; 89
 fbe:	4e 00       	.word	0x004e	; ????
