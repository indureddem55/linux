# CMPE 283 Assignment 4 
- Team Members: 
- Annapurna Ananya Annadatha - 015218385
- Indhu Priya Reddem - 015930148

## Assignment 4:  
  
1. Run your assignment 3 code and boot a test VM using that code.
2. Once the VM has booted, record total exit count information (total count for each type of exit 
handled by KVM). You should do this via a sequence of queries of CPUID leaf function 
0x4FFFFFFE.
3. Shutdown your test (inner) VM.
4. Remove the ‘kvm-intel’ module from your running kernel:
◦rmmod kvm-intel
1. Reload the kvm-intel module with the parameter ept=0 (this will disable nested paging and force 
KVM to use shadow paging instead)
◦The module you want is usually found in /lib/modules/XXX/kernel/arch/x86/kvm  , where 
XXX is the version of the kernel you build for assignment 3 – don’t make a mistake and 
use the one that came with the stock Linux installation.
◦insmod  /lib/modules/XXX/kernel/arch/x86/kvm/kvm-intel.ko ept=0
1. Boot the same test VM again, and capture the same output as you did in step 2.
2. Answer the questions below. 

## Question: 
### 1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. 

## Prerequisite 
Once Assignment 1,2,3 were finished, we started working on this project.

### Work by Ananya:
I worked on performance for nested paging to illustrate the different exit frequencies and types. I captured the total exit count information in nested.txt file.

### Work by Indhu:
I worked on performance for shadow paging to illustrate the different exit frequencies and types. I have removed the kvm-intel module and reloaded with parameter ept=0 and recorded the total exit count information in shadow.txt file.

### 2: Include a sample of your print of exit count output from dmesg from “with ept” and “without ept”.

Below links show the outputs for the file:
https://github.com/indureddem55/linux/blob/master/cmpe283/Assignment4/nested.txt
https://github.com/indureddem55/linux/blob/master/cmpe283/Assignment4/shadow.txt

### 3. What did you learn from the count of exits? Was the count what you expected? If not, why not?
The number of exits were more for shadow pagaing compared to nested paging exits. The explanation for this could be because the shadow paging architecture necessitates more exits in order for the VMM to work properly.

### 4. What changed between the two runs (ept vs no-ept)?

When comparing the results of total exit count with and without adv, we discovered that changing the parameter ept=0 dramatically boosts the exit counts for a few exit numbers.
Because shadow paging requires a two-layer translation from the guest physical address to the host physical address, it necessitates greater VMM involvement, resulting in more VM exits.
Shadow paging takes additional memory since it keeps an extra shadow page table.
This eliminates the need for VMM intervention and resulting in fewer VM Exits.
