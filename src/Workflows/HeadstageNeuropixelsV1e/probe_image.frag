#version 400

// The input texture
uniform sampler2D uTexture;

// Interpolated texture coordinate per fragment
in vec2 texCoord;
out vec4 fragColor;

void main()
{
  // intensity value is stored in RED channel of texture [0-1023]
  // Neuropixels data is 10-bit and R16 internal formation is 16 bit
  // So the incoming data need to be multipled by 64 to get it in 0-1 range.
  float texel = 64.0 * texture(uTexture, texCoord).r;

  // map positive intensity values to RED channel: 0.5 => 0 and 1 => 1
  float red = texel >= 0.5 ? 2.0 * (texel - 0.5) : 0.0;

  // map negative intensity values to BLUE channel: 0 => 1 and 0.5 => 0
  float blue = texel < 0.5 ? 2.0 * (0.5 - texel) : 0.0;
  
  // map how much the intensity value is away from
  // the middle of the scale into the GREEN channel
  float green = 0.75 * (1.0 - max(red, blue));

  // final colour is mix of all channels: green is added to all channels for gray background
  fragColor = vec4(red + green, green, blue + green, 1.0);
}