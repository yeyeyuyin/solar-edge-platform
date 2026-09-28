#include "stm32f10x.h"
#include "MyI2C.h"

#define LTC2944_ADDRESS 0xC8

void LTC2944_WriteReg(uint8_t RegAddress, uint8_t Data)
{
	MyI2C_Start();						
	MyI2C_SendByte(LTC2944_ADDRESS);	
	MyI2C_ReceiveAck();					
	MyI2C_SendByte(RegAddress);			
	MyI2C_ReceiveAck();				
	MyI2C_SendByte(Data);				
	MyI2C_ReceiveAck();					
	MyI2C_Stop();						
}

uint8_t LTC2944_ReadReg(uint8_t RegAddress)
{
	uint8_t Data;
	
	MyI2C_Start();						
	MyI2C_SendByte(LTC2944_ADDRESS);	
	MyI2C_ReceiveAck();					
	MyI2C_SendByte(RegAddress);			
	MyI2C_ReceiveAck();					
	
	MyI2C_Start();						
	MyI2C_SendByte(LTC2944_ADDRESS | 0x01);	
	MyI2C_ReceiveAck();					
	Data = MyI2C_ReceiveByte();			
	MyI2C_SendAck(0);				
	MyI2C_Stop();						
	
	return Data;
}

void LTC2944_Init(void){
}
