#version 400
uniform sampler2D tex;
uniform float range = 1.0f;
uniform float red = 1.0f;
vec2 value;
in vec2 texCoord;
out vec4 frag_colour;

void main()
{
  vec4 texel = texture(tex, texCoord);
  
  frag_colour = vec4(red, 0.0, 0.0, 1.0);
}
