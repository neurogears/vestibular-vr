#version 400
uniform mat4 modelview; 
uniform mat4 projection;
layout(location = 0) in vec3 vp;
out vec3 texCoord;

void main()
{
  vec4 position = projection * modelview * vec4(vp, 1.0);
  gl_Position = position.xyww;
  texCoord = vp;
}