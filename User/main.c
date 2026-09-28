#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "LTC2944.h"
#include "stdio.h"
#include "MyI2C.h"
int fputc(int ch, FILE *f) {
    ITM_SendChar(ch);  // ?? ITM ???????????
    return ch;
}
volatile uint32_t timeVariable = 0;
//volatile uint32_t display = 100;// ????????????

int main(void) {
    // ??? OLED
	//OLED_ShowHexNum(1, 1, MSB, 2);
	//OLED_ShowHexNum(1, 3, LSB, 2);

    // ??? LTC2944,??????? 3000mAh
	  
	  

    while (1) {
			  if (timeVariable % 1000 == 0 ){
  OLED_Init();
	LTC2944_Init();
	uint8_t MSB = LTC2944_ReadReg(0x02);
	uint8_t LSB = LTC2944_ReadReg(0x03);
	uint16_t combined = (MSB << 8) | LSB;
	int present = combined;
	int MAX = 65535;
	int MIN = 13107;
	int battery_percentage = (present - MIN)*100/(MAX - MIN);
	if(battery_percentage < 0){
		battery_percentage = 0;
	}
	OLED_ShowNum(1, 1, battery_percentage, 3);
	OLED_ShowString(1, 4, "%");
}
	
    }
}


// ???????????
        //float battery_percentage = ...
        //float battery_percentage = 100.0f;
        // ?????????? OLED
        //OLED_Clear();  // ??
        //OLED_ShowString(1, 1, "Battery:");  // ?? "Battery:"
        //OLED_ShowNum(1, 10, (uint32_t)battery_percentage, 3);  // ?????
  // ?????????
			  //OLED_ShowNum(1, 10, 100, 3);
        //OLED_ShowString(1, 14, "%");  // ?????
        
			
			/* //I2C test
			  MyI2C_Init();
	      MyI2C_Start();
	      MyI2C_SendByte(0xC8);
	      uint8_t Ack = MyI2C_ReceiveAck();
	      MyI2C_Stop();
	      OLED_ShowNum(1, 1, Ack, 3);
        // ?? 1 ?
        Delay_ms(1000);
       */


/* //OLED test
				SystemCoreClockUpdate();
    if (SysTick_Config(SystemCoreClock / 1000)) { // 1ms ??
        while (1); // ????,?????
    }
		OLED_ShowString(1, 9, "%");

        // ??????? timeVariable,??1ms????
        if (timeVariable % 4320000 == 0 & display != 0) {
            // ??1?,??????
					display--;
					OLED_ShowNum(1, 1, display, 8);
					
        }
	*/
		 