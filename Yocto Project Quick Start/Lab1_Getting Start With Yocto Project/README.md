# LAB1 - Building Image for Qemuarm 
## Steps 
### 1. Clone the poky repo 
```
git clone git://git.yoctoproject.org/poky
cd poky 
git checkout kirkstone
```
## 2. Environment setup 
### Source the `oe-init-build-env`
```
$ poky> source oe-init-build-env "../build/"
```
> build folder structure  

`conf` folder contains fileImage specific and layer configuration.

`conf/local.conf` 
- Variables have a local scope 
- Setup and overwrite the environment variable 
- Configurations the `local.conf`
```
# Machine Selection
MACHINE = "qemuarm"

# Where to place downloads
DL_DIR = "/mnt/d/OJT/projectBase/downloads"

# Where to place shared-state files
SSTATE_DIR = "/mnt/d/OJT/projectBase/sstate-cache"

# Where to place the build output
TMPDIR = "/mnt/d/OJT/projectBase/tmp"

# How many tasks BitBake should perform in parallel
BB_NUMBER_THREADS = "8"

# How many processes should be used when compiling
PARALLEL_MAKE = "-j 8"
```
it is useful to set the `DL_DIR`, `SSTATE_DIR`, and `TMPDIR` to avoid data duplication in different build folders 

`conf/bblayer.conf`
- it is a layer related, will be discussed later on.

## 3. Start Building the `core-image-minimal`
```
bitbake -k  core-image-minimal
```

```
Loading cache: 100% |                                                                                                                                                                                                        | ETA:  --:--:--Loaded 0 entries from dependency cache.                                                                                                                                                                                                      Parsing recipes: 100% |#######################################################################################################################################################################################################| Time: 0:01:21Parsing of 883 .bb files complete (0 cached, 883 parsed). 1644 targets, 63 skipped, 0 masked, 0 errors.                                                                                                                                      NOTE: Resolving any missing task queue dependencies                                                                                                                                                                                                                                                                                                                                                                                                                                       Build Configuration:                                                                                                                                                                                                                         BB_VERSION           = "2.0.0"                                                                                                                                                                                                               BUILD_SYS            = "x86_64-linux"                                                                                                                                                                                                        NATIVELSBSTRING      = "ubuntu-20.04"                                                                                                                                                                                                        TARGET_SYS           = "arm-poky-linux-gnueabi"                                                                                                                                                                                              MACHINE              = "qemuarm"                                                                                                                                                                                                             DISTRO               = "poky"                                                                                                                                                                                                                DISTRO_VERSION       = "4.0.16"                                                                                                                                                                                                              TUNE_FEATURES        = "arm vfp cortexa15 neon thumb callconvention-hard"                                                                                                                                                                    Setscene tasks: 1391 of 1391                                                                                                                                                                                                                 Currently  8 running tasks (1209 of 3582)  33% |###############################################################                                                                                                                             |0: linux-yocto-5.15.148+gitAUTOINC+c07c75a1e9_c0150afdb5-r0 do_fetch - 1h38m37s (pid 9040)  77% |###########################################################################################################                                |
1: gcc-cross-arm-11.4.0-r0 do_compile - 1h10m2s (pid 29113)                                                                                       
```
### Building output - file structure
* `downloads` - Contains the required dependencies of recipes for the image 
* `sstate-cache` - shared cache used by all building process.
* `tmp` - bulk of the building work should be done and where BitBake should place its temporary files and output `use Gigabytes of hard disk space`   
Under `tmp/`
    * `buildstats` - Build statistics for all packages built (CPU usage, elapsed time, host,timestamps…).
    * `deploy` - Final Output
    * `deploy/images` - Contains the complete images 
    * `tmp/work` - Set of specific work directories, split by architecture. They are used to unpack, configure and build the packages
    * `sysroots`- Shared libraries and headers used to compile applications for the target.  
    
![Final_Output](./assets/Qemu%20(1).PNG)
## 4. Run Qemu 
### Run qemu 

```
runqemu qemuarm nographic 
```
![runqemu](./assets/Qemu%20(2).PNG)

`username` : `root`

### Output
![runqemu](./assets/Qemu%20(3).PNG)

## Resources 
* [WSL Installation](https://learn.microsoft.com/en-us/windows/wsl/install)
* [Manual WSL Installation](https://learn.microsoft.com/en-us/windows/wsl/install-manual)
* [Setting Up to Use the Yocto Project](https://docs.yoctoproject.org/kirkstone/dev-manual/start.html)
* [Bootlin](https://bootlin.com/training/yocto/)
* [Using the Quick EMUlator (QEMU)](https://docs.yoctoproject.org/dev-manual/qemu.html)