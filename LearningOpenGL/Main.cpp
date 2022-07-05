#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void InputHandling(GLFWwindow* window);


int main() {

	//initializing GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	//creating GLFW window
	GLFWwindow* window = glfwCreateWindow(800, 600, "MyOpenGlWindow",NULL,NULL);
	if (window == NULL) {
	cout << "Failed to create a window" << endl;
	glfwTerminate();
	return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//loading GLAD, GLAD load all the OPENGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

		cout << "Failed to intialize GLAD" << endl;
		return -1;
	}

	//render loop
	while (!glfwWindowShouldClose(window)) {


		//input
		InputHandling(window);


		//rendering commands

		glClearColor(0.9f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		//check and call events and swapping the buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	

	


	return 0;
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void InputHandling(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {

		glfwSetWindowShouldClose(window,true);

	}
}