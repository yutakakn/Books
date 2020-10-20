obj-m := sample.o

# ドライバのコンパイラオプションを追加したい場合は下記を指定する
#EXTRA_CFLAGS += -save-temps=obj
EXTRA_CFLAGS = -I$(src)/../include

ARM_ARCH := ARCH=arm
ARM_CC := CROSS_COMPILE=arm-linux-gnueabihf-

KERNELDIR := /home/yutaka/raspi/linux5.6

# make -Cオプションで再帰呼び出しする場合、
# $(PWD)では正しく動作しない(親ディレクトリを引き継ぐ)ため、
# $(shell pwd)か$(CURDIR)を使うこと。
#PWD := $(PWD)       # NG 
#PWD := $(CURDIR)   
PWD := $(shell pwd) 

all:
	make $(ARM_ARCH) $(ARM_CC) -C $(KERNELDIR) M=$(PWD) modules

clean:
	make $(ARM_ARCH) $(ARM_CC) -C $(KERNELDIR) M=$(PWD) clean

