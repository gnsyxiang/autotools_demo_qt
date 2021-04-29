# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    29/04 2021 16:58
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        29/04 2021      create the file
# 
#     last modified: 29/04 2021 16:58
# ===============================================================

include $(top_srcdir)/res/autotroll.mk

noinst_LTLIBRARIES = libqt_ui2h.la

_include_com  	=
_sources_com 	=
_cppflags_com 	= $(QT_CPPFLAGS)
_cflags_com 	= $(QT_CFLAGS)
_cxxflags_com 	= $(QT_CXXFLAGS)
_ldflags_com 	= $(QT_LDFLAGS)
_ldadd_com 		= $(QT_LIBS)

# ---------------------
# add necessary content
# ---------------------
_include_com  	+=

_qt_ui_files 	= DialogShow.ui.h
_sources_com 	+= $(_qt_ui_files)

_cppflags_com 	+= $(CPPFLAGS_COM) \
				   $(_include_com)

_cflags_com 	+= $(CFLAGS_COM)

_cxxflags_com 	+= $(CXXFLAGS_COM)

_ldflags_com 	+= $(LIB_LDFLAGS_COM)

_ldadd_com 		+=

libqt_ui2h_la_SOURCES  	= $(_sources_com)
libqt_ui2h_la_CPPFLAGS 	= $(_cppflags_com)
libqt_ui2h_la_CFLAGS 	= $(_cflags_com)
libqt_ui2h_la_CXXFLAGS 	= $(_cxxflags_com)
libqt_ui2h_la_LDFLAGS  	= $(_ldflags_com)
libqt_ui2h_la_LIBADD   	= $(_ldadd_com)

BUILT_SOURCES = $(_qt_ui_files)

