/**
  ******************************************************************************
  * @file    lps25hb_reg.h
  * @author  Sensors Software Solution Team
  * @brief   This file contains all the functions prototypes for the
  *          lps25hb_reg.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LPS25HB_REGS_H
#define LPS25HB_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

/** @addtogroup LPS25HB
  * @{
  *
  */

/** @defgroup  Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/**
  * @}
  *
  */


/** @defgroup STMicroelectronics sensors common types
  * @{
  *
  */

#ifndef MEMS_SHARED_TYPES
#define MEMS_SHARED_TYPES

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0       : 1;
  uint8_t bit1       : 1;
  uint8_t bit2       : 1;
  uint8_t bit3       : 1;
  uint8_t bit4       : 1;
  uint8_t bit5       : 1;
  uint8_t bit6       : 1;
  uint8_t bit7       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7       : 1;
  uint8_t bit6       : 1;
  uint8_t bit5       : 1;
  uint8_t bit4       : 1;
  uint8_t bit3       : 1;
  uint8_t bit2       : 1;
  uint8_t bit1       : 1;
  uint8_t bit0       : 1;
#endif /* DRV_BYTE_ORDER */
} bitwise_t;

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, const uint8_t *, uint16_t);
typedef int32_t (*stmdev_read_ptr)(void *, uint8_t, uint8_t *, uint16_t);
typedef void (*stmdev_mdelay_ptr)(uint32_t millisec);

typedef struct
{
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Component optional fields **/
  stmdev_mdelay_ptr   mdelay;
  /** Customizable optional pointer **/
  void *handle;

  /** private data **/
  void *priv_data;
} stmdev_ctx_t;

/**
  * @}
  *
  */

#endif /* MEMS_SHARED_TYPES */

#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** @defgroup    Generic address-data structure definition
  * @brief       This structure is useful to load a predefined configuration
  *              of a sensor.
  *              You can create a sensor configuration by your own or using
  *              Unico / Unicleo tools available on STMicroelectronics
  *              web site.
  *
  * @{
  *
  */

typedef struct
{
  uint8_t address;
  uint8_t data;
} ucf_line_t;

/**
  * @}
  *
  */

#endif /* MEMS_UCF_SHARED_TYPES */

/**
  * @}
  *
  */

/** @defgroup LPS25HB_Infos
  * @{
  *
  */

/** I2C Device Address 8 bit format if SA0=0 -> B9 if SA0=1 -> BB **/
#define LPS25HB_I2C_ADD_L    0xB9U
#define LPS25HB_I2C_ADD_H    0xBBU

/** Device Identification (Who am I) **/
#define LPS25HB_ID             0xBDU

/**
  * @}
  *
  */

#define LPS25HB_REF_P_XL        0x08U
#define LPS25HB_REF_P_L         0x09U
#define LPS25HB_REF_P_H         0x0AU
#define LPS25HB_WHO_AM_I        0x0FU
#define LPS25HB_RES_CONF        0x10U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t avgp             : 2;
  uint8_t avgt             : 2;
  uint8_t not_used_01      : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01      : 4;
  uint8_t avgt             : 2;
  uint8_t avgp             : 2;
#endif /* DRV_BYTE_ORDER */
} lps25hb_res_conf_t;

#define LPS25HB_CTRL_REG1       0x20U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sim              : 1;
  uint8_t reset_az         : 1;
  uint8_t bdu              : 1;
  uint8_t diff_en          : 1;
  uint8_t odr              : 4; /* pd + odr -> odr */
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t odr              : 4; /* pd + odr -> odr */
  uint8_t diff_en          : 1;
  uint8_t bdu              : 1;
  uint8_t reset_az         : 1;
  uint8_t sim              : 1;
#endif /* DRV_BYTE_ORDER */
} lps25hb_ctrl_reg1_t;

#define LPS25HB_CTRL_REG2       0x21U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t one_shot         : 1;
  uint8_t autozero         : 1;
  uint8_t swreset          : 1;
  uint8_t i2c_dis          : 1;
  uint8_t fifo_mean_dec    : 1;
  uint8_t stop_on_fth      : 1;
  uint8_t fifo_en          : 1;
  uint8_t boot             : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t boot             : 1;
  uint8_t fifo_en          : 1;
  uint8_t stop_on_fth      : 1;
  uint8_t fifo_mean_dec    : 1;
  uint8_t i2c_dis          : 1;
  uint8_t swreset          : 1;
  uint8_t autozero         : 1;
  uint8_t one_shot         : 1;
#endif /* DRV_BYTE_ORDER */
} lps25hb_ctrl_reg2_t;

