#version 400
in vec2 texCoord;
out vec4 frag_colour;

void main()
{ 
  frag_colour = vec4(texCoord.x, texCoord.y, 0.0, 1.0);
}
