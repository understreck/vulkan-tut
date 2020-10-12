#ifndef VK_TUT_GLFW_UTILITY
#define VK_TUT_GLFW_UTILITY

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

#include <string>
#include <memory>
#include <vector>

namespace glfwUtils {
struct WindowDeleter {
    auto
    operator()(GLFWwindow* window) noexcept -> void
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};

using UniqueWindow = std::unique_ptr<GLFWwindow, WindowDeleter>;

[[nodiscard]] auto
create_window(int width, int height, bool resizeable, std::string const& title)
        -> UniqueWindow;

[[nodiscard]] auto
required_vk_extensions() -> std::vector<char const*>;

[[nodiscard]] auto
create_window_surface(
        vk::UniqueInstance const& instance,
        UniqueWindow const& window) -> vk::UniqueSurfaceKHR;
}    // namespace glfwUtils

#endif    // VK_TUT_GLFW_UTILITY
