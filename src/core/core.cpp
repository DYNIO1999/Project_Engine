#include "core.h"
using namespace DEngine;

EngineCore::EngineCore(){
 window =nullptr;
 fullscreen = true;
 deltatime = 0.0f;
 monitor = nullptr;
 currentTime =0;
 lastTime =0;
 //engineWinManager = new WindowManager(window,WINDOW_WIDTH, WINDOW_HEIGHT);

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
    monitor =  glfwGetPrimaryMonitor();
    glfwGetWindowSize( window,&SCREEN_WIDTH ,&SCREEN_HEIGHT);
    glfwGetWindowPos( window,&SCREEN_POS_X, &SCREEN_POS_Y);
    glViewport(0, 0,WINDOW_WIDTH, WINDOW_HEIGHT);

    return true;
}
void EngineCore::mainLoop(){

    ////?
    const char *vertexShaderSource = "#version 450 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                    "{\n"
                                    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                    "}\0";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const char *fragmentShaderSource = 
    "#version 450 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
    }
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "SHADER PROGRAM\n"
                  << infoLog << std::endl;
    }

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 
         0.5f, -0.5f, 0.0f,  
         0.0f,  0.5f, 0.0f     
    }; 

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0); 
    while (!glfwWindowShouldClose(window))
    {
        
        processInput();

        //draw

        //update
        currentTime = glfwGetTime();
    if(currentTime - lastTime >= 1.0/ENGINE_FPS_CAP){
        lastTime = currentTime;
        std::cout<<"TEST:"<<currentTime<<std::endl;
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
        
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteProgram(shaderProgram);
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