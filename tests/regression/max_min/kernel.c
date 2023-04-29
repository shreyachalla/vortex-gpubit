#include <stdint.h>
#include <vx_intrinsics.h>
#include <vx_spawn.h>
#include "common.h"

void kernel_body(int task_id, kernel_arg_t* arg) {
	uint32_t count    = arg->task_size;
	int32_t* src0_ptr = (int32_t*)arg->src0_addr;
	int32_t* src1_ptr = (int32_t*)arg->src1_addr;
	int32_t* dst_ptr  = (int32_t*)arg->dst_addr;
	
	uint32_t offset = task_id * count;

	for (uint32_t i = 0; i < count; ++i) {
	
		// max: src1 is arg2, src2 is arg3
		//vx_max(0x5, -0x3, 0x1); 
		//vx_umax(0x5, 0x3, 0x1); 
		//vx_min(0x5, -0x3, 0x1); 
		//vx_umin(0x5, 0x3, 0x1);
		//vx_umin(0x5, -0x3, 10);

		//vx_sextb(0xfff, 0x4);
		vx_sexth(-0xfffff, 0x4);

		// zexth: 
		
		//vx_zexth(0x5, 0xFFFFF, 0x1); 
	
		dst_ptr[offset+i] = src0_ptr[offset+i] + src1_ptr[offset+i];
	}

	
}

void main() {
	kernel_arg_t* arg = (kernel_arg_t*)KERNEL_ARG_DEV_MEM_ADDR;
	vx_spawn_tasks(arg->num_tasks, (vx_spawn_tasks_cb)kernel_body, arg);
}
