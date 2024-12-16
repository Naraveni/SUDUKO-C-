#ifndef __LOGGER__H__
#define __LOGGER__H__

#include <fstream>
using namespace std;
class Logger{
    private:
        ofstream outPutFile;
        Logger(){
            outPutFile.open("output.txt", ios_base::app); 
        }
        ~Logger(){
            if(outPutFile.is_open()){
                outPutFile.close();
            }
        }
    public:
        //deleting copy and moving constructors
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;


        static std::ofstream& getStream() {
            static Logger instance;
            return instance.outPutFile;
        }

        template<typename T>
        ostream& operator<< (const T& data) {
            outPutFile << data;
            return getStream();
        }

};
#endif  //!__LOGGER__H__