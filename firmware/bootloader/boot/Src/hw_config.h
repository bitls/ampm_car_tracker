/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HW_CONFIG_H__
#define __HW_CONFIG_H__

#define PAGE_SIZE                         (0x400)    /* 1 Kbyte */
#define FLASH_SIZE                        (0x10000)  /* 64 KBytes */

#define ApplicationAddress    0x8003000
#define EEPROM_START_ADDRESS ((uint32_t)(0x8060000 - PAGE_SIZE*2)) /* EEPROM emulation start address: after 64KByte of used Flash memory */

#define CONFIG_AREA_SIZE		1024
#define CONFIG_AREA_START ((uint32_t)((FLASH_BASE | FLASH_SIZE) - PAGE_SIZE*(CONFIG_AREA_SIZE/PAGE_SIZE)))		




#define SYS_SLEEP	2
#define SYS_INIT	1
#define SYS_DEINIT	0

#define ACC_ON		0
#define ACC_OFF		GPIO_IDR_IDR0
#define ENGINE_ON	1
#define ENGINE_OFF 0
#define SECURITY_OFF	0
#define SECURITY_ON	1



#define ACC_PORT			GPIOA	
#define ACC_PIN			GPIO_IDR_IDR0
#define GET_ACC_PIN 	(ACC_PORT->IDR & ACC_PIN)

#define VIN_PORT			GPIOB	
#define VIN_PIN			GPIO_IDR_IDR1
#define GET_VIN_PIN 	(VIN_PORT->IDR & VIN_PIN)


#define ENGINE_TURN_OFF		OUTPUT1_PIN_CLR
#define ENGINE_TURN_ON		OUTPUT1_PIN_SET

#define OUTPUT1_PORT	GPIOB
#define OUTPUT1_PIN					GPIO_BSRR_BS8
#define OUTPUT1_SET_OUTPUT		OUTPUT1_PORT->CRH	&= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8); OUTPUT1_PORT->CRH	|= (GPIO_CRH_MODE8_0 | GPIO_CRH_MODE8_1)
#define OUTPUT1_SET_INPUT		OUTPUT1_PORT->CRH	&= ~(GPIO_CRH_MODE8 | GPIO_CRH_CNF8); OUTPUT1_PORT->CRH	|= (GPIO_CRH_CNF8_0)
#define OUTPUT1_PIN_SET			OUTPUT1_PORT->BSRR = OUTPUT1_PIN
#define OUTPUT1_PIN_CLR			OUTPUT1_PORT->BRR = OUTPUT1_PIN

#define OUTPUT2_PORT	GPIOB
#define OUTPUT2_PIN					GPIO_BSRR_BS9
#define OUTPUT2_SET_OUTPUT		OUTPUT2_PORT->CRH	&= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9); OUTPUT2_PORT->CRH	|= (GPIO_CRH_MODE9_0 | GPIO_CRH_MODE9_1)
#define OUTPUT2_SET_INPUT		OUTPUT2_PORT->CRH	&= ~(GPIO_CRH_MODE9 | GPIO_CRH_CNF9); OUTPUT2_PORT->CRH	|= (GPIO_CRH_CNF9_0)
#define OUTPUT2_PIN_SET			OUTPUT2_PORT->BSRR = OUTPUT2_PIN
#define OUTPUT2_PIN_CLR			OUTPUT2_PORT->BRR = OUTPUT2_PIN

#define POWER_EN_PORT	GPIOA
#define POWER_EN_PIN					GPIO_BSRR_BS1
#define POWER_EN_SET_OUTPUT		POWER_EN_PORT->CRL	&= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1); POWER_EN_PORT->CRL	|= (GPIO_CRL_MODE1_0 | GPIO_CRL_MODE1_1)
#define POWER_EN_SET_INPUT		POWER_EN_PORT->CRL	&= ~(GPIO_CRL_MODE1 | GPIO_CRL_CNF1); POWER_EN_PORT->CRL	|= (GPIO_CRL_CNF1_0)
#define POWER_EN_PIN_SET			POWER_EN_PORT->BSRR = POWER_EN_PIN
#define POWER_EN_PIN_CLR			POWER_EN_PORT->BRR = POWER_EN_PIN


/*
	PRIORITY CONFIG
*/
#define GPS_PRIORITY					2
#define GSM_PRIORITY  				1
#define TICK_PRIORITY 				1
#define RTCALARM_PRIORITY 		4
#define MODEMRI_PRIORITY 			4
#define USB_MANAGER_PRIORITY	4
#define USB_WAKEUP_PRIORITY		4
#define ACCL_PRIORITY					4
#define SOS_PRIORITY					4
#define ACC_PRIORITY					4
#define RF_PRIORITY						4

#define ALARM_TIME		300//5min


extern uint32_t systemStatus;

#endif  /*__HW_CONFIG_H*/

