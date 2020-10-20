obj-m := sample.o

# ドライバのコンパイラオプションを追加したい場合は下記を指定する
EXTRA_CFLAGS +=

KERNELDIR := /lib/modules/$(shell uname -r)/build

# make -Cオプションで再帰呼び出しする場合、
# $(PWD)では正しく動作しない(親ディレクトリを引き継ぐ)ため、
# $(shell pwd)か$(CURDIR)を使うこと。
#PWD := $(PWD)       # NG 
#PWD := $(CURDIR)   
PWD := $(shell pwd) 

all:
	make -C $(KERNELDIR) M=$(PWD) modules

clean:
	make -C $(KERNELDIR) M=$(PWD) clean

