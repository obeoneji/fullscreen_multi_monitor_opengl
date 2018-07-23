//#define FREEGLUT_STATIC // defined so you can link to freeglut_static.lib when compiling
//#define GLEW_STATIC     // defined so you can link to glew's static .lib when compiling

#include <GL/glew.h>     // has to be included before gl.h, or any header that includes gl.h
#include "GLFW\glfw3.h"
#include <GL/freeglut.h>

#include "textfile.h"
#include "fullscreen.h"





int main(int argc, char** argv)
{

	// glfw init
	int glfwErr =  glfwInit();

	if (glfwErr != GLFW_TRUE)
	{
		std::cout << "glfw init error!" << std::endl;
	}


	// create windows in secondary monitor
	int count;

	GLFWmonitor** monitors;
	GLFWwindow* window;
	
	monitors = glfwGetMonitors(&count);
	window = glfwCreateWindow(1920, 1080, "Fullscreen Pattern", monitors[1], NULL);
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);


	// glew init (for shader use), after window create
	GLenum err = glewInit();

	if (err != GLEW_OK) 
	{
		std::cout << "glew init error!" << std::endl;
	}

	if (glewIsSupported("GL_VERSION_4_6"))
		printf("Ready for OpenGL 4.6\n");
	else {
		printf("OpenGL 4.6 not supported\n");
		exit(1);
	}


	// set and compile shader
	setShaders();


	//load texture using opencv
	load_bind_texture("pattern/test.jpg");


	//render loop
	while (!glfwWindowShouldClose(window))
	{
		// code for rendering here
		glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw rectangle for texture display
		glBegin(GL_QUADS);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0, 0.0);
		glVertex3f(1.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0, 1.0);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0, 1.0);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0, 0.0);
		glEnd();

		glfwSwapBuffers(window);
		//glfwPollEvents();
	}


	// release and exit
	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}