



#include "FileWork.hpp"
#include "StringWork.hpp"



bool LoadTextFile(std::string filepath , std::string& fstr) {
   
   bool ret = false;
   
   FILE* f = fopen(filepath.c_str() , "rb");
 
   if (f) {
      unsigned int count = 0;
      while (fgetc(f) != EOF) {++count;}
      
      if (count) {
         fseek(f , 0 , SEEK_SET);
         fstr = std::string();
         fstr.reserve(count);
         if (count == fread(&fstr[0] , sizeof(char) , count , f)) {
            ret = true;
         }
      }
      fclose(f);
   }
   
   return ret;
}



bool SaveTextFile(std::string filepath , const std::vector<std::string>& lines , bool append , bool overwrite) {
   if (!overwrite)
   {
      FILE* f = fopen(filepath.c_str() , "r");
      if (f) {
         fclose(f);
         return false;
      }
   }
   const char* flags = "w";
   if (append) {flags = "w+";}
   
   bool ret = true;
   FILE* f = fopen(filepath.c_str() , flags);
   if (f) {
      for (unsigned int i = 0 ; i < lines.size() ; ++i) {
         if (0 > fprintf(f , "%s\n" , lines[i].c_str())) {
            ret = false;
            break;
         }
      }
      fclose(f);
   }
   return ret;
}



/// ------------------------------     TextFile     ---------------------------------



TextFile::TextFile() :
      fpath(""),
      fstr(""),
      flines()
{}



void TextFile::Clear() {
   fstr.clear();
   flines.clear();
}



bool TextFile::Load(std::string filepath) {
   Clear();
   fpath = filepath;
   if (!LoadTextFile(filepath , fstr)) {
      return false;
   }
   flines = SplitByNewLines(fstr);
   fstr.clear();
   return true;
}



void TextFile::AddLine(const std::string line) {
   flines.push_back(line);
}



void TextFile::AppendCurrentLine(const std::string append) {
   if (!flines.size()) {
      flines.push_back("");
   }
   flines.back() += append;
}



bool TextFile::Save(std::string filepath) {
   fpath = filepath;
   if (!SaveTextFile(filepath , flines , false , true)) {
      return false;
   }
   return true;
}

