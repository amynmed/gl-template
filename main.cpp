

#include <iostream>
#include <chrono>

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#define TITLE   "renderer"

#define WIDTH   800
#define HEIGHT  600


int main()
{

        std::chrono::high_resolution_clock clk;



        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!glfwInit())
        {
                std::cout << "GLFW initialization error" << std::endl;
        }


        GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

        if (!window) 
        {
                std::cerr << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return -1;
        }

        glfwMakeContextCurrent(window);

        int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0) 
        {
                printf("Failed to initialize OpenGL context\n");
                return -1;
        }

        // Successfully loaded OpenGL
        printf("Loaded OpenGL %d.%d\n", GLAD_VERSION_MAJOR(version), GLAD_VERSION_MINOR(version));

        while (!glfwWindowShouldClose(window))
        {
                // Render here (e.g., clear the screen)
                glClear(GL_COLOR_BUFFER_BIT);

                // Swap front and back buffers
                glfwSwapBuffers(window);

                // Poll for and process events
                glfwPollEvents();
        }

        glfwTerminate();
        






        return 0;
}