#define LPS25HB_CTRL_REG3       0x22U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int_s           : 2;
  uint8_t not_used_01     : 4;
  uint8_t pp_od           : 1;
  uint8_t int_h_l         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int_h_l         : 1;
  uint8_t pp_od           : 1;
  uint8_t not_used_01     : 4;
  uint8_t int_s           : 2;
#endif /* DRV_BYTE_ORDER */
} lps25hb_ctrl_reg3_t;

#define LPS25HB_CTRL_REG4       0x23U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t drdy            : 1;
  uint8_t f_ovr           : 1;
  uint8_t f_fth           : 1;
  uint8_t f_empty         : 1;
  uint8_t not_used_01     : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01     : 4;
  uint8_t f_empty         : 1;
  uint8_t f_fth           : 1;
  uint8_t f_ovr           : 1;
  uint8_t drdy            : 1;
#endif /* DRV_BYTE_ORDER */
} lps25hb_ctrl_reg4_t;

#define LPS25HB_INTERRUPT_CFG   0x24U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t pe              : 2;  /* pl_e + ph_e -> pe */
  uint8_t lir             : 1;
  uint8_t not_used_01     : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01     : 5;
  uint8_t lir             : 1;
  uint8_t pe              : 2;  /* pl_e + ph_e -> pe */
#endif /* DRV_BYTE_ORDER */
} lps25hb_interrupt_cfg_t;

#define LPS25HB_INT_SOURCE      0x25U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ph              : 1;
  uint8_t pl              : 1;
  uint8_t ia              : 1;
  uint8_t not_used_01     : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_01     : 5;
  uint8_t ia              : 1;
  uint8_t pl              : 1;
  uint8_t ph              : 1;
#endif /* DRV_BYTE_ORDER */
} lps25hb_int_source_t;

#define LPS25HB_STATUS_REG      0x27U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t t_da            : 1;
  uint8_t p_da            : 1;
  uint8_t not_used_01     : 2;
  uint8_t t_or            : 1;
  uint8_t p_or            : 1;
  uint8_t not_used_02     : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used_02     : 2;
  uint8_t p_or            : 1;
  uint8_t t_or            : 1;
  uint8_t not_used_01     : 2;
  uint8_t p_da            : 1;
  uint8_t t_da            : 1;
#endif /* DRV_BYTE_ORDER */
} lps25hb_status_reg_t;

#define LPS25HB_PRESS_OUT_XL    0x28U
#define LPS25HB_PRESS_OUT_L     0x29U
#define LPS25HB_PRESS_OUT_H     0x2AU
#define LPS25HB_TEMP_OUT_L      0x2BU
#define LPS25HB_TEMP_OUT_H      0x2CU
#define LPS25HB_FIFO_CTRL       0x2EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t wtm_point       : 5;
  uint8_t f_mode          : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t f_mode          : 3;
  uint8_t wtm_point       : 5;
#endif /* DRV_BYTE_ORDER */
} lps25hb_fifo_ctrl_t;

#define LPS25HB_FIFO_STATUS     0x2FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fss             : 5;
  uint8_t empty_fifo      : 1;
  uint8_t ovr             : 1;
  uint8_t fth_fifo        : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fth_fifo        : 1;
  uint8_t ovr             : 1;
  uint8_t empty_fifo      : 1;
  uint8_t fss             : 5;
#endif /* DRV_BYTE_ORDER */
} lps25hb_fifo_status_t;

#define LPS25HB_THS_P_L         0x30U
#define LPS25HB_THS_P_H         0x31U
#define LPS25HB_RPDS_L          0x39U
#define LPS25HB_RPDS_H          0x3AU

/**
  * @defgroup LPS25HB_Register_Union
  * @brief    This union group all the registers having a bit-field
  *           description.
  *           This union is useful but it's not needed by the driver.
  *
  *           REMOVING this union you are compliant with:
  *           MISRA-C 2012 [Rule 19.2] -> " Union are not allowed "
  *
  * @{
  *
  */
typedef union
{
  lps25hb_res_conf_t            res_conf;
  lps25hb_ctrl_reg1_t           ctrl_reg1;
  lps25hb_ctrl_reg2_t           ctrl_reg2;
  lps25hb_ctrl_reg3_t           ctrl_reg3;
  lps25hb_ctrl_reg4_t           ctrl_reg4;
  lps25hb_interrupt_cfg_t       interrupt_cfg;
  lps25hb_int_source_t          int_source;
  lps25hb_status_reg_t          status_reg;
  lps25hb_fifo_ctrl_t           fifo_ctrl;
  lps25hb_fifo_status_t         fifo_status;
  bitwise_t                     bitwise;
  uint8_t                       byte;
} lps25hb_reg_t;

/**
  * @}
  *
  */

#ifndef __weak
#define __weak __attribute__((weak))
#endif /* __weak */

