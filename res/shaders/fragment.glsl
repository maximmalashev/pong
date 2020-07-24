#version 330

in vec3 vColor;
uniform float testColor;
out vec4 final_color;

void main()
{
	final_color = vec4(vColor.x, vColor.y, testColor, 1.0);
};