// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
using namespace glm;

int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	//window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	window = glfwCreateWindow( 100, 768, "Tutorial 01", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear( GL_COLOR_BUFFER_BIT );

		// Draw nothing, see you in tutorial 2 !

		
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}


//glew（The OpenGL Extension Wrangler Library）是对底层OpenGL接口的封装，可以让你的代码跨平台。glad与glew作用相同，可以看作它的升级版。
//Freeglut（OpenGL Utility Toolkit）主要用于创建OpenGL上下文、接收一些鼠标键盘事件等等。
//glfw（Graphics Library Framework）是Freeglut升级版，作用基本一样。
//通常来说glad和glfw配合使用，比如我上面发的那个网站就是。
//glew和Freeglut配合使用，比如OpenGL红宝书上面的例子。
// 
// >>glad<<->(glew)
// >>glfw<<->(glut)
//
//作者：醉里挑灯看剑
//链接：https ://www.zhihu.com/question/264132001/answer/729626917
//来源：知乎
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

