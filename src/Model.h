#pragma once

#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model {
public:

	Model() { } 

	Model(char *path) {
		loadModel(path);
	}

	// draws the model, and thus all its meshes
	void Draw(Shader shader);

private:
	/* Model Data */
	vector<Mesh> meshes;
	string directory;

	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	vector<Texture> textures_loaded;

	/* Functions */
	// loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
	void loadModel(string path);

	// processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
	void processNode(aiNode *node, const aiScene *scene);

	// Process Mesh
	Mesh processMesh(aiMesh *mesh, const aiScene *scene);

	// checks all material textures of a given type and loads the textures if they're not loaded yet.
	// the required info is returned as a Texture struct.
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
	unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);
};



#endif // MODEL_H

