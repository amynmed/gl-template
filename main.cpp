

#include <iostream>
#include <chrono>

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>


#define WIDTH  800
#define HEIGHT 600


int main()
{
        std::cout << "renderer" << std::endl;

        std::chrono::high_resolution_clock clk;

        if (!glfwInit())
        {
                std::cout << "GLFW initialization error" << std::endl;
        }

        glfwTerminate();

        GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
        glfwMakeContextCurrent(window);

        int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0) 
        {
                printf("Failed to initialize OpenGL context\n");
                return -1;
        }

        // Successfully loaded OpenGL
        printf("Loaded OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));
        
        return 0;
}