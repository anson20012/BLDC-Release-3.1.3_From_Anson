/**************************************************************************//**
 * @file     pac5xxx_GPIO.h
 * @brief    CMSIS Cortex-M Header File for the PAC5XXX GPIO Controller
 *
 * @note
 * Copyright (C) 2015, Active-Semi International
 *
 * THIS SOFTWARE IS SUBJECT TO A SOURCE CODE LICENSE AGREEMENT WHICH PROVIDES,
 * AMONG OTHER THINGS:  (i) THAT IT CAN BE USED ONLY TO ADAPT THE LICENSEE'S
 * APPLICATION TO PAC PROCESSORS SUPPLIED BY ACTIVE-SEMI INTERNATIONAL;
 * (ii) THAT  IT IS PROVIDED "AS IS" WITHOUT WARRANTY;  (iii) THAT
 * ACTIVE-SEMICONDUCTOR IS NOT LIABLE FOR ANY INDIRECT DAMAGES OR FOR DIRECT
 * DAMAGES EXCEEDING US$1,500;  AND (iv) THAT IT CAN BE DISCLOSED TO AND USED
 * ONLY BY CERTAIN AUTHORIZED PERSONS.
 *
 ******************************************************************************/

#ifndef PAC5XXX_GPIO_H
#define PAC5XXX_GPIO_H

/*------------- General-Purpose IO (GPIO) ----------------------*/
/** @addtogroup PAC5XXX_GPIO PAC5XXX General-Purpose IO (GPIO)
  @{
*/

typedef union
{
  __IO uint32_t w;
  struct {
  __IO uint32_t s               	: 16;
       uint32_t                 	: 16;
  };
  struct {
  __IO uint32_t b               	: 8;
       uint32_t                 	: 24;
  };
  struct {
    __IO uint32_t P0              	: 1;           /*!< P0 (bit 0)                                                 */
    __IO uint32_t P1              	: 1;           /*!< P1 (bit 1)                                                 */
	  __IO uint32_t P2              : 1;           /*!< P2 (bit 2)                                                 */
	  __IO uint32_t P3              : 1;           /*!< P3 (bit 3)                                                 */
	  __IO uint32_t P4              : 1;           /*!< P4 (bit 4)                                                 */
	  __IO uint32_t P5              : 1;           /*!< P5 (bit 5)                                                 */
	  __IO uint32_t P6              : 1;           /*!< P6 (bit 6)                                                 */
	  __IO uint32_t P7              : 1;           /*!< P7 (bit 7)                                                 */
	       uint32_t                 : 24;
  };
  struct {
	  __IO uint32_t LO_P0           : 1;           /*!< PY (bit 0) for low port                                    */
	  __IO uint32_t LO_P1           : 1;           /*!< P1 (bit 1) for low port                                    */
	  __IO uint32_t LO_P2           : 1;           /*!< P2 (bit 2) for low port                                    */
	  __IO uint32_t LO_P3           : 1;           /*!< P3 (bit 3) for low port                                    */
	  __IO uint32_t LO_P4           : 1;           /*!< P4 (bit 4) for low port                                    */
	  __IO uint32_t LO_P5           : 1;           /*!< P5 (bit 5) for low port                                    */
	  __IO uint32_t LO_P6           : 1;           /*!< P6 (bit 6) for low port                                    */
	  __IO uint32_t LO_P7           : 1;           /*!< P7 (bit 7) for low port [e.g., for GPIOXY, this is GPIOX7  */
	       uint32_t                 : 8;
	  __IO uint32_t HI_P0           : 1;           /*!< P6 (bit 0) for high port                                   */
	  __IO uint32_t HI_P1           : 1;           /*!< P6 (bit 1) for high port                                   */
	  __IO uint32_t HI_P2           : 1;           /*!< P6 (bit 2) for high port                                   */
	  __IO uint32_t HI_P3           : 1;           /*!< P6 (bit 3) for high port                                   */
	  __IO uint32_t HI_P4           : 1;           /*!< P6 (bit 4) for high port                                   */
	  __IO uint32_t HI_P5           : 1;           /*!< P6 (bit 5) for high port                                   */
	  __IO uint32_t HI_P6           : 1;           /*!< P6 (bit 6) for high port                                   */
	  __IO uint32_t HI_P7           : 1;           /*!< P7 (bit 7) for high port [e.g., for GPIOXY, this is GPIOY7 */
           uint32_t                 : 8;
  };
} PAC5XXX_GPIO_PINS_TypeDef;

#define GPIO_DS_8MA               0             /*!< GPIO Drive Strength: 8mA                                    */
#define GPIO_DS_16MA              1             /*!< GPIO Drive Strength: 16mA                                   */

