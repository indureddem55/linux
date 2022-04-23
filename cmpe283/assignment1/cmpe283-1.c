#include <linux/module.h> /* Needed by all modules */
#include <linux/kernel.h> /* Needed for KERN_INFO */
#include <asm/msr.h>

#define MAX_MSG 80

#define IA32_VMX_PINBASED_CTLS 0x481

struct capability_info {
uint8_t bit;
const char *name;
};
struct capability_info pinbased[5] =
{
{ 0, "External Interrupt Exiting" },
{ 3, "NMI Exiting" },
{ 5, "Virtual NMIs" },
{ 6, "Activate VMX Preemption Timer" },
{ 7, "Process Posted Interrupts" }
};
void report_capability(struct capability_info *cap, uint8_t len, uint32_t lo, uint32_t hi)
{
uint8_t i;
struct capability_info *c;
char msg[MAX_MSG];
memset(msg, 0, sizeof(msg));

for (i = 0; i < len; i++) {
c = &cap[i];
snprintf(msg, 79, " %s: Can set=%s, Can clear=%s\n",
  c->name,
  (hi & (1 << c->bit)) ? "Yes" : "No",
  !(lo & (1 << c->bit)) ? "Yes" : "No");
printk(msg);
}
}

void detect_vmx_features(void)
{
uint32_t lo, hi;

/* Pinbased controls */
rdmsr(IA32_VMX_PINBASED_CTLS, lo, hi);
pr_info("Pinbased Controls MSR: 0x%llx\n",
(uint64_t)(lo | (uint64_t)hi << 32));
report_capability(pinbased, 5, lo, hi);
}

int init_module(void)
{
printk(KERN_INFO "CMPE 283 Assignment 1 Module Start\n");

detect_vmx_features();

/*
* A non 0 return means init_module failed; module can't be loaded. 
*/
return 0;
}

void cleanup_module(void)
{
printk(KERN_INFO "CMPE 283 Assignment 1 Module Exits\n");
}
MODULE_LICENSE("GPL v2");
