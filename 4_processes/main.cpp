#include <filesystem>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <vector>

const std::vector<std::string> kPreferedPaths = {
"/home/ivan_main/development/spz_cpp_2",
"/home/ivan_main/development/spz_cpp"
};
const std::string kFileExtension = ".cpp";

void ProcessFunction(int process_id){
    std::string path = kPreferedPaths[process_id];
    std::cout << "Current path > " << path << "\n";

    namespace fs = std::filesystem;
    for (const auto & entry : fs::directory_iterator(path)){
        if(entry.path().string().rfind(kFileExtension) != std::string::npos){
            std::cout << entry.path() << std::endl;
        }
    }
    std::cout << std::endl;
}

int main(){
    int process_num = kPreferedPaths.size();

    for(int i = 0; i < process_num; i++){
        std::cout << std::endl;
        pid_t pid = fork();
        if (pid == 0){
            // child process
            std::cout << "process id " << getpid() << std::endl;
            ProcessFunction(i);
        }
        else if (pid > 0){
            // parent process
            wait(NULL);
        }
        else{
            // fork failed
            std::cerr << "fork() failed!" << std::endl;
            return 1;
        }     
    }

    return 0;
}
