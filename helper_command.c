/*
 * helper_command.c
 *
 *  Created on: 01.11.2015
 *      Author: rauser
 */

#include "helper_command.h"

#include "socketcand.h"	// extern int state

#include <string.h>

int decode_command(char* command) {

	/* search the command from the current state */
	switch(state) {

	case STATE_NO_BUS:	// ================================ NO_BUS ============
		if(!strncmp("< open ", command, 7)) 		return COMMAND_OPEN;
		break;

	case STATE_BCM:		// ================================ BCM ===============
		if(!strncmp("< send ", command, 7)) 		return COMMAND_SEND;

		if(!strncmp("< add ", command, 6)) 			return COMMAND_ADD;
		if(!strncmp("< update ", command, 9)) 		return COMMAND_UPDATE;
		if(!strncmp("< delete ", command, 9)) 		return COMMAND_DELETE;

		if(!strncmp("< filter ", command, 9)) 		return COMMAND_FILTER;
		if(!strncmp("< subscribe ", command, 12)) 	return COMMAND_SUBSCRIBE;
		if(!strncmp("< unsubscribe ", command, 14)) return COMMAND_UNSUBSCRIBE;
		break;

	case STATE_RAW:		// ================================ RAW ===============
		if(!strncmp("< send ", command, 7)) 		return COMMAND_SEND;
		break;

	case STATE_DEFAULT:	// ================================ DEFAULT ===========
		break;

	case STATE_ISOTP:	// ================================ ISOTP =============
		if(!strncmp("< sendpdu ", command, 10))		return COMMAND_SENDPDU;
		if(!strncmp("< isotpconf ", command, 12))	return COMMAND_ISOTPCONF;
		break;

	case STATE_CONTROL:	// ================================ CONTROL ===========
		if(!strncmp("< statistics ", command, 13))	return COMMAND_STATISTICS;
		break;

	case STATE_SHUTDOWN:// ================================ SHUTDOWN ==========
		break;
	}

	// ==================================================== ALL STATES ========
	if( !strcmp("< echo >", command) ) 				return COMMAND_ECHO;

	// ==================================================== CHANGE STATE ======
	// TODO detect state change here

	return COMMAND_UNKNOWN;
}


