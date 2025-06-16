#include <webgpu/webgpu.h>
#include <iostream>

int main() {
    // create descriptor
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    // create instance using desc
#ifdef WEBGPU_BACKEND_EMSCRIPTEN
    WGPUInstance instance = wgpuCreateInstance(nullptr);
#else
    WGPUInstance instance = wgpuCreateInstance(&desc);
#endif
    if (!instance)
    {
        std::cerr << "Failed to create WGPU instance." << std::endl;
        return 1;
    }

    std::cout << "WGPU instance: " << instance << std::endl;
    // Clean up the instance
    wgpuInstanceRelease(instance);
    return 0;
}