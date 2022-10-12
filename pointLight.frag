#version 450

layout(location = 0) in vec2 fragOffset;

layout(location = 0) out vec4 outColor;

struct PointLight{
	vec4 position;
	vec4 color;
};

layout(set =0, binding = 0) uniform UBO{
	mat4 projectionMatrix;
	mat4 viewMatrix;
	mat4 inverseViewMatrix;
	vec4 ambientLightColor;
	PointLight pointLights[10];//TODO : specialization constant
	int nbLights;
} ubo;

layout(push_constant) uniform Push{
	vec4 position;
	vec4 color;
	float radius;
}push;

const float M_PI = 3.1415926538;

void main(){
	float dist = sqrt(dot(fragOffset,fragOffset));
	if(dist >= 1.0){
		discard;
	}
	float cosDist = 0.5 * (cos(dist * M_PI) + 1.0); 
	outColor = vec4(push.color.xyz + 0.5 * cosDist, cosDist);
}