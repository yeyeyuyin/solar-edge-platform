#ifndef __LTC2944_H
#define __LTC2944_H
void LTC2944_WriteReg(uint8_t RegAddress, uint8_t Data);
uint8_t LTC2944_ReadReg(uint8_t RegAddress);
void LTC2944_Init(void);

#endif
