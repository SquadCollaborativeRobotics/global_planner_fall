#include <ros/ros.h>
#include <ros/package.h>
#include <boost/thread.hpp>
#include "std_msgs/String.h"
#include "string.h"

class SoundManager
{
public:
    SoundManager()
    {
        is_playing = false;
    };
    ~SoundManager(){};

    bool is_playing;

    //ros::NodeHandle _nh;

    // ROS topic callback
    void sound_thread(std::string str)
    {
        try
        {
            if (is_playing)
            {
                system("killall -9 aplay");
            }

            is_playing = true;

            std::string path_to_sound = std::string("aplay -q ");
            path_to_sound += ros::package::getPath("global_planner");
            path_to_sound += std::string("/resources/sounds/");
            path_to_sound += str;
            ROS_INFO_STREAM("Playing sound: "<<path_to_sound);
            system(path_to_sound.c_str());
        }
        catch(boost::thread_interrupted&)
        {
            system("killall -9 aplay");
            return;
        }
    };

    // Thread function
    void play_sound(std::string str)
    {
        boost::thread m_soundThread(&SoundManager::sound_thread, this, str);
    };

};

SoundManager sound_manager;

void sound_callback(const std_msgs::String::ConstPtr& msg) {
    std::string str = msg->data;
    ROS_INFO_STREAM("Got request to play sound: "<<str);
    sound_manager.play_sound(str);
}

int main(int argc, char** argv){
    // ROS Node Initialization
    ros::init(argc, argv, "human_interaction_node");
    ros::NodeHandle nh;

    // Subscribe to command node
    ros::Subscriber sound_sub = nh.subscribe("play_sound", 1, sound_callback);

    ROS_INFO("Starting interaction node");

    while(ros::ok())
    {
        ros::spinOnce();
    }
}
