/*----------------------------------------------------------------------*/
/* Service Schnittstelle                                                */
/*----------------------------------------------------------------------*/

#include <string.h>
#include "service.h"
#include "stm32f411xe.h"
#include "xprintf.h"
#include "cmsis_os.h"


uint32_t AccSize;				/* Work register for fs command */
uint16_t AccFiles, AccDirs;

char Line[256];				/* Console input buffer */
unsigned char Buff[4096] __attribute__ ((aligned (4))) ;	/* Working buffer */

static
const char HelpMsg[] =
  "/n*-HELP------COMMAND OVERVIEW----------------------------------------*\n"
	"| cmd     Command   Params     Description                          |\n"
	"| ---     -------   ------     -----------                          |\n"
	"| H       help      -          print help menu                      |\n"
	"| I       info      -          print device information             |\n"
	"| D       display   -          control display                      |\n"
	"| P       pwm       chan, val  pwm control                          |\n"
	"| Q       Quit      -          exit help menu                       |\n"
	"| S       status    kat        state of different device parameters |\n"
	"| T       tranf. r. t          transfer rate of comm. data          |\n"
	"*-------------------------------------------------------------------*\n"
	"\n";



void ServiceTask (void)
{
	char *ptr;

	xputs("Service Task started\n");

	for (;;) {
		xputc('>');
		xgets(Line, sizeof Line);
		xputs(Line);

		ptr = Line;
//		xprintf("Str:%s ", Line);

		switch (*ptr++) {
		case 'h' :	/* print help menu */
		case 'H' :
			xputs(HelpMsg);
			break;
		case 'i' :	/* print device information */
		case 'I' :
			break;
		case 'd' :	/* control display */
		case 'D' :
			break;
		case 'p' :	/* pwm control */
		case 'P' :
			switch (*ptr++) {
			case 'd' :
				switch (*ptr++) {
				case 'w':
					break;
				case 'h':
					break;
				default:
					break;
				} // switch 3. character
				break;
			case 'f' :
				break;
			case 'e' :
				switch (*ptr++) {	/* Get data width */
				case 'w':
				case 'h':
				default:
					break;
				}
				break;
			} // switch 2. character
			break;
		default:
			xprintf("\n%s -> invalid input\n", Line);
			break;
		} // switch 1. character
	}
}

