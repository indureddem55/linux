CMPE283 Assignment 1

To create a Linux kernel module that will query various MSRs to determine virtualization features available in your CPU. This module will report (via the system message log) the features it discovers.

Functionality to Implement
Read the VMX configuration MSRs to ascertain support capabilities/features ◦Entry / Exit / Procbased / Secondary Procbased / Pinbased controls
For each group of controls above, interpret and output the values read from the MSR to the system via printk(..), including if the value can be set or cleared.

Followed the below mention steps to achieve the above said functionality:

* Downloaded and Installed the lastest version(16.2.3) of VMWare workstation on windows system.

* Installed Ubuntu(22.04) operating systemon Virtual Machine.

* Forked the kernel sources from the master linux git repository(https://github.com/torvalds/linux.git).

* Cloned the kernel sources from the master linux git repository:

* git clone https://github.com/mmandapati/linux.git

* Pushed the file 'cmpe283-1.c' - which generic code on how to build the kernel

* Copied the contents of 'Makefile'

* BuilT the module using the below command:

make

* Load and unload the module using the following commands: When a module is inserted into the kernel, the module_init macro will be invoked, 
which will call the function init_module.
Similarly, when the module is removed with rmmod, module_exit macro will be invoked, which will call the cleanup_module.
sudo insmod cmpe283-1.ko

sudo rmmod cmpe283-1

* The VMX features are logged in the kernel log and are checked using the dmesg command:
dmesg

* Here is the image of the output:

![WhatsApp Image 2022-04-22 at 10 13 11 PM (1)](https://user-images.githubusercontent.com/48903573/164878987-28cb7751-fb6c-48b2-9be2-d31711dce334.jpeg)
![WhatsApp Image 2022-04-22 at 10 13 11 PM](https://user-images.githubusercontent.com/48903573/164878989-ad875ccb-ca85-4649-bdaa-c80e135490f6.jpeg)


