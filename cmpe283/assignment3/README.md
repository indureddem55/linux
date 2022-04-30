# CMPE 283 Assignment 3 
### Team Members: 
- Monica Lakshmi Mandapati - 015219711
- Manasa Bobba - 015945527

## Assignment 2:  
  
Modify the CPUID emulation code in KVM to report back additional information when special CPUID leaf nodes are requested.
- For CPUID leaf node %eax=0x4FFFFFFD:
Return the number of exits for the exit number provided (on input) in %ecx 
▪This value should be returned in %eax 
▪For CPUID leaf node %eax=0x4FFFFFFC:
- Return the time spent processing the exit number provided (on input) in %ecx
▪Return the high 32 bits of the total time spent for that exit in %ebx
▪Return the low 32 bits of the total time spent for that exit in %ecx 

## Question: 
### 1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. 

### Work by Monica(015219711):
Made Code changes into the cpuid.c file and vmx.c file for the EAX value 0x4FFFFFFD. Built the Kernel and loaded the modules. 
Installed KVM and Virtual Machine Managaer and ran the test scripts using gcc commands to see the result in the output files.

### Work by Manasa(015945527):
Made Code changes into the cpuid.c file and vmx.c file for the EAX value 0x4FFFFFFC. Compiled the Kernel and loaded them.  
Initialised KVM and Virtual Machine Managaer environment and ran the test scripts using gcc commands.


### 2. Describe in detail the steps you used to complete the assignment. 

#### Initial Setup
1. Build environment https://wiki.ubuntu.com/Kernel/BuildYourOwnKernel  
2. Clone the Kernel code from GitHub: git clone https://github.com/torvalds/linux.git   

#### Build
1. Updated the code in below files:
> arch/x86/kvm/vmx/vmx.c
> arch/x86/kvm/cpuid.c
2. Rebuild the kernel using make modules command and make INSTALL_MOD_STRIP=1 modules_install && make install.
3.Compile using: make -j 2 modules && make -j 2 && sudo make modules_install && sudo make install  

#### Setup KVM
1. Install KVM and supporting packagesusing the following query: sudo apt-get install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils  
2. Install the virt-manager using: sudo apt-get install virt-manager  
3. Reboot 
4. Install Ubuntu in the nested Virtual Machine

### Test Setup
1. Installed gcc in the Virtual Machine Manager following the resource: https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/
2. Wrote the test scripts test3.c and test4.c
3. Compile the test files:
> gcc test3.c
> gcc test4.c
4. Check the output : ./a.out

### Output:

1. Output when eax=0x4FFFFFFD:
<img width="1288" alt="image" src="https://user-images.githubusercontent.com/91310893/166090170-68d984d8-c3a3-42ec-9e44-5baff56ba4a2.png">


2. Output when eax=0x4FFFFFFC:
<img width="1289" alt="image" src="https://user-images.githubusercontent.com/91310893/166090186-e4556bd4-c15b-4f2b-817e-4127c5f1c48b.png">

### 3. Comment on the frequency of exits – does the number of exits increase at a stable rate? Or are there more exits performed during certain VM operations? Approximately how many exits does a full VM boot entail?
We noticed that the count increased at a stable rate.  The exit count is 15039 for the first exit reason. We did another reboot to see the increase in count of exits. The exit count raised to 32786 which is approcimately double the previous count.

### 4. Of the exit types defined in the SDM, which are the most frequent? Least?
There were many exit reasons with 0 exits
