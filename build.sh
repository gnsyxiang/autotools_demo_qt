#!/usr/bin/env bash

# set -x

target=autotools_demo_qt

data_disk_path=/opt/data

# gcc
platform=arm-himix200-linux
cross_gcc_path=${data_disk_path}/opt/toolchains/hisi-linux/${platform}/bin/${platform}-

# cross lib on pc
lib_3rd_path=${data_disk_path}/install/hisi-linux/arm-himix200-linux

# target
target_path=${data_disk_path}/office/xia/${target}
prefix_path=${data_disk_path}/nfs/meian/app

cd ${target_path} && ./autogen.sh && cd -

${target_path}/configure \
    --prefix=${prefix_path} \
    CC=${cross_gcc_path}gcc \
    CXX=${cross_gcc_path}g++ \
    --host=${platform} \
    \
    --with-qt=${lib_3rd_path}/bin \
    PKG_CONFIG_PATH=${lib_3rd_path}/lib/pkgconfig

make -j4; make install
