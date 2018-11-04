/*----------------------------------------------------------------------*/
/* FAT file system sample project for FatFs            (C)ChaN, 2018    */
/*----------------------------------------------------------------------*/

#include <string.h>
//#include "STM32F100.h"
//#include "uart_stm32f1.h"
#include "service.h"
#include "stm32f411xe.h"
#include "xprintf.h"
#include "cmsis_os.h"

//typedef unsigned int	UINT;	/* int must be 16-bit or 32-bit */
//typedef unsigned char	BYTE;	/* char must be 8-bit */
//typedef uint16_t		WORD;	/* 16-bit unsigned integer */
//typedef uint16_t		WCHAR;	/* 16-bit unsigned integer */
//typedef uint32_t		DWORD;	/* 32-bit unsigned integer */
//typedef uint64_t		QWORD;	/* 64-bit unsigned integer */


uint32_t AccSize;				/* Work register for fs command */
uint16_t AccFiles, AccDirs;

char Line[256];				/* Console input buffer */
unsigned char Buff[4096] __attribute__ ((aligned (4))) ;	/* Working buffer */

static
const char HelpMsg[] =
	"[Disk contorls]\n"
	" di <pd#> - Initialize disk\n"
	" dd [<pd#> <lba>] - Dump a secrtor\n"
	" ds <pd#> - Show disk status\n"
	"[Buffer controls]\n"
	" bd <ofs> - Dump working buffer\n"
	" be <ofs> [<data>] ... - Edit working buffer\n"
	" br <pd#> <lba> [<count>] - Read disk into working buffer\n"
	" bw <pd#> <lba> [<count>] - Write working buffer into disk\n"
	" bf <val> - Fill working buffer\n"
	"[File system controls]\n"
	" fi <ld#> [<mount>]- Force initialized the volume\n"
	" fs [<path>] - Show volume status\n"
	" fl [<path>] - Show a directory\n"
	" fo <mode> <file> - Open a file\n"
	" fc - Close the file\n"
	" fe <ofs> - Move fp in normal seek\n"
	" fd <len> - Read and dump the file\n"
	" fr <len> - Read the file\n"
	" fw <len> <val> - Write to the file\n"
	" fn <org.name> <new.name> - Rename an object\n"
	" fu <name> - Unlink an object\n"
	" fv - Truncate the file at current fp\n"
	" fk <name> - Create a directory\n"
	" fa <atrr> <mask> <object name> - Change attribute of an object\n"
	" ft <year> <month> <day> <hour> <min> <sec> <name> - Change timestamp of an object\n"
	" fx <src.file> <dst.file> - Copy a file\n"
	" fg <path> - Change current directory\n"
	" fq - Show current directory\n"
	" fb <name> - Set volume label\n"
	" fm <ld#> <type> <csize> - Create file system\n"
	" fz [<len>] - Change/Show R/W length for fr/fw/fx command\n"
	"[Misc commands]\n"
	" md[b|h|w] <addr> [<count>] - Dump memory\n"
	" mf <addr> <value> <count> - Fill memory\n"
	" me[b|h|w] <addr> [<value> ...] - Edit memory\n"
	" t [<year> <mon> <mday> <hour> <min> <sec>] - Set/Show RTC\n"
	"\n";



void ServiceTask (void)
{
	char *ptr;

	xputs("Service Task gestartet\n");

	for (;;) {
		xputc('>');
		xgets(Line, sizeof Line);
		xputs(Line);

		ptr = Line;
//		xprintf("Str:%s ", Line);

		switch (*ptr++) {
		case '?' :	/* Show Command List */
			xputs(HelpMsg);
			break;
		case 'm' :	/* Memory dump/fill/edit */
			switch (*ptr++) {
			case 'd' :
				switch (*ptr++) {
				case 'w':
					break;
				case 'h':
					break;
				default:
					break;
				} // switch 3. Zeichen
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
			} // switch 2. Zeichen
			break;
		default:
			xprintf("\n%s -> keine gültige Eingabe\n", Line);
			break;
		} // switch 1. Zeichen
	}
}

