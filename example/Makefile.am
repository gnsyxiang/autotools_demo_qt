# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    05/03 2021 10:38
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        05/03 2021      create the file
# 
#     last modified: 05/03 2021 10:38
# ===============================================================

include $(top_srcdir)/res/autotroll.mk

# ------------------
# defining variables
# ------------------
_no_error_com   =
_define_com     =
_include_com    = $(include_com)
_sources_com    =
_cppflags_com   = $(QT_CPPFLAGS)
_cflags_com     = $(QT_CFLAGS)
_cxxflags_com   = $(QT_CXXFLAGS)
_ldflags_com    = $(QT_LDFLAGS)
_ldadd_com      = $(QT_LIBS)
bin_PROGRAMS    =

# ---------------------
# add necessary content
# ---------------------
_no_error_com   +=

_define_com     +=

_include_com    += -I$(top_srcdir)/include

_sources_com    +=

_cppflags_com   += \
                   $(_no_error_com) \
                   $(_include_com)  \
                   $(_define_com)

_cflags_com     +=

_cxxflags_com   +=

_ldflags_com    +=

_ldadd_com      += \
                   $(top_builddir)/src/lib@project_name@.la \
                   $(ldadd_com)

bin_PROGRAMS        += hy_qt_demo
hy_qt_demo_SOURCES    = $(_sources_com) hy_qt_demo.cpp
hy_qt_demo_CPPFLAGS   = $(_cppflags_com)
hy_qt_demo_CFLAGS     = $(_cflags_com)
hy_qt_demo_CXXFLAGS   = $(_cxxflags_com)
hy_qt_demo_LDFLAGS    = $(_ldflags_com)
hy_qt_demo_LDADD      = $(_ldadd_com)
