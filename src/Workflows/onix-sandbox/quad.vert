#version 400
uniform int channel;
uniform int numchannels = 64;
in vec2 vp;
in vec2 vt;
out vec2 tex_coord;

void main()
{
  vec2 scale = vec2(1.0 / numchannels, 1);
  vec2 shift = vec2(channel * scale.x * 2 - 1 + scale.x, 0);
  gl_Position = vec4(vp * scale + shift, 0.0, 1.0);
  tex_coord = vt;
}
