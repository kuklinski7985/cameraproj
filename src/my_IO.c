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

#include "my_IO.h"

int usr_led_toggle(int lednum, int togvalue)
{
  FILE * ledfile;

  if(togvalue > 1)
    {
      printf("Only values of 1 or 0: 0=OFF | 1=ON\n");
      return 1;
    }
  switch(lednum){
  case 1:
    ledfile = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr1/brightness", "w");
    fprintf(ledfile,"%d",togvalue);
    break;
  case 2:
    ledfile = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr2/brightness", "w");
    fprintf(ledfile,"%d",togvalue);
    break;
  case 3:
    ledfile = fopen("/sys/devices/platform/leds/leds/beaglebone:green:usr3/brightness", "w");
    fprintf(ledfile,"%d",togvalue);
    break;
  default:
    printf("Not a valid LED number.\n Please choose from LED 1,2, or 3\n");
  }

  if(ledfile == NULL)
    {
      printf("ERROR!  LED file not opened\n");
      return 1;
    }
  
  fclose(ledfile);
  return 0;
}

void userInput(void)
{
  printf("/***********************/\n");
  printf("******Options Menu******\n");
  printf("1. Motion Sensor OFF\n");
  printf("2. Motion Sensor ON\n");
  printf("3. Display SD Card Stats\n");
  printf("4. Take Picture\n");
  printf("5. Get Camera SN #\n");
  printf("6. Terminate Program\n");
  printf("/***********************/\n\n");

  int userinput;
  scanf("%d", &userinput);
  switch(userinput)
  {
    case 1:
      printf("motion off\n\n");
      break;
    case 2:
      printf("motion on\n\n");
      break;
    case 3:
      printf("SD stats\n\n");
      break;
    case 4:
      printf("take pic\n\n");
      break;
    case 5:
      printf("camera SN\n\n");
      break;
    case 6:
      printf("Terminating Program...\n\n");
      bizzounce = 1;
      break;
    default:
      printf("Not a Valid Entry, Please try again\n");
      break;
  }
}