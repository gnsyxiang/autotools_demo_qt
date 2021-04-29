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

include_com  	=
cppflags_com 	= $(QT_CPPFLAGS)
cflags_com 		= $(QT_CFLAGS)
cxxflags_com 	= $(QT_CXXFLAGS)
ldflags_com 	= $(QT_LDFLAGS)
ldadd_com 		= $(QT_LIBS)
bin_PROGRAMS 	=

# ---------------------
# add necessary content
# ---------------------
include_com  	+= -I$(top_srcdir)/include
cppflags_com 	+= $(CPPFLAGS_COM) \
				   $(include_com)

ldflags_com 	+= $(BIN_LDFLAGS_COM) \
				   -Wl,-rpath=../lib \
				   -Wl,-Bsymbolic

qt_h_files 		= test.hpp
qt_moc_files 	= test.moc.cpp
sources 		= main.cpp test.cpp $(qt_h_files) $(qt_moc_files)

bin_PROGRAMS	+= main
main_SOURCES 	= $(sources)
main_CPPFLAGS  	= $(cppflags_com)
main_CFLAGS  	= $(cflags_com)
main_CXXFLAGS  	= $(cxxflags_com)
main_LDFLAGS	= $(ldflags_com)
main_LDADD   	= $(ldadd_com)

BUILT_SOURCES = $(qt_moc_files)

