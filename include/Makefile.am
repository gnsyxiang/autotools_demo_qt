# ===============================================================
# 
# Release under GPLv-3.0.
# 
# @file    Makefile.am
# @brief   
# @author  gnsyxiang <gnsyxiang@163.com>
# @date    05/03 2021 10:35
# @version v0.0.1
# 
# @since    note
# @note     note
# 
#     change log:
#     NO.     Author              Date            Modified
#     00      zhenquan.qiu        05/03 2021      create the file
# 
#     last modified: 05/03 2021 10:35
# ===============================================================

include $(top_srcdir)/res/autotroll.mk

noinst_LTLIBRARIES = libqt_h2cpp.la

_include_com    =
_sources_com    =
_cppflags_com   = $(QT_CPPFLAGS)
_cflags_com     = $(QT_CFLAGS)
_cxxflags_com   = $(QT_CXXFLAGS)
_ldflags_com    = $(QT_LDFLAGS)
_ldadd_com      = $(QT_LIBS)

# ---------------------
# add necessary content
# ---------------------
_include_com    += -I$(top_builddir)/res/ui

_qt_h_files     = DialogShow.moc.cpp
_sources_com    += $(_qt_h_files)

_cppflags_com   += \
                   $(_no_error_com) \
                   $(_include_com)  \
                   $(_define_com)

_cflags_com     +=

_cxxflags_com   +=

_ldflags_com    +=

_ldadd_com      +=

libqt_h2cpp_la_SOURCES  = $(_sources_com)
libqt_h2cpp_la_CPPFLAGS = $(_cppflags_com)
libqt_h2cpp_la_CFLAGS   = $(_cflags_com)
libqt_h2cpp_la_CXXFLAGS = $(_cxxflags_com)
libqt_h2cpp_la_LDFLAGS  = $(_ldflags_com)
libqt_h2cpp_la_LIBADD   = $(_ldadd_com)

BUILT_SOURCES = $(_qt_h_files)

# ------------------
# make install files
# ------------------
_no_install_headers_com =
noinst_HEADERS          = $(_no_install_headers_com)

_install_headers_com    =
install_includedir      = $(includedir)/@project_name@
install_include_HEADERS = $(_install_headers_com)
