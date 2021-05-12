#!/usr/bin/env bash

set -x

data_disk_path=/opt/data
top_path=${data_disk_path}/office/xia/autotools_demo_qt

# project
target_path=${top_path}
prefix_path=${data_disk_path}/nfs/meian/meian

# qt
qt_path=${data_disk_path}/nfs/meian/qt-5.12.10

# 3rd_lib
lib_3rd_path=${data_disk_path}/nfs/meian/3rd-lib

# gcc
platform=arm-himix200-linux
cross_gcc_path=${data_disk_path}/opt/toolchains/hisi-linux/${platform}/bin/${platform}-

cd ${target_path} && ./autogen.sh && cd -

${target_path}/configure \
    --prefix=${prefix_path} \
    CC=${cross_gcc_path}gcc \
    CXX=${cross_gcc_path}g++ \
    --host=${platform} \
    \
    --with-qt=${qt_path}/bin \
    PKG_CONFIG_PATH=${lib_3rd_path}/lib/pkgconfig

make -j4; make install
