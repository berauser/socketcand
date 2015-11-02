/*
 * helper_command.h
 *
 *  Created on: 01.11.2015
 *      Author: rauser
 */

#ifndef HELPER_COMMAND_H_
#define HELPER_COMMAND_H_

/* all */
#define COMMAND_UNKNOWN 0
#define COMMAND_ECHO 1
#define COMMAND_STATE_CHANGE 2

/* raw, bcm */
#define COMMAND_SEND 3

/* bcm */
#define COMMAND_ADD 4
#define COMMAND_UPDATE 5
#define COMMAND_DELETE 6
#define COMMAND_FILTER 7
#define COMMAND_SUBSCRIBE 8
#define COMMAND_UNSUBSCRIBE 9

/* control */
#define COMMAND_STATISTICS 10

/* isotp */
#define COMMAND_SENDPDU 11
#define COMMAND_ISOTPCONF 12

/* no bus */
#define COMMAND_OPEN 13

int decode_command(char* command);

#endif /* HELPER_COMMAND_H_ */
