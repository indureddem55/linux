# CMPE 283 Assignment 2  
Team Members: 
 Monica Lakshmi Mandapati - 015219711
 Manasa Bobba - 015945527

## Assignment 2:  
  
Modify the CPUID emulation code in KVM to report back additional information when special CPUID leaf nodes are requested.
- For CPUID leaf node %eax=0x4FFFFFFF:
◦Return the total number of exits (all types) in %eax
- For CPUID leaf node %eax=0x4FFFFFFE:
◦Return the high 32 bits of the total time spent processing all exits in %ebx
◦Return the low 32 bits of the total time spent processing all exits in %ecx
-%ebx and %ecx return values are measured in processor cycles, across all VCPUs  

## Question: 
### 1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. 

### Work by Monica(015219711):
Started working on this assignment once the assignement1 is done. Have researched on how to build the kernel and found the resources.
Started buidling the kernel and edited the cupid.c and vmx.c files for the CPUID: 0x4fffffff

### Work by Manasa(015945527):
Started working on this assignment once the assignement1 is done. Resolved the encountered errors while building the kernel. 
Edited the cupid.c and vmx.c files for the CPUID: 0x4ffffffe

### 2. Describe in detail the steps you used to complete the assignment. 

#### Initial Setup
1. Build environment https://wiki.ubuntu.com/Kernel/BuildYourOwnKernel  
2. Clone the Kernel code from GitHub: git clone https://github.com/torvalds/linux.git   

#### Setup KVM
1.Install KVM and supporting packages: sudo apt-get install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils  
2.Install the virt-manager using: sudo apt-get install virt-manager  
3.Reboot 

#### Build
1. Update the files:
> arch/x86/kvm/vmx/vmx.c
> arch/x86/kvm/cpuid.c
2. Rebuild the kernel using make modules command and make INSTALL_MOD_STRIP=1 modules_install && make install.
3.Compile using: make -j 2 modules && make -j 2 && sudo make modules_install && sudo make install  

### Output:

1. Output when eax=0x4fffffff:
> CPUID(0x4FFFFFFF), exits=2660924

2. Output when eax=0x4ffffffe:
> CPUID(0x4FFFFFFE), number of cycles spent: 387563425

 

