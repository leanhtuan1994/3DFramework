#pragma once

#ifndef VERTEX_H
#define VERTEX_H

#include "glm.hpp"

struct Vertex
{
	// position
	glm::vec3 Position;

	// normal 
	glm::vec3 Normal;

	// texCoords
	glm::vec2 TexCoords;

	// tangent
	glm::vec3 Tangent;

	// bitangent
	glm::vec3 Bitangent;

};




#endif //VERTEX_H
