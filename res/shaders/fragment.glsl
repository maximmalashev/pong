#version 330

in vec3 vColor;
out vec4 final_color;

void main()
{
	final_color = vec4(vColor, 1.0);
};