/*
 * These are the basic platform dependent I/O routines to read
 * and write device registers connected on a standard bus.
 * The driver keeps offering a default implementation based on function
 * pointers to read/write routines for backward compatibility.
 * The __weak directive allows the final application to overwrite
 * them with a custom implementation.
 */

int32_t lps25hb_read_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                         uint8_t *data,
                         uint16_t len);
int32_t lps25hb_write_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                          uint8_t *data,
                          uint16_t len);

float_t lps25hb_from_lsb_to_hpa(uint32_t lsb);

float_t lps25hb_from_lsb_to_degc(int16_t lsb);

int32_t lps25hb_pressure_ref_set(const stmdev_ctx_t *ctx, int32_t val);
int32_t lps25hb_pressure_ref_get(const stmdev_ctx_t *ctx, int32_t *val);

typedef enum
{
  LPS25HB_P_AVG_8  = 0,
  LPS25HB_P_AVG_16 = 1,
  LPS25HB_P_AVG_32 = 2,
  LPS25HB_P_AVG_64 = 3,
} lps25hb_avgp_t;
int32_t lps25hb_pressure_avg_set(const stmdev_ctx_t *ctx,
                                 lps25hb_avgp_t val);
int32_t lps25hb_pressure_avg_get(const stmdev_ctx_t *ctx,
                                 lps25hb_avgp_t *val);

typedef enum
{
  LPS25HB_T_AVG_8  = 0,
  LPS25HB_T_AVG_16 = 1,
  LPS25HB_T_AVG_32 = 2,
  LPS25HB_T_AVG_64 = 3,
} lps25hb_avgt_t;
int32_t lps25hb_temperature_avg_set(const stmdev_ctx_t *ctx,
                                    lps25hb_avgt_t val);
int32_t lps25hb_temperature_avg_get(const stmdev_ctx_t *ctx,
                                    lps25hb_avgt_t *val);

int32_t lps25hb_autozero_rst_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_autozero_rst_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_block_data_update_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_block_data_update_get(const stmdev_ctx_t *ctx,
                                      uint8_t *val);

typedef enum
{
  LPS25HB_POWER_DOWN = 0,
  LPS25HB_ODR_1Hz    = 9,
  LPS25HB_ODR_7Hz    = 10,
  LPS25HB_ODR_12Hz5  = 11,
  LPS25HB_ODR_25Hz   = 12,
  LPS25HB_ONE_SHOT   = 8,
} lps25hb_odr_t;
int32_t lps25hb_data_rate_set(const stmdev_ctx_t *ctx, lps25hb_odr_t val);
int32_t lps25hb_data_rate_get(const stmdev_ctx_t *ctx, lps25hb_odr_t *val);

int32_t lps25hb_one_shoot_trigger_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_one_shoot_trigger_get(const stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lps25hb_autozero_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_autozero_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_mean_decimator_set(const stmdev_ctx_t *ctx,
                                        uint8_t val);
int32_t lps25hb_fifo_mean_decimator_get(const stmdev_ctx_t *ctx,
                                        uint8_t *val);

int32_t lps25hb_press_data_ready_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_temp_data_ready_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_temp_data_ovr_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_press_data_ovr_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_pressure_raw_get(const stmdev_ctx_t *ctx, uint32_t *buff);

int32_t lps25hb_temperature_raw_get(const stmdev_ctx_t *ctx, int16_t *buff);

int32_t lps25hb_pressure_offset_set(const stmdev_ctx_t *ctx, int16_t val);
int32_t lps25hb_pressure_offset_get(const stmdev_ctx_t *ctx, int16_t *val);

int32_t lps25hb_device_id_get(const stmdev_ctx_t *ctx, uint8_t *buff);

int32_t lps25hb_reset_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_reset_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_boot_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_boot_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_status_get(const stmdev_ctx_t *ctx,
                           lps25hb_status_reg_t *val);

int32_t lps25hb_int_generation_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_int_generation_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LPS25HB_DRDY_OR_FIFO_FLAGS  = 0,
  LPS25HB_HIGH_PRES_INT       = 1,
  LPS25HB_LOW_PRES_INT        = 2,
  LPS25HB_EVERY_PRES_INT      = 3,
} lps25hb_int_s_t;
int32_t lps25hb_int_pin_mode_set(const stmdev_ctx_t *ctx,
                                 lps25hb_int_s_t val);
int32_t lps25hb_int_pin_mode_get(const stmdev_ctx_t *ctx,
                                 lps25hb_int_s_t *val);

typedef enum
{
  LPS25HB_PUSH_PULL   = 0,
  LPS25HB_OPEN_DRAIN  = 1,
} lps25hb_pp_od_t;
int32_t lps25hb_pin_mode_set(const stmdev_ctx_t *ctx, lps25hb_pp_od_t val);
int32_t lps25hb_pin_mode_get(const stmdev_ctx_t *ctx, lps25hb_pp_od_t *val);

