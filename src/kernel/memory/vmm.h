// Virtual Memory Manager Header File // ~ eylon

#if !defined(VMM_H)
#define VMM_H

#include <kernel/memory/mm.h>
#include <kernel/process/pm.h>
#include <utils/type.h>
#include "paging.h"


/* Attributes */

// Page table directories size
#define MM_PTD_SIZE MM_PAGE_SIZE * PM_MAX_PROCESSES

// Reserved pages count between the top of the kernel stack and the start of the PTD
#define MM_RESERVED_PAGES 8


// Kernel stack size for each process
#define MM_PROC_KSTACK_SIZE KB(8)

//[TODO] arrange this for easier distinguition between processes stack
// [TODO] do we really need to know how many pages each one?

// Kernel stack overall max size
#define MM_KSTACK_SIZE MM_PROC_KSTACK_SIZE * PM_MAX_PROCESSES

// Kernel stack max pages
#define MM_KSTACK_PAGES (u32_t) (MM_KSTACK_SIZE / MM_PAGE_SIZE)

// Kernel heap max size
#define MM_KHEAP_SIZE  MB(1)

// Kernel heap max pages
#define MM_KHEAP_PAGES  (u32_t) (MM_KHEAP_SIZE / MM_PAGE_SIZE)


/* Memory mapped IO area size
    ~ VGA Text Mode Screen: [columns * rows * char_size] = 80 * 25 * 2 = 4000 ≈ (4096 = 4KB) */
#define MM_MMIO_SIZE  KB(4)

// Memory mapped IO pages
#define MM_MMIO_PAGES  (u32_t) (MM_MMIO_SIZE / MM_PAGE_SIZE)


// User stack max size
#define MM_USTACK_SIZE MB(8) 

// User heap max size
#define MM_UHEAP_SIZE  GB(1)

// User stack max pages
#define MM_USTACK_PAGES (u32_t) (MM_USTACK_SIZE / MM_PAGE_SIZE)

// User heap max pages
#define MM_UHEAP_PAGES  (u32_t) (MM_UHEAP_SIZE / MM_PAGE_SIZE)



/* Virtual Address Space */

// Top of virtual memory (4GB)
#define MM_VIRT_TOP 0xFFFFFFFF

// Start of the page table directory (list of all processes' PDs)
#define MM_PTD_START MM_VIRT_TOP - (MM_PTD_SIZE) + 1

// Start of reserved pages area
#define MM_RESERVED_START MM_PTD_START - (MM_PAGE_SIZE * MM_RESERVED_PAGES)

// Kernel top of stack
#define MM_KSTACK_TOP MM_RESERVED_START - 1

// Kernel start of heap
#define MM_KHEAP_START MM_KSTACK_TOP - MM_KSTACK_SIZE - MM_KHEAP_SIZE + 1

// Memory mapped IO start
#define MM_MMIO_START MM_KHEAP_START - MM_MMIO_SIZE

// Higher half start (3GB) / Kernel code, bss, and data start
#define MM_KSPACE_START 0xC0000000

// User top of stack
#define MM_USTACK_TOP MM_KSPACE_START - 1

// User start of heap
#define MM_UHEAP_START MM_USTACK_TOP - MM_USTACK_SIZE - MM_UHEAP_SIZE + 1

// User space start (1MB) / User code, bss and data start
#define MM_USPACE_START 0x100000

void init_vmm();
pde_t* vmm_get_pd();
int vmm_map_page(pde_t* pd, paddr_t phys_base, vaddr_t virt_base, u8_t rw, u8_t us, u8_t pcd);
int vmm_unmap_page(pde_t* pd, vaddr_t virt_base);
vaddr_t vmm_attach_page(paddr_t phys_base);
void vmm_detach_page(vaddr_t virt_base);

#endif