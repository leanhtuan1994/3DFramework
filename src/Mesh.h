#pragma once

#ifndef MESH_H
#define MESH_H

#include "ogles_sys.h"
#include "Shader.h"
#include "Vertex.h"
#include "Texture.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
using namespace glm;

class Mesh {

public:

	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	unsigned int VAO;

	// Constructor
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

	// render the mesh
	void Draw(Shader shader);


private:

	/*  Render data  */
	unsigned int VBO, EBO;

	// initializes all the buffer objects/arrays
	void setupMesh();

};

#endif // MESH_H

