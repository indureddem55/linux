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
Executed make command to verify output through cpuid command in nested VM and dmesg command in the host VM.

### Work by Indhu: 
Edited the cpuid.c code block for eax=0x4ffffffc to return the time spent processing the exit number provided in ecx and return it to register.
Executed make command to verify output through cpuid command in nested VM and dmesg command in the host VM.

### 2. Describe in detail the steps you used to complete the assignment. 



