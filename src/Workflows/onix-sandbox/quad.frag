#version 400
uniform sampler2D tex;
in vec2 tex_coord;
out vec4 frag_colour;
uniform float white = 0.5;

void main()
{
  // intensity value is stored in RED channel of texture [0-1]
  float value = texture(tex, tex_coord).x;

  // map positive intensity values to RED channel: 0.5 => 0 and 1 => 1
  float red = value >= 0.5 ? value * 2 - 1 : 0.0;

  // map negative intensity values to BLUE channel: 0 => 1 and 0.5 => 0
  float blue = value < 0.5 ? 2 * (1 - value) - 1 : 0.0;
  
  // map how much the intensity value is away from
  // the middle of the scale into the GREEN channel
  float green = white * (1 - max(red, blue));

  // final colour is mix of all channels: green is added to all channels for gray background
  frag_colour = vec4(red + green, green, blue + green, 1.0);
}
