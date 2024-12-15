# I2C Device Module Study Repo
RPI device module study repo

## Modules 
- easy to develop drivers without rebooting
    - load, test, unload, rebuild, load repeat ...
- can minimze the kernel image size
- reduce boot time
- `CAUTION`: once loaded, have full control and privileges
- Utilities:
   - modinfo: gets information about ta module without loading it
   - insmod: load the given module
   - modprobe: load all the dependencies of the given top module
   - lsmod: list of loaded modules
   - rmmod: remove the given module
## Compiling a module
- out of tree: when the code is outside of the kernel source tree, in a different directory
    - not integrated into the kernel
    - need to be built separately
    - driver cannot be built statically, only as a module
- inside the kernel tree
    - integrated into the kernel config
    - driver can be built statically or as a module

## Platform Devices
- Devices that are directly part of a system-on-chip: UART, Ethernet, SPI, or I2C etc
- platform bus handles platform devices
- devices are enumerated statically instead of being discovered dynamically

## I2C Bus Driver
- I2C bus driver is responsible for:
    - providing API to implement I2C controller drivers
    - providing API to implement I2C device driver in kernel space
    - providing API to implmennt I2C device drivers in user space
- The core of I2C bus driver is in `/driver/i2c`
- I2C controller dirver `/driver/i2c/busses/`

## Registering an I2C Device Driver
- defines a `struct i2c_driver` inherits from `struct device_driver`
    - points to `->probe()` and `->remove()`
    - `id_table`
- `i2c_add_driver()` and `i2c_del_driver()` functions are used to register/unregister the driver

## I2C subsystem
The kerenl divides the I2C Subsystem by Buses and Devices. Buses again divide into algorithms and adapters. Devices divided into Driver and Clients.
- Algorithms: general code used by Adapters
- Adapters: represents the bus
- Clients: represents the slave chip

### Steps to write a driver
1. Get the I2C adapter
2. create a info struct and create a device using that 
3. create device id for the slave and register
4. create a i2c_driver stuct and register to the I2C subsystem
5. Driver ready to communicate
6. remove the device once done with it

