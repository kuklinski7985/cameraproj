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
 * @file ipc.h
 * @brief fxn protypes for IPC
 * 
 * In depth description.
 *
 * @author Andrew Kuklinski
 * @date May 5th, 2018
 * @version 1.0
 *
 */

/*Needed in this file
*-struct definition for messages
*-enums for source, type, message, and data (possible void type)
*-queue callback functions? possibly in main instead
*-
*/

#ifndef ipc_h_
#define ipc_h_

#include <stdint.h>                         //needed for uint8_t ect data types
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
//#include <time.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_MESSAGE_LENGTH  64

pthread_mutex_t time_mutex;                 //mutex created for aquisition for current time

/**********Enums and Struct Used for Logging System informtion to File*******/
//describes the message type for the ipc messages
typedef enum{
  INFO, ERROR 
} message_t;

//describes the source of the ipc message
typedef enum{
  IPC_NONE, IPC_MOTION, IPC_CAMERA, IPC_MAIN
} source_t;

//ipc struct that is passed for logging
typedef struct ipcmessage{
    char timestamp[100];
    source_t source;
    message_t mess_type;
    char message_string[MAX_MESSAGE_LENGTH];
    void * data;
}ipcmessage_t;

/**
 *@brief use this to send logging messages to file
 *
 * This function sends the loggging struct to the associated logger thread
 * as well as prints the message to the screen.
 * 
 *@param type: enum message type
 *@param message: string message listed in log entry
 *@param data: any numerical data that is nessary here
 *
 *@return void *
 */
void logmessage(message_t in_type, source_t in_source, char * in_message, void * in_data);

#endif /*ipc_h_*/
