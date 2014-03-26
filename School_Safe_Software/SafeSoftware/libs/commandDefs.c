//rules for speaking to each other.
#define OFF	 	42
#define ON 		1
#define OPEN 	2
#define CLOSE 	3
#define SREAD 	4
#define BT		5
#define PREAD 	6
#define SETPIN 	7
#define SLEEP 	8
#define LOGOUT 	9
#define LOGIN 	10

//Response commands:
#define BTOK 121 									//Needs to be unique, 150 = 66(B) + 84(T)
#define FALSE 42 									//Used when an operation/command failes
#define TRUE 1 										//Used when an operation/command succeeds
#define SERIAL_ACCES 2							 	//Used to say that the client/android/pc has acces
#define SERIAL_DENIED 3 							//Used to say that the client/android/pc has no acces
#define ROTARY_NORMAL 20 							//Used to state that the rotarys states is in normal/no rotation
#define ROTARY_LEFT 21 								//Used to state that the user is rotating the rotary to the left
#define ROTARY_RIGHT 22 							//Used to state that the user is rotating the rotary to the right
//#define SEGMENT byte(1), byte(num0), byte(num1), byte(num2), byte(num3)
#define DISCONNECTED 4 								//Used to say to the client/android/pc that the user has been succesfully logged out
#define OPENED 5 									//Used to say that the safe is currently open
#define CLOSED 6									//Used to say that the safi is currently closed
