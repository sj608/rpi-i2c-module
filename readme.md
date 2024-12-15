# I2C Device Module Study Repo

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