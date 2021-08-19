/* Library Definition */
#include <VirtualWire.h> 
#include <LCD5110_Basic.h>
  
/* Pin Definition */
#define CLK 8
#define DIN 9
#define DC 10
#define RST 11
#define CE 12
#define ReceiverPin 6

/* Object Definition */
LCD5110 myGLCD(CLK,DIN,DC,RST,CE);

/* Veriables Definition */
extern uint8_t BigNumbers[];
int Number;

/* Configration Definition */
void setup(){

    myGLCD.InitLCD(); 
    myGLCD.setFont(BigNumbers);
    Serial.begin(9600);
    vw_set_ptt_inverted(true);
    vw_set_rx_pin(ReceiverPin);  
    vw_setup(500);
    vw_rx_start();
    
}

/* İnfinity Loop Definition */
void loop(){
    
    uint8_t Buffers[VW_MAX_MESSAGE_LEN];
    uint8_t Bufferslength = VW_MAX_MESSAGE_LEN;  
    if (vw_get_message(Buffers, &Bufferslength)) 
    {
         if(Buffers[0]=='1'){
          Number=1;
         }
         else if(Buffers[0]=='2'){
           Number=2;
         }     
         else if(Buffers[0]=='3'){ 
           Number=3;
         }     
         else if(Buffers[0]=='4'){ 
           Number=4;
         }     
         else if(Buffers[0]=='5'){ 
           Number=5;
         }   
         else if(Buffers[0]=='6'){
           Number=6;
         }       
         else if(Buffers[0]=='7'){ 
           Number=7;
         }      
         else if(Buffers[0]=='8'){ 
           Number=8;
         }    
         else if(Buffers[0]=='9'){ 
           Number=9;
         }  
         else if(Buffers[0]=='0'){ 
           Number=0;
         } 
}

myGLCD.clrScr();
myGLCD.printNumI(Number,36,8); 
delay(100);

}
  
