#ifndef RTLSDR_REDIR_PRINT_H
#define RTLSDR_REDIR_PRINT_H

#define LOG_TRG_STDERR 1
#define LOG_TRG_STDOUT 2

#include <stdio.h>
#include "rtl-sdr_export.h"

typedef void(*std_print_wrapper)(char target, char *text, void *ctx);

/* Configure a redirection for data printed to stdout or stderr
 * \param cb callback function to receive printed data
 * \param ctx user specific context to pass via the callback function
 * \return 0 on success
 */
RTLSDR_API int rtlsdr_print_redirection(std_print_wrapper cb, void *ctx);

/*
 * fprintf wrapper. If there's a registered redirection, it prints to a buffer
 * and sends it to the callback.
 * otherwise normal output to specified stream.
 */
int rtlsdr_fprintf(FILE *stream, const char* aFormat, ...);

#endif // RTLSDR_REDIR_PRINT_H
