#include <iostream>
#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

int main() {

    glfwInit();

    std::cout << "Hello, World!" << glfwVulkanSupported() << std::endl;

    glfwTerminate();
}
