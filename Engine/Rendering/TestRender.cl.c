#ifdef OPENCL_KERNEL_CODE

// https://www.compilersutra.com/docs/gpu/opencl/basic/running_first_opencl_code_part2_a/
//https://github.com/KhronosGroup/OpenCL-Guide/blob/main/chapters/cpp_for_opencl.md
// Slangs ? meh
__kernel void Render_Kernel(__global const float* A, 
                          __global const float* B, 
                          __global float* result) 
{
    int i = get_global_id(0);
    result[i] = A[i] + B[i];
}
//https://cmake.org/cmake/help/v3.1/prop_sf/VS_DEPLOYMENT_CONTENT.html
#endif