attribute vec3 a_Position;
attribute vec3 a_Normal;
attribute vec2 a_TexCoords;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

varying vec2 v_TexCoords;

void main()
{
	v_TexCoords = a_TexCoords;
	gl_Position = u_Projection*u_View*u_Model*vec4(a_Position, 1.0);
	
}
   