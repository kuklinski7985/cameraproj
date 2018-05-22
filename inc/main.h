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
 * @file template.c
 * @brief Brief description
 * 
 * In depth description.
 *
 * @author Andrew Kuklinski
 * @date May 5th, 2018
 * @version 1.0
 *
 * NOTES:  all fxns that return a value, 0 = no error, >0 error
 */



#include <stdint.h>                         //needed for uint8_t ect data types
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>                         //needed for queue operation

#include "BBB_tasks.h"
#include "camera.h"
#include "presence_sense.h"
#include "my_IO.h"
#include "ipc.h"

uint8_t bizzounce = 0;                  //global variable that will exit all running threads

/****Thread creation variables****/
pthread_t motion_thread;
pthread_t logger_thread;

/****variable for queue creation***/
file_t logfile;             //file where logger information is stored
mqd_t log_queue;            //queue for logger
struct mq_attr ipc_attr;    //attributes for ipc queue
