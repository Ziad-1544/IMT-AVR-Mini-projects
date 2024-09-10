/*********************************/
/*********************************/
/*******Layer : HAL *************/
/*******SWC   : SSD   *************/
/*******Date  :7 Sep 2024  *******/
/*******Version : 1.0 ************/
/*******Author  : Yousef Ahmad  **/
/*********************************/
/*********************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct
{
	u8 DataPort;
	u8 CtrlPort;
	u8 CtrlPin;
	u8 Type;
}SSD_t;

void SSD_voidEnableDisable(SSD_t Copy_tSeven,u8 Copy_u8Mode);

void SSD_voidDisplayNumber(SSD_t Copy_tSeven,u8 Copy_u8Number);

#define COMMON_CATHODE   0
#define COMMON_ANODE     1

#define ENABLED      1
#define DISABLED     0

#endif