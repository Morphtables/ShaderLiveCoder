#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm.hpp>

#include "TextRenderer.hpp"
#include "Shader.hpp"
#include <time.h>
#include <chrono>

int init() {
    if (!glfwInit()) {
        glfwTerminate();
        return -1;
    }
    
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

int glfwWindowInit(GLFWwindow* window) {
    if (!window) {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = true;
    if(glewInit() != GLEW_OK)
        std::cout << "error" << std::endl;

    return 0;
}

const int WIDTH = 800;
const int HEIGHT = 500;
const double PI = 3.14159265359;

int main () {
    std::cout << PI << std::endl;
    init();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Test Game", NULL, NULL);
    glfwWindowInit(window);
    	
    TextRenderer textRenderer(WIDTH, HEIGHT);
    //std::string fontPath = "/Users/pashaukolov/Library/Fonts/Roboto-regular.ttf";
    std::string fontPath = "/Users/pashaukolov/Library/Fonts/PixelFont.ttf";
    textRenderer.loadFont(fontPath, 36);
    glClearColor(0.0f, 0.05f, 0.08f, 0.0f);

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    
    //double xpos ypos;
    bool isMousePressed = false;
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    
    while(!glfwWindowShouldClose(window)) {
	//glfwGetCursorPos(window, &xpos, &ypos);
	float currentTime = glfwGetTime();
	deltaTime = currentTime - lastFrame;
	lastFrame = currentTime;

	static bool reload_key_pressed = false;
	bool down = glfwGetKey( window, GLFW_KEY_R );
	if ( down && !reload_key_pressed ) {
	    reload_key_pressed = true;
	} else if ( !down && reload_key_pressed ) {
	    reload_key_pressed = false;
	    textRenderer.reloadShader();
	}

	if(!glfwGetMouseButton(window, 0)) {
	    isMousePressed = false;
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	} else {
	    isMousePressed = true;
	}

	textRenderer.renderText("hello world", deltaTime, glm::vec2(0.0f, 0.0f), glm::vec3(0.9f, 0.95f, 0.99f));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    
    std::cout << "App closed succesfully" << std::endl;

    return 0;
}