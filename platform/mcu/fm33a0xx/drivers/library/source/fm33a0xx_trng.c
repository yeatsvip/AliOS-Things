/**
  ******************************************************************************
  * @file    fm33a0xx_trng.c
  * @author  FM33a0xx Application Team
  * @version V2.0.2
  * @date    30-11-2017
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_trng.h" 


/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup TRNG 
  * @brief TRNG driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-22-21
//FM33A0XX_Driver_Gen_V1.4

/* RNGʹ�ܼĴ���������д1ʹ�� ��غ��� */
//void TRNG_TRNGCON_RNGEN_Setable(FunState NewState)
//{
//	if (NewState == ENABLE)
//	{
//		TRNG->TRNGCON |= (TRNG_TRNGCON_RNGEN_Msk);
//	}
//	else
//	{
//		TRNG->TRNGCON &= ~(TRNG_TRNGCON_RNGEN_Msk);
//	}
//}

//FunState TRNG_TRNGCON_RNGEN_Getable(void)
//{
//	if (TRNG->TRNGCON & (TRNG_TRNGCON_RNGEN_Msk))
//	{
//		return ENABLE;
//	}
//	else
//	{
//		return DISABLE;
//	}
//}

/********************************
TRNG���ܿ��ƺ���
����: ��ȡ��������
���룺��
���: ��������ɽ��
********************************/
uint32_t TRNG_RNGOUT_Read(void)
{
	return (TRNG->RNGOUT);
}

/********************************
TRNG���ܿ��ƺ���
����: �������������ʧ���ж�ʹ��
���룺ENABLE/DISABLE		���������ʧ���ж�ʹ��/���������ʧ���жϽ�ֹ
���: ��
********************************/
void TRNG_RNGIE_RNGIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		TRNG->RNGIE |= (TRNG_RNGIE_RNGIE_Msk);
	}
	else
	{
		TRNG->RNGIE &= ~(TRNG_RNGIE_RNGIE_Msk);
	}
}
/********************************
TRNG���ܿ��ƺ���
����: ��ȡ���������ʧ���ж�ʹ��
���룺��
���: ENABLE/DISABLE		���������ʧ���ж�ʹ��/���������ʧ���жϽ�ֹ
********************************/
FunState TRNG_RNGIE_RNGIE_Getable(void)
{
	if (TRNG->RNGIE & (TRNG_RNGIE_RNGIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
TRNG���ܿ��ƺ���
����: ��ȡ�����LFSRʹ�ܱ�־
���룺��
���: SET/RESET				LFSR�������У����ɽ���CRC��֤/LFSR���������У��ɽ���CRC��֤
********************************/
FlagStatus TRNG_RNGIF_LFSREN_Chk(void)
{
	if (TRNG->RNGIF & TRNG_RNGIF_LFSREN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
TRNG���ܿ��ƺ���
����: �������LFSRʹ�ܱ�־
���룺��
���: ��
********************************/
void TRNG_RNGIF_RNF_Clr(void)
{
	TRNG->RNGIF = TRNG_RNGIF_RNF_Msk;
}
/********************************
TRNG���ܿ��ƺ���
����: ��ȡ���������ʧ�ܱ�־
���룺��
���: SET/RESET				�����δ��ͨ���������/�����ͨ���������
********************************/
FlagStatus TRNG_RNGIF_RNF_Chk(void)
{
	if (TRNG->RNGIF & TRNG_RNGIF_RNF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
TRNG���ܿ��ƺ���
����: ���������CRCʹ��
���룺ENABLE/DISABLE		CRCʹ��/CRC�ر�
���: ��
********************************/
void TRNG_CRCCON_CRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		TRNG->CRCCON |= (TRNG_CRCCON_CRCEN_Msk);
	}
	else
	{
		TRNG->CRCCON &= ~(TRNG_CRCCON_CRCEN_Msk);
	}
}

/********************************
TRNG���ܿ��ƺ���
����: ��ȡ�����CRCʹ��
���룺��
���: ENABLE/DISABLE		CRCʹ��/CRC�ر�
********************************/
FunState TRNG_CRCCON_CRCEN_Getable(void)
{
	if (TRNG->CRCCON & (TRNG_CRCCON_CRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/********************************
TRNG���ܿ��ƺ���
����: ���������CRC������������(����LFSREN=0��Ч)
���룺32λ����
���: ��
********************************/
void TRNG_CRCIN_Write(uint32_t SetValue)
{
	TRNG->CRCIN = (SetValue);
}
/********************************
TRNG���ܿ��ƺ���
����: ��ȡ�����CRC������������
���룺��
���: 32λ����
********************************/
uint32_t TRNG_CRCIN_Read(void)
{
	return (TRNG->CRCIN);
}

/********************************
TRNG���ܿ��ƺ���
����: ��CRC������ɱ�־
���룺��
���: ��
********************************/
void TRNG_CRCFLAG_CRCD_Clr(void)
{
	TRNG->CRCFLAG &= ~(TRNG_CRCFLAG_CRCD_Msk);
}
/********************************
TRNG���ܿ��ƺ���
����: ��ȡCRC������ɱ�־
���룺��
���: SET/RESET			CRC�������/CRC����δ���
********************************/
FlagStatus TRNG_CRCFLAG_CRCD_Chk(void)
{
	if (TRNG->CRCFLAG & TRNG_CRCFLAG_CRCD_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/********************************
TRNG���ܿ��ƺ���
����: ȱʡ����
���룺��
���: ��
********************************/
void TRNG_Deinit(void)
{
	ANAC->TRNGCON = 0x00000000;//TRNG->TRNGCON = 0x00000000;
	//TRNG->RNGOUT = ;
	TRNG->RNGIE = 0x00000000;
	//TRNG->RNGIF = ;
	TRNG->CRCCON = 0x00000000;
	TRNG->CRCIN = 0x00000000;
	TRNG->CRCFLAG = 0x00000000;
}
//Code_End



/******END OF FILE****/


