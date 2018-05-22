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
 * @file ipc.c
 * @brief fxns for interprocess communications
 *
 * Extended Description:
 * 
 * @author Andrew Kuklinski
 * @date May 5th, 2018
 * @version 1.0
 *
 */

#include "ipc.h"

void logmessage(message_t in_type, source_t in_source, char * in_message, void * in_data)
{
    struct timeval my_timestamp;                        //creates instance of time struct
    gettimeofday(&my_timestamp,NULL);
    
    ipcmessage_t message_struct;
    snprintf(message_struct.timestamp,16,"%ld.%ld\n",(my_timestamp.tv_sec-1513728000), my_timestamp.tv_usec);
    message_struct.source = in_source;
    message_struct.mess_type = in_type;
    strcpy(message_struct.message_string, in_message);
    message_struct.data = in_data;

    //send struct to queue

    char print_source[MAX_MESSAGE_LENGTH];
    char print_type[MAX_MESSAGE_LENGTH];
    switch(in_type)
    {
        case 0:
            strcpy(print_type, "INFO");
            break;
        case 1:
            strcpy(print_type, "ERROR");
            break;
        default:
            strcpy(print_type, "BROKEN");
            break;
    }

    switch(in_source)
    {
        case 0:
            strcpy(print_source, "IPC_NONE");
            break;
        case 1:
            strcpy(print_source, "IPC_MOTION");
            break;
        case 2:
            strcpy(print_source, "IPC_CAMERA");
            break;
        case 3:
            strcpy(print_source, "IPC_MAIN");
            break;
        default:
            strcpy(print_source, "BROKEN!");
            break;
    }


    printf("[%s]|[%s]|[%s]| %s\n",message_struct.timestamp,print_type, 
                                print_source, message_struct.message_string);
}
