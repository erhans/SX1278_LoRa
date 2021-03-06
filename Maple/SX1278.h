#ifndef __SX1278_HWSPI_H__
#define __SX1278_HWSPI_H__

#include "HardwareSPI.h"
#include <wirish.h>
#include "SX1278_Base.h"

typedef struct _SX1278_Config_t {
	int	pin_NSS;
	int pin_RESET;
	int pin_DIO0;
	HardwareSPI *SPI;
} SX1278_Config_t;


class SX1278 : public SX1278_Base {
private:
	SX1278(SX1278_Config_t* hwConfig);
	static SX1278* instance;

	SX1278_Config_t hwConfig;

protected:
	void HAL_init();
	void HAL_SetNSS(bool value);
	void HAL_Reset();
	void HAL_SPICommand(uint8_t cmd);
	uint8_t HAL_SPIReadByte();
	void HAL_DelayMs(uint32_t msec);
	bool HAL_GetDIO0();

public:
	static SX1278* getInstance(SX1278_Config_t* hwConfig = NULL);
};


#endif
