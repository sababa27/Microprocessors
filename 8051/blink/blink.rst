                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.0 #15242 (Mac OS X ppc)
                                      4 ;--------------------------------------------------------
                                      5 	.module blink
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _pin2
                                     13 	.globl _t
                                     14 	.globl _delay
                                     15 ;--------------------------------------------------------
                                     16 ; special function registers
                                     17 ;--------------------------------------------------------
                                     18 	.area RSEG    (ABS,DATA)
      000000                         19 	.org 0x0000
                                     20 ;--------------------------------------------------------
                                     21 ; special function bits
                                     22 ;--------------------------------------------------------
                                     23 	.area RSEG    (ABS,DATA)
      000000                         24 	.org 0x0000
                           000091    25 _pin2	=	0x0091
                                     26 ;--------------------------------------------------------
                                     27 ; overlayable register banks
                                     28 ;--------------------------------------------------------
                                     29 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         30 	.ds 8
                                     31 ;--------------------------------------------------------
                                     32 ; internal ram data
                                     33 ;--------------------------------------------------------
                                     34 	.area DSEG    (DATA)
      000008                         35 _t::
      000008                         36 	.ds 2
                                     37 ;--------------------------------------------------------
                                     38 ; overlayable items in internal ram
                                     39 ;--------------------------------------------------------
                                     40 	.area	OSEG    (OVR,DATA)
                                     41 ;--------------------------------------------------------
                                     42 ; Stack segment in internal ram
                                     43 ;--------------------------------------------------------
                                     44 	.area SSEG
      00000A                         45 __start__stack:
      00000A                         46 	.ds	1
                                     47 
                                     48 ;--------------------------------------------------------
                                     49 ; indirectly addressable internal ram data
                                     50 ;--------------------------------------------------------
                                     51 	.area ISEG    (DATA)
                                     52 ;--------------------------------------------------------
                                     53 ; absolute internal ram data
                                     54 ;--------------------------------------------------------
                                     55 	.area IABS    (ABS,DATA)
                                     56 	.area IABS    (ABS,DATA)
                                     57 ;--------------------------------------------------------
                                     58 ; bit data
                                     59 ;--------------------------------------------------------
                                     60 	.area BSEG    (BIT)
                                     61 ;--------------------------------------------------------
                                     62 ; paged external ram data
                                     63 ;--------------------------------------------------------
                                     64 	.area PSEG    (PAG,XDATA)
                                     65 ;--------------------------------------------------------
                                     66 ; uninitialized external ram data
                                     67 ;--------------------------------------------------------
                                     68 	.area XSEG    (XDATA)
                                     69 ;--------------------------------------------------------
                                     70 ; absolute external ram data
                                     71 ;--------------------------------------------------------
                                     72 	.area XABS    (ABS,XDATA)
                                     73 ;--------------------------------------------------------
                                     74 ; initialized external ram data
                                     75 ;--------------------------------------------------------
                                     76 	.area XISEG   (XDATA)
                                     77 	.area HOME    (CODE)
                                     78 	.area GSINIT0 (CODE)
                                     79 	.area GSINIT1 (CODE)
                                     80 	.area GSINIT2 (CODE)
                                     81 	.area GSINIT3 (CODE)
                                     82 	.area GSINIT4 (CODE)
                                     83 	.area GSINIT5 (CODE)
                                     84 	.area GSINIT  (CODE)
                                     85 	.area GSFINAL (CODE)
                                     86 	.area CSEG    (CODE)
                                     87 ;--------------------------------------------------------
                                     88 ; interrupt vector
                                     89 ;--------------------------------------------------------
                                     90 	.area HOME    (CODE)
      000000                         91 __interrupt_vect:
      000000 02 00 4C         [24]   92 	ljmp	__sdcc_gsinit_startup
                                     93 ; restartable atomic support routines
      000003                         94 	.ds	5
      000008                         95 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]   96 	nop
      000009 00               [12]   97 	nop
      00000A                         98 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]   99 	movx	a, @r0
      00000B FB               [12]  100 	mov	r3, a
      00000C EA               [12]  101 	mov	a, r2
      00000D F2               [24]  102 	movx	@r0, a
      00000E 80 2C            [24]  103 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  104 	nop
      000011 00               [12]  105 	nop
      000012                        106 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  107 	movx	a, @dptr
      000013 FB               [12]  108 	mov	r3, a
      000014 EA               [12]  109 	mov	a, r2
      000015 F0               [24]  110 	movx	@dptr, a
      000016 80 24            [24]  111 	sjmp	sdcc_atomic_exchange_exit
      000018                        112 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  113 	mov	a, @r0
      000019 B5 02 02         [24]  114 	cjne	a, ar2, .+#5
      00001C EB               [12]  115 	mov	a, r3
      00001D F6               [12]  116 	mov	@r0, a
      00001E 22               [24]  117 	ret
      00001F 00               [12]  118 	nop
      000020                        119 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  120 	movx	a, @r0
      000021 B5 02 02         [24]  121 	cjne	a, ar2, .+#5
      000024 EB               [12]  122 	mov	a, r3
      000025 F2               [24]  123 	movx	@r0, a
      000026 22               [24]  124 	ret
      000027 00               [12]  125 	nop
      000028                        126 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  127 	movx	a, @dptr
      000029 B5 02 02         [24]  128 	cjne	a, ar2, .+#5
      00002C EB               [12]  129 	mov	a, r3
      00002D F0               [24]  130 	movx	@dptr, a
      00002E 22               [24]  131 	ret
      00002F                        132 sdcc_atomic_exchange_rollback_end::
                                    133 
      00002F                        134 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  135 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  136 	mov	r0, dpl
      000034 20 F5 D3         [24]  137 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        138 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  139 	mov	a, r2
      000038 C6               [12]  140 	xch	a, @r0
      000039 F5 82            [12]  141 	mov	dpl, a
      00003B 22               [24]  142 	ret
      00003C                        143 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  144 	mov	dpl, r3
      00003E 22               [24]  145 	ret
      00003F                        146 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  147 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  148 	mov	r0, dpl
      000044 20 F5 D9         [24]  149 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  150 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    151 ;--------------------------------------------------------
                                    152 ; global & static initialisations
                                    153 ;--------------------------------------------------------
                                    154 	.area HOME    (CODE)
                                    155 	.area GSINIT  (CODE)
                                    156 	.area GSFINAL (CODE)
                                    157 	.area GSINIT  (CODE)
                                    158 	.globl __sdcc_gsinit_startup
                                    159 	.globl __sdcc_program_startup
                                    160 	.globl __start__stack
                                    161 	.globl __mcs51_genXINIT
                                    162 	.globl __mcs51_genXRAMCLEAR
                                    163 	.globl __mcs51_genRAMCLEAR
                                    164 ;	blink.c:3: unsigned int t = 10000;
      0000A5 75 08 10         [24]  165 	mov	_t,#0x10
      0000A8 75 09 27         [24]  166 	mov	(_t + 1),#0x27
                                    167 	.area GSFINAL (CODE)
      0000AB 02 00 49         [24]  168 	ljmp	__sdcc_program_startup
                                    169 ;--------------------------------------------------------
                                    170 ; Home
                                    171 ;--------------------------------------------------------
                                    172 	.area HOME    (CODE)
                                    173 	.area HOME    (CODE)
      000049                        174 __sdcc_program_startup:
      000049 02 00 AE         [24]  175 	ljmp	_main
                                    176 ;	return from main will return to caller
                                    177 ;--------------------------------------------------------
                                    178 ; code
                                    179 ;--------------------------------------------------------
                                    180 	.area CSEG    (CODE)
                                    181 ;------------------------------------------------------------
                                    182 ;Allocation info for local variables in function 'main'
                                    183 ;------------------------------------------------------------
                                    184 ;	blink.c:5: void main(void){
                                    185 ;	-----------------------------------------
                                    186 ;	 function main
                                    187 ;	-----------------------------------------
      0000AE                        188 _main:
                           000007   189 	ar7 = 0x07
                           000006   190 	ar6 = 0x06
                           000005   191 	ar5 = 0x05
                           000004   192 	ar4 = 0x04
                           000003   193 	ar3 = 0x03
                           000002   194 	ar2 = 0x02
                           000001   195 	ar1 = 0x01
                           000000   196 	ar0 = 0x00
                                    197 ;	blink.c:6: while(1){
      0000AE                        198 00102$:
                                    199 ;	blink.c:7: pin2 = 1;
                                    200 ;	assignBit
      0000AE D2 91            [12]  201 	setb	_pin2
                                    202 ;	blink.c:8: delay(t);
      0000B0 85 08 82         [24]  203 	mov	dpl, _t
      0000B3 85 09 83         [24]  204 	mov	dph, (_t + 1)
      0000B6 12 00 C6         [24]  205 	lcall	_delay
                                    206 ;	blink.c:9: pin2 = 0;
                                    207 ;	assignBit
      0000B9 C2 91            [12]  208 	clr	_pin2
                                    209 ;	blink.c:10: delay(t);
      0000BB 85 08 82         [24]  210 	mov	dpl, _t
      0000BE 85 09 83         [24]  211 	mov	dph, (_t + 1)
      0000C1 12 00 C6         [24]  212 	lcall	_delay
                                    213 ;	blink.c:12: }
      0000C4 80 E8            [24]  214 	sjmp	00102$
                                    215 ;------------------------------------------------------------
                                    216 ;Allocation info for local variables in function 'delay'
                                    217 ;------------------------------------------------------------
                                    218 ;t             Allocated to registers r6 r7 
                                    219 ;i             Allocated to registers r4 r5 
                                    220 ;------------------------------------------------------------
                                    221 ;	blink.c:14: void delay(unsigned int t){
                                    222 ;	-----------------------------------------
                                    223 ;	 function delay
                                    224 ;	-----------------------------------------
      0000C6                        225 _delay:
      0000C6 AE 82            [24]  226 	mov	r6, dpl
      0000C8 AF 83            [24]  227 	mov	r7, dph
                                    228 ;	blink.c:16: for(i=0; i<t; i++){
      0000CA 7C 00            [12]  229 	mov	r4,#0x00
      0000CC 7D 00            [12]  230 	mov	r5,#0x00
      0000CE                        231 00103$:
      0000CE C3               [12]  232 	clr	c
      0000CF EC               [12]  233 	mov	a,r4
      0000D0 9E               [12]  234 	subb	a,r6
      0000D1 ED               [12]  235 	mov	a,r5
      0000D2 9F               [12]  236 	subb	a,r7
      0000D3 50 07            [24]  237 	jnc	00105$
      0000D5 0C               [12]  238 	inc	r4
      0000D6 BC 00 F5         [24]  239 	cjne	r4,#0x00,00103$
      0000D9 0D               [12]  240 	inc	r5
      0000DA 80 F2            [24]  241 	sjmp	00103$
      0000DC                        242 00105$:
                                    243 ;	blink.c:19: }
      0000DC 22               [24]  244 	ret
                                    245 	.area CSEG    (CODE)
                                    246 	.area CONST   (CODE)
                                    247 	.area XINIT   (CODE)
                                    248 	.area CABS    (ABS,CODE)
