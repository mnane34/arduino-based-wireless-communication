/* Library Definition */
#include <VirtualWire.h> 
#include <Keypad.h>  

/* Pin Definition */
#define Column1 6
#define Column2 7
#define Column3 8
#define Raw1 2
#define Raw2 3
#define Raw3 4
#define Raw4 5
#define TransmitPin 12

/* Veriables Definition */
char *Message; 
const byte RowNumber = 4; 
const byte ColNumber = 3;
char Keyboards[RowNumber][ColNumber]=  
{
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'},
};
byte Rows[RowNumber]={Raw1,Raw2,Raw3,Raw4};  
byte Columns[ColNumber]={Column1,Column2,Column3};  
char Key;  

/* Object Definition */
Keypad Keys = Keypad(makeKeymap(Keyboards),Rows,Columns,RowNumber,ColNumber); 


/* Configration Definition */
void setup(){
  
  Serial.begin(9600);
   
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(TransmitPin); 
  vw_setup(500);

  Message = " ";
  
}

/* İnfinity Loop Definition */
void loop(){

   Key = Keys.getKey();
   *Message = Key;
   Serial.println(Key);
   vw_send((uint8_t *)Message, strlen(Message)); 
   vw_wait_tx();
   delay(100);
 
}
