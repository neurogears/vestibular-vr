#version 400
uniform sampler2D tex;
uniform float range = 0.5f;
vec2 value;
in vec2 texCoord;
out vec4 frag_colour;

void main()
{
  vec4 texel = texture(tex, texCoord);
  if (texel.x < 0.0f)
  {
    value.x = (-1.0f * texel.x)/range;
    value.y = 0.0f;
  } else {
    value.x = 0.0f;
    value.y = texel.x/range;
  }
  frag_colour = vec4(value, 0.0f, 1.0f);
}
