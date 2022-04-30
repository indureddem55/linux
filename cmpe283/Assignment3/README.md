## CMPE 283 Assignment-3
- Team Members: 
- Annapurna Ananya Annadatha - 015218385
- Indhu Priya Reddem - 015930148

### Assignment - 3

For CPUID leaf node %eax=0x4FFFFFFD:
◦Return the number of exits for the exit number provided (on input) in %ecx
▪This value should be returned in %eax 

For CPUID leaf node %eax=0x4FFFFFFC: 
◦Return the time spent processing the exit number provided (on input) in %ecx
▪Return the high 32 bits of the total time spent for that exit in %ebx
▪Return the low 32 bits of the total time spent for that exit in %ecx

## Question: 
### 1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. 

## Prerequisite 
Once Assignment 1 and Assignment 2 were finished, we started working on this project.

### Work by Ananya:
Edited the cpuid.c code block for eax=0x4ffffffd to return the number of exits for a specific exit reason and return the value in eax register. 
Executed make command to verify output through cpuid command in nested VM and dmesg command in the host VM. Ran the test scripts using gcc commands to see the result in the output files.

### Work by Indhu: 
Edited the cpuid.c code block for eax=0x4ffffffc to return the time spent processing the exit number provided in ecx and return it to register.
Executed make command to verify output through cpuid command in nested VM and dmesg command in the host VM. Ran the test scripts using gcc commands to see the result in the output files.

### 2. Describe in detail the steps you used to complete the assignment. 
Once we changed the cpuid.c and vmx.c, we used the following commands to rebuild the kernel.
1. make modules 
2. make INSTALL_MOD_STRIP=1 modules_install && make install
3. lsmod | grep kvm // command to check if the kvm modules are preloaded
4. rmmod kvm and rmmod kvm_intel // command to remove already presented modules
5. modprobe kvm and modprobe kvm_intel // command to reload the edited kvm modules

#### Installed nested VM using following commands
1. sudo apt install cpu-checker
2. sudo apt update
3. sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils
4. sudo adduser ‘username’ libvirt
5. sudo adduser ‘[username]’ kvm
6. virsh list –all
7. sudo systemctl status libvirtd
8. sudo systemctl enable --now libvirtd
9. sudo apt install virt-manager

Executed sudo virt-manager command to start with virt-manager GUI.

Installed Ubuntu Desktop and connected this to the previously installed nested VM.

### Test SetUp
1. Installed gcc in the Virtual Machine Manager following the resource: https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/
2. Written test files and compiled them using gcc.testfilename.c command 
3. Exected ./a.out to check the output of the test files.

### Output 
1. Output when eax = 0x4FFFFFFD:

![Screenshot (2)](https://user-images.githubusercontent.com/48903573/166091124-58cfbb6f-07e1-493a-9653-a6a6efe619de.png)

2. Output when eax=0x4FFFFFFC:

![Screenshot (3)](https://user-images.githubusercontent.com/48903573/166091157-7531c237-b9fd-4ad1-968e-d65951061ab9.png)

### 3. Comment on the frequency of exits – does the number of exits increase at a stable rate? Or are there more exits performed during certain VM operations? Approximately how many exits does a full VM boot entail?
We have observed that there was increase in count at a stable rate. The maximum exit count is 285643.

### 4. Of the exit types defined in the SDM, which are the most frequent? Least?
There were many exit reasons with 0 exits




