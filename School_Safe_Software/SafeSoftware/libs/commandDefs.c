/*
login <4 digit number>: login with de 4 digit number as pin
  when acces:
    1: set 5v line to low, and all other pins to ground
    0: tunrs 5v line HIGH and the other neccesary pins
    open: change servo to open state
    close: change servo to closed state
    sread: read servo value
    pread: read the pin code
    pin <4 digit number>: set the pin
    sleep: enter sleep mode
    logout: logout, basically set a boolean to false
    login <4 digit number>: login with de 4 digit number as pin
  no acces:
    message acces denied
BT
  send BTOK
*/
//rules for speaking to each other.
#define OFF	 	52
#define ON 		11
#define OPEN 	12
#define CLOSE 	13
#define SREAD 	14
#define BT		15
#define PREAD 	16
#define SETPIN 	17
#define SLEEP 	18
#define LOGOUT 	19
#define LOGIN 	20

/*
//action undertaken by safe firmware.
if BT:
	send BTOK
if SREAD:
	send servo_val
if PREAD:
	send pin
if SETPIN:
	read pin
if LOGIN:
	send "acces" if entered_pin == pin
	else send "acces denied."

login:
10,pin,!0
if pin 1234

send 10
send 1
send 2
send 3
send 4
send !0
*/

//Response commands:
#define BTOK 131 									//Needs to be unique, 150 = 66(B) + 84(T)
#define FALSE 52 									//Used when an operation/command failes
#define TRUE 11 										//Used when an operation/command succeeds
#define SERIAL_ACCES 12							 	//Used to say that the client/android/pc has acces
#define SERIAL_DENIED 13 							//Used to say that the client/android/pc has no acces
#define ROTARY_NORMAL 30 							//Used to state that the rotarys states is in normal/no rotation
#define ROTARY_LEFT 31 								//Used to state that the user is rotating the rotary to the left
#define ROTARY_RIGHT 32 							//Used to state that the user is rotating the rotary to the right
#define SEGMENT 18									//byte(1), byte(num0), byte(num1), byte(num2), byte(num3)
#define DISCONNECTED 14 								//Used to say to the client/android/pc that the user has been succesfully logged out
#define OPENED 15 									//Used to say that the safe is currently open
#define CLOSED 16									//Used to say that the safi is currently closed
#define PASSWORD_CHANGED 17							//Password has changed with succes
#define PASSWORD_FAILED 19							//Password failed to change

/*
usage of SEGMENT:
When the client receiver this command, it will use the 4 least significant bytes, as the pin, which is then split
in 4 separate digits to be shown on de seven segment displays on the GUI/android application
*/
