/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		mdu16(16位硬件乘除法)
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C51 V9.60
 * @Target core		STC8H8K64S4
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-06-03
 ********************************************************************************************************************/
#ifndef __ZF_MDU16_H
#define __ZF_MDU16_H

#include "common.h"


//-------------------------------------------------------------------------------------------------------------------
//  @brief      16位乘以16位
//  @param      dat1			乘数1         
//  @param      dat2			乘数2     
//  @param      res				返回结果      
//  @return     void
//  Sample usage:              
//-------------------------------------------------------------------------------------------------------------------
#define MUL16(dat1, dat2, res) 		P_SW2 |= 0x80;MD1U16 = dat1;MD5U16 = dat2;ARCON = 4 << 5;OPCON = 1;while((OPCON & 1) != 0);res=MD3U32
//-------------------------------------------------------------------------------------------------------------------
//  @brief      16位除以16位
//  @param      dat1		分子         
//  @param      dat2		分母     
//  @param      quo			商      
//  @param      mod			余数      
//  @return     void
//  Sample usage:              
//-------------------------------------------------------------------------------------------------------------------	
#define DIV16(dat1, dat2, quo ,mod)	P_SW2 |= 0x80;MD1U16 = dat1;MD5U16 = dat2;ARCON = 6 << 5;OPCON = 1;while((OPCON & 1) != 0);quo = MD1U16;mod = MD5U16
//-------------------------------------------------------------------------------------------------------------------
//  @brief      32位除以16位
//  @param      dat1		分子         
//  @param      dat2		分母    
//  @param      quo			商      
//  @param      mod			余数      
//  @return     void
//  Sample usage:              
//-------------------------------------------------------------------------------------------------------------------	
#define DIV32(dat1, dat2, quo ,mod)  P_SW2 |= 0x80;MD3U32 = dat1;MD5U16 = dat2;ARCON = 6 << 5;OPCON = 1;while((OPCON & 1) != 0);quo = MD3U32;mod = MD5U16
//  @brief      数据左移
//  @param      dat			原始数据   
//  @param      num			移多少位     
//  @param      res			返回结果      
//  @return     void
//  Sample usage:              
//-------------------------------------------------------------------------------------------------------------------	
#define LEFT_SHIFT(dat, num, res) 	P_SW2 |= 0x80;MD3U32 = dat;ARCON = (2 << 5) + num;OPCON = 1;while((OPCON & 1) != 0);res = MD3U32
//  @brief      数据右移移
//  @param      dat			原始数据   
//  @param      num			移多少位     
//  @param      res			返回结果      
//  @return     void
//  Sample usage:              
//-------------------------------------------------------------------------------------------------------------------	
#define RIGHT_SHIFT(dat, num, res) 	P_SW2 |= 0x80;MD3U32 = dat;ARCON = (1 << 5) + num;OPCON = 1;while((OPCON & 1) != 0);res = MD3U32




#endif