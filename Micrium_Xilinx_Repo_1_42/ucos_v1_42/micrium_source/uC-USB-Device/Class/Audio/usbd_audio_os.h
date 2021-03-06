/*
*********************************************************************************************************
*                                            uC/USB-Device
*                                       The Embedded USB Stack
*
*                         (c) Copyright 2004-2014; Micrium, Inc.; Weston, FL
*
*                  All rights reserved.  Protected by international copyright laws.
*
*                  uC/USB-Device is provided in source form to registered licensees ONLY.  It is
*                  illegal to distribute this source code to any third party unless you receive
*                  written permission by an authorized Micrium representative.  Knowledge of
*                  the source code may NOT be used to develop a similar product.
*
*                  Please help us continue to provide the Embedded community with the finest
*                  software available.  Your honesty is greatly appreciated.
*
*                  You can find our product's user manual, API reference, release notes and
*                  more information at: https://doc.micrium.com
*
*                  You can contact us at: http://www.micrium.com
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                       USB DEVICE AUDIO CLASS
*
* File          : usbd_audio_os.h
* Version       : V4.05.00
* Programmer(s) : CM
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  USBD_AUDIO_OS_MODULE_PRESENT
#define  USBD_AUDIO_OS_MODULE_PRESENT


/*
*********************************************************************************************************
*********************************************************************************************************
*                                            INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             DATA TYPES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                          GLOBAL VARIABLES
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MACRO'S
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*********************************************************************************************************
*/

void   USBD_Audio_OS_Init               (CPU_INT16U   msg_qty,
                                         USBD_ERR    *p_err);

void   USBD_Audio_OS_AS_IF_LockCreate   (CPU_INT08U   as_if_nbr,
                                         USBD_ERR    *p_err);

void   USBD_Audio_OS_AS_IF_LockAcquire  (CPU_INT08U   as_if_nbr,
                                         CPU_INT16U   timeout_ms,
                                         USBD_ERR    *p_err);

void   USBD_Audio_OS_AS_IF_LockRelease  (CPU_INT08U   as_if_nbr);

void   USBD_Audio_OS_RingBufQLockCreate (CPU_INT08U   as_if_settings_ix,
                                         USBD_ERR    *p_err);

void   USBD_Audio_OS_RingBufQLockAcquire(CPU_INT08U   as_if_settings_ix,
                                         CPU_INT16U   timeout_ms,
                                         USBD_ERR    *p_err);

void   USBD_Audio_OS_RingBufQLockRelease(CPU_INT08U   as_if_settings_ix);

#if (USBD_AUDIO_CFG_RECORD_EN == DEF_ENABLED)
void   USBD_Audio_OS_RecordReqPost      (void        *p_msg,
                                         USBD_ERR    *p_err);

void  *USBD_Audio_OS_RecordReqPend      (USBD_ERR    *p_err);
#endif

#if (USBD_AUDIO_CFG_PLAYBACK_EN == DEF_ENABLED)
void   USBD_Audio_OS_PlaybackReqPost    (void        *p_msg,
                                         USBD_ERR    *p_err);

void  *USBD_Audio_OS_PlaybackReqPend    (USBD_ERR    *p_err);
#endif

void   USBD_Audio_OS_DlyMs              (CPU_INT32U   ms);


/*
*********************************************************************************************************
*********************************************************************************************************
*                                        CONFIGURATION ERRORS
*********************************************************************************************************
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif

