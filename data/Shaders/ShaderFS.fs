precision mediump float;

uniform sampler2D texture_diffuse1;

varying vec2 v_TexCoords;

void main()
{
	gl_FragColor = texture2D(texture_diffuse1, v_TexCoords);
}
