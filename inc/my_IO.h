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
 * @file my_IO.h
 * @brief fxn prototypes for GPIO on the BBB
 * 
 * Contains fxns for all GPIO: USRLED, UART, i2c, SPI, GPIO (in and out),
 *                              and user input functions
 *
 * @author Andrew Kuklinski
 * @date May 5th, 2018
 * @version 1.0
 *
 */

#ifndef my_IO_h_
#define my_IO_h_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>             //needed for uint8_t ect data types



extern uint8_t bizzounce;

/**
 *@brief used to toggle the USR LED's on the beaglebone green
 *
 *@param "lednum" which led to toggle, not including USRLED 0, options 1,2,3
 *@param "togvalue" 0 for off, 1 for on
 *
 *@return VOID
 */

int usr_led_toggle(int lednum, int togvalue);

/**
 *@brief function to make main fxn cleaner, accepts user input and changes options accordingly
 *
 *@param NULL
 *
 *@return VOID
 */
void userInput(void);

#endif /*my_IO_h_*/