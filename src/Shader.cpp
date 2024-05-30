#include "Shader.h"
#include "Debug.h"

std::string Shader::ReadFile(const std::string& filenPath){
    std::ifstream file;
    file.open(filenPath.c_str());
    char c;
    std::string sfile;
    while(file.get(c)) sfile += c;
    file.close();
    return sfile;
}
void Shader::CheckShader(GLuint shader,const std::string& name)
{
    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &errorLog[0]);
        std::cout << name << ": " << errorLog.data() << '\n';
        // Provide the infolog in whatever manor you deem best.
        // Exit with failure.
        glDeleteShader(shader); // Don't leak the shader.
    }
}
void Shader::Init(const std::string &vs, const std::string &fs)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string vertexSource = ReadFile(("Shaders/"+vs));
    std::string fragSource = ReadFile(("Shaders/"+fs));
    const char* vertexSourceS = vertexSource.c_str();
    const char* fragSourceS = fragSource.c_str();
    glShaderSource(vertexShader, 1, &vertexSourceS, NULL);
    glShaderSource(fragShader, 1, &fragSourceS, NULL);
    glCompileShader(vertexShader);
    glCompileShader(fragShader);
    CheckShader(vertexShader, vs);
    CheckShader(fragShader, fs);
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragShader);
    glLinkProgram(ID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
    HasInit = true;
}

void Shader::Init(const std::string &cs)
{
    GLuint compute;
    compute = glCreateShader(GL_COMPUTE_SHADER);
    std::string compSource = Shader::ReadFile("Shaders/"+cs);
    const char* cShaderCode = compSource.c_str();
    glShaderSource(compute, 1, &cShaderCode, NULL);
    glCompileShader(compute);
    CheckShader(compute, cs);

    ID = glCreateProgram();
    glAttachShader(ID, compute);
    glLinkProgram(ID);
    HasInit = true;
}

void Shader::Init(const std::string &vs, const std::string &gs, const std::string &fs)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    GLuint geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    std::string vertexSource = ReadFile(("Shaders/"+vs));
    std::string fragSource = ReadFile(("Shaders/"+fs));
    std::string geomSource = ReadFile(("Shaders/"+gs));
    const char* vertexSourceS = vertexSource.c_str();
    const char* fragSourceS = fragSource.c_str();
    const char* geomSourceS = geomSource.c_str();
    glShaderSource(vertexShader, 1, &vertexSourceS, NULL);
    glShaderSource(fragShader, 1, &fragSourceS, NULL);
    glShaderSource(geometryShader, 1, &geomSourceS, NULL);
    glCompileShader(vertexShader);
    glCompileShader(fragShader);
    glCompileShader(geometryShader);
    CheckShader(vertexShader, vs);
    CheckShader(fragShader, fs);
    CheckShader(geometryShader, gs);
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragShader);
    glAttachShader(ID, geometryShader);
    glLinkProgram(ID);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
    glDeleteShader(geometryShader);
    HasInit = true;
}

Shader::Shader(const std::string &vs, const std::string &fs)
{
    Init(vs, fs);
}

Shader::Shader(const std::string &cs)
{
    Init(cs);
}

Shader::Shader(const std::string &vs, const std::string &gs, const std::string &fs)
{
    Init(vs, gs, fs);
}

void Shader::Bind()
{
    HAS_INIT(HasInit);
    glUseProgram(ID);
}

void Shader::Unbind()
{
    glUseProgram(0);
}
int GetUniformLocation(GLuint id, const std::string& name){
    int result = glGetUniformLocation(id, name.c_str());
    if(result == -1){
        std::cout << "Uniform with name: " << name << " can't be found!" << '\n';
    }
    return result;
}
void Shader::SetUniform(const std::string &name, int data)
{
    HAS_INIT(HasInit);
    glUniform1i(GetUniformLocation(ID, name.c_str()),data);
}

void Shader::SetUniform(const std::string &name, GLuint data)
{
    HAS_INIT(HasInit);
    glUniform1i(GetUniformLocation(ID, name.c_str()),data);
}

void Shader::SetUniform(const std::string &name, float data)
{
    HAS_INIT(HasInit);
    glUniform1f(GetUniformLocation(ID, name.c_str()),data);
}

void Shader::SetUniform(const std::string &name, const glm::vec3& data)
{
    HAS_INIT(HasInit);
    glUniform3f(GetUniformLocation(ID, name.c_str()),data.x, data.y, data.z);
}

void Shader::SetUniform(const std::string &name, const glm::vec2 &data)
{
    HAS_INIT(HasInit);
    glUniform2f(GetUniformLocation(ID, name.c_str()),data.x, data.y);
}

void Shader::SetUniform(const std::string &name, const glm::mat4 &mat)
{
    HAS_INIT(HasInit);
    glUniformMatrix4fv(GetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::SetUniform(const std::string &name, const glm::mat3 &mat)
{
    HAS_INIT(HasInit);
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::Dispatch(const glm::vec3& groups, int BarrierBit)
{
    HAS_INIT(HasInit);
    glDispatchCompute(groups.x, groups.y, groups.z);
    glMemoryBarrier(BarrierBit);
}
