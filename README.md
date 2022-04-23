# CMPE283 Assignment 1
To create a Linux kernel module that will query various MSRs to determine 
virtualization features available in your CPU. This module will report (via the system message log) the 
features it discovers.

### Functionality to Implement
- Read the VMX configuration MSRs to ascertain support capabilities/features
◦Entry / Exit / Procbased / Secondary Procbased / Pinbased controls
- For each group of controls above, interpret and output the values read from the MSR to the system
via printk(..), including if the value can be set or cleared.

## The following procedure describes the steps followed to develop and test the kernel module:

1) Downloaded and Installed the lastest version(16.2.3) of VMWare workstation onto my windows system.

2) Installed Ubuntu(22.04) operating system onto my Virtual Machine.

3) Forked the kernel sources from the master linux git repository(https://github.com/torvalds/linux.git) into my github repo.

4) Cloned the kernel sources from the master linux git repository:
> git clone https://github.com/mmandapati/linux.git

5) Added the file 'cmpe283-1.c' - which consists of the skeleton code on how to build the kernel

6) Copied the 'Makefile' provided

7) Build the module using the below command:
> make

8) Load and unload the module using the following commands:
When a module is inserted into the kernel, the module_init macro will be invoked, which will call the function init_module. 
Similarly, when the module is removed with rmmod, module_exit macro will be invoked, which will call the cleanup_module.
> sudo insmod cmpe283-1.ko

> sudo rmmod cmpe283-1

9) The VMX features are logged in the kernel log and are verified using the dmesg command:
> dmesg

10) Here is the image of the output:

![WhatsApp Image 2022-04-22 at 5 21 13 PM](https://user-images.githubusercontent.com/91310893/164838048-1e5098a0-cf88-4951-bd92-8e25d7efaa5e.jpeg)
