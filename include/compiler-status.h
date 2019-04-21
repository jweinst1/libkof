#ifndef KOF_COMPILER_STATUS_H
#define KOF_COMPILER_STATUS_H

/**
 * The following tells us what kind of C
 * features are available to us. Also informs
 * of specific requirements to the OS
 */
#if defined(__STDC__)
# define KOF_STD_C_1989
# if defined(__STDC_VERSION__)
#  define KOF_STD_C_1990
#  if (__STDC_VERSION__ >= 199409L)
#   define KOF_STD_C_1994
#  endif
#  if (__STDC_VERSION__ >= 199901L)
#   define KOF_STD_C_1999
#  endif
#  if (__STDC_VERSION__ >= 201112L)
#   define KOF_STD_C_2011
#  endif
# endif
#endif

#if defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
#  define KOF_OS_UNIX
#endif

#ifdef _WIN32
#  define KOF_OS_WIN32
#endif

#ifdef KOF_STD_C_1999
#  define KOF_HAS_VARIADIC_ARGS
#endif

#ifdef WIN32_UTF16_PATHNAMES
#  ifndef KOF_STD_C_1994
#     include <stddef.h>
#  else
#     include <wchar.h>
#  endif // KOF_STD_C_1994
   typedef wchar_t ospath_ch_t;
#  define OSPATH_CON(expr) L##expr
#else
   typedef char ospath_ch_t;
#  define OSPATH_CON(expr) expr
#endif // WIN32_UTF16_PATHNAMES

#endif // KOF_COMPILER_STATUS_H
