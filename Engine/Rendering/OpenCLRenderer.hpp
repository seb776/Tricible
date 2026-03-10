#pragma once
//
//
//void GetAvailableHardware()
//{
//	std::vector<cl::Platform> platforms;
//	cl::Platform::get(&platforms);
//
//	int platform_id = 0;
//	int device_id = 0;
//
//	std::cout << "Number of Platforms: " << platforms.size() << std::endl;
//
//	for (std::vector<cl::Platform>::iterator it = platforms.begin(); it != platforms.end(); ++it) {
//		cl::Platform platform(*it);
//
//		std::cout << "Platform ID: " << platform_id++ << std::endl;
//		std::cout << "Platform Name: " << platform.getInfo<CL_PLATFORM_NAME>() << std::endl;
//		std::cout << "Platform Vendor: " << platform.getInfo<CL_PLATFORM_VENDOR>() << std::endl;
//
//		std::vector<cl::Device> devices;
//		platform.getDevices(CL_DEVICE_TYPE_GPU | CL_DEVICE_TYPE_CPU, &devices);
//
//		for (std::vector<cl::Device>::iterator it2 = devices.begin(); it2 != devices.end(); ++it2) {
//			cl::Device device(*it2);
//
//			std::cout << "\tDevice " << device_id++ << ": " << std::endl;
//			std::cout << "\t\tDevice Name: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
//			std::cout << "\t\tDevice Type: " << device.getInfo<CL_DEVICE_TYPE>();
//			std::cout << " (GPU: " << CL_DEVICE_TYPE_GPU << ", CPU: " << CL_DEVICE_TYPE_CPU << ")" << std::endl;
//			std::cout << "\t\tDevice Vendor: " << device.getInfo<CL_DEVICE_VENDOR>() << std::endl;
//			std::cout << "\t\tDevice Max Compute Units: " << device.getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>() << std::endl;
//			std::cout << "\t\tDevice Global Memory: " << device.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() << std::endl;
//			std::cout << "\t\tDevice Max Clock Frequency: " << device.getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>() << std::endl;
//			std::cout << "\t\tDevice Max Allocateable Memory: " << device.getInfo<CL_DEVICE_MAX_MEM_ALLOC_SIZE>() << std::endl;
//			std::cout << "\t\tDevice Local Memory: " << device.getInfo<CL_DEVICE_LOCAL_MEM_SIZE>() << std::endl;
//			std::cout << "\t\tDevice Available: " << device.getInfo< CL_DEVICE_AVAILABLE>() << std::endl;
//		}
//		std::cout << std::endl;
//	}
//	const auto& exePath = GetCurrentExecutableDirectory();
//	const auto& kernalFilePath = PathCombine(exePath, "./Rendering/TestRender.cl.c");
//	const auto& kernelSource = ReadFile(kernalFilePath);
//	cl::Program program = cl::Program("#define OPENCL_KERNEL_CODE\n" + kernelSource);
//	try {
//		program.build("-cl-std=CL2.0");
//	}
//	catch (...) {
//		// Print build info for all devices
//		cl_int buildErr = CL_SUCCESS;
//		auto buildInfo = program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(&buildErr);
//		for (auto& pair : buildInfo) {
//			std::cerr << pair.second << std::endl << std::endl;
//		}
//		return;
//	}
//	// TODO Allocate output buffer
//	// https://github.khronos.org/OpenCL-CLHPP/index.html
//
//	//std::vector<int> output(numElements, 0xdeadbeef);
//	//cl::Buffer outputBuffer(begin(output), end(output), false);
//	//cl::Pipe aPipe(sizeof(cl_int), numElements / 2);
//
//	//// Default command queue, also passed in as a parameter
//	//cl::DeviceCommandQueue defaultDeviceQueue = cl::DeviceCommandQueue::makeDefault(
//	//	cl::Context::getDefault(), cl::Device::getDefault());
//
//	//typedef struct { int* bar; } SceneExample;
//
//	//// Then pass correct parameters
//	//// Prepare call (pass parameters)
//	//auto renderKernel =
//	//	cl::KernelFunctor<
//	//	decltype(fooPointer)&,
//	//	int*,
//	//	cl::coarse_svm_vector<int>&,
//	//	cl::Buffer,
//	//	int,
//	//	cl::Pipe&,
//	//	cl::DeviceCommandQueue
//	//	>(program, "Render_Kernel");
//
//	//renderKernel.setSVMPointers(anSVMInt);
//
//	// Executes the kernel
//	//cl_int error;
//	//renderKernel(
//	//	cl::EnqueueArgs(
//	//		cl::NDRange(numElements / 2),
//	//		cl::NDRange(numElements / 2)),
//	//	fooPointer,
//	//	inputA.data(),
//	//	inputB,
//	//	outputBuffer,
//	//	3,
//	//	aPipe,
//	//	defaultDeviceQueue,
//	//	error
//	//);
//
//}