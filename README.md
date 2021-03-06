# README

## 依赖

* `autotools`
* `java`
* `doxygen`
* `graphviz`

> 安装方法，详见[README.md](https://github.com/gnsyxiang/autotools_demo_lib/blob/main/README.md)

## 使用说明

* 执行`./autogen.sh`，生成`configure`脚本

* 三部曲编译源码并生成对应文件

```shell
$ ./configure --prefix=`pwd`/install PKG_CONFIG_PATH=`pwd`/3rd_lib/install/lib/pkgconfig
$ make
$ make install
```

## 配置相关选项

* `--prefix=PREFIX`: 指定安装路径

* `--enable-doxygen-doc`: 生成html帮助文档

* `PKG_CONFIG_PATH`: 使用`pkg-config`检测依赖库

* `--with-qt[=ARG]`: 指定qt交叉编译生成的可执行文件的路径

## 交叉编译

```shell
$ ./configure \
    --prefix=`pwd`/install \
    PKG_CONFIG_PATH=`pwd`/3rd_lib/install/lib/pkgconfig \
    CC=arm-himix200-linux-gcc \
    CXX=arm-himix200-linux-g++ \
    --host=arm-himix200-linux \
    --with-qt=/opt/hisi-linux/arm-himix200-linux/bin
$ make
$ make install
```