typedef enum
{
  LPS25HB_ACTIVE_HIGH = 0,
  LPS25HB_ACTIVE_LOW  = 1,
} lps25hb_int_h_l_t;
int32_t lps25hb_int_polarity_set(const stmdev_ctx_t *ctx,
                                 lps25hb_int_h_l_t val);
int32_t lps25hb_int_polarity_get(const stmdev_ctx_t *ctx,
                                 lps25hb_int_h_l_t *val);

int32_t lps25hb_drdy_on_int_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_drdy_on_int_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_ovr_on_int_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_fifo_ovr_on_int_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_threshold_on_int_set(const stmdev_ctx_t *ctx,
                                          uint8_t val);
int32_t lps25hb_fifo_threshold_on_int_get(const stmdev_ctx_t *ctx,
                                          uint8_t *val);

int32_t lps25hb_fifo_empty_on_int_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_fifo_empty_on_int_get(const stmdev_ctx_t *ctx,
                                      uint8_t *val);

typedef enum
{
  LPS25HB_NO_THRESHOLD = 0,
  LPS25HB_POSITIVE     = 1,
  LPS25HB_NEGATIVE     = 2,
  LPS25HB_BOTH         = 3,
} lps25hb_pe_t;
int32_t lps25hb_sign_of_int_threshold_set(const stmdev_ctx_t *ctx,
                                          lps25hb_pe_t val);
int32_t lps25hb_sign_of_int_threshold_get(const stmdev_ctx_t *ctx,
                                          lps25hb_pe_t *val);

typedef enum
{
  LPS25HB_INT_PULSED = 0,
  LPS25HB_INT_LATCHED = 1,
} lps25hb_lir_t;
int32_t lps25hb_int_notification_mode_set(const stmdev_ctx_t *ctx,
                                          lps25hb_lir_t val);
int32_t lps25hb_int_notification_mode_get(const stmdev_ctx_t *ctx,
                                          lps25hb_lir_t *val);

int32_t lps25hb_int_source_get(const stmdev_ctx_t *ctx,
                               lps25hb_int_source_t *val);

int32_t lps25hb_int_on_press_high_get(const stmdev_ctx_t *ctx,
                                      uint8_t *val);

int32_t lps25hb_int_on_press_low_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_interrupt_event_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_int_threshold_set(const stmdev_ctx_t *ctx, uint16_t val);
int32_t lps25hb_int_threshold_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lps25hb_stop_on_fifo_threshold_set(const stmdev_ctx_t *ctx,
                                           uint8_t val);
int32_t lps25hb_stop_on_fifo_threshold_get(const stmdev_ctx_t *ctx,
                                           uint8_t *val);

int32_t lps25hb_fifo_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_fifo_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_watermark_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lps25hb_fifo_watermark_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LPS25HB_BYPASS_MODE               = 0,
  LPS25HB_FIFO_MODE                 = 1,
  LPS25HB_STREAM_MODE               = 2,
  LPS25HB_Stream_to_FIFO_mode      = 3,
  LPS25HB_BYPASS_TO_STREAM_MODE    = 4,
  LPS25HB_MEAN_MODE                 = 6,
  LPS25HB_BYPASS_TO_FIFO_MODE      = 7,
} lps25hb_f_mode_t;
int32_t lps25hb_fifo_mode_set(const stmdev_ctx_t *ctx,
                              lps25hb_f_mode_t val);
int32_t lps25hb_fifo_mode_get(const stmdev_ctx_t *ctx,
                              lps25hb_f_mode_t *val);

int32_t lps25hb_fifo_status_get(const stmdev_ctx_t *ctx,
                                lps25hb_fifo_status_t *val);

int32_t lps25hb_fifo_data_level_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_empty_flag_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_ovr_flag_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lps25hb_fifo_fth_flag_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LPS25HB_SPI_4_WIRE = 0,
  LPS25HB_SPI_3_WIRE = 1,
} lps25hb_sim_t;
int32_t lps25hb_spi_mode_set(const stmdev_ctx_t *ctx, lps25hb_sim_t val);
int32_t lps25hb_spi_mode_get(const stmdev_ctx_t *ctx, lps25hb_sim_t *val);

typedef enum
{
  LPS25HB_I2C_ENABLE  = 0,
  LPS25HB_I2C_DISABLE = 1,
} lps25hb_i2c_dis_t;
int32_t lps25hb_i2c_interface_set(const stmdev_ctx_t *ctx,
                                  lps25hb_i2c_dis_t val);
int32_t lps25hb_i2c_interface_get(const stmdev_ctx_t *ctx,
                                  lps25hb_i2c_dis_t *val);

/**
  *@}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /* LPS25HB_REGS_H */
