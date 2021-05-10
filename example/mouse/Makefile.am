# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    10/05 2021 18:49
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        10/05 2021      create the file
# 
#     last modified: 10/05 2021 18:49
# ===============================================================

include $(top_srcdir)/res/autotroll.mk

_include_com  	=
_sources_com 	=
_cppflags_com 	= $(QT_CPPFLAGS)
_cflags_com 	= $(QT_CFLAGS)
_cxxflags_com 	= $(QT_CXXFLAGS)
_ldflags_com 	= $(QT_LDFLAGS)
_ldadd_com 		= $(QT_LIBS)
noinst_PROGRAMS	=

# ---------------------
# add necessary content
# ---------------------
_include_com  	+=

_qt_ui_files 	= mouse.ui.h
_qt_h_files 	= MouseDialog.moc.cpp
_qt_cpp_files 	= main.cpp \
				  MouseDialog.cpp
_sources_com 	+= $(_qt_ui_files) \
				   $(_qt_h_files) \
				   $(_qt_cpp_files)

_cppflags_com 	+= $(CPPFLAGS_COM) \
				   $(_include_com)

_cflags_com 	+= $(CFLAGS_COM)

_cxxflags_com 	+= $(CXXFLAGS_COM)

_ldflags_com 	+= $(BIN_LDFLAGS_COM)

_ldadd_com 		+=

_target 				= event_mouse
noinst_PROGRAMS			+= $(_target)
event_mouse_SOURCES 	= $(_sources_com)
event_mouse_CPPFLAGS 	= $(_cppflags_com)
event_mouse_CFLAGS  	= $(_cflags_com)
event_mouse_CXXFLAGS 	= $(_cxxflags_com)
event_mouse_LDFLAGS		= $(_ldflags_com)
event_mouse_LDADD   	= $(_ldadd_com)

BUILT_SOURCES 	= $(_qt_h_files) \
				  $(_qt_ui_files)

# -----------------
# find source files
# -----------------
all_sources_files 	= `find $(top_srcdir)/example/mouse -name "*.cpp" -o -name "*.h"`
all_sources_files 	+= `find $(top_builddir)/example/mouse -name "*.cpp" -o -name "*.h"`

