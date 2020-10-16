#ifndef VK_TUT_HELLO_TRIANGLE_HPP
#define VK_TUT_HELLO_TRIANGLE_HPP

#include "glfwUtility.hpp"
#include "vulkanUtility.hpp"

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdlib>

class HelloTriangle {
public:
    static int constexpr width  = 800;
    static int constexpr height = 600;

    HelloTriangle();

    auto
    run() -> void
    {
        main_loop();
        cleanup();
    }

private:
    glfwUtils::UniqueWindow const m_window;

    std::vector<char const*> const m_validationLayers{
            "VK_LAYER_KHRONOS_validation"};
    vk::UniqueInstance const m_instance;

    vulkanUtils::LoaderDispatcherPair const m_loaderDispatcherPair;
    vulkanUtils::UniqueDebugUtilsMessengerEXT const m_debugMessenger;
    vk::UniqueSurfaceKHR const m_surface;

    std::vector<char const*> const m_deviceExtensions{
            VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    vk::PhysicalDevice const m_physicalDevice;

    vulkanUtils::QueueFamilyAndPos const m_graphicsQueues;
    vulkanUtils::QueueFamilyAndPos const m_presentationQueues;
    std::vector<float> const m_queuePriorities;
    std::vector<uint32_t> const m_queueIndicies;

    vk::UniqueDevice const m_logicalDevice;
    vk::Queue const m_deviceQueue;

    vk::SurfaceFormatKHR const m_surfaceFormat{
            vulkanUtils::defaultSurfaceFormat};
    vk::UniqueSwapchainKHR const m_swapChain;
    std::vector<vk::Image> const m_swapChainImages;
    std::vector<vk::UniqueImageView> const m_imageViews;

    auto
    main_loop() -> void;

    static auto
    cleanup() -> void;
};

#endif    // VK_TUT_HELLO_TRIANGLE_HPP
