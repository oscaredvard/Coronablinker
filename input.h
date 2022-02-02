#ifndef __AX_HA_IT_INPUT__
#define __AX_HA_IT_INPUT__

#include <errno.h>

/*
  If something goes wrong all functions
  1) sets the global errno variable to EIO
  2) empties the input buffer
  3) returns 0
*/

/* Read an integer from standard input.
   Uses standard 'whitespace' delimiter (spaces/tabs/newline)
*/
int readInt(void);
/* Read an integer from standard input followed by a custom delimiter.
   Example: readIntAnd(',') expects an integer followed by a comma.
*/
int readIntAnd(char delimiter);

/* Read an unsigned integer from standard input */
unsigned readUnsigned(void);
unsigned readUnsignedAnd(char delimiter);

/* Read a short integer from standard input */
short readShort(void);
short readShortAnd(char delimiter);

/* Read a long integer from standard input */
long readLong(void);
long readLongAnd(char delimiter);

/* Read a float from standard input */
float readFloat(void);
float readFloatAnd(char delimiter);

/* Read a double from standard input */
double readDouble(void);
double readDoubleAnd(char delimiter);

/* Read a char from standard input */
char readChar(void);
char readCharAnd(char delimiter);

#endif // __AX_HA_IT_INPUT__