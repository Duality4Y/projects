00000000 <.sec1>:
       0:	0c 94 1b 01 	jmp	0x236	;  0x236
       4:	0c 94 43 01 	jmp	0x286	;  0x286
       8:	0c 94 43 01 	jmp	0x286	;  0x286
       c:	0c 94 43 01 	jmp	0x286	;  0x286
      10:	0c 94 43 01 	jmp	0x286	;  0x286
      14:	0c 94 43 01 	jmp	0x286	;  0x286
      18:	0c 94 43 01 	jmp	0x286	;  0x286
      1c:	0c 94 43 01 	jmp	0x286	;  0x286
      20:	0c 94 43 01 	jmp	0x286	;  0x286
      24:	0c 94 43 01 	jmp	0x286	;  0x286
      28:	0c 94 43 01 	jmp	0x286	;  0x286
      2c:	0c 94 43 01 	jmp	0x286	;  0x286
      30:	0c 94 43 01 	jmp	0x286	;  0x286
      34:	0c 94 43 01 	jmp	0x286	;  0x286
      38:	0c 94 43 01 	jmp	0x286	;  0x286
      3c:	0c 94 43 01 	jmp	0x286	;  0x286
      40:	0c 94 43 01 	jmp	0x286	;  0x286
      44:	0c 94 43 01 	jmp	0x286	;  0x286
      48:	0c 94 43 01 	jmp	0x286	;  0x286
      4c:	0c 94 43 01 	jmp	0x286	;  0x286
      50:	0c 94 43 01 	jmp	0x286	;  0x286
      54:	00 00       	nop
      56:	00 00       	nop
      58:	00 00       	nop
      5a:	00 5f       	subi	r16, 0xF0	; 240
      5c:	00 00       	nop
      5e:	00 07       	cpc	r16, r16
      60:	00 07       	cpc	r16, r16
      62:	00 14       	cp	r0, r0
      64:	7f 14       	cp	r7, r15
      66:	7f 14       	cp	r7, r15
      68:	24 2a       	or	r2, r20
      6a:	7f 2a       	or	r7, r31
      6c:	12 23       	and	r17, r18
      6e:	13 08       	sbc	r1, r3
      70:	64 62       	ori	r22, 0x24	; 36
      72:	36 49       	sbci	r19, 0x96	; 150
      74:	55 22       	and	r5, r21
      76:	50 00       	.word	0x0050	; ????
      78:	05 03       	mulsu	r16, r21
      7a:	00 00       	nop
      7c:	00 1c       	adc	r0, r0
      7e:	22 41       	sbci	r18, 0x12	; 18
      80:	00 00       	nop
      82:	41 22       	and	r4, r17
      84:	1c 00       	.word	0x001c	; ????
      86:	08 2a       	or	r0, r24
      88:	1c 2a       	or	r1, r28
      8a:	08 08       	sbc	r0, r8
      8c:	08 3e       	cpi	r16, 0xE8	; 232
      8e:	08 08       	sbc	r0, r8
      90:	00 50       	subi	r16, 0x00	; 0
      92:	30 00       	.word	0x0030	; ????
      94:	00 08       	sbc	r0, r0
      96:	08 08       	sbc	r0, r8
      98:	08 08       	sbc	r0, r8
      9a:	00 60       	ori	r16, 0x00	; 0
      9c:	60 00       	.word	0x0060	; ????
      9e:	00 20       	and	r0, r0
      a0:	10 08       	sbc	r1, r0
      a2:	04 02       	muls	r16, r20
      a4:	3e 51       	subi	r19, 0x1E	; 30
      a6:	49 45       	sbci	r20, 0x59	; 89
      a8:	3e 00       	.word	0x003e	; ????
      aa:	42 7f       	andi	r20, 0xF2	; 242
      ac:	40 00       	.word	0x0040	; ????
      ae:	42 61       	ori	r20, 0x12	; 18
      b0:	51 49       	sbci	r21, 0x91	; 145
      b2:	46 21       	and	r20, r6
      b4:	41 45       	sbci	r20, 0x51	; 81
      b6:	4b 31       	cpi	r20, 0x1B	; 27
      b8:	18 14       	cp	r1, r8
      ba:	12 7f       	andi	r17, 0xF2	; 242
      bc:	10 27       	eor	r17, r16
      be:	45 45       	sbci	r20, 0x55	; 85
      c0:	45 39       	cpi	r20, 0x95	; 149
      c2:	3c 4a       	sbci	r19, 0xAC	; 172
      c4:	49 49       	sbci	r20, 0x99	; 153
      c6:	30 01       	movw	r6, r0
      c8:	71 09       	sbc	r23, r1
      ca:	05 03       	mulsu	r16, r21
      cc:	36 49       	sbci	r19, 0x96	; 150
      ce:	49 49       	sbci	r20, 0x99	; 153
      d0:	36 06       	cpc	r3, r22
      d2:	49 49       	sbci	r20, 0x99	; 153
      d4:	29 1e       	adc	r2, r25
      d6:	00 36       	cpi	r16, 0x60	; 96
      d8:	36 00       	.word	0x0036	; ????
      da:	00 00       	nop
      dc:	56 36       	cpi	r21, 0x66	; 102
      de:	00 00       	nop
      e0:	00 08       	sbc	r0, r0
      e2:	14 22       	and	r1, r20
      e4:	41 14       	cp	r4, r1
      e6:	14 14       	cp	r1, r4
      e8:	14 14       	cp	r1, r4
      ea:	41 22       	and	r4, r17
      ec:	14 08       	sbc	r1, r4
      ee:	00 02       	muls	r16, r16
      f0:	01 51       	subi	r16, 0x11	; 17
      f2:	09 06       	cpc	r0, r25
      f4:	32 49       	sbci	r19, 0x92	; 146
      f6:	79 41       	sbci	r23, 0x19	; 25
      f8:	3e 7e       	andi	r19, 0xEE	; 238
      fa:	11 11       	cpse	r17, r1
      fc:	11 7e       	andi	r17, 0xE1	; 225
      fe:	7f 49       	sbci	r23, 0x9F	; 159
     100:	49 49       	sbci	r20, 0x99	; 153
     102:	36 3e       	cpi	r19, 0xE6	; 230
     104:	41 41       	sbci	r20, 0x11	; 17
     106:	41 22       	and	r4, r17
     108:	7f 41       	sbci	r23, 0x1F	; 31
     10a:	41 22       	and	r4, r17
     10c:	1c 7f       	andi	r17, 0xFC	; 252
     10e:	49 49       	sbci	r20, 0x99	; 153
     110:	49 41       	sbci	r20, 0x19	; 25
     112:	7f 09       	sbc	r23, r15
     114:	09 01       	movw	r0, r18
     116:	01 3e       	cpi	r16, 0xE1	; 225
     118:	41 41       	sbci	r20, 0x11	; 17
     11a:	51 32       	cpi	r21, 0x21	; 33
     11c:	7f 08       	sbc	r7, r15
     11e:	08 08       	sbc	r0, r8
     120:	7f 00       	.word	0x007f	; ????
     122:	41 7f       	andi	r20, 0xF1	; 241
     124:	41 00       	.word	0x0041	; ????
     126:	20 40       	sbci	r18, 0x00	; 0
     128:	41 3f       	cpi	r20, 0xF1	; 241
     12a:	01 7f       	andi	r16, 0xF1	; 241
     12c:	08 14       	cp	r0, r8
     12e:	22 41       	sbci	r18, 0x12	; 18
     130:	7f 40       	sbci	r23, 0x0F	; 15
     132:	40 40       	sbci	r20, 0x00	; 0
     134:	40 7f       	andi	r20, 0xF0	; 240
     136:	02 04       	cpc	r0, r2
     138:	02 7f       	andi	r16, 0xF2	; 242
     13a:	7f 04       	cpc	r7, r15
     13c:	08 10       	cpse	r0, r8
     13e:	7f 3e       	cpi	r23, 0xEF	; 239
     140:	41 41       	sbci	r20, 0x11	; 17
     142:	41 3e       	cpi	r20, 0xE1	; 225
     144:	7f 09       	sbc	r23, r15
     146:	09 09       	sbc	r16, r9
     148:	06 3e       	cpi	r16, 0xE6	; 230
     14a:	41 51       	subi	r20, 0x11	; 17
     14c:	21 5e       	subi	r18, 0xE1	; 225
     14e:	7f 09       	sbc	r23, r15
     150:	19 29       	or	r17, r9
     152:	46 46       	sbci	r20, 0x66	; 102
     154:	49 49       	sbci	r20, 0x99	; 153
     156:	49 31       	cpi	r20, 0x19	; 25
     158:	01 01       	movw	r0, r2
     15a:	7f 01       	movw	r14, r30
     15c:	01 3f       	cpi	r16, 0xF1	; 241
     15e:	40 40       	sbci	r20, 0x00	; 0
     160:	40 3f       	cpi	r20, 0xF0	; 240
     162:	1f 20       	and	r1, r15
     164:	40 20       	and	r4, r0
     166:	1f 7f       	andi	r17, 0xFF	; 255
     168:	20 18       	sub	r2, r0
     16a:	20 7f       	andi	r18, 0xF0	; 240
     16c:	63 14       	cp	r6, r3
     16e:	08 14       	cp	r0, r8
     170:	63 03       	mulsu	r22, r19
     172:	04 78       	andi	r16, 0x84	; 132
     174:	04 03       	mulsu	r16, r20
     176:	61 51       	subi	r22, 0x11	; 17
     178:	49 45       	sbci	r20, 0x59	; 89
     17a:	43 00       	.word	0x0043	; ????
     17c:	00 7f       	andi	r16, 0xF0	; 240
     17e:	41 41       	sbci	r20, 0x11	; 17
     180:	02 04       	cpc	r0, r2
     182:	08 10       	cpse	r0, r8
     184:	20 41       	sbci	r18, 0x10	; 16
     186:	41 7f       	andi	r20, 0xF1	; 241
     188:	00 00       	nop
     18a:	04 02       	muls	r16, r20
     18c:	01 02       	muls	r16, r17
     18e:	04 40       	sbci	r16, 0x04	; 4
     190:	40 40       	sbci	r20, 0x00	; 0
     192:	40 40       	sbci	r20, 0x00	; 0
     194:	00 01       	movw	r0, r0
     196:	02 04       	cpc	r0, r2
     198:	00 20       	and	r0, r0
     19a:	54 54       	subi	r21, 0x44	; 68
     19c:	54 78       	andi	r21, 0x84	; 132
     19e:	7f 48       	sbci	r23, 0x8F	; 143
     1a0:	44 44       	sbci	r20, 0x44	; 68
     1a2:	38 38       	cpi	r19, 0x88	; 136
     1a4:	44 44       	sbci	r20, 0x44	; 68
     1a6:	44 20       	and	r4, r4
     1a8:	38 44       	sbci	r19, 0x48	; 72
     1aa:	44 48       	sbci	r20, 0x84	; 132
     1ac:	7f 38       	cpi	r23, 0x8F	; 143
     1ae:	54 54       	subi	r21, 0x44	; 68
     1b0:	54 18       	sub	r5, r4
     1b2:	08 7e       	andi	r16, 0xE8	; 232
     1b4:	09 01       	movw	r0, r18
     1b6:	02 08       	sbc	r0, r2
     1b8:	14 54       	subi	r17, 0x44	; 68
     1ba:	54 3c       	cpi	r21, 0xC4	; 196
     1bc:	7f 08       	sbc	r7, r15
     1be:	04 04       	cpc	r0, r4
     1c0:	78 00       	.word	0x0078	; ????
     1c2:	44 7d       	andi	r20, 0xD4	; 212
     1c4:	40 00       	.word	0x0040	; ????
     1c6:	20 40       	sbci	r18, 0x00	; 0
     1c8:	44 3d       	cpi	r20, 0xD4	; 212
     1ca:	00 00       	nop
     1cc:	7f 10       	cpse	r7, r15
     1ce:	28 44       	sbci	r18, 0x48	; 72
     1d0:	00 41       	sbci	r16, 0x10	; 16
     1d2:	7f 40       	sbci	r23, 0x0F	; 15
     1d4:	00 7c       	andi	r16, 0xC0	; 192
     1d6:	04 18       	sub	r0, r4
     1d8:	04 78       	andi	r16, 0x84	; 132
     1da:	7c 08       	sbc	r7, r12
     1dc:	04 04       	cpc	r0, r4
     1de:	78 38       	cpi	r23, 0x88	; 136
     1e0:	44 44       	sbci	r20, 0x44	; 68
     1e2:	44 38       	cpi	r20, 0x84	; 132
     1e4:	7c 14       	cp	r7, r12
     1e6:	14 14       	cp	r1, r4
     1e8:	08 08       	sbc	r0, r8
     1ea:	14 14       	cp	r1, r4
     1ec:	18 7c       	andi	r17, 0xC8	; 200
     1ee:	7c 08       	sbc	r7, r12
     1f0:	04 04       	cpc	r0, r4
     1f2:	08 48       	sbci	r16, 0x88	; 136
     1f4:	54 54       	subi	r21, 0x44	; 68
     1f6:	54 20       	and	r5, r4
     1f8:	04 3f       	cpi	r16, 0xF4	; 244
     1fa:	44 40       	sbci	r20, 0x04	; 4
     1fc:	20 3c       	cpi	r18, 0xC0	; 192
     1fe:	40 40       	sbci	r20, 0x00	; 0
     200:	20 7c       	andi	r18, 0xC0	; 192
     202:	1c 20       	and	r1, r12
     204:	40 20       	and	r4, r0
     206:	1c 3c       	cpi	r17, 0xCC	; 204
     208:	40 30       	cpi	r20, 0x00	; 0
     20a:	40 3c       	cpi	r20, 0xC0	; 192
     20c:	44 28       	or	r4, r4
     20e:	10 28       	or	r1, r0
     210:	44 0c       	add	r4, r4
     212:	50 50       	subi	r21, 0x00	; 0
     214:	50 3c       	cpi	r21, 0xC0	; 192
     216:	44 64       	ori	r20, 0x44	; 68
     218:	54 4c       	sbci	r21, 0xC4	; 196
     21a:	44 00       	.word	0x0044	; ????
     21c:	08 36       	cpi	r16, 0x68	; 104
     21e:	41 00       	.word	0x0041	; ????
     220:	00 00       	nop
     222:	7f 00       	.word	0x007f	; ????
     224:	00 00       	nop
     226:	41 36       	cpi	r20, 0x61	; 97
     228:	08 00       	.word	0x0008	; ????
     22a:	08 08       	sbc	r0, r8
     22c:	2a 1c       	adc	r2, r10
     22e:	08 08       	sbc	r0, r8
     230:	1c 2a       	or	r1, r28
     232:	08 08       	sbc	r0, r8
     234:	68 04       	cpc	r6, r8
     236:	11 24       	eor	r1, r1
     238:	1f be       	out	0x3f, r1	; 63
     23a:	cf e5       	ldi	r28, 0x5F	; 95
     23c:	d4 e0       	ldi	r29, 0x04	; 4
     23e:	de bf       	out	0x3e, r29	; 62
     240:	cd bf       	out	0x3d, r28	; 61
     242:	11 e0       	ldi	r17, 0x01	; 1
     244:	a0 e6       	ldi	r26, 0x60	; 96
     246:	b0 e0       	ldi	r27, 0x00	; 0
     248:	e4 e1       	ldi	r30, 0x14	; 20
     24a:	f1 e1       	ldi	r31, 0x11	; 17
     24c:	02 c0       	rjmp	.+4      	;  0x252
     24e:	05 90       	lpm	r0, Z+
     250:	0d 92       	st	X+, r0
     252:	a8 39       	cpi	r26, 0x98	; 152
     254:	b1 07       	cpc	r27, r17
     256:	d9 f7       	brne	.-10     	;  0x24e
     258:	13 e0       	ldi	r17, 0x03	; 3
     25a:	a8 e9       	ldi	r26, 0x98	; 152
     25c:	b1 e0       	ldi	r27, 0x01	; 1
     25e:	01 c0       	rjmp	.+2      	;  0x262
     260:	1d 92       	st	X+, r1
     262:	a3 3a       	cpi	r26, 0xA3	; 163
     264:	b1 07       	cpc	r27, r17
     266:	e1 f7       	brne	.-8      	;  0x260
     268:	12 e0       	ldi	r17, 0x02	; 2
     26a:	c6 e3       	ldi	r28, 0x36	; 54
     26c:	d2 e0       	ldi	r29, 0x02	; 2
     26e:	04 c0       	rjmp	.+8      	;  0x278
     270:	22 97       	sbiw	r28, 0x02	; 2
     272:	fe 01       	movw	r30, r28
     274:	0e 94 2a 05 	call	0xa54	;  0xa54
     278:	c4 33       	cpi	r28, 0x34	; 52
     27a:	d1 07       	cpc	r29, r17
     27c:	c9 f7       	brne	.-14     	;  0x270
     27e:	0e 94 da 02 	call	0x5b4	;  0x5b4
     282:	0c 94 88 08 	jmp	0x1110	;  0x1110
     286:	0c 94 00 00 	jmp	0	;  0x0
     28a:	97 b1       	in	r25, 0x07	; 7
     28c:	87 70       	andi	r24, 0x07	; 7
     28e:	98 7f       	andi	r25, 0xF8	; 248
     290:	89 2b       	or	r24, r25
     292:	87 b9       	out	0x07, r24	; 7
     294:	36 9a       	sbi	0x06, 6	; 6
     296:	36 99       	sbic	0x06, 6	; 6
     298:	fe cf       	rjmp	.-4      	;  0x296
     29a:	84 b1       	in	r24, 0x04	; 4
     29c:	95 b1       	in	r25, 0x05	; 5
     29e:	08 95       	ret
     2a0:	94 9a       	sbi	0x12, 4	; 18
     2a2:	8a e1       	ldi	r24, 0x1A	; 26
     2a4:	8a 95       	dec	r24
     2a6:	f1 f7       	brne	.-4      	;  0x2a4
     2a8:	00 c0       	rjmp	.+0      	;  0x2aa
     2aa:	94 98       	cbi	0x12, 4	; 18
     2ac:	8a e1       	ldi	r24, 0x1A	; 26
     2ae:	8a 95       	dec	r24
     2b0:	f1 f7       	brne	.-4      	;  0x2ae
     2b2:	00 c0       	rjmp	.+0      	;  0x2b4
     2b4:	94 9a       	sbi	0x12, 4	; 18
     2b6:	08 95       	ret
     2b8:	95 b3       	in	r25, 0x15	; 21
     2ba:	15 ba       	out	0x15, r1	; 21
     2bc:	61 30       	cpi	r22, 0x01	; 1
     2be:	79 f4       	brne	.+30     	;  0x2de
     2c0:	95 98       	cbi	0x12, 5	; 18
     2c2:	96 9a       	sbi	0x12, 6	; 18
     2c4:	85 bb       	out	0x15, r24	; 21
     2c6:	94 9a       	sbi	0x12, 4	; 18
     2c8:	8a e1       	ldi	r24, 0x1A	; 26
     2ca:	8a 95       	dec	r24
     2cc:	f1 f7       	brne	.-4      	;  0x2ca
     2ce:	00 c0       	rjmp	.+0      	;  0x2d0
     2d0:	94 98       	cbi	0x12, 4	; 18
     2d2:	8a e1       	ldi	r24, 0x1A	; 26
     2d4:	8a 95       	dec	r24
     2d6:	f1 f7       	brne	.-4      	;  0x2d4
     2d8:	00 c0       	rjmp	.+0      	;  0x2da
     2da:	94 9a       	sbi	0x12, 4	; 18
     2dc:	08 95       	ret
     2de:	66 23       	and	r22, r22
     2e0:	71 f4       	brne	.+28     	;  0x2fe
     2e2:	95 98       	cbi	0x12, 5	; 18
     2e4:	96 98       	cbi	0x12, 6	; 18
     2e6:	85 bb       	out	0x15, r24	; 21
     2e8:	94 9a       	sbi	0x12, 4	; 18
     2ea:	8a e1       	ldi	r24, 0x1A	; 26
     2ec:	8a 95       	dec	r24
     2ee:	f1 f7       	brne	.-4      	;  0x2ec
     2f0:	00 c0       	rjmp	.+0      	;  0x2f2
     2f2:	94 98       	cbi	0x12, 4	; 18
     2f4:	8a e1       	ldi	r24, 0x1A	; 26
     2f6:	8a 95       	dec	r24
     2f8:	f1 f7       	brne	.-4      	;  0x2f6
     2fa:	00 c0       	rjmp	.+0      	;  0x2fc
     2fc:	94 9a       	sbi	0x12, 4	; 18
     2fe:	08 95       	ret
     300:	80 6b       	ori	r24, 0xB0	; 176
     302:	60 e0       	ldi	r22, 0x00	; 0
     304:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     308:	08 95       	ret
     30a:	cf 93       	push	r28
     30c:	df 93       	push	r29
     30e:	c8 2f       	mov	r28, r24
     310:	d0 e0       	ldi	r29, 0x00	; 0
     312:	ce 01       	movw	r24, r28
     314:	24 e0       	ldi	r18, 0x04	; 4
     316:	95 95       	asr	r25
     318:	87 95       	ror	r24
     31a:	2a 95       	dec	r18
     31c:	e1 f7       	brne	.-8      	;  0x316
     31e:	80 61       	ori	r24, 0x10	; 16
     320:	60 e0       	ldi	r22, 0x00	; 0
     322:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     326:	9e 01       	movw	r18, r28
     328:	2f 70       	andi	r18, 0x0F	; 15
     32a:	82 2f       	mov	r24, r18
     32c:	60 e0       	ldi	r22, 0x00	; 0
     32e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     332:	df 91       	pop	r29
     334:	cf 91       	pop	r28
     336:	08 95       	ret
     338:	a1 e0       	ldi	r26, 0x01	; 1
     33a:	b0 e0       	ldi	r27, 0x00	; 0
     33c:	e2 ea       	ldi	r30, 0xA2	; 162
     33e:	f1 e0       	ldi	r31, 0x01	; 1
     340:	0c 94 ed 04 	jmp	0x9da	;  0x9da
     344:	66 30       	cpi	r22, 0x06	; 6
     346:	08 f0       	brcs	.+2      	;  0x34a
     348:	66 e0       	ldi	r22, 0x06	; 6
     34a:	84 36       	cpi	r24, 0x64	; 100
     34c:	08 f0       	brcs	.+2      	;  0x350
     34e:	84 e6       	ldi	r24, 0x64	; 100
     350:	69 83       	std	Y+1, r22	; 0x01
     352:	0e 94 85 01 	call	0x30a	;  0x30a
     356:	69 81       	ldd	r22, Y+1	; 0x01
     358:	86 2f       	mov	r24, r22
     35a:	0e 94 80 01 	call	0x300	;  0x300
     35e:	21 96       	adiw	r28, 0x01	; 1
     360:	e2 e0       	ldi	r30, 0x02	; 2
     362:	0c 94 09 05 	jmp	0xa12	;  0xa12
     366:	a1 e0       	ldi	r26, 0x01	; 1
     368:	b0 e0       	ldi	r27, 0x00	; 0
     36a:	e9 eb       	ldi	r30, 0xB9	; 185
     36c:	f1 e0       	ldi	r31, 0x01	; 1
     36e:	0c 94 eb 04 	jmp	0x9d6	;  0x9d6
     372:	16 2f       	mov	r17, r22
     374:	84 36       	cpi	r24, 0x64	; 100
     376:	d0 f5       	brcc	.+116    	;  0x3ec
     378:	60 33       	cpi	r22, 0x30	; 48
     37a:	c0 f5       	brcc	.+112    	;  0x3ec
     37c:	66 95       	lsr	r22
     37e:	66 95       	lsr	r22
     380:	66 95       	lsr	r22
     382:	49 83       	std	Y+1, r20	; 0x01
     384:	0e 94 9c 01 	call	0x338	;  0x338
     388:	80 ee       	ldi	r24, 0xE0	; 224
     38a:	60 e0       	ldi	r22, 0x00	; 0
     38c:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     390:	14 ba       	out	0x14, r1	; 20
     392:	13 ba       	out	0x13, r1	; 19
     394:	95 9a       	sbi	0x12, 5	; 18
     396:	96 9a       	sbi	0x12, 6	; 18
     398:	0e 94 50 01 	call	0x2a0	;  0x2a0
     39c:	8a e1       	ldi	r24, 0x1A	; 26
     39e:	8a 95       	dec	r24
     3a0:	f1 f7       	brne	.-4      	;  0x39e
     3a2:	00 c0       	rjmp	.+0      	;  0x3a4
     3a4:	0e 94 50 01 	call	0x2a0	;  0x2a0
     3a8:	ea e1       	ldi	r30, 0x1A	; 26
     3aa:	ea 95       	dec	r30
     3ac:	f1 f7       	brne	.-4      	;  0x3aa
     3ae:	00 c0       	rjmp	.+0      	;  0x3b0
     3b0:	03 b3       	in	r16, 0x13	; 19
     3b2:	8f ef       	ldi	r24, 0xFF	; 255
     3b4:	84 bb       	out	0x14, r24	; 20
     3b6:	80 2f       	mov	r24, r16
     3b8:	61 e0       	ldi	r22, 0x01	; 1
     3ba:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     3be:	8e ee       	ldi	r24, 0xEE	; 238
     3c0:	60 e0       	ldi	r22, 0x00	; 0
     3c2:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     3c6:	17 70       	andi	r17, 0x07	; 7
     3c8:	21 e0       	ldi	r18, 0x01	; 1
     3ca:	30 e0       	ldi	r19, 0x00	; 0
     3cc:	82 2f       	mov	r24, r18
     3ce:	01 2e       	mov	r0, r17
     3d0:	01 c0       	rjmp	.+2      	;  0x3d4
     3d2:	88 0f       	add	r24, r24
     3d4:	0a 94       	dec	r0
     3d6:	ea f7       	brpl	.-6      	;  0x3d2
     3d8:	49 81       	ldd	r20, Y+1	; 0x01
     3da:	44 23       	and	r20, r20
     3dc:	11 f0       	breq	.+4      	;  0x3e2
     3de:	80 2b       	or	r24, r16
     3e0:	02 c0       	rjmp	.+4      	;  0x3e6
     3e2:	80 95       	com	r24
     3e4:	80 23       	and	r24, r16
     3e6:	61 e0       	ldi	r22, 0x01	; 1
     3e8:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     3ec:	21 96       	adiw	r28, 0x01	; 1
     3ee:	e4 e0       	ldi	r30, 0x04	; 4
     3f0:	0c 94 07 05 	jmp	0xa0e	;  0xa0e
     3f4:	84 31       	cpi	r24, 0x14	; 20
     3f6:	40 f4       	brcc	.+16     	;  0x408
     3f8:	66 30       	cpi	r22, 0x06	; 6
     3fa:	30 f4       	brcc	.+12     	;  0x408
     3fc:	98 2f       	mov	r25, r24
     3fe:	99 0f       	add	r25, r25
     400:	99 0f       	add	r25, r25
     402:	89 0f       	add	r24, r25
     404:	0e 94 9c 01 	call	0x338	;  0x338
     408:	08 95       	ret
     40a:	80 58       	subi	r24, 0x80	; 128
     40c:	60 e0       	ldi	r22, 0x00	; 0
     40e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     412:	08 95       	ret
     414:	a0 e0       	ldi	r26, 0x00	; 0
     416:	b0 e0       	ldi	r27, 0x00	; 0
     418:	e0 e1       	ldi	r30, 0x10	; 16
     41a:	f2 e0       	ldi	r31, 0x02	; 2
     41c:	0c 94 e5 04 	jmp	0x9ca	;  0x9ca
     420:	5c 01       	movw	r10, r24
     422:	ec 01       	movw	r28, r24
     424:	09 90       	ld	r0, Y+
     426:	00 20       	and	r0, r0
     428:	e9 f7       	brne	.-6      	;  0x424
     42a:	21 97       	sbiw	r28, 0x01	; 1
     42c:	c8 1b       	sub	r28, r24
     42e:	d9 0b       	sbc	r29, r25
     430:	c5 31       	cpi	r28, 0x15	; 21
     432:	d1 05       	cpc	r29, r1
     434:	14 f0       	brlt	.+4      	;  0x43a
     436:	c4 e1       	ldi	r28, 0x14	; 20
     438:	d0 e0       	ldi	r29, 0x00	; 0
     43a:	80 ee       	ldi	r24, 0xE0	; 224
     43c:	60 e0       	ldi	r22, 0x00	; 0
     43e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     442:	cc 24       	eor	r12, r12
     444:	dd 24       	eor	r13, r13
     446:	1f c0       	rjmp	.+62     	;  0x486
     448:	f5 01       	movw	r30, r10
     44a:	81 91       	ld	r24, Z+
     44c:	5f 01       	movw	r10, r30
     44e:	80 52       	subi	r24, 0x20	; 32
     450:	00 e0       	ldi	r16, 0x00	; 0
     452:	10 e0       	ldi	r17, 0x00	; 0
     454:	90 e0       	ldi	r25, 0x00	; 0
     456:	7c 01       	movw	r14, r24
     458:	ee 0c       	add	r14, r14
     45a:	ff 1c       	adc	r15, r15
     45c:	ee 0c       	add	r14, r14
     45e:	ff 1c       	adc	r15, r15
     460:	e8 0e       	add	r14, r24
     462:	f9 1e       	adc	r15, r25
     464:	f8 01       	movw	r30, r16
     466:	ee 0d       	add	r30, r14
     468:	ff 1d       	adc	r31, r15
     46a:	ec 5a       	subi	r30, 0xAC	; 172
     46c:	ff 4f       	sbci	r31, 0xFF	; 255
     46e:	84 91       	lpm	r24, Z+
     470:	61 e0       	ldi	r22, 0x01	; 1
     472:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     476:	0f 5f       	subi	r16, 0xFF	; 255
     478:	1f 4f       	sbci	r17, 0xFF	; 255
     47a:	05 30       	cpi	r16, 0x05	; 5
     47c:	11 05       	cpc	r17, r1
     47e:	91 f7       	brne	.-28     	;  0x464
     480:	08 94       	sec
     482:	c1 1c       	adc	r12, r1
     484:	d1 1c       	adc	r13, r1
     486:	cc 16       	cp	r12, r28
     488:	dd 06       	cpc	r13, r29
     48a:	f4 f2       	brlt	.-68     	;  0x448
     48c:	8e ee       	ldi	r24, 0xEE	; 238
     48e:	60 e0       	ldi	r22, 0x00	; 0
     490:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     494:	80 e0       	ldi	r24, 0x00	; 0
     496:	0e 94 85 01 	call	0x30a	;  0x30a
     49a:	cd b7       	in	r28, 0x3d	; 61
     49c:	de b7       	in	r29, 0x3e	; 62
     49e:	ea e0       	ldi	r30, 0x0A	; 10
     4a0:	0c 94 01 05 	jmp	0xa02	;  0xa02
     4a4:	9c 01       	movw	r18, r24
     4a6:	81 31       	cpi	r24, 0x11	; 17
     4a8:	91 05       	cpc	r25, r1
     4aa:	74 f0       	brlt	.+28     	;  0x4c8
     4ac:	fc 01       	movw	r30, r24
     4ae:	e8 57       	subi	r30, 0x78	; 120
     4b0:	fe 4f       	sbci	r31, 0xFE	; 254
     4b2:	81 e0       	ldi	r24, 0x01	; 1
     4b4:	90 e0       	ldi	r25, 0x00	; 0
     4b6:	40 81       	ld	r20, Z
     4b8:	44 23       	and	r20, r20
     4ba:	11 f4       	brne	.+4      	;  0x4c0
     4bc:	80 e0       	ldi	r24, 0x00	; 0
     4be:	90 e0       	ldi	r25, 0x00	; 0
     4c0:	20 3f       	cpi	r18, 0xF0	; 240
     4c2:	31 05       	cpc	r19, r1
     4c4:	5c f4       	brge	.+22     	;  0x4dc
     4c6:	02 c0       	rjmp	.+4      	;  0x4cc
     4c8:	80 e0       	ldi	r24, 0x00	; 0
     4ca:	90 e0       	ldi	r25, 0x00	; 0
     4cc:	f9 01       	movw	r30, r18
     4ce:	e8 56       	subi	r30, 0x68	; 104
     4d0:	fe 4f       	sbci	r31, 0xFE	; 254
     4d2:	41 e0       	ldi	r20, 0x01	; 1
     4d4:	50 e0       	ldi	r21, 0x00	; 0
     4d6:	60 89       	ldd	r22, Z+16	; 0x10
     4d8:	66 23       	and	r22, r22
     4da:	11 f4       	brne	.+4      	;  0x4e0
     4dc:	40 e0       	ldi	r20, 0x00	; 0
     4de:	50 e0       	ldi	r21, 0x00	; 0
     4e0:	84 0f       	add	r24, r20
     4e2:	95 1f       	adc	r25, r21
     4e4:	22 30       	cpi	r18, 0x02	; 2
     4e6:	31 05       	cpc	r19, r1
     4e8:	44 f0       	brlt	.+16     	;  0x4fa
     4ea:	f9 01       	movw	r30, r18
     4ec:	e9 56       	subi	r30, 0x69	; 105
     4ee:	fe 4f       	sbci	r31, 0xFE	; 254
     4f0:	41 e0       	ldi	r20, 0x01	; 1
     4f2:	50 e0       	ldi	r21, 0x00	; 0
     4f4:	60 81       	ld	r22, Z
     4f6:	66 23       	and	r22, r22
     4f8:	11 f4       	brne	.+4      	;  0x4fe
     4fa:	40 e0       	ldi	r20, 0x00	; 0
     4fc:	50 e0       	ldi	r21, 0x00	; 0
     4fe:	48 0f       	add	r20, r24
     500:	59 1f       	adc	r21, r25
     502:	2f 3f       	cpi	r18, 0xFF	; 255
     504:	31 05       	cpc	r19, r1
     506:	44 f4       	brge	.+16     	;  0x518
     508:	f9 01       	movw	r30, r18
     50a:	e8 56       	subi	r30, 0x68	; 104
     50c:	fe 4f       	sbci	r31, 0xFE	; 254
     50e:	81 e0       	ldi	r24, 0x01	; 1
     510:	90 e0       	ldi	r25, 0x00	; 0
     512:	61 81       	ldd	r22, Z+1	; 0x01
     514:	66 23       	and	r22, r22
     516:	11 f4       	brne	.+4      	;  0x51c
     518:	80 e0       	ldi	r24, 0x00	; 0
     51a:	90 e0       	ldi	r25, 0x00	; 0
     51c:	84 0f       	add	r24, r20
     51e:	95 1f       	adc	r25, r21
     520:	20 31       	cpi	r18, 0x10	; 16
     522:	31 05       	cpc	r19, r1
     524:	44 f0       	brlt	.+16     	;  0x536
     526:	f9 01       	movw	r30, r18
     528:	e7 57       	subi	r30, 0x77	; 119
     52a:	fe 4f       	sbci	r31, 0xFE	; 254
     52c:	61 e0       	ldi	r22, 0x01	; 1
     52e:	70 e0       	ldi	r23, 0x00	; 0
     530:	40 81       	ld	r20, Z
     532:	44 23       	and	r20, r20
     534:	11 f4       	brne	.+4      	;  0x53a
     536:	60 e0       	ldi	r22, 0x00	; 0
     538:	70 e0       	ldi	r23, 0x00	; 0
     53a:	68 0f       	add	r22, r24
     53c:	79 1f       	adc	r23, r25
     53e:	22 31       	cpi	r18, 0x12	; 18
     540:	31 05       	cpc	r19, r1
     542:	44 f0       	brlt	.+16     	;  0x554
     544:	f9 01       	movw	r30, r18
     546:	e9 57       	subi	r30, 0x79	; 121
     548:	fe 4f       	sbci	r31, 0xFE	; 254
     54a:	41 e0       	ldi	r20, 0x01	; 1
     54c:	50 e0       	ldi	r21, 0x00	; 0
     54e:	80 81       	ld	r24, Z
     550:	88 23       	and	r24, r24
     552:	11 f4       	brne	.+4      	;  0x558
     554:	40 e0       	ldi	r20, 0x00	; 0
     556:	50 e0       	ldi	r21, 0x00	; 0
     558:	46 0f       	add	r20, r22
     55a:	57 1f       	adc	r21, r23
     55c:	21 3f       	cpi	r18, 0xF1	; 241
     55e:	31 05       	cpc	r19, r1
     560:	44 f4       	brge	.+16     	;  0x572
     562:	f9 01       	movw	r30, r18
     564:	e8 56       	subi	r30, 0x68	; 104
     566:	fe 4f       	sbci	r31, 0xFE	; 254
     568:	81 e0       	ldi	r24, 0x01	; 1
     56a:	90 e0       	ldi	r25, 0x00	; 0
     56c:	67 85       	ldd	r22, Z+15	; 0x0f
     56e:	66 23       	and	r22, r22
     570:	11 f4       	brne	.+4      	;  0x576
     572:	80 e0       	ldi	r24, 0x00	; 0
     574:	90 e0       	ldi	r25, 0x00	; 0
     576:	84 0f       	add	r24, r20
     578:	95 1f       	adc	r25, r21
     57a:	2f 3e       	cpi	r18, 0xEF	; 239
     57c:	31 05       	cpc	r19, r1
     57e:	44 f4       	brge	.+16     	;  0x590
     580:	28 56       	subi	r18, 0x68	; 104
     582:	3e 4f       	sbci	r19, 0xFE	; 254
     584:	41 e0       	ldi	r20, 0x01	; 1
     586:	50 e0       	ldi	r21, 0x00	; 0
     588:	f9 01       	movw	r30, r18
     58a:	21 89       	ldd	r18, Z+17	; 0x11
     58c:	22 23       	and	r18, r18
     58e:	11 f4       	brne	.+4      	;  0x594
     590:	40 e0       	ldi	r20, 0x00	; 0
     592:	50 e0       	ldi	r21, 0x00	; 0
     594:	84 0f       	add	r24, r20
     596:	95 1f       	adc	r25, r21
     598:	08 95       	ret
     59a:	dc 01       	movw	r26, r24
     59c:	a0 50       	subi	r26, 0x00	; 0
     59e:	bf 4f       	sbci	r27, 0xFF	; 255
     5a0:	e8 e9       	ldi	r30, 0x98	; 152
     5a2:	f2 e0       	ldi	r31, 0x02	; 2
     5a4:	02 c0       	rjmp	.+4      	;  0x5aa
     5a6:	8e 91       	ld	r24, -X
     5a8:	82 93       	st	-Z, r24
     5aa:	81 e0       	ldi	r24, 0x01	; 1
     5ac:	e8 39       	cpi	r30, 0x98	; 152
     5ae:	f8 07       	cpc	r31, r24
     5b0:	d1 f7       	brne	.-12     	;  0x5a6
     5b2:	08 95       	ret
     5b4:	2f 92       	push	r2
     5b6:	3f 92       	push	r3
     5b8:	4f 92       	push	r4
     5ba:	5f 92       	push	r5
     5bc:	6f 92       	push	r6
     5be:	7f 92       	push	r7
     5c0:	8f 92       	push	r8
     5c2:	9f 92       	push	r9
     5c4:	af 92       	push	r10
     5c6:	bf 92       	push	r11
     5c8:	df 92       	push	r13
     5ca:	ef 92       	push	r14
     5cc:	ff 92       	push	r15
     5ce:	0f 93       	push	r16
     5d0:	1f 93       	push	r17
     5d2:	df 93       	push	r29
     5d4:	cf 93       	push	r28
     5d6:	cd b7       	in	r28, 0x3d	; 61
     5d8:	de b7       	in	r29, 0x3e	; 62
     5da:	65 97       	sbiw	r28, 0x15	; 21
     5dc:	0f b6       	in	r0, 0x3f	; 63
     5de:	f8 94       	cli
     5e0:	de bf       	out	0x3e, r29	; 62
     5e2:	0f be       	out	0x3f, r0	; 63
     5e4:	cd bf       	out	0x3d, r28	; 61
     5e6:	0f ef       	ldi	r16, 0xFF	; 255
     5e8:	08 c0       	rjmp	.+16     	;  0x5fa
     5ea:	06 30       	cpi	r16, 0x06	; 6
     5ec:	30 f4       	brcc	.+12     	;  0x5fa
     5ee:	e0 2f       	mov	r30, r16
     5f0:	f0 e0       	ldi	r31, 0x00	; 0
     5f2:	ee 56       	subi	r30, 0x6E	; 110
     5f4:	fe 4f       	sbci	r31, 0xFE	; 254
     5f6:	10 81       	ld	r17, Z
     5f8:	01 c0       	rjmp	.+2      	;  0x5fc
     5fa:	10 e0       	ldi	r17, 0x00	; 0
     5fc:	e1 2e       	mov	r14, r17
     5fe:	e2 94       	swap	r14
     600:	af e0       	ldi	r26, 0x0F	; 15
     602:	ea 22       	and	r14, r26
     604:	86 eb       	ldi	r24, 0xB6	; 182
     606:	60 e0       	ldi	r22, 0x00	; 0
     608:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     60c:	8e 2d       	mov	r24, r14
     60e:	80 61       	ori	r24, 0x10	; 16
     610:	60 e0       	ldi	r22, 0x00	; 0
     612:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     616:	81 2f       	mov	r24, r17
     618:	8f 70       	andi	r24, 0x0F	; 15
     61a:	60 e0       	ldi	r22, 0x00	; 0
     61c:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     620:	80 e0       	ldi	r24, 0x00	; 0
     622:	61 e0       	ldi	r22, 0x01	; 1
     624:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     628:	0f 5f       	subi	r16, 0xFF	; 255
     62a:	06 30       	cpi	r16, 0x06	; 6
     62c:	f1 f6       	brne	.-68     	;  0x5ea
     62e:	80 e4       	ldi	r24, 0x40	; 64
     630:	87 b9       	out	0x07, r24	; 7
     632:	87 e8       	ldi	r24, 0x87	; 135
     634:	86 b9       	out	0x06, r24	; 6
     636:	80 e0       	ldi	r24, 0x00	; 0
     638:	0e 94 45 01 	call	0x28a	;  0x28a
     63c:	0e 94 77 05 	call	0xaee	;  0xaee
     640:	b8 9a       	sbi	0x17, 0	; 23
     642:	e8 e9       	ldi	r30, 0x98	; 152
     644:	f3 e0       	ldi	r31, 0x03	; 3
     646:	01 c0       	rjmp	.+2      	;  0x64a
     648:	12 92       	st	-Z, r1
     64a:	32 e0       	ldi	r19, 0x02	; 2
     64c:	e8 39       	cpi	r30, 0x98	; 152
     64e:	f3 07       	cpc	r31, r19
     650:	d9 f7       	brne	.-10     	;  0x648
     652:	82 e9       	ldi	r24, 0x92	; 146
     654:	90 e0       	ldi	r25, 0x00	; 0
     656:	0e 94 cd 02 	call	0x59a	;  0x59a
     65a:	81 e1       	ldi	r24, 0x11	; 17
     65c:	0e 94 05 02 	call	0x40a	;  0x40a
     660:	80 e0       	ldi	r24, 0x00	; 0
     662:	60 e0       	ldi	r22, 0x00	; 0
     664:	0e 94 fa 01 	call	0x3f4	;  0x3f4
     668:	80 e0       	ldi	r24, 0x00	; 0
     66a:	91 e0       	ldi	r25, 0x01	; 1
     66c:	90 93 a2 03 	sts	0x03A2, r25
     670:	80 93 a1 03 	sts	0x03A1, r24
     674:	e1 2c       	mov	r14, r1
     676:	f1 e0       	ldi	r31, 0x01	; 1
     678:	ff 2e       	mov	r15, r31
     67a:	e0 e1       	ldi	r30, 0x10	; 16
     67c:	8e 2e       	mov	r8, r30
     67e:	91 2c       	mov	r9, r1
     680:	dd 24       	eor	r13, r13
     682:	d3 94       	inc	r13
     684:	5e 01       	movw	r10, r28
     686:	08 94       	sec
     688:	a1 1c       	adc	r10, r1
     68a:	b1 1c       	adc	r11, r1
     68c:	70 e6       	ldi	r23, 0x60	; 96
     68e:	67 2e       	mov	r6, r23
     690:	70 e0       	ldi	r23, 0x00	; 0
     692:	77 2e       	mov	r7, r23
     694:	6b e6       	ldi	r22, 0x6B	; 107
     696:	46 2e       	mov	r4, r22
     698:	60 e0       	ldi	r22, 0x00	; 0
     69a:	56 2e       	mov	r5, r22
     69c:	52 e0       	ldi	r21, 0x02	; 2
     69e:	25 2e       	mov	r2, r21
     6a0:	31 2c       	mov	r3, r1
     6a2:	e6 c0       	rjmp	.+460    	;  0x870
     6a4:	87 01       	movw	r16, r14
     6a6:	02 1b       	sub	r16, r18
     6a8:	13 0b       	sbc	r17, r19
     6aa:	c8 01       	movw	r24, r16
     6ac:	b4 01       	movw	r22, r8
     6ae:	0e 94 ca 04 	call	0x994	;  0x994
     6b2:	90 93 99 03 	sts	0x0399, r25
     6b6:	80 93 98 03 	sts	0x0398, r24
     6ba:	80 91 98 03 	lds	r24, 0x0398
     6be:	90 91 99 03 	lds	r25, 0x0399
     6c2:	00 97       	sbiw	r24, 0x00	; 0
     6c4:	a1 f4       	brne	.+40     	;  0x6ee
     6c6:	80 91 9a 03 	lds	r24, 0x039A
     6ca:	90 91 9b 03 	lds	r25, 0x039B
     6ce:	01 96       	adiw	r24, 0x01	; 1
     6d0:	90 93 9b 03 	sts	0x039B, r25
     6d4:	80 93 9a 03 	sts	0x039A, r24
     6d8:	80 91 9a 03 	lds	r24, 0x039A
     6dc:	90 91 9b 03 	lds	r25, 0x039B
     6e0:	80 31       	cpi	r24, 0x10	; 16
     6e2:	91 05       	cpc	r25, r1
     6e4:	24 f0       	brlt	.+8      	;  0x6ee
     6e6:	10 92 9b 03 	sts	0x039B, r1
     6ea:	10 92 9a 03 	sts	0x039A, r1
     6ee:	80 91 98 03 	lds	r24, 0x0398
     6f2:	60 91 9a 03 	lds	r22, 0x039A
     6f6:	0e 94 fa 01 	call	0x3f4	;  0x3f4
     6fa:	f8 01       	movw	r30, r16
     6fc:	e8 56       	subi	r30, 0x68	; 104
     6fe:	fe 4f       	sbci	r31, 0xFE	; 254
     700:	80 81       	ld	r24, Z
     702:	88 23       	and	r24, r24
     704:	31 f0       	breq	.+12     	;  0x712
     706:	80 91 98 03 	lds	r24, 0x0398
     70a:	60 91 9a 03 	lds	r22, 0x039A
     70e:	41 e0       	ldi	r20, 0x01	; 1
     710:	05 c0       	rjmp	.+10     	;  0x71c
     712:	80 91 98 03 	lds	r24, 0x0398
     716:	60 91 9a 03 	lds	r22, 0x039A
     71a:	40 e0       	ldi	r20, 0x00	; 0
     71c:	0e 94 b3 01 	call	0x366	;  0x366
     720:	00 91 a1 03 	lds	r16, 0x03A1
     724:	10 91 a2 03 	lds	r17, 0x03A2
     728:	f8 01       	movw	r30, r16
     72a:	e8 56       	subi	r30, 0x68	; 104
     72c:	fe 4f       	sbci	r31, 0xFE	; 254
     72e:	80 81       	ld	r24, Z
     730:	88 23       	and	r24, r24
     732:	51 f0       	breq	.+20     	;  0x748
     734:	c8 01       	movw	r24, r16
     736:	0e 94 52 02 	call	0x4a4	;  0x4a4
     73a:	82 30       	cpi	r24, 0x02	; 2
     73c:	91 05       	cpc	r25, r1
     73e:	39 f4       	brne	.+14     	;  0x74e
     740:	f8 01       	movw	r30, r16
     742:	e8 56       	subi	r30, 0x68	; 104
     744:	fd 4f       	sbci	r31, 0xFD	; 253
     746:	09 c0       	rjmp	.+18     	;  0x75a
     748:	c8 01       	movw	r24, r16
     74a:	0e 94 52 02 	call	0x4a4	;  0x4a4
     74e:	f8 01       	movw	r30, r16
     750:	e8 56       	subi	r30, 0x68	; 104
     752:	fd 4f       	sbci	r31, 0xFD	; 253
     754:	83 30       	cpi	r24, 0x03	; 3
     756:	91 05       	cpc	r25, r1
     758:	11 f4       	brne	.+4      	;  0x75e
     75a:	d0 82       	st	Z, r13
     75c:	01 c0       	rjmp	.+2      	;  0x760
     75e:	10 82       	st	Z, r1
     760:	01 15       	cp	r16, r1
     762:	11 05       	cpc	r17, r1
     764:	09 f0       	breq	.+2      	;  0x768
     766:	84 c0       	rjmp	.+264    	;  0x870
     768:	88 e9       	ldi	r24, 0x98	; 152
     76a:	92 e0       	ldi	r25, 0x02	; 2
     76c:	0e 94 cd 02 	call	0x59a	;  0x59a
     770:	f0 92 a2 03 	sts	0x03A2, r15
     774:	e0 92 a1 03 	sts	0x03A1, r14
     778:	08 e9       	ldi	r16, 0x98	; 152
     77a:	11 e0       	ldi	r17, 0x01	; 1
     77c:	f8 01       	movw	r30, r16
     77e:	80 e0       	ldi	r24, 0x00	; 0
     780:	91 91       	ld	r25, Z+
     782:	91 11       	cpse	r25, r1
     784:	8f 5f       	subi	r24, 0xFF	; 255
     786:	92 e0       	ldi	r25, 0x02	; 2
     788:	e8 39       	cpi	r30, 0x98	; 152
     78a:	f9 07       	cpc	r31, r25
     78c:	c9 f7       	brne	.-14     	;  0x780
     78e:	80 93 9c 03 	sts	0x039C, r24
     792:	81 e0       	ldi	r24, 0x01	; 1
     794:	0e 94 45 01 	call	0x28a	;  0x28a
     798:	45 e0       	ldi	r20, 0x05	; 5
     79a:	96 95       	lsr	r25
     79c:	87 95       	ror	r24
     79e:	4a 95       	dec	r20
     7a0:	e1 f7       	brne	.-8      	;  0x79a
     7a2:	0e 94 05 02 	call	0x40a	;  0x40a
     7a6:	20 91 9e 03 	lds	r18, 0x039E
     7aa:	2f 30       	cpi	r18, 0x0F	; 15
     7ac:	51 f0       	breq	.+20     	;  0x7c2
     7ae:	80 91 9f 03 	lds	r24, 0x039F
     7b2:	90 91 a0 03 	lds	r25, 0x03A0
     7b6:	a3 e0       	ldi	r26, 0x03	; 3
     7b8:	89 3e       	cpi	r24, 0xE9	; 233
     7ba:	9a 07       	cpc	r25, r26
     7bc:	14 f4       	brge	.+4      	;  0x7c2
     7be:	b2 9b       	sbis	0x16, 2	; 22
     7c0:	7f c0       	rjmp	.+254    	;  0x8c0
     7c2:	10 92 9e 03 	sts	0x039E, r1
     7c6:	10 92 a0 03 	sts	0x03A0, r1
     7ca:	10 92 9f 03 	sts	0x039F, r1
     7ce:	0e 94 72 05 	call	0xae4	;  0xae4
     7d2:	b1 01       	movw	r22, r2
     7d4:	0e 94 ca 04 	call	0x994	;  0x994
     7d8:	21 e0       	ldi	r18, 0x01	; 1
     7da:	00 97       	sbiw	r24, 0x00	; 0
     7dc:	09 f4       	brne	.+2      	;  0x7e0
     7de:	20 e0       	ldi	r18, 0x00	; 0
     7e0:	f8 01       	movw	r30, r16
     7e2:	21 93       	st	Z+, r18
     7e4:	8f 01       	movw	r16, r30
     7e6:	f2 e0       	ldi	r31, 0x02	; 2
     7e8:	08 39       	cpi	r16, 0x98	; 152
     7ea:	1f 07       	cpc	r17, r31
     7ec:	81 f7       	brne	.-32     	;  0x7ce
     7ee:	0f c0       	rjmp	.+30     	;  0x80e
     7f0:	c0 9a       	sbi	0x18, 0	; 24
     7f2:	2f 5f       	subi	r18, 0xFF	; 255
     7f4:	20 93 9e 03 	sts	0x039E, r18
     7f8:	0a c0       	rjmp	.+20     	;  0x80e
     7fa:	c0 98       	cbi	0x18, 0	; 24
     7fc:	30 93 9d 03 	sts	0x039D, r19
     800:	01 96       	adiw	r24, 0x01	; 1
     802:	90 93 a0 03 	sts	0x03A0, r25
     806:	80 93 9f 03 	sts	0x039F, r24
     80a:	10 92 9e 03 	sts	0x039E, r1
     80e:	80 e0       	ldi	r24, 0x00	; 0
     810:	65 e0       	ldi	r22, 0x05	; 5
     812:	0e 94 fa 01 	call	0x3f4	;  0x3f4
     816:	8d b7       	in	r24, 0x3d	; 61
     818:	9e b7       	in	r25, 0x3e	; 62
     81a:	0a 97       	sbiw	r24, 0x0a	; 10
     81c:	0f b6       	in	r0, 0x3f	; 63
     81e:	f8 94       	cli
     820:	9e bf       	out	0x3e, r25	; 62
     822:	0f be       	out	0x3f, r0	; 63
     824:	8d bf       	out	0x3d, r24	; 61
     826:	ed b7       	in	r30, 0x3d	; 61
     828:	fe b7       	in	r31, 0x3e	; 62
     82a:	31 96       	adiw	r30, 0x01	; 1
     82c:	ad b7       	in	r26, 0x3d	; 61
     82e:	be b7       	in	r27, 0x3e	; 62
     830:	12 96       	adiw	r26, 0x02	; 2
     832:	bc 92       	st	X, r11
     834:	ae 92       	st	-X, r10
     836:	11 97       	sbiw	r26, 0x01	; 1
     838:	73 82       	std	Z+3, r7	; 0x03
     83a:	62 82       	std	Z+2, r6	; 0x02
     83c:	55 82       	std	Z+5, r5	; 0x05
     83e:	44 82       	std	Z+4, r4	; 0x04
     840:	80 91 9f 03 	lds	r24, 0x039F
     844:	90 91 a0 03 	lds	r25, 0x03A0
     848:	97 83       	std	Z+7, r25	; 0x07
     84a:	86 83       	std	Z+6, r24	; 0x06
     84c:	80 91 9e 03 	lds	r24, 0x039E
     850:	90 e0       	ldi	r25, 0x00	; 0
     852:	91 87       	std	Z+9, r25	; 0x09
     854:	80 87       	std	Z+8, r24	; 0x08
     856:	0e 94 82 05 	call	0xb04	;  0xb04
     85a:	ed b7       	in	r30, 0x3d	; 61
     85c:	fe b7       	in	r31, 0x3e	; 62
     85e:	3a 96       	adiw	r30, 0x0a	; 10
     860:	0f b6       	in	r0, 0x3f	; 63
     862:	f8 94       	cli
     864:	fe bf       	out	0x3e, r31	; 62
     866:	0f be       	out	0x3f, r0	; 63
     868:	ed bf       	out	0x3d, r30	; 61
     86a:	c5 01       	movw	r24, r10
     86c:	0e 94 0a 02 	call	0x414	;  0x414
     870:	80 91 a1 03 	lds	r24, 0x03A1
     874:	90 91 a2 03 	lds	r25, 0x03A2
     878:	9c 01       	movw	r18, r24
     87a:	21 50       	subi	r18, 0x01	; 1
     87c:	30 40       	sbci	r19, 0x00	; 0
     87e:	30 93 a2 03 	sts	0x03A2, r19
     882:	20 93 a1 03 	sts	0x03A1, r18
     886:	00 97       	sbiw	r24, 0x00	; 0
     888:	09 f0       	breq	.+2      	;  0x88c
     88a:	0c cf       	rjmp	.-488    	;  0x6a4
     88c:	80 e0       	ldi	r24, 0x00	; 0
     88e:	90 e0       	ldi	r25, 0x00	; 0
     890:	65 96       	adiw	r28, 0x15	; 21
     892:	0f b6       	in	r0, 0x3f	; 63
     894:	f8 94       	cli
     896:	de bf       	out	0x3e, r29	; 62
     898:	0f be       	out	0x3f, r0	; 63
     89a:	cd bf       	out	0x3d, r28	; 61
     89c:	cf 91       	pop	r28
     89e:	df 91       	pop	r29
     8a0:	1f 91       	pop	r17
     8a2:	0f 91       	pop	r16
     8a4:	ff 90       	pop	r15
     8a6:	ef 90       	pop	r14
     8a8:	df 90       	pop	r13
     8aa:	bf 90       	pop	r11
     8ac:	af 90       	pop	r10
     8ae:	9f 90       	pop	r9
     8b0:	8f 90       	pop	r8
     8b2:	7f 90       	pop	r7
     8b4:	6f 90       	pop	r6
     8b6:	5f 90       	pop	r5
     8b8:	4f 90       	pop	r4
     8ba:	3f 90       	pop	r3
     8bc:	2f 90       	pop	r2
     8be:	08 95       	ret
     8c0:	30 91 9c 03 	lds	r19, 0x039C
     8c4:	40 91 9d 03 	lds	r20, 0x039D
     8c8:	34 17       	cp	r19, r20
     8ca:	09 f0       	breq	.+2      	;  0x8ce
     8cc:	96 cf       	rjmp	.-212    	;  0x7fa
     8ce:	90 cf       	rjmp	.-224    	;  0x7f0
     8d0:	cf 93       	push	r28
     8d2:	df 93       	push	r29
     8d4:	81 b3       	in	r24, 0x11	; 17
     8d6:	80 67       	ori	r24, 0x70	; 112
     8d8:	81 bb       	out	0x11, r24	; 17
     8da:	8f ef       	ldi	r24, 0xFF	; 255
     8dc:	84 bb       	out	0x14, r24	; 20
     8de:	8f ef       	ldi	r24, 0xFF	; 255
     8e0:	90 e7       	ldi	r25, 0x70	; 112
     8e2:	a2 e0       	ldi	r26, 0x02	; 2
     8e4:	81 50       	subi	r24, 0x01	; 1
     8e6:	90 40       	sbci	r25, 0x00	; 0
     8e8:	a0 40       	sbci	r26, 0x00	; 0
     8ea:	e1 f7       	brne	.-8      	;  0x8e4
     8ec:	00 c0       	rjmp	.+0      	;  0x8ee
     8ee:	00 00       	nop
     8f0:	82 ee       	ldi	r24, 0xE2	; 226
     8f2:	60 e0       	ldi	r22, 0x00	; 0
     8f4:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     8f8:	8f ef       	ldi	r24, 0xFF	; 255
     8fa:	99 e6       	ldi	r25, 0x69	; 105
     8fc:	a8 e1       	ldi	r26, 0x18	; 24
     8fe:	81 50       	subi	r24, 0x01	; 1
     900:	90 40       	sbci	r25, 0x00	; 0
     902:	a0 40       	sbci	r26, 0x00	; 0
     904:	e1 f7       	brne	.-8      	;  0x8fe
     906:	00 c0       	rjmp	.+0      	;  0x908
     908:	00 00       	nop
     90a:	81 ea       	ldi	r24, 0xA1	; 161
     90c:	60 e0       	ldi	r22, 0x00	; 0
     90e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     912:	82 ea       	ldi	r24, 0xA2	; 162
     914:	60 e0       	ldi	r22, 0x00	; 0
     916:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     91a:	8c e2       	ldi	r24, 0x2C	; 44
     91c:	60 e0       	ldi	r22, 0x00	; 0
     91e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     922:	8e e2       	ldi	r24, 0x2E	; 46
     924:	60 e0       	ldi	r22, 0x00	; 0
     926:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     92a:	8f e2       	ldi	r24, 0x2F	; 47
     92c:	60 e0       	ldi	r22, 0x00	; 0
     92e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     932:	86 ea       	ldi	r24, 0xA6	; 166
     934:	60 e0       	ldi	r22, 0x00	; 0
     936:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     93a:	8f e8       	ldi	r24, 0x8F	; 143
     93c:	60 e0       	ldi	r22, 0x00	; 0
     93e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     942:	84 ea       	ldi	r24, 0xA4	; 164
     944:	60 e0       	ldi	r22, 0x00	; 0
     946:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     94a:	8f ea       	ldi	r24, 0xAF	; 175
     94c:	60 e0       	ldi	r22, 0x00	; 0
     94e:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     952:	80 e4       	ldi	r24, 0x40	; 64
     954:	60 e0       	ldi	r22, 0x00	; 0
     956:	0e 94 5c 01 	call	0x2b8	;  0x2b8
     95a:	80 e0       	ldi	r24, 0x00	; 0
     95c:	60 e0       	ldi	r22, 0x00	; 0
     95e:	0e 94 fa 01 	call	0x3f4	;  0x3f4
     962:	c0 e0       	ldi	r28, 0x00	; 0
     964:	d0 e0       	ldi	r29, 0x00	; 0
     966:	8c 2f       	mov	r24, r28
     968:	0e 94 80 01 	call	0x300	;  0x300
     96c:	89 e7       	ldi	r24, 0x79	; 121
     96e:	90 e0       	ldi	r25, 0x00	; 0
     970:	0e 94 0a 02 	call	0x414	;  0x414
     974:	21 96       	adiw	r28, 0x01	; 1
     976:	c6 30       	cpi	r28, 0x06	; 6
     978:	d1 05       	cpc	r29, r1
     97a:	a9 f7       	brne	.-22     	;  0x966
     97c:	8f ef       	ldi	r24, 0xFF	; 255
     97e:	90 e7       	ldi	r25, 0x70	; 112
     980:	a2 e0       	ldi	r26, 0x02	; 2
     982:	81 50       	subi	r24, 0x01	; 1
     984:	90 40       	sbci	r25, 0x00	; 0
     986:	a0 40       	sbci	r26, 0x00	; 0
     988:	e1 f7       	brne	.-8      	;  0x982
     98a:	00 c0       	rjmp	.+0      	;  0x98c
     98c:	00 00       	nop
     98e:	df 91       	pop	r29
     990:	cf 91       	pop	r28
     992:	08 95       	ret
     994:	97 fb       	bst	r25, 7
     996:	09 2e       	mov	r0, r25
     998:	07 26       	eor	r0, r23
     99a:	0a d0       	rcall	.+20     	;  0x9b0
     99c:	77 fd       	sbrc	r23, 7
     99e:	04 d0       	rcall	.+8      	;  0x9a8
     9a0:	43 d0       	rcall	.+134    	;  0xa28
     9a2:	06 d0       	rcall	.+12     	;  0x9b0
     9a4:	00 20       	and	r0, r0
     9a6:	1a f4       	brpl	.+6      	;  0x9ae
     9a8:	70 95       	com	r23
     9aa:	61 95       	neg	r22
     9ac:	7f 4f       	sbci	r23, 0xFF	; 255
     9ae:	08 95       	ret
     9b0:	f6 f7       	brtc	.-4      	;  0x9ae
     9b2:	90 95       	com	r25
     9b4:	81 95       	neg	r24
     9b6:	9f 4f       	sbci	r25, 0xFF	; 255
     9b8:	08 95       	ret
     9ba:	2f 92       	push	r2
     9bc:	3f 92       	push	r3
     9be:	4f 92       	push	r4
     9c0:	5f 92       	push	r5
     9c2:	6f 92       	push	r6
     9c4:	7f 92       	push	r7
     9c6:	8f 92       	push	r8
     9c8:	9f 92       	push	r9
     9ca:	af 92       	push	r10
     9cc:	bf 92       	push	r11
     9ce:	cf 92       	push	r12
     9d0:	df 92       	push	r13
     9d2:	ef 92       	push	r14
     9d4:	ff 92       	push	r15
     9d6:	0f 93       	push	r16
     9d8:	1f 93       	push	r17
     9da:	cf 93       	push	r28
     9dc:	df 93       	push	r29
     9de:	cd b7       	in	r28, 0x3d	; 61
     9e0:	de b7       	in	r29, 0x3e	; 62
     9e2:	ca 1b       	sub	r28, r26
     9e4:	db 0b       	sbc	r29, r27
     9e6:	0f b6       	in	r0, 0x3f	; 63
     9e8:	f8 94       	cli
     9ea:	de bf       	out	0x3e, r29	; 62
     9ec:	0f be       	out	0x3f, r0	; 63
     9ee:	cd bf       	out	0x3d, r28	; 61
     9f0:	09 94       	ijmp
     9f2:	2a 88       	ldd	r2, Y+18	; 0x12
     9f4:	39 88       	ldd	r3, Y+17	; 0x11
     9f6:	48 88       	ldd	r4, Y+16	; 0x10
     9f8:	5f 84       	ldd	r5, Y+15	; 0x0f
     9fa:	6e 84       	ldd	r6, Y+14	; 0x0e
     9fc:	7d 84       	ldd	r7, Y+13	; 0x0d
     9fe:	8c 84       	ldd	r8, Y+12	; 0x0c
     a00:	9b 84       	ldd	r9, Y+11	; 0x0b
     a02:	aa 84       	ldd	r10, Y+10	; 0x0a
     a04:	b9 84       	ldd	r11, Y+9	; 0x09
     a06:	c8 84       	ldd	r12, Y+8	; 0x08
     a08:	df 80       	ldd	r13, Y+7	; 0x07
     a0a:	ee 80       	ldd	r14, Y+6	; 0x06
     a0c:	fd 80       	ldd	r15, Y+5	; 0x05
     a0e:	0c 81       	ldd	r16, Y+4	; 0x04
     a10:	1b 81       	ldd	r17, Y+3	; 0x03
     a12:	aa 81       	ldd	r26, Y+2	; 0x02
     a14:	b9 81       	ldd	r27, Y+1	; 0x01
     a16:	ce 0f       	add	r28, r30
     a18:	d1 1d       	adc	r29, r1
     a1a:	0f b6       	in	r0, 0x3f	; 63
     a1c:	f8 94       	cli
     a1e:	de bf       	out	0x3e, r29	; 62
     a20:	0f be       	out	0x3f, r0	; 63
     a22:	cd bf       	out	0x3d, r28	; 61
     a24:	ed 01       	movw	r28, r26
     a26:	08 95       	ret
     a28:	aa 1b       	sub	r26, r26
     a2a:	bb 1b       	sub	r27, r27
     a2c:	51 e1       	ldi	r21, 0x11	; 17
     a2e:	07 c0       	rjmp	.+14     	;  0xa3e
     a30:	aa 1f       	adc	r26, r26
     a32:	bb 1f       	adc	r27, r27
     a34:	a6 17       	cp	r26, r22
     a36:	b7 07       	cpc	r27, r23
     a38:	10 f0       	brcs	.+4      	;  0xa3e
     a3a:	a6 1b       	sub	r26, r22
     a3c:	b7 0b       	sbc	r27, r23
     a3e:	88 1f       	adc	r24, r24
     a40:	99 1f       	adc	r25, r25
     a42:	5a 95       	dec	r21
     a44:	a9 f7       	brne	.-22     	;  0xa30
     a46:	80 95       	com	r24
     a48:	90 95       	com	r25
     a4a:	bc 01       	movw	r22, r24
     a4c:	cd 01       	movw	r24, r26
     a4e:	08 95       	ret
     a50:	ee 0f       	add	r30, r30
     a52:	ff 1f       	adc	r31, r31
     a54:	05 90       	lpm	r0, Z+
     a56:	f4 91       	lpm	r31, Z+
     a58:	e0 2d       	mov	r30, r0
     a5a:	09 94       	ijmp
     a5c:	a0 e0       	ldi	r26, 0x00	; 0
     a5e:	b0 e0       	ldi	r27, 0x00	; 0
     a60:	e4 e3       	ldi	r30, 0x34	; 52
     a62:	f5 e0       	ldi	r31, 0x05	; 5
     a64:	0c 94 e5 04 	jmp	0x9ca	;  0x9ca
     a68:	ec 01       	movw	r28, r24
     a6a:	68 81       	ld	r22, Y
     a6c:	79 81       	ldd	r23, Y+1	; 0x01
     a6e:	8a 81       	ldd	r24, Y+2	; 0x02
     a70:	9b 81       	ldd	r25, Y+3	; 0x03
     a72:	61 15       	cp	r22, r1
     a74:	71 05       	cpc	r23, r1
     a76:	81 05       	cpc	r24, r1
     a78:	91 05       	cpc	r25, r1
     a7a:	21 f4       	brne	.+8      	;  0xa84
     a7c:	64 e2       	ldi	r22, 0x24	; 36
     a7e:	79 ed       	ldi	r23, 0xD9	; 217
     a80:	8b e5       	ldi	r24, 0x5B	; 91
     a82:	97 e0       	ldi	r25, 0x07	; 7
     a84:	2d e1       	ldi	r18, 0x1D	; 29
     a86:	33 ef       	ldi	r19, 0xF3	; 243
     a88:	41 e0       	ldi	r20, 0x01	; 1
     a8a:	50 e0       	ldi	r21, 0x00	; 0
     a8c:	0e 94 4b 08 	call	0x1096	;  0x1096
     a90:	79 01       	movw	r14, r18
     a92:	8a 01       	movw	r16, r20
     a94:	27 ea       	ldi	r18, 0xA7	; 167
     a96:	31 e4       	ldi	r19, 0x41	; 65
     a98:	40 e0       	ldi	r20, 0x00	; 0
     a9a:	50 e0       	ldi	r21, 0x00	; 0
     a9c:	0e 94 2c 08 	call	0x1058	;  0x1058
     aa0:	5b 01       	movw	r10, r22
     aa2:	6c 01       	movw	r12, r24
     aa4:	c8 01       	movw	r24, r16
     aa6:	b7 01       	movw	r22, r14
     aa8:	2c ee       	ldi	r18, 0xEC	; 236
     aaa:	34 ef       	ldi	r19, 0xF4	; 244
     aac:	4f ef       	ldi	r20, 0xFF	; 255
     aae:	5f ef       	ldi	r21, 0xFF	; 255
     ab0:	0e 94 2c 08 	call	0x1058	;  0x1058
     ab4:	6a 0d       	add	r22, r10
     ab6:	7b 1d       	adc	r23, r11
     ab8:	8c 1d       	adc	r24, r12
     aba:	9d 1d       	adc	r25, r13
     abc:	97 ff       	sbrs	r25, 7
     abe:	04 c0       	rjmp	.+8      	;  0xac8
     ac0:	61 50       	subi	r22, 0x01	; 1
     ac2:	70 40       	sbci	r23, 0x00	; 0
     ac4:	80 40       	sbci	r24, 0x00	; 0
     ac6:	90 48       	sbci	r25, 0x80	; 128
     ac8:	68 83       	st	Y, r22
     aca:	79 83       	std	Y+1, r23	; 0x01
     acc:	8a 83       	std	Y+2, r24	; 0x02
     ace:	9b 83       	std	Y+3, r25	; 0x03
     ad0:	7f 77       	andi	r23, 0x7F	; 127
     ad2:	cb 01       	movw	r24, r22
     ad4:	cd b7       	in	r28, 0x3d	; 61
     ad6:	de b7       	in	r29, 0x3e	; 62
     ad8:	ea e0       	ldi	r30, 0x0A	; 10
     ada:	0c 94 01 05 	jmp	0xa02	;  0xa02
     ade:	0e 94 2e 05 	call	0xa5c	;  0xa5c
     ae2:	08 95       	ret
     ae4:	8e e8       	ldi	r24, 0x8E	; 142
     ae6:	90 e0       	ldi	r25, 0x00	; 0
     ae8:	0e 94 2e 05 	call	0xa5c	;  0xa5c
     aec:	08 95       	ret
     aee:	a0 e0       	ldi	r26, 0x00	; 0
     af0:	b0 e0       	ldi	r27, 0x00	; 0
     af2:	80 93 8e 00 	sts	0x008E, r24
     af6:	90 93 8f 00 	sts	0x008F, r25
     afa:	a0 93 90 00 	sts	0x0090, r26
     afe:	b0 93 91 00 	sts	0x0091, r27
     b02:	08 95       	ret
     b04:	ae e0       	ldi	r26, 0x0E	; 14
     b06:	b0 e0       	ldi	r27, 0x00	; 0
     b08:	e8 e8       	ldi	r30, 0x88	; 136
     b0a:	f5 e0       	ldi	r31, 0x05	; 5
     b0c:	0c 94 eb 04 	jmp	0x9d6	;  0x9d6
     b10:	0d 89       	ldd	r16, Y+21	; 0x15
     b12:	1e 89       	ldd	r17, Y+22	; 0x16
     b14:	86 e0       	ldi	r24, 0x06	; 6
     b16:	8c 83       	std	Y+4, r24	; 0x04
     b18:	1a 83       	std	Y+2, r17	; 0x02
     b1a:	09 83       	std	Y+1, r16	; 0x01
     b1c:	8f ef       	ldi	r24, 0xFF	; 255
     b1e:	9f e7       	ldi	r25, 0x7F	; 127
     b20:	9e 83       	std	Y+6, r25	; 0x06
     b22:	8d 83       	std	Y+5, r24	; 0x05
     b24:	9e 01       	movw	r18, r28
     b26:	27 5e       	subi	r18, 0xE7	; 231
     b28:	3f 4f       	sbci	r19, 0xFF	; 255
     b2a:	ce 01       	movw	r24, r28
     b2c:	01 96       	adiw	r24, 0x01	; 1
     b2e:	6f 89       	ldd	r22, Y+23	; 0x17
     b30:	78 8d       	ldd	r23, Y+24	; 0x18
     b32:	a9 01       	movw	r20, r18
     b34:	0e 94 a5 05 	call	0xb4a	;  0xb4a
     b38:	ef 81       	ldd	r30, Y+7	; 0x07
     b3a:	f8 85       	ldd	r31, Y+8	; 0x08
     b3c:	e0 0f       	add	r30, r16
     b3e:	f1 1f       	adc	r31, r17
     b40:	10 82       	st	Z, r1
     b42:	2e 96       	adiw	r28, 0x0e	; 14
     b44:	e4 e0       	ldi	r30, 0x04	; 4
     b46:	0c 94 07 05 	jmp	0xa0e	;  0xa0e
     b4a:	ac e0       	ldi	r26, 0x0C	; 12
     b4c:	b0 e0       	ldi	r27, 0x00	; 0
     b4e:	eb ea       	ldi	r30, 0xAB	; 171
     b50:	f5 e0       	ldi	r31, 0x05	; 5
     b52:	0c 94 dd 04 	jmp	0x9ba	;  0x9ba
     b56:	6c 01       	movw	r12, r24
     b58:	1b 01       	movw	r2, r22
     b5a:	8a 01       	movw	r16, r20
     b5c:	fc 01       	movw	r30, r24
     b5e:	17 82       	std	Z+7, r1	; 0x07
     b60:	16 82       	std	Z+6, r1	; 0x06
     b62:	83 81       	ldd	r24, Z+3	; 0x03
     b64:	81 ff       	sbrs	r24, 1
     b66:	d1 c1       	rjmp	.+930    	;  0xf0a
     b68:	2e 01       	movw	r4, r28
     b6a:	08 94       	sec
     b6c:	41 1c       	adc	r4, r1
     b6e:	51 1c       	adc	r5, r1
     b70:	f6 01       	movw	r30, r12
     b72:	93 81       	ldd	r25, Z+3	; 0x03
     b74:	f1 01       	movw	r30, r2
     b76:	93 fd       	sbrc	r25, 3
     b78:	85 91       	lpm	r24, Z+
     b7a:	93 ff       	sbrs	r25, 3
     b7c:	81 91       	ld	r24, Z+
     b7e:	1f 01       	movw	r2, r30
     b80:	88 23       	and	r24, r24
     b82:	09 f4       	brne	.+2      	;  0xb86
     b84:	be c1       	rjmp	.+892    	;  0xf02
     b86:	85 32       	cpi	r24, 0x25	; 37
     b88:	39 f4       	brne	.+14     	;  0xb98
     b8a:	93 fd       	sbrc	r25, 3
     b8c:	85 91       	lpm	r24, Z+
     b8e:	93 ff       	sbrs	r25, 3
     b90:	81 91       	ld	r24, Z+
     b92:	1f 01       	movw	r2, r30
     b94:	85 32       	cpi	r24, 0x25	; 37
     b96:	29 f4       	brne	.+10     	;  0xba2
     b98:	90 e0       	ldi	r25, 0x00	; 0
     b9a:	b6 01       	movw	r22, r12
     b9c:	0e 94 a2 07 	call	0xf44	;  0xf44
     ba0:	e7 cf       	rjmp	.-50     	;  0xb70
     ba2:	ee 24       	eor	r14, r14
     ba4:	ff 24       	eor	r15, r15
     ba6:	20 e0       	ldi	r18, 0x00	; 0
     ba8:	20 32       	cpi	r18, 0x20	; 32
     baa:	b0 f4       	brcc	.+44     	;  0xbd8
     bac:	8b 32       	cpi	r24, 0x2B	; 43
     bae:	69 f0       	breq	.+26     	;  0xbca
     bb0:	8c 32       	cpi	r24, 0x2C	; 44
     bb2:	28 f4       	brcc	.+10     	;  0xbbe
     bb4:	80 32       	cpi	r24, 0x20	; 32
     bb6:	51 f0       	breq	.+20     	;  0xbcc
     bb8:	83 32       	cpi	r24, 0x23	; 35
     bba:	71 f4       	brne	.+28     	;  0xbd8
     bbc:	0b c0       	rjmp	.+22     	;  0xbd4
     bbe:	8d 32       	cpi	r24, 0x2D	; 45
     bc0:	39 f0       	breq	.+14     	;  0xbd0
     bc2:	80 33       	cpi	r24, 0x30	; 48
     bc4:	49 f4       	brne	.+18     	;  0xbd8
     bc6:	21 60       	ori	r18, 0x01	; 1
     bc8:	2c c0       	rjmp	.+88     	;  0xc22
     bca:	22 60       	ori	r18, 0x02	; 2
     bcc:	24 60       	ori	r18, 0x04	; 4
     bce:	29 c0       	rjmp	.+82     	;  0xc22
     bd0:	28 60       	ori	r18, 0x08	; 8
     bd2:	27 c0       	rjmp	.+78     	;  0xc22
     bd4:	20 61       	ori	r18, 0x10	; 16
     bd6:	25 c0       	rjmp	.+74     	;  0xc22
     bd8:	27 fd       	sbrc	r18, 7
     bda:	2c c0       	rjmp	.+88     	;  0xc34
     bdc:	38 2f       	mov	r19, r24
     bde:	30 53       	subi	r19, 0x30	; 48
     be0:	3a 30       	cpi	r19, 0x0A	; 10
     be2:	98 f4       	brcc	.+38     	;  0xc0a
     be4:	26 ff       	sbrs	r18, 6
     be6:	08 c0       	rjmp	.+16     	;  0xbf8
     be8:	8e 2d       	mov	r24, r14
     bea:	88 0f       	add	r24, r24
     bec:	e8 2e       	mov	r14, r24
     bee:	ee 0c       	add	r14, r14
     bf0:	ee 0c       	add	r14, r14
     bf2:	e8 0e       	add	r14, r24
     bf4:	e3 0e       	add	r14, r19
     bf6:	15 c0       	rjmp	.+42     	;  0xc22
     bf8:	8f 2d       	mov	r24, r15
     bfa:	88 0f       	add	r24, r24
     bfc:	f8 2e       	mov	r15, r24
     bfe:	ff 0c       	add	r15, r15
     c00:	ff 0c       	add	r15, r15
     c02:	f8 0e       	add	r15, r24
     c04:	f3 0e       	add	r15, r19
     c06:	20 62       	ori	r18, 0x20	; 32
     c08:	0c c0       	rjmp	.+24     	;  0xc22
     c0a:	8e 32       	cpi	r24, 0x2E	; 46
     c0c:	21 f4       	brne	.+8      	;  0xc16
     c0e:	26 fd       	sbrc	r18, 6
     c10:	78 c1       	rjmp	.+752    	;  0xf02
     c12:	20 64       	ori	r18, 0x40	; 64
     c14:	06 c0       	rjmp	.+12     	;  0xc22
     c16:	8c 36       	cpi	r24, 0x6C	; 108
     c18:	11 f4       	brne	.+4      	;  0xc1e
     c1a:	20 68       	ori	r18, 0x80	; 128
     c1c:	02 c0       	rjmp	.+4      	;  0xc22
     c1e:	88 36       	cpi	r24, 0x68	; 104
     c20:	49 f4       	brne	.+18     	;  0xc34
     c22:	f1 01       	movw	r30, r2
     c24:	93 fd       	sbrc	r25, 3
     c26:	85 91       	lpm	r24, Z+
     c28:	93 ff       	sbrs	r25, 3
     c2a:	81 91       	ld	r24, Z+
     c2c:	1f 01       	movw	r2, r30
     c2e:	88 23       	and	r24, r24
     c30:	09 f0       	breq	.+2      	;  0xc34
     c32:	ba cf       	rjmp	.-140    	;  0xba8
     c34:	98 2f       	mov	r25, r24
     c36:	95 54       	subi	r25, 0x45	; 69
     c38:	93 30       	cpi	r25, 0x03	; 3
     c3a:	18 f0       	brcs	.+6      	;  0xc42
     c3c:	90 52       	subi	r25, 0x20	; 32
     c3e:	93 30       	cpi	r25, 0x03	; 3
     c40:	28 f4       	brcc	.+10     	;  0xc4c
     c42:	0c 5f       	subi	r16, 0xFC	; 252
     c44:	1f 4f       	sbci	r17, 0xFF	; 255
     c46:	ff e3       	ldi	r31, 0x3F	; 63
     c48:	f9 83       	std	Y+1, r31	; 0x01
     c4a:	0d c0       	rjmp	.+26     	;  0xc66
     c4c:	83 36       	cpi	r24, 0x63	; 99
     c4e:	31 f0       	breq	.+12     	;  0xc5c
     c50:	83 37       	cpi	r24, 0x73	; 115
     c52:	71 f0       	breq	.+28     	;  0xc70
     c54:	83 35       	cpi	r24, 0x53	; 83
     c56:	09 f0       	breq	.+2      	;  0xc5a
     c58:	60 c0       	rjmp	.+192    	;  0xd1a
     c5a:	22 c0       	rjmp	.+68     	;  0xca0
     c5c:	f8 01       	movw	r30, r16
     c5e:	80 81       	ld	r24, Z
     c60:	89 83       	std	Y+1, r24	; 0x01
     c62:	0e 5f       	subi	r16, 0xFE	; 254
     c64:	1f 4f       	sbci	r17, 0xFF	; 255
     c66:	42 01       	movw	r8, r4
     c68:	71 e0       	ldi	r23, 0x01	; 1
     c6a:	a7 2e       	mov	r10, r23
     c6c:	b1 2c       	mov	r11, r1
     c6e:	16 c0       	rjmp	.+44     	;  0xc9c
     c70:	62 e0       	ldi	r22, 0x02	; 2
     c72:	66 2e       	mov	r6, r22
     c74:	71 2c       	mov	r7, r1
     c76:	60 0e       	add	r6, r16
     c78:	71 1e       	adc	r7, r17
     c7a:	f8 01       	movw	r30, r16
     c7c:	80 80       	ld	r8, Z
     c7e:	91 80       	ldd	r9, Z+1	; 0x01
     c80:	26 ff       	sbrs	r18, 6
     c82:	03 c0       	rjmp	.+6      	;  0xc8a
     c84:	6e 2d       	mov	r22, r14
     c86:	70 e0       	ldi	r23, 0x00	; 0
     c88:	02 c0       	rjmp	.+4      	;  0xc8e
     c8a:	6f ef       	ldi	r22, 0xFF	; 255
     c8c:	7f ef       	ldi	r23, 0xFF	; 255
     c8e:	c4 01       	movw	r24, r8
     c90:	2c 87       	std	Y+12, r18	; 0x0c
     c92:	0e 94 97 07 	call	0xf2e	;  0xf2e
     c96:	5c 01       	movw	r10, r24
     c98:	83 01       	movw	r16, r6
     c9a:	2c 85       	ldd	r18, Y+12	; 0x0c
     c9c:	2f 77       	andi	r18, 0x7F	; 127
     c9e:	17 c0       	rjmp	.+46     	;  0xcce
     ca0:	52 e0       	ldi	r21, 0x02	; 2
     ca2:	65 2e       	mov	r6, r21
     ca4:	71 2c       	mov	r7, r1
     ca6:	60 0e       	add	r6, r16
     ca8:	71 1e       	adc	r7, r17
     caa:	f8 01       	movw	r30, r16
     cac:	80 80       	ld	r8, Z
     cae:	91 80       	ldd	r9, Z+1	; 0x01
     cb0:	26 ff       	sbrs	r18, 6
     cb2:	03 c0       	rjmp	.+6      	;  0xcba
     cb4:	6e 2d       	mov	r22, r14
     cb6:	70 e0       	ldi	r23, 0x00	; 0
     cb8:	02 c0       	rjmp	.+4      	;  0xcbe
     cba:	6f ef       	ldi	r22, 0xFF	; 255
     cbc:	7f ef       	ldi	r23, 0xFF	; 255
     cbe:	c4 01       	movw	r24, r8
     cc0:	2c 87       	std	Y+12, r18	; 0x0c
     cc2:	0e 94 8c 07 	call	0xf18	;  0xf18
     cc6:	5c 01       	movw	r10, r24
     cc8:	2c 85       	ldd	r18, Y+12	; 0x0c
     cca:	20 68       	ori	r18, 0x80	; 128
     ccc:	83 01       	movw	r16, r6
     cce:	23 fd       	sbrc	r18, 3
     cd0:	20 c0       	rjmp	.+64     	;  0xd12
     cd2:	08 c0       	rjmp	.+16     	;  0xce4
     cd4:	80 e2       	ldi	r24, 0x20	; 32
     cd6:	90 e0       	ldi	r25, 0x00	; 0
     cd8:	b6 01       	movw	r22, r12
     cda:	2c 87       	std	Y+12, r18	; 0x0c
     cdc:	0e 94 a2 07 	call	0xf44	;  0xf44
     ce0:	fa 94       	dec	r15
     ce2:	2c 85       	ldd	r18, Y+12	; 0x0c
     ce4:	8f 2d       	mov	r24, r15
     ce6:	90 e0       	ldi	r25, 0x00	; 0
     ce8:	a8 16       	cp	r10, r24
     cea:	b9 06       	cpc	r11, r25
     cec:	98 f3       	brcs	.-26     	;  0xcd4
     cee:	11 c0       	rjmp	.+34     	;  0xd12
     cf0:	f4 01       	movw	r30, r8
     cf2:	27 fd       	sbrc	r18, 7
     cf4:	85 91       	lpm	r24, Z+
     cf6:	27 ff       	sbrs	r18, 7
     cf8:	81 91       	ld	r24, Z+
     cfa:	4f 01       	movw	r8, r30
     cfc:	90 e0       	ldi	r25, 0x00	; 0
     cfe:	b6 01       	movw	r22, r12
     d00:	2c 87       	std	Y+12, r18	; 0x0c
     d02:	0e 94 a2 07 	call	0xf44	;  0xf44
     d06:	2c 85       	ldd	r18, Y+12	; 0x0c
     d08:	f1 10       	cpse	r15, r1
     d0a:	fa 94       	dec	r15
     d0c:	08 94       	sec
     d0e:	a1 08       	sbc	r10, r1
     d10:	b1 08       	sbc	r11, r1
     d12:	a1 14       	cp	r10, r1
     d14:	b1 04       	cpc	r11, r1
     d16:	61 f7       	brne	.-40     	;  0xcf0
     d18:	f1 c0       	rjmp	.+482    	;  0xefc
     d1a:	84 36       	cpi	r24, 0x64	; 100
     d1c:	11 f0       	breq	.+4      	;  0xd22
     d1e:	89 36       	cpi	r24, 0x69	; 105
     d20:	49 f5       	brne	.+82     	;  0xd74
     d22:	27 ff       	sbrs	r18, 7
     d24:	08 c0       	rjmp	.+16     	;  0xd36
     d26:	f8 01       	movw	r30, r16
     d28:	60 81       	ld	r22, Z
     d2a:	71 81       	ldd	r23, Z+1	; 0x01
     d2c:	82 81       	ldd	r24, Z+2	; 0x02
     d2e:	93 81       	ldd	r25, Z+3	; 0x03
     d30:	0c 5f       	subi	r16, 0xFC	; 252
     d32:	1f 4f       	sbci	r17, 0xFF	; 255
     d34:	09 c0       	rjmp	.+18     	;  0xd48
     d36:	f8 01       	movw	r30, r16
     d38:	60 81       	ld	r22, Z
     d3a:	71 81       	ldd	r23, Z+1	; 0x01
     d3c:	88 27       	eor	r24, r24
     d3e:	77 fd       	sbrc	r23, 7
     d40:	80 95       	com	r24
     d42:	98 2f       	mov	r25, r24
     d44:	0e 5f       	subi	r16, 0xFE	; 254
     d46:	1f 4f       	sbci	r17, 0xFF	; 255
     d48:	4f e6       	ldi	r20, 0x6F	; 111
     d4a:	b4 2e       	mov	r11, r20
     d4c:	b2 22       	and	r11, r18
     d4e:	97 ff       	sbrs	r25, 7
     d50:	09 c0       	rjmp	.+18     	;  0xd64
     d52:	90 95       	com	r25
     d54:	80 95       	com	r24
     d56:	70 95       	com	r23
     d58:	61 95       	neg	r22
     d5a:	7f 4f       	sbci	r23, 0xFF	; 255
     d5c:	8f 4f       	sbci	r24, 0xFF	; 255
     d5e:	9f 4f       	sbci	r25, 0xFF	; 255
     d60:	f0 e8       	ldi	r31, 0x80	; 128
     d62:	bf 2a       	or	r11, r31
     d64:	a2 01       	movw	r20, r4
     d66:	2a e0       	ldi	r18, 0x0A	; 10
     d68:	30 e0       	ldi	r19, 0x00	; 0
     d6a:	0e 94 ce 07 	call	0xf9c	;  0xf9c
     d6e:	78 2e       	mov	r7, r24
     d70:	74 18       	sub	r7, r4
     d72:	45 c0       	rjmp	.+138    	;  0xdfe
     d74:	85 37       	cpi	r24, 0x75	; 117
     d76:	31 f4       	brne	.+12     	;  0xd84
     d78:	3f ee       	ldi	r19, 0xEF	; 239
     d7a:	b3 2e       	mov	r11, r19
     d7c:	b2 22       	and	r11, r18
     d7e:	2a e0       	ldi	r18, 0x0A	; 10
     d80:	30 e0       	ldi	r19, 0x00	; 0
     d82:	25 c0       	rjmp	.+74     	;  0xdce
     d84:	99 ef       	ldi	r25, 0xF9	; 249
     d86:	b9 2e       	mov	r11, r25
     d88:	b2 22       	and	r11, r18
     d8a:	8f 36       	cpi	r24, 0x6F	; 111
     d8c:	c1 f0       	breq	.+48     	;  0xdbe
     d8e:	80 37       	cpi	r24, 0x70	; 112
     d90:	20 f4       	brcc	.+8      	;  0xd9a
     d92:	88 35       	cpi	r24, 0x58	; 88
     d94:	09 f0       	breq	.+2      	;  0xd98
     d96:	b5 c0       	rjmp	.+362    	;  0xf02
     d98:	0d c0       	rjmp	.+26     	;  0xdb4
     d9a:	80 37       	cpi	r24, 0x70	; 112
     d9c:	21 f0       	breq	.+8      	;  0xda6
     d9e:	88 37       	cpi	r24, 0x78	; 120
     da0:	09 f0       	breq	.+2      	;  0xda4
     da2:	af c0       	rjmp	.+350    	;  0xf02
     da4:	02 c0       	rjmp	.+4      	;  0xdaa
     da6:	20 e1       	ldi	r18, 0x10	; 16
     da8:	b2 2a       	or	r11, r18
     daa:	b4 fe       	sbrs	r11, 4
     dac:	0b c0       	rjmp	.+22     	;  0xdc4
     dae:	84 e0       	ldi	r24, 0x04	; 4
     db0:	b8 2a       	or	r11, r24
     db2:	08 c0       	rjmp	.+16     	;  0xdc4
     db4:	b4 fe       	sbrs	r11, 4
     db6:	09 c0       	rjmp	.+18     	;  0xdca
     db8:	e6 e0       	ldi	r30, 0x06	; 6
     dba:	be 2a       	or	r11, r30
     dbc:	06 c0       	rjmp	.+12     	;  0xdca
     dbe:	28 e0       	ldi	r18, 0x08	; 8
     dc0:	30 e0       	ldi	r19, 0x00	; 0
     dc2:	05 c0       	rjmp	.+10     	;  0xdce
     dc4:	20 e1       	ldi	r18, 0x10	; 16
     dc6:	30 e0       	ldi	r19, 0x00	; 0
     dc8:	02 c0       	rjmp	.+4      	;  0xdce
     dca:	20 e1       	ldi	r18, 0x10	; 16
     dcc:	32 e0       	ldi	r19, 0x02	; 2
     dce:	b7 fe       	sbrs	r11, 7
     dd0:	08 c0       	rjmp	.+16     	;  0xde2
     dd2:	f8 01       	movw	r30, r16
     dd4:	60 81       	ld	r22, Z
     dd6:	71 81       	ldd	r23, Z+1	; 0x01
     dd8:	82 81       	ldd	r24, Z+2	; 0x02
     dda:	93 81       	ldd	r25, Z+3	; 0x03
     ddc:	0c 5f       	subi	r16, 0xFC	; 252
     dde:	1f 4f       	sbci	r17, 0xFF	; 255
     de0:	07 c0       	rjmp	.+14     	;  0xdf0
     de2:	f8 01       	movw	r30, r16
     de4:	60 81       	ld	r22, Z
     de6:	71 81       	ldd	r23, Z+1	; 0x01
     de8:	80 e0       	ldi	r24, 0x00	; 0
     dea:	90 e0       	ldi	r25, 0x00	; 0
     dec:	0e 5f       	subi	r16, 0xFE	; 254
     dee:	1f 4f       	sbci	r17, 0xFF	; 255
     df0:	a2 01       	movw	r20, r4
     df2:	0e 94 ce 07 	call	0xf9c	;  0xf9c
     df6:	78 2e       	mov	r7, r24
     df8:	74 18       	sub	r7, r4
     dfa:	ff e7       	ldi	r31, 0x7F	; 127
     dfc:	bf 22       	and	r11, r31
     dfe:	b6 fe       	sbrs	r11, 6
     e00:	0b c0       	rjmp	.+22     	;  0xe18
     e02:	2e ef       	ldi	r18, 0xFE	; 254
     e04:	b2 22       	and	r11, r18
     e06:	7e 14       	cp	r7, r14
     e08:	38 f4       	brcc	.+14     	;  0xe18
     e0a:	b4 fe       	sbrs	r11, 4
     e0c:	07 c0       	rjmp	.+14     	;  0xe1c
     e0e:	b2 fc       	sbrc	r11, 2
     e10:	05 c0       	rjmp	.+10     	;  0xe1c
     e12:	8f ee       	ldi	r24, 0xEF	; 239
     e14:	b8 22       	and	r11, r24
     e16:	02 c0       	rjmp	.+4      	;  0xe1c
     e18:	a7 2c       	mov	r10, r7
     e1a:	01 c0       	rjmp	.+2      	;  0xe1e
     e1c:	ae 2c       	mov	r10, r14
     e1e:	8b 2d       	mov	r24, r11
     e20:	90 e0       	ldi	r25, 0x00	; 0
     e22:	b4 fe       	sbrs	r11, 4
     e24:	0d c0       	rjmp	.+26     	;  0xe40
     e26:	fe 01       	movw	r30, r28
     e28:	e7 0d       	add	r30, r7
     e2a:	f1 1d       	adc	r31, r1
     e2c:	20 81       	ld	r18, Z
     e2e:	20 33       	cpi	r18, 0x30	; 48
     e30:	19 f4       	brne	.+6      	;  0xe38
     e32:	e9 ee       	ldi	r30, 0xE9	; 233
     e34:	be 22       	and	r11, r30
     e36:	09 c0       	rjmp	.+18     	;  0xe4a
     e38:	a3 94       	inc	r10
     e3a:	b2 fe       	sbrs	r11, 2
     e3c:	06 c0       	rjmp	.+12     	;  0xe4a
     e3e:	04 c0       	rjmp	.+8      	;  0xe48
     e40:	86 78       	andi	r24, 0x86	; 134
     e42:	90 70       	andi	r25, 0x00	; 0
     e44:	00 97       	sbiw	r24, 0x00	; 0
     e46:	09 f0       	breq	.+2      	;  0xe4a
     e48:	a3 94       	inc	r10
     e4a:	8b 2c       	mov	r8, r11
     e4c:	99 24       	eor	r9, r9
     e4e:	b3 fc       	sbrc	r11, 3
     e50:	14 c0       	rjmp	.+40     	;  0xe7a
     e52:	b0 fe       	sbrs	r11, 0
     e54:	0f c0       	rjmp	.+30     	;  0xe74
     e56:	af 14       	cp	r10, r15
     e58:	28 f4       	brcc	.+10     	;  0xe64
     e5a:	e7 2c       	mov	r14, r7
     e5c:	ef 0c       	add	r14, r15
     e5e:	ea 18       	sub	r14, r10
     e60:	af 2c       	mov	r10, r15
     e62:	08 c0       	rjmp	.+16     	;  0xe74
     e64:	e7 2c       	mov	r14, r7
     e66:	06 c0       	rjmp	.+12     	;  0xe74
     e68:	80 e2       	ldi	r24, 0x20	; 32
     e6a:	90 e0       	ldi	r25, 0x00	; 0
     e6c:	b6 01       	movw	r22, r12
     e6e:	0e 94 a2 07 	call	0xf44	;  0xf44
     e72:	a3 94       	inc	r10
     e74:	af 14       	cp	r10, r15
     e76:	c0 f3       	brcs	.-16     	;  0xe68
     e78:	04 c0       	rjmp	.+8      	;  0xe82
     e7a:	af 14       	cp	r10, r15
     e7c:	10 f4       	brcc	.+4      	;  0xe82
     e7e:	fa 18       	sub	r15, r10
     e80:	01 c0       	rjmp	.+2      	;  0xe84
     e82:	ff 24       	eor	r15, r15
     e84:	84 fe       	sbrs	r8, 4
     e86:	0f c0       	rjmp	.+30     	;  0xea6
     e88:	80 e3       	ldi	r24, 0x30	; 48
     e8a:	90 e0       	ldi	r25, 0x00	; 0
     e8c:	b6 01       	movw	r22, r12
     e8e:	0e 94 a2 07 	call	0xf44	;  0xf44
     e92:	82 fe       	sbrs	r8, 2
     e94:	1f c0       	rjmp	.+62     	;  0xed4
     e96:	81 fe       	sbrs	r8, 1
     e98:	03 c0       	rjmp	.+6      	;  0xea0
     e9a:	88 e5       	ldi	r24, 0x58	; 88
     e9c:	90 e0       	ldi	r25, 0x00	; 0
     e9e:	10 c0       	rjmp	.+32     	;  0xec0
     ea0:	88 e7       	ldi	r24, 0x78	; 120
     ea2:	90 e0       	ldi	r25, 0x00	; 0
     ea4:	0d c0       	rjmp	.+26     	;  0xec0
     ea6:	c4 01       	movw	r24, r8
     ea8:	86 78       	andi	r24, 0x86	; 134
     eaa:	90 70       	andi	r25, 0x00	; 0
     eac:	00 97       	sbiw	r24, 0x00	; 0
     eae:	91 f0       	breq	.+36     	;  0xed4
     eb0:	81 fc       	sbrc	r8, 1
     eb2:	02 c0       	rjmp	.+4      	;  0xeb8
     eb4:	80 e2       	ldi	r24, 0x20	; 32
     eb6:	01 c0       	rjmp	.+2      	;  0xeba
     eb8:	8b e2       	ldi	r24, 0x2B	; 43
     eba:	b7 fc       	sbrc	r11, 7
     ebc:	8d e2       	ldi	r24, 0x2D	; 45
     ebe:	90 e0       	ldi	r25, 0x00	; 0
     ec0:	b6 01       	movw	r22, r12
     ec2:	0e 94 a2 07 	call	0xf44	;  0xf44
     ec6:	06 c0       	rjmp	.+12     	;  0xed4
     ec8:	80 e3       	ldi	r24, 0x30	; 48
     eca:	90 e0       	ldi	r25, 0x00	; 0
     ecc:	b6 01       	movw	r22, r12
     ece:	0e 94 a2 07 	call	0xf44	;  0xf44
     ed2:	ea 94       	dec	r14
     ed4:	7e 14       	cp	r7, r14
     ed6:	c0 f3       	brcs	.-16     	;  0xec8
     ed8:	7a 94       	dec	r7
     eda:	f2 01       	movw	r30, r4
     edc:	e7 0d       	add	r30, r7
     ede:	f1 1d       	adc	r31, r1
     ee0:	80 81       	ld	r24, Z
     ee2:	90 e0       	ldi	r25, 0x00	; 0
     ee4:	b6 01       	movw	r22, r12
     ee6:	0e 94 a2 07 	call	0xf44	;  0xf44
     eea:	77 20       	and	r7, r7
     eec:	a9 f7       	brne	.-22     	;  0xed8
     eee:	06 c0       	rjmp	.+12     	;  0xefc
     ef0:	80 e2       	ldi	r24, 0x20	; 32
     ef2:	90 e0       	ldi	r25, 0x00	; 0
     ef4:	b6 01       	movw	r22, r12
     ef6:	0e 94 a2 07 	call	0xf44	;  0xf44
     efa:	fa 94       	dec	r15
     efc:	ff 20       	and	r15, r15
     efe:	c1 f7       	brne	.-16     	;  0xef0
     f00:	37 ce       	rjmp	.-914    	;  0xb70
     f02:	f6 01       	movw	r30, r12
     f04:	26 81       	ldd	r18, Z+6	; 0x06
     f06:	37 81       	ldd	r19, Z+7	; 0x07
     f08:	02 c0       	rjmp	.+4      	;  0xf0e
     f0a:	2f ef       	ldi	r18, 0xFF	; 255
     f0c:	3f ef       	ldi	r19, 0xFF	; 255
     f0e:	c9 01       	movw	r24, r18
     f10:	2c 96       	adiw	r28, 0x0c	; 12
     f12:	e2 e1       	ldi	r30, 0x12	; 18
     f14:	0c 94 f9 04 	jmp	0x9f2	;  0x9f2
     f18:	fc 01       	movw	r30, r24
     f1a:	05 90       	lpm	r0, Z+
     f1c:	61 50       	subi	r22, 0x01	; 1
     f1e:	70 40       	sbci	r23, 0x00	; 0
     f20:	01 10       	cpse	r0, r1
     f22:	d8 f7       	brcc	.-10     	;  0xf1a
     f24:	80 95       	com	r24
     f26:	90 95       	com	r25
     f28:	8e 0f       	add	r24, r30
     f2a:	9f 1f       	adc	r25, r31
     f2c:	08 95       	ret
     f2e:	fc 01       	movw	r30, r24
     f30:	61 50       	subi	r22, 0x01	; 1
     f32:	70 40       	sbci	r23, 0x00	; 0
     f34:	01 90       	ld	r0, Z+
     f36:	01 10       	cpse	r0, r1
     f38:	d8 f7       	brcc	.-10     	;  0xf30
     f3a:	80 95       	com	r24
     f3c:	90 95       	com	r25
     f3e:	8e 0f       	add	r24, r30
     f40:	9f 1f       	adc	r25, r31
     f42:	08 95       	ret
     f44:	0f 93       	push	r16
     f46:	1f 93       	push	r17
     f48:	cf 93       	push	r28
     f4a:	df 93       	push	r29
     f4c:	8c 01       	movw	r16, r24
     f4e:	eb 01       	movw	r28, r22
     f50:	8b 81       	ldd	r24, Y+3	; 0x03
     f52:	81 ff       	sbrs	r24, 1
     f54:	1b c0       	rjmp	.+54     	;  0xf8c
     f56:	82 ff       	sbrs	r24, 2
     f58:	0d c0       	rjmp	.+26     	;  0xf74
     f5a:	2e 81       	ldd	r18, Y+6	; 0x06
     f5c:	3f 81       	ldd	r19, Y+7	; 0x07
     f5e:	8c 81       	ldd	r24, Y+4	; 0x04
     f60:	9d 81       	ldd	r25, Y+5	; 0x05
     f62:	28 17       	cp	r18, r24
     f64:	39 07       	cpc	r19, r25
     f66:	64 f4       	brge	.+24     	;  0xf80
     f68:	e8 81       	ld	r30, Y
     f6a:	f9 81       	ldd	r31, Y+1	; 0x01
     f6c:	01 93       	st	Z+, r16
     f6e:	f9 83       	std	Y+1, r31	; 0x01
     f70:	e8 83       	st	Y, r30
     f72:	06 c0       	rjmp	.+12     	;  0xf80
     f74:	e8 85       	ldd	r30, Y+8	; 0x08
     f76:	f9 85       	ldd	r31, Y+9	; 0x09
     f78:	80 2f       	mov	r24, r16
     f7a:	09 95       	icall
     f7c:	00 97       	sbiw	r24, 0x00	; 0
     f7e:	31 f4       	brne	.+12     	;  0xf8c
     f80:	8e 81       	ldd	r24, Y+6	; 0x06
     f82:	9f 81       	ldd	r25, Y+7	; 0x07
     f84:	01 96       	adiw	r24, 0x01	; 1
     f86:	9f 83       	std	Y+7, r25	; 0x07
     f88:	8e 83       	std	Y+6, r24	; 0x06
     f8a:	02 c0       	rjmp	.+4      	;  0xf90
     f8c:	0f ef       	ldi	r16, 0xFF	; 255
     f8e:	1f ef       	ldi	r17, 0xFF	; 255
     f90:	c8 01       	movw	r24, r16
     f92:	df 91       	pop	r29
     f94:	cf 91       	pop	r28
     f96:	1f 91       	pop	r17
     f98:	0f 91       	pop	r16
     f9a:	08 95       	ret
     f9c:	fa 01       	movw	r30, r20
     f9e:	aa 27       	eor	r26, r26
     fa0:	28 30       	cpi	r18, 0x08	; 8
     fa2:	51 f1       	breq	.+84     	;  0xff8
     fa4:	20 31       	cpi	r18, 0x10	; 16
     fa6:	81 f1       	breq	.+96     	;  0x1008
     fa8:	e8 94       	clt
     faa:	6f 93       	push	r22
     fac:	6e 7f       	andi	r22, 0xFE	; 254
     fae:	6e 5f       	subi	r22, 0xFE	; 254
     fb0:	7f 4f       	sbci	r23, 0xFF	; 255
     fb2:	8f 4f       	sbci	r24, 0xFF	; 255
     fb4:	9f 4f       	sbci	r25, 0xFF	; 255
     fb6:	af 4f       	sbci	r26, 0xFF	; 255
     fb8:	b1 e0       	ldi	r27, 0x01	; 1
     fba:	3e d0       	rcall	.+124    	;  0x1038
     fbc:	b4 e0       	ldi	r27, 0x04	; 4
     fbe:	3c d0       	rcall	.+120    	;  0x1038
     fc0:	67 0f       	add	r22, r23
     fc2:	78 1f       	adc	r23, r24
     fc4:	89 1f       	adc	r24, r25
     fc6:	9a 1f       	adc	r25, r26
     fc8:	a1 1d       	adc	r26, r1
     fca:	68 0f       	add	r22, r24
     fcc:	79 1f       	adc	r23, r25
     fce:	8a 1f       	adc	r24, r26
     fd0:	91 1d       	adc	r25, r1
     fd2:	a1 1d       	adc	r26, r1
     fd4:	6a 0f       	add	r22, r26
     fd6:	71 1d       	adc	r23, r1
     fd8:	81 1d       	adc	r24, r1
     fda:	91 1d       	adc	r25, r1
     fdc:	a1 1d       	adc	r26, r1
     fde:	20 d0       	rcall	.+64     	;  0x1020
     fe0:	09 f4       	brne	.+2      	;  0xfe4
     fe2:	68 94       	set
     fe4:	3f 91       	pop	r19
     fe6:	2a e0       	ldi	r18, 0x0A	; 10
     fe8:	26 9f       	mul	r18, r22
     fea:	11 24       	eor	r1, r1
     fec:	30 19       	sub	r19, r0
     fee:	30 5d       	subi	r19, 0xD0	; 208
     ff0:	31 93       	st	Z+, r19
     ff2:	de f6       	brtc	.-74     	;  0xfaa
     ff4:	cf 01       	movw	r24, r30
     ff6:	08 95       	ret
     ff8:	46 2f       	mov	r20, r22
     ffa:	47 70       	andi	r20, 0x07	; 7
     ffc:	40 5d       	subi	r20, 0xD0	; 208
     ffe:	41 93       	st	Z+, r20
    1000:	b3 e0       	ldi	r27, 0x03	; 3
    1002:	0f d0       	rcall	.+30     	;  0x1022
    1004:	c9 f7       	brne	.-14     	;  0xff8
    1006:	f6 cf       	rjmp	.-20     	;  0xff4
    1008:	46 2f       	mov	r20, r22
    100a:	4f 70       	andi	r20, 0x0F	; 15
    100c:	40 5d       	subi	r20, 0xD0	; 208
    100e:	4a 33       	cpi	r20, 0x3A	; 58
    1010:	18 f0       	brcs	.+6      	;  0x1018
    1012:	49 5d       	subi	r20, 0xD9	; 217
    1014:	31 fd       	sbrc	r19, 1
    1016:	40 52       	subi	r20, 0x20	; 32
    1018:	41 93       	st	Z+, r20
    101a:	02 d0       	rcall	.+4      	;  0x1020
    101c:	a9 f7       	brne	.-22     	;  0x1008
    101e:	ea cf       	rjmp	.-44     	;  0xff4
    1020:	b4 e0       	ldi	r27, 0x04	; 4
    1022:	a6 95       	lsr	r26
    1024:	97 95       	ror	r25
    1026:	87 95       	ror	r24
    1028:	77 95       	ror	r23
    102a:	67 95       	ror	r22
    102c:	ba 95       	dec	r27
    102e:	c9 f7       	brne	.-14     	;  0x1022
    1030:	00 97       	sbiw	r24, 0x00	; 0
    1032:	61 05       	cpc	r22, r1
    1034:	71 05       	cpc	r23, r1
    1036:	08 95       	ret
    1038:	9b 01       	movw	r18, r22
    103a:	ac 01       	movw	r20, r24
    103c:	0a 2e       	mov	r0, r26
    103e:	06 94       	lsr	r0
    1040:	57 95       	ror	r21
    1042:	47 95       	ror	r20
    1044:	37 95       	ror	r19
    1046:	27 95       	ror	r18
    1048:	ba 95       	dec	r27
    104a:	c9 f7       	brne	.-14     	;  0x103e
    104c:	62 0f       	add	r22, r18
    104e:	73 1f       	adc	r23, r19
    1050:	84 1f       	adc	r24, r20
    1052:	95 1f       	adc	r25, r21
    1054:	a0 1d       	adc	r26, r0
    1056:	08 95       	ret
    1058:	62 9f       	mul	r22, r18
    105a:	d0 01       	movw	r26, r0
    105c:	73 9f       	mul	r23, r19
    105e:	f0 01       	movw	r30, r0
    1060:	82 9f       	mul	r24, r18
    1062:	e0 0d       	add	r30, r0
    1064:	f1 1d       	adc	r31, r1
    1066:	64 9f       	mul	r22, r20
    1068:	e0 0d       	add	r30, r0
    106a:	f1 1d       	adc	r31, r1
    106c:	92 9f       	mul	r25, r18
    106e:	f0 0d       	add	r31, r0
    1070:	83 9f       	mul	r24, r19
    1072:	f0 0d       	add	r31, r0
    1074:	74 9f       	mul	r23, r20
    1076:	f0 0d       	add	r31, r0
    1078:	65 9f       	mul	r22, r21
    107a:	f0 0d       	add	r31, r0
    107c:	99 27       	eor	r25, r25
    107e:	72 9f       	mul	r23, r18
    1080:	b0 0d       	add	r27, r0
    1082:	e1 1d       	adc	r30, r1
    1084:	f9 1f       	adc	r31, r25
    1086:	63 9f       	mul	r22, r19
    1088:	b0 0d       	add	r27, r0
    108a:	e1 1d       	adc	r30, r1
    108c:	f9 1f       	adc	r31, r25
    108e:	bd 01       	movw	r22, r26
    1090:	cf 01       	movw	r24, r30
    1092:	11 24       	eor	r1, r1
    1094:	08 95       	ret
    1096:	97 fb       	bst	r25, 7
    1098:	09 2e       	mov	r0, r25
    109a:	05 26       	eor	r0, r21
    109c:	0e d0       	rcall	.+28     	;  0x10ba
    109e:	57 fd       	sbrc	r21, 7
    10a0:	04 d0       	rcall	.+8      	;  0x10aa
    10a2:	14 d0       	rcall	.+40     	;  0x10cc
    10a4:	0a d0       	rcall	.+20     	;  0x10ba
    10a6:	00 1c       	adc	r0, r0
    10a8:	38 f4       	brcc	.+14     	;  0x10b8
    10aa:	50 95       	com	r21
    10ac:	40 95       	com	r20
    10ae:	30 95       	com	r19
    10b0:	21 95       	neg	r18
    10b2:	3f 4f       	sbci	r19, 0xFF	; 255
    10b4:	4f 4f       	sbci	r20, 0xFF	; 255
    10b6:	5f 4f       	sbci	r21, 0xFF	; 255
    10b8:	08 95       	ret
    10ba:	f6 f7       	brtc	.-4      	;  0x10b8
    10bc:	90 95       	com	r25
    10be:	80 95       	com	r24
    10c0:	70 95       	com	r23
    10c2:	61 95       	neg	r22
    10c4:	7f 4f       	sbci	r23, 0xFF	; 255
    10c6:	8f 4f       	sbci	r24, 0xFF	; 255
    10c8:	9f 4f       	sbci	r25, 0xFF	; 255
    10ca:	08 95       	ret
    10cc:	a1 e2       	ldi	r26, 0x21	; 33
    10ce:	1a 2e       	mov	r1, r26
    10d0:	aa 1b       	sub	r26, r26
    10d2:	bb 1b       	sub	r27, r27
    10d4:	fd 01       	movw	r30, r26
    10d6:	0d c0       	rjmp	.+26     	;  0x10f2
    10d8:	aa 1f       	adc	r26, r26
    10da:	bb 1f       	adc	r27, r27
    10dc:	ee 1f       	adc	r30, r30
    10de:	ff 1f       	adc	r31, r31
    10e0:	a2 17       	cp	r26, r18
    10e2:	b3 07       	cpc	r27, r19
    10e4:	e4 07       	cpc	r30, r20
    10e6:	f5 07       	cpc	r31, r21
    10e8:	20 f0       	brcs	.+8      	;  0x10f2
    10ea:	a2 1b       	sub	r26, r18
    10ec:	b3 0b       	sbc	r27, r19
    10ee:	e4 0b       	sbc	r30, r20
    10f0:	f5 0b       	sbc	r31, r21
    10f2:	66 1f       	adc	r22, r22
    10f4:	77 1f       	adc	r23, r23
    10f6:	88 1f       	adc	r24, r24
    10f8:	99 1f       	adc	r25, r25
    10fa:	1a 94       	dec	r1
    10fc:	69 f7       	brne	.-38     	;  0x10d8
    10fe:	60 95       	com	r22
    1100:	70 95       	com	r23
    1102:	80 95       	com	r24
    1104:	90 95       	com	r25
    1106:	9b 01       	movw	r18, r22
    1108:	ac 01       	movw	r20, r24
    110a:	bd 01       	movw	r22, r26
    110c:	cf 01       	movw	r24, r30
    110e:	08 95       	ret
    1110:	f8 94       	cli
    1112:	ff cf       	rjmp	.-2      	;  0x1112
    1114:	25 73       	andi	r18, 0x35	; 53
    1116:	25 64       	ori	r18, 0x45	; 69
    1118:	2c 20       	and	r2, r12
    111a:	25 64       	ori	r18, 0x45	; 69
    111c:	20 20       	and	r2, r0
    111e:	00 47       	sbci	r16, 0x70	; 112
    1120:	61 6d       	ori	r22, 0xD1	; 209
    1122:	65 20       	and	r6, r5
    1124:	6f 66       	ori	r22, 0x6F	; 111
    1126:	20 4c       	sbci	r18, 0xC0	; 192
    1128:	69 66       	ori	r22, 0x69	; 105
    112a:	65 3a       	cpi	r22, 0xA5	; 165
    112c:	00 20       	and	r0, r0
    112e:	20 20       	and	r2, r0
    1130:	20 20       	and	r2, r0
    1132:	20 20       	and	r2, r0
    1134:	20 20       	and	r2, r0
    1136:	20 20       	and	r2, r0
    1138:	20 20       	and	r2, r0
    113a:	20 20       	and	r2, r0
    113c:	20 20       	and	r2, r0
    113e:	20 20       	and	r2, r0
    1140:	20 00       	.word	0x0020	; ????
    1142:	01 00       	.word	0x0001	; ????
	...
    1160:	00 00       	nop
    1162:	01 01       	movw	r0, r2
    1164:	00 01       	movw	r0, r0
    1166:	01 00       	.word	0x0001	; ????
	...
    1174:	00 00       	nop
    1176:	01 00       	.word	0x0001	; ????
    1178:	00 00       	nop
    117a:	01 00       	.word	0x0001	; ????
	...
    1188:	00 00       	nop
    118a:	00 01       	movw	r0, r0
    118c:	01 01       	movw	r0, r2
	...
    1246:	14 1f       	adc	r17, r20
    1248:	20 39       	cpi	r18, 0x90	; 144
    124a:	45 4e       	sbci	r20, 0xE5	; 229
