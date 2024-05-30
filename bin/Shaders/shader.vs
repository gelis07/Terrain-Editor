#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in vec3 aNorm;
layout (location = 3) in vec3 aTang;
layout (location = 4) in vec3 aBitang;
	
out vec2 TexCoords;
out mat3 TBN;
out vec3 FragPos;
uniform mat4 mvp;
uniform mat4 model;
	
void main()
{
    TexCoords = aTexCoords;
    mat3 normalMatrix = transpose(inverse(mat3(model)));
    vec3 T = normalize(normalMatrix * aTang);
    vec3 N = normalize(normalMatrix * aNorm);
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    TBN = transpose(mat3(T,B,N));
    FragPos = vec3(model * vec4(aPos,1.0));
    gl_Position = mvp * vec4(aPos, 1.0);
}