# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    27/04 2021 20:21
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        27/04 2021      create the file
# 
#     last modified: 27/04 2021 20:21
# ===============================================================

include $(top_srcdir)/res/autotroll.mk

_include_com  	=
_sources_com 	=
_cppflags_com 	= $(QT_CPPFLAGS)
_cflags_com 	= $(QT_CFLAGS)
_cxxflags_com 	= $(QT_CXXFLAGS)
_ldflags_com 	= $(QT_LDFLAGS)
_ldadd_com 		= $(QT_LIBS)
bin_PROGRAMS 	=

# ---------------------
# add necessary content
# ---------------------
_include_com  	+= -I$(top_srcdir)/include \
				   -I$(top_builddir)/res/ui

_sources_com 	+= main.cpp \
				   DialogShow.cpp

_cppflags_com 	+= $(CPPFLAGS_COM) \
				   $(_include_com)

_cflags_com 	+= $(CFLAGS_COM)

_cxxflags_com 	+= $(CXXFLAGS_COM)

_ldflags_com 	+= $(BIN_LDFLAGS_COM)

_ldadd_com 		+= $(top_builddir)/include/libqt_h2cpp.la

bin_PROGRAMS	+= main
main_SOURCES 	= $(_sources_com)
main_CPPFLAGS  	= $(_cppflags_com)
main_CFLAGS  	= $(_cflags_com)
main_CXXFLAGS  	= $(_cxxflags_com)
main_LDFLAGS	= $(_ldflags_com)
main_LDADD   	= $(_ldadd_com)

