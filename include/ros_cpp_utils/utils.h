#include <ros/ros.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <boost/filesystem.hpp>
#include <string>


class ROSCppUtils{
public:
  // Get home path in linux
  static std::string getHomePath()
  {
    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    if (pw == NULL)
    {
        ROS_ERROR("Failed to get homedir. \n");
        return "";
    }

    // printf("%s\n", pw->pw_dir);
    std::string str(pw->pw_dir);
    return str;

  }

  static bool createDirectory(std::string path)
  {


    boost::filesystem::path dir(path);

    if(!(boost::filesystem::exists(dir)))
    {
        ROS_INFO("Directory Doesn't Exists");

    }

    if (boost::filesystem::create_directory(dir))
    {

        ROS_INFO("Directory Successfully Created !");
        return true;
    }


        return false;
  }

};