typedef union
{
  __IO uint32_t w;
  struct {
  __IO uint32_t s               	: 16;
       uint32_t                 	: 16;
  };
  struct {
  __IO uint32_t b               	: 8;
       uint32_t                 	: 24;
  };
  struct {
    __IO uint32_t P0              	: 2;           /*!< P0 (bit 0)                                                 */
    __IO uint32_t P1              	: 2;           /*!< P1 (bit 1)                                                 */
	  __IO uint32_t P2              : 2;           /*!< P2 (bit 2)                                                 */
	  __IO uint32_t P3              : 2;           /*!< P3 (bit 3)                                                 */
	  __IO uint32_t P4              : 2;           /*!< P4 (bit 4)                                                 */
	  __IO uint32_t P5              : 2;           /*!< P5 (bit 5)                                                 */
	  __IO uint32_t P6              : 2;           /*!< P6 (bit 6)                                                 */
	  __IO uint32_t P7              : 2;           /*!< P7 (bit 7)                                                 */
	       uint32_t                 : 16;
  };
  struct {
	  __IO uint32_t LO_P0           : 2;           /*!< PY (bit 0) for low port                                    */
	  __IO uint32_t LO_P1           : 2;           /*!< PY (bit 1) for low port                                    */
	  __IO uint32_t LO_P2           : 2;           /*!< PY (bit 2) for low port                                    */
	  __IO uint32_t LO_P3           : 2;           /*!< PY (bit 3) for low port                                    */
	  __IO uint32_t LO_P4           : 2;           /*!< PY (bit 4) for low port                                    */
	  __IO uint32_t LO_P5           : 2;           /*!< PY (bit 5) for low port                                    */
	  __IO uint32_t LO_P6           : 2;           /*!< PY (bit 6) for low port                                    */
	  __IO uint32_t LO_P7           : 2;           /*!< PY (bit 7) for low port [e.g., for GPIOYZ, this is GPIOY7  */
	  __IO uint32_t HI_P0           : 2;           /*!< PZ (bit 0) for high port                                   */
	  __IO uint32_t HI_P1           : 2;           /*!< PZ (bit 1) for high port                                   */
	  __IO uint32_t HI_P2           : 2;           /*!< PZ (bit 2) for high port                                   */
	  __IO uint32_t HI_P3           : 2;           /*!< PZ (bit 3) for high port                                   */
	  __IO uint32_t HI_P4           : 2;           /*!< PZ (bit 4) for high port                                   */
	  __IO uint32_t HI_P5           : 2;           /*!< PZ (bit 5) for high port                                   */
	  __IO uint32_t HI_P6           : 2;           /*!< PZ (bit 6) for high port                                   */
	  __IO uint32_t HI_P7           : 2;           /*!< PZ (bit 7) for high port [e.g., for GPIOYZ, this is GPIOZ7 */
  };
} PAC5XXX_GPIO_PSEL_TypeDef;


typedef struct
{
  __IO PAC5XXX_GPIO_PINS_TypeDef OUT;             /*!< Offset: 0x0000   GPIO Output Register                       */
  __IO PAC5XXX_GPIO_PINS_TypeDef OUTEN;           /*!< Offset: 0x0004   GPIO Output Enable Register                */
  __IO PAC5XXX_GPIO_PINS_TypeDef DS;              /*!< Offset: 0x0008   GPIO Output Drive Strength Register        */
  __IO PAC5XXX_GPIO_PINS_TypeDef PU;              /*!< Offset: 0x000C   GPIO Output Weak Pull-up Register          */
  __IO PAC5XXX_GPIO_PINS_TypeDef PD;              /*!< Offset: 0x0010   GPIO Output Weak Pull-down Register        */
  __I  PAC5XXX_GPIO_PINS_TypeDef IN;              /*!< Offset: 0x0014   GPIO Input Register                        */
  __IO PAC5XXX_GPIO_PINS_TypeDef INE;             /*!< Offset: 0x0024   GPIO Input Enable Register                 */
  __IO PAC5XXX_GPIO_PSEL_TypeDef PSEL;            /*!< Offset: 0x001C   GPIO Peripheral Select Register            */
  __IO PAC5XXX_GPIO_PINS_TypeDef INTP;            /*!< Offset: 0x0020   GPIO Interrupt Polarity Select Register    */
  __IO PAC5XXX_GPIO_PINS_TypeDef INTE;            /*!< Offset: 0x0024   GPIO Interrupt Enable Register             */
  __IO PAC5XXX_GPIO_PINS_TypeDef INTF;            /*!< Offset: 0x0028   GPIO Interrupt Flag Register               */
  __IO PAC5XXX_GPIO_PINS_TypeDef INTM;            /*!< Offset: 0x002C   GPIO Interrupt Mask Register               */
} PAC5XXX_GPIO_TypeDef;

/*@}*/ /* end of group PAC5XXX_GPIO */

#endif // PAC5XXX_GPIO_H
