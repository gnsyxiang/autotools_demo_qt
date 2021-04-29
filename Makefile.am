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

SUBDIRS = 3rd_lib \
		  include \
		  src \
		  doc \
		  res

# --------
# cppflags
# --------
ACLOCAL_AMFLAGS 	= -I m4
no_error_com 		= -Wno-error=deprecated-copy \
					  -Wno-error=unused-result \
					  -Wno-unused-parameter \
					  -Wno-error=unused-but-set-variable
CPPFLAGS_COM 		= -pipe -W -Wall -Werror \
					  $(no_error_com) \
					  $(ACLOCAL_AMFLAGS)

LIB_CPPFLAGS_COM 	= -ffunction-sections \
					  -fdata-sections

# -----------
# lib ldflags
# -----------
LIB_LDFLAGS_COM = -rdynamic

# -----------
# bin ldflags
# -----------
BIN_LDFLAGS_COM = -Wl,--gc-sections

# ------------------
# make install files
# ------------------
install_files_com 	= LICENSE \
					  README.md
dist_doc_DATA 		= $(install_files_com)

# ---------------
# make dist files
# ---------------
dist_files_com 	= autogen.sh
EXTRA_DIST 		= $(dist_files_com)

# ----------
# export var
# ----------
export CPPFLAGS_COM
export LIB_CPPFLAGS_COM
export LIB_LDFLAGS_COM
export BIN_LDFLAGS_COM
