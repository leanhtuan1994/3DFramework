#include "ogles_sys.h"
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "Model.h"
#include "Camera.h"
#include "Definitions.h"

using namespace glm;

SysContext oglSysCtx;
int init();
void update(float deltaTime);
void render();
void keyEvent(unsigned char key, bool bIsPressed);



Shader ourShader;
Model ourModel;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCREEN_WIDTH / 2.0f;
float lastY = SCREEN_HEIGHT / 2.0f;
bool firstMouse = true;

glm::mat4 projectionMatrix;
glm::mat4 modelMatrix;
glm::mat4 viewMatrix;



void main()
{
	ZeroMemory(&oglSysCtx, sizeof(SysContext));

	sysInit(&oglSysCtx, SCREEN_WIDTH, SCREEN_HEIGHT);

	/* enable depth test */
	glEnable(GL_DEPTH_TEST);


	if (init() != 0) {	

		Debug("\nInit shader failed");
	}

	sysRegisterKeyFunc(&oglSysCtx, keyEvent);
	sysRegisterRenderFunc(&oglSysCtx, render);
	sysRegisterUpdateFunc(&oglSysCtx, update);

	sysMainLoop(&oglSysCtx);
}


int init()
{
	 ourShader = Shader("../data/Shaders/ShaderVS.vs", "../data/Shaders/ShaderFS.fs");
	 ourModel = Model("../data/Models/nanosuit/nanosuit.obj");
	
	

	 // view/projection transformations
	 projectionMatrix = glm::perspective(glm::radians(camera.GetZoom()), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
	 viewMatrix = camera.GetViewMatrix();


	 // model 
	 modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, -0.8f, 0.0f));
	 modelMatrix = glm::scale(modelMatrix, glm::vec3(0.12f, 0.12f, 0.12f));




	return 0;
}

void update(float dt)
{
	modelMatrix = glm::rotate(modelMatrix, 0.001f, glm::vec3(0.0f, 1.0f, 0.0f));
	viewMatrix = camera.GetViewMatrix();
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ourShader.use();

	/* Set PVM */ 
	ourShader.setMat4("u_Projection", projectionMatrix);
	ourShader.setMat4("u_View", viewMatrix);
	ourShader.setMat4("u_Model", modelMatrix);


	// render the loaded model
	ourModel.Draw(ourShader);


	eglSwapBuffers(oglSysCtx.eglDisplay, oglSysCtx.eglSurface);
}

void keyEvent(unsigned char key, bool bIsPressed)
{

	switch (key)
	{
	case 'W':
		camera.ProcessKeyboard(FORWARD, 0.05f);
		break;
	case 'S':
		camera.ProcessKeyboard(BACKWARD, 0.05f);
		break;
	case 'A':
		camera.ProcessKeyboard(LEFT, 0.05f);
		break;
	case 'D':
		camera.ProcessKeyboard(RIGHT, 0.05f);
		break;

	default:
		break;
	}

}