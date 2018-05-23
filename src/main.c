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
 * @file main.c
 * @brief main function for project.
 * 
 * This file servers as the initialization and user interface to the sensors 
 * assocaited with this project.  
 * Sensors: Motion detect, SD card read/write, TTL camera
 * Function:  When the motion sensor detects motion, it will trigger the camera
 *            to take and picture and save directly to the SD card.
 *
 * @author Andrew Kuklinski
 * @date May 5th, 2018
 * @version 1.0
 *
 */

#include "main.h"

int main(int argc, char * argv[])
{
  //fxn that blinks all LED's to verify working
  //fxn my_UART_init(uint8_t uartNum, uint8_t BAUDRATE) for each necessary UART

  uint8_t checking;               //holds value of pthread return

  /************section for creating and verifying threads*************************/

  //thread for the motion sensor
  checking = pthread_create(&motion_thread, NULL, motionSense, NULL);
  if(checking)
  {
      logmessage(ERROR, IPC_MAIN, "Motion Thread creation FAILED\n",NULL);
      return 1;
  }
  logmessage(INFO, IPC_MAIN, "Motion Thread Created Successfully\n", NULL);

  //thread for the logger
  checking = pthread_create(&logger_thread, NULL, logger, NULL);
  if(checking)
  {
      logmessage(ERROR, IPC_MAIN, "Logger Thread creation FAILED\n", NULL);
      return 1;
  }
  logmessage(INFO, IPC_MAIN, "Logger Thread Created Successfully\n", NULL);
  usleep(100);

  /*********************************While loop for Main thread******************/
  
  while(bizzounce == 0)
  {
    userInput();
  }


  /************************Rejoin threads and exit program***********************/
  pthread_join(motion_thread,NULL);
  pthread_join(logger_thread, NULL);

  /************************Close queues and un_link****************************/
  //mq_close(log_queue);
  
  return 0;
}


/*next steps
- create the logger queue, include the mouting of the queue file
- create / copy the functions necessary for creating a new text log file
- link the queue and logger file similar in fashion to project 1
*/