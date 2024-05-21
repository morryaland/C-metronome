/************************************************\
*                                                *
* AUTHOR:  Muly                                  *
*                                                *
* CREATED: 2024.05.20                            *
*                                                *
* FOR:     Mishander                             *
*                                                *
* ABOUT:   cross-platform metronome written in C *
*                                                *
\************************************************/

#include "include/log.h"

void error(const char *pach, char *format, ...)
{
  va_list args;
  char tmp[BUFSIZ] = "ERROR: ";
  strcat(tmp, format);
  logg(pach, tmp, args);
}

void logg( const char *pach, const char *format, ... )
{
  va_list args;
  FILE *f;

  if (pach) {
    if ((f = fopen(pach, "w"))) {
      va_start(args, format);
      vfprintf(f, format, args);
      fclose(f);
      va_end(args);
    }
  }
  memset(args, 0, sizeof(args));
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}
