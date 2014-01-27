.device attiny84
;-----------------------------------------;
; FIRST WE'LL DEFINE SOME REGISTER TO USE ;
;-----------------------------------------;
.DEF A = R16   ;GENERAL PURPOSE ACCUMULATOR
.DEF I = R21   ;INDEXES FOR LOOP CONTROL

.ORG $0000

;-----------------------------------------;
; FIRST WE SETUP A STACK AREA THEN SET    ;
; DIRECTION BIT ON PORT-B FOR OUTPUT/SPKR ;
;-----------------------------------------;
START:
  LDI A,LOW(RAMEND)   ;SETUP STACK POINTER
  OUT SPL,A           ;SO CALLS TO SUBROUTINES
  LDI A,HIGH(RAMEND)  ;SETUP STACK POINTER
  OUT SPH,A           ;SO CALLS TO SUBROUTINES

  LDI A,0xFF   ;SET ALL PORTB FOR OUTPUT
  OUT DDRA,A          ;WRITE 1s TO DIRECTN REGS

;--------------;
; MAIN ROUTINE ;
;--------------;
LEDONOFF:
  SER A
  OUT  PORTA,A
   RCALL DELAYLONG
  CLR A
  OUT PORTA,A
   RCALL DELAYLONG
  RJMP LEDONOFF
  



DELAYLONG:
; ============================= 
; Delaying approximately 1 sec at 8Mhz.
; This code has been created with  “AVR Delay Loop Generator V1.2″.
          ldi  R17, 0x48
WGLOOP0:  ldi  R18, 0xBC
WGLOOP1:  ldi  R19, 0xC4
WGLOOP2:  dec  R19
          brne WGLOOP2
          dec  R18
          brne WGLOOP1
          dec  R17
          brne WGLOOP0
; ============================= 
RET