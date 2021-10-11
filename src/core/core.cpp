#include "core.h"
using namespace DEngine;

EngineCore::EngineCore(){
 window =nullptr;
 fullscreen = true;
 monitor = nullptr;
}
EngineCore::~EngineCore(){
}

bool EngineCore::initWindow(){
    if (!glfwInit())
    {
        std::cout<<"ERROR WHILE INIT GLFW!!"<<std::endl;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window= glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT, "DEngine", nullptr, nullptr);
    
    
    if(window == nullptr){
        std::cout << "ERROR WHILE CREATING WINDOW GLFW!!" << std::endl;
        return false;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }
    std::cout<<"OpenGL version supported by this platform:"<<glGetString(GL_VERSION)<<'\n';

    monitor =  glfwGetPrimaryMonitor();
    glfwGetWindowSize( window,&SCREEN_WIDTH ,&SCREEN_HEIGHT);
    glfwGetWindowPos( window,&SCREEN_POS_X, &SCREEN_POS_Y);
    glViewport(0, 0,WINDOW_WIDTH, WINDOW_HEIGHT);

    return true;
}
void EngineCore::mainLoop(){
    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    unsigned int vertexShader_ID;
    vertexShader_ID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader_ID, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader_ID);

    int success;
    char infoLog[512];
    
    glGetShaderiv(vertexShader_ID, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }
    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.976f, 0.643f, 0.945f, 1.0f);\n"
    "}\0";

    const char *fragmentShaderSource2 = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(0.5f, 0.5f, 0.945f, 1.0f);\n"
                                       "}\0";

    unsigned int fragmentShader_ID;
    fragmentShader_ID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader_ID, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader_ID);

    unsigned int fragmentShader2_ID;
    fragmentShader2_ID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2_ID, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShader2_ID);

    glGetShaderiv(fragmentShader_ID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }
    glGetShaderiv(fragmentShader2_ID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader2_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    unsigned int shaderProgram_ID;
    shaderProgram_ID = glCreateProgram();

    unsigned int shaderProgram2_ID;
    shaderProgram2_ID = glCreateProgram();

    glAttachShader(shaderProgram_ID, vertexShader_ID);
    glAttachShader(shaderProgram_ID, fragmentShader_ID);
    glLinkProgram(shaderProgram_ID);

    glGetProgramiv(shaderProgram_ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram_ID, 512, NULL, infoLog);
        std::cout << "ERROR::LINKING_SHADERS::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    glAttachShader(shaderProgram2_ID, vertexShader_ID);
    glAttachShader(shaderProgram2_ID, fragmentShader2_ID);
    glLinkProgram(shaderProgram2_ID);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram2_ID, 512, NULL, infoLog);
        std::cout << "ERROR::LINKING_SHADERS::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }

    glDeleteShader(vertexShader_ID);
    glDeleteShader(fragmentShader_ID);
    glDeleteShader(fragmentShader2_ID);

    float vertices1[] = {
        -1.0f, -0.5f, 0.0f,
         0.0f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        };

    float vertices2[] =
        {
            0.0f, -0.5f, 0.0f, //LEFT_BOTTOM
            1.0f, -0.5f, 0.0f, //right bottom
            0.5f, 0.5f, 0.0f,  //top
        };


    
    /*float vertices[] = {
        0.5f, 0.5f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, // bottom left
        -0.5f, 0.5f, 0.0f   // top left
    };
    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };*/

    //unsigned int EBO_ID;
    //glGenBuffers(1, &EBO_ID);

    unsigned int VAO_ID[2];
    glGenVertexArrays(2, VAO_ID);

    unsigned int VBO_ID[2];
    glGenBuffers(2, VBO_ID);

    glBindVertexArray(VAO_ID[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_ID[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO_ID[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_ID[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_ID);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



    while (!glfwWindowShouldClose(window))
    {
        processInput();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram_ID);
        glBindVertexArray(VAO_ID[0]);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glUseProgram(shaderProgram2_ID);
        glBindVertexArray(VAO_ID[1]);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glfwPollEvents();
        glfwSwapBuffers(window);   
    }
}
void EngineCore::cleanup(){
    glfwTerminate();
}
void EngineCore::run(){
    initWindow();
    mainLoop();
    cleanup();
}
void EngineCore::processInput(){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE )== GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS){
        if(fullscreen==false){
        glfwSetWindowMonitor(window, nullptr,  SCREEN_POS_X, SCREEN_POS_Y, SCREEN_WIDTH, SCREEN_HEIGHT, 0 );
        int temp1;
        int temp2;
        glfwGetFramebufferSize( window, &temp1, &temp2);
        glViewport( 0, 0, temp1, temp2);
    
        fullscreen= true;    
        }
    }
    if(glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS){
        if(fullscreen == true){
        glfwGetWindowSize( window,&SCREEN_WIDTH ,&SCREEN_HEIGHT);
        glfwGetWindowPos( window,&SCREEN_POS_X, &SCREEN_POS_Y);
        
        const GLFWvidmode * mode = glfwGetVideoMode(monitor);
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, 0);
        int temp1;
        int temp2;
        glfwGetFramebufferSize( window, &temp1, &temp2);
        glViewport( 0, 0, temp1, temp2);

        fullscreen = false;
        }
        
    }
}