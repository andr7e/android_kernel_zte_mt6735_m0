#ifndef _CUST_BATTERY_METER_H
#define _CUST_BATTERY_METER_H

#if defined(CONFIG_MTK_BQ24196_SUPPORT) \
	|| defined(CONFIG_MTK_BQ24296_SUPPORT) \
	|| defined(CONFIG_MTK_BQ24261_SUPPORT)
#define SWCHR_POWER_PATH
#define EXTERNAL_SWCHR_SUPPORT
#endif

/* ============================================================
// define
// ============================================================*/
/*#define SOC_BY_AUXADC*/
#define SOC_BY_HW_FG
/*#define HW_FG_FORCE_USE_SW_OCV*/
#define DISABLE_RFG_EXIST_CHECK
/*#define SOC_BY_SW_FG*/

#define CONFIG_DIS_CHECK_BATTERY
//#define FIXED_TBAT_25

/* ADC resistor  */
#define R_BAT_SENSE 4
#define R_I_SENSE 4
#define R_CHARGER_1 330
#define R_CHARGER_2 39

#define TEMPERATURE_T0 110
#define TEMPERATURE_T1 0
#define TEMPERATURE_T2 25
#define TEMPERATURE_T3 50
#define TEMPERATURE_T 255 /* This should be fixed, never change the value*/

#define FG_METER_RESISTANCE 0

/* Qmax for battery  */
#define Q_MAX_POS_50	2265
#define Q_MAX_POS_25	2252
#define Q_MAX_POS_0		2260
#define Q_MAX_NEG_10	2300

#define Q_MAX_POS_50_H_CURRENT	2258
#define Q_MAX_POS_25_H_CURRENT	2240
#define Q_MAX_POS_0_H_CURRENT	2138
#define Q_MAX_NEG_10_H_CURRENT	1901

/* Discharge Percentage */
#define OAM_D5		 1		/*  1 : D5,   0: D2*/

/* battery meter parameter */
#define CHANGE_TRACKING_POINT
#ifdef CONFIG_MTK_HAFG_20
#define CUST_TRACKING_POINT  0
#else
#define CUST_TRACKING_POINT  1
#endif
#define CUST_R_SENSE         56
#define CUST_HW_CC 		     0
#define AGING_TUNING_VALUE   103
#define CUST_R_FG_OFFSET     0

#define OCV_BOARD_COMPESATE	0 /*mV */
#define R_FG_BOARD_BASE 1000
#define R_FG_BOARD_SLOPE 1000 /*slope*/
#define CAR_TUNE_VALUE		103 //1.00

/* HW Fuel gague  */
#define CURRENT_DETECT_R_FG 10  /*1mA*/
#define MinErrorOffset 1000
#define FG_VBAT_AVERAGE_SIZE 18
#define R_FG_VALUE 10 /* mOhm, base is 20*/

#define CUST_POWERON_DELTA_CAPACITY_TOLRANCE	30
#define CUST_POWERON_LOW_CAPACITY_TOLRANCE		5
#define CUST_POWERON_MAX_VBAT_TOLRANCE			90
#define CUST_POWERON_DELTA_VBAT_TOLRANCE		30
#define CUST_POWERON_DELTA_HW_SW_OCV_CAPACITY_TOLRANCE	10


/* Disable Battery check for HQA */
#ifdef CONFIG_MTK_DISABLE_POWER_ON_OFF_VOLTAGE_LIMITATION
#define FIXED_TBAT_25
#endif

/* Dynamic change wake up period of battery thread when suspend*/
#define VBAT_NORMAL_WAKEUP		3600
#define VBAT_LOW_POWER_WAKEUP		3500
#define NORMAL_WAKEUP_PERIOD		5400
#define LOW_POWER_WAKEUP_PERIOD		300
#define CLOSE_POWEROFF_WAKEUP_PERIOD	30

#define FG_BAT_INT
#define IS_BATTERY_REMOVE_BY_PMIC


#endif	//#ifndef _CUST_BATTERY_METER_H
