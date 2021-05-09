# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    27/04 2021 20:19
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        27/04 2021      create the file
# 
#     last modified: 27/04 2021 20:19
# ===============================================================

include res/doxygen.am

SUBDIRS = include \
		  src \
		  example \
		  3rd_lib \
		  res \
		  doc

# -----
# flags
# -----
ACLOCAL_AMFLAGS 	= -I m4

_no_error_com 		= -W -Wall

_remove_unuse_func 	= -ffunction-sections \
					  -fdata-sections

CPPFLAGS_COM 		= -pipe \
					  $(_no_error_com) \
					  $(ACLOCAL_AMFLAGS)

CFLAGS_COM 			= $(_remove_unuse_func)

CXXFLAGS_COM 		= $(_remove_unuse_func)

LIB_LDFLAGS_COM 	= -rdynamic

BIN_LDFLAGS_COM 	=

if COMPILE_SELECT_BUILD_SYSTEM_OS_LINUX
BIN_LDFLAGS_COM 	+= -Wl,--gc-sections
endif

export CPPFLAGS_COM
export CFLAGS_COM
export CXXFLAGS_COM
export LIB_LDFLAGS_COM
export BIN_LDFLAGS_COM

# ------------------
# make install files
# ------------------
install_files_com 	= LICENSE \
					  README.md
dist_doc_DATA 		= $(install_files_com)

# ---------------
# make dist files
# ---------------
dist_files_com 		= autogen.sh
EXTRA_DIST 			= $(dist_files_com)

