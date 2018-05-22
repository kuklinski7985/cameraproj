/******************************************************************************
* Copyright (C) 2018 Andrew Kuklinski
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. This file
* was created as a personal project to better understand programming.  
* Andrew Kuklinski is not liable for an misuse of this material.
*
*******************************************************************************/
/**
 * @file my_IO.c
 * @brief fxn defintions for GPIO on the BBB
 * 
 * Contains fxns for all GPIO: USRLED, UART, i2c, SPI, GPIO (in and out)
 *
 * @author Andrew Kuklinski
 * @date May 5th, 2018
 * @version 1.0
 *
 */

#ifndef BBB_tasks_h_
#define BBB_tasks_h_

#include <stdint.h>             //needed for uint8_t ect data types
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <errno.h>

//threading library
#include <pthread.h>

/****global variables that are defined in main.h*****/
extern uint8_t bizzounce;

/**
 *@brief calling fxn for the motionSense thread
 *
 *@param void* vars : can be passed in when creating thread
 *
 *@return void *
 */
void * motionSense(void* vars);

/**
 *@brief calling fxn for the logger thread
 *
 *@param void* vars : can be passed in when creating thread
 *
 *@return void *
 */
void * logger(void* vars);

#endif /*BBB_tasks_h_*/

