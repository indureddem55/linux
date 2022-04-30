# CMPE 283 Assignment 4
### Team Members: 
- Monica Lakshmi Mandapati - 015219711
- Manasa Bobba - 015945527

## Assignment 4: Nested Paging vs. Shadow Paging 

## Question: 
### 1. For each member in your team, provide 1 paragraph detailing what parts of the lab that member implemented / researched. 

### Work by Monica(015219711):
I worked on performance for shadow paging to illustrate the different exit frequencies and types. I removed the kvm-intel module and reloaded with parameter ept=0 and recorded the total exit count information in shadow.txt file.

### Work by Manasa(015945527):
I worked on performance for nested paging to illustrate the different exit frequencies and types. I recorded the total exit count information in nested.txt file.

### 2: Include a sample of your print of exit count output from dmesg from “with ept” and “without ept”.

The outputs can be found here:
https://github.com/mmandapati/linux/blob/master/cmpe283/assignment4/shadow.txt
https://github.com/mmandapati/linux/blob/master/cmpe283/assignment4/nested.txt

### 3. What did you learn from the count of exits? Was the count what you expected? If not, why not?
The number of exits were quite huge for shadow pagaing when compared to nested paging exits. The reason could be that the shadow paging architecture requires additional exits in order to function properly as a VMM. 

### 4. What changed between the two runs (ept vs no-ept)?

While comparing the values of total exit count with ept and without ept, we saw that when the parameter ept=0 is changed, the exit counts for few exit numbers significantly increases. 
The reason being that shadow paging uses a two-layer translation from guest physical address to host physical address and it involved more VMM involvement which causes additional VM exits.
The shadow paging maintains a extra shadow page table which requires extra memory. 
This requires no intervention from VMM, and results in less VM Exits.
