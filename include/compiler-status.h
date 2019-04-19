#ifndef KOF_COMPILER_STATUS_H
#define KOF_COMPILER_STATUS_H

/**
 * The following tells us what kind of C
 * features are available to us.
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

#endif // KOF_COMPILER_STATUS_H
