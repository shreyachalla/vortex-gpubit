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
		//vx_umax(54, 200, 10); 
		vx_max(5, 2, 1); 
		// vx_umin(54, 200, 10);
		// vx_min(-54, -200, 10);

		// vx_sexth(255, 4);
		// vx_sextb(65535, 4);
		//vx_zexth(8, -2, 10); 
		dst_ptr[offset] = src0_ptr[offset] + src1_ptr[offset];
		
	}

	
}

void main() {
	kernel_arg_t* arg = (kernel_arg_t*)KERNEL_ARG_DEV_MEM_ADDR;
	vx_spawn_tasks(arg->num_tasks, (vx_spawn_tasks_cb)kernel_body, arg);
}
