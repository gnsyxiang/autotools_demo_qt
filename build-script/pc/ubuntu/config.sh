#!/usr/bin/env bash

chip=ubuntu

product=HY-pc

language=cn en

host=
cross_gcc_path=

configure_param=--disable-silent-rules

cppflag=-fstack-protector-all
cflag=
cxxflag=
ldflag=-rdynamic
lib=
debug=-g -O0
release=-O2 -DNDEBUG

install_path=/mnt/nfs/pc/ubuntu
