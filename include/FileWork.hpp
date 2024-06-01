



#ifndef FileWork_HPP
#define FileWork_HPP


#include <string>
#include <vector>



bool LoadTextFile(std::string filepath , std::string& fstr);

bool SaveTextFile(std::string filepath , const std::vector<std::string>& lines , bool append = false , bool overwrite = false);



class TextFile {
private :
   std::string fpath;
   std::string fstr;
   std::vector<std::string> flines;
   
   
public :
   TextFile();
   
   void Clear();
   bool Load(std::string filepath);
   
   void AddLine(const std::string line);
   void AppendCurrentLine(const std::string append);

   bool Save(std::string filepath);

   const std::string Path() {return fpath;}
   const std::string FileStr() {return fstr;}
   const std::vector<std::string>& Lines() {return flines;}
};


#endif // FileWork_HPP

