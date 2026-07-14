dnl Process this file with autoconf to produce a configure script.
AC_INIT([cpp-learning-journey], [1.0], [h3377@github.com])
AC_CONFIG_SRCDIR([])
AC_CONFIG_HEADERS([config.h])

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

dnl Initialize automake
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

dnl Checks for libraries.
dnl AC_CHECK_LIB([m], [sin])

dnl Checks for header files.
AC_CHECK_HEADERS([stdio.h stdlib.h string.h])

dnl Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

dnl Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([
 Makefile
])
AC_OUTPUT
