KDIR = /lib/modules/$(shell uname -r)/build
obj-m := hello_module.o
# Adding debug flag while building, enables the pr_debug() function
CFLAGS_hello_module.o:= -DDEBUG 

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean