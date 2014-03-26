/*
 * This file contains all the available constants
 * this is handy in case of adding/editing/removing constants 
 */

//define simple true false
#define true 1
#define false 0

//posible states the servo can have
#define SERVO_CLOSED 10
#define SERVO_OPENED 5
#define SERVO_KICKED 0

//rules for speaking to computer and vise versa.
#define OFF	 	42
#define ON 		1
#define OPEN 	2
#define CLOSE 	3
#define SREAD 	4
#define BT	5
#define PREAD 	6
#define SETPIN 	7
#define SLEEP 	8
#define LOGOUT 	9
#define LOGIN 	10


//rules for receiving data from the computer
#define BTOK 121 //Needs to be unique, 150 = 66(B) + 84(T)
#define FALSE 42
#define TRUE 1
#define SERIAL_ACCES 2
#define SERIAL_DENIED 3
#define ROTARY_NORMAL 20
#define ROTARY_LEFT 21
#define ROTARY_RIGHT 22
#define SEGMENT 1
#define DISCONNECTED 4
#define OPENED 5
#define CLOSED 6
