



#ifndef Shader_HPP
#define Shader_HPP


class ShaderBase {
   
protected :
   std::string src;
   
   
public :
   
   
   virtual bool Compile(std::string source);
   bool Compile(std::string source) {
      
   }
   
};




class ShaderProgram {
protected :
   VertexShader vert;
   FragmentShader frag;
   
   
public :
   
   bool UseProgram();
};

#endif // Shader_HPP
