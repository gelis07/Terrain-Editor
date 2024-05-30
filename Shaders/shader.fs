#version 430 core
out vec4 FragColor;
	
in vec2 TexCoords;
in vec3 FragPos;
in mat3 TBN;

uniform sampler2D tex;
uniform sampler2D normalMap;
uniform vec3 LightPos;
uniform vec3 ViewPos;


vec3 TransViewPos;
vec3 TransLightPos;
vec3 TransFragPos;
void main()
{             

    TransFragPos = TBN * FragPos;
    TransLightPos = TBN * LightPos;
    TransViewPos = TBN * ViewPos;
    vec3 Normal = texture(normalMap, TexCoords).rgb;
    Normal = normalize(Normal * 2.0 - 1.0);

    vec3 texCol = texture(tex, TexCoords).rgb;
    vec3 LightDir = normalize(TransLightPos - TransFragPos);
    float diff = max(dot(LightDir, Normal), 0);
    vec3 diffuse = vec3(diff);

    float specStrength = 0.5;
    vec3 viewDir = normalize(TransViewPos - TransFragPos);
    vec3 reflectDir = reflect(-LightDir, Normal);
    vec3 halfwayDir = normalize(LightDir + viewDir);
    float spec = pow(max(dot(Normal, halfwayDir), 0.0), 32);
    vec3 specular = vec3(specStrength * spec);

    FragColor = vec4(texCol * (diffuse + specular), 1.0);
}