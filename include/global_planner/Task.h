/**
 * Task.h - A "task" is any objective that can be assigned which robots can
 * accomplish.
 *
 * Tasks can have subtasks, and all have success and failure criteria
 *
 * All tasks must be given a name/uuid
 */

#include <ros/ros.h>
#include <boost/shared_ptr>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace Task
{
    enum Status
    {
        InProgress = 0,
        Success = 1,
        Failure = 2,
        Impossible = 3,
        Unknown = 4,
        Assigned = 5,
        Unassigned = 6,
    };

    class Task
    {
    public:
        virtual Task();
        ~Task();

        void addSubtask(task_ptr subtask){ m_subtasks.push_back(subtask); };

        // Returns the task at the given index;
        task_ptr getSubtask(int index) { return m_subtasks[index]; };
        bool isSubtaskDone(int index) { return m_subtasks[index].isFinished(); };
        bool isFinished(){ return m_status != InProgress; };

        double revenue;
        double cost;

    private:
        std::vector< task_ptr > m_subtasks;

        // The unique identifier of the task
        boost::uuids::uuid m_uuid;

        // The unique name of the task
        std::string m_name;

        //Time that the task was created
        ros::Time m_creation_time;

        // ID of the robot that this task is assigned to
        boost::uuids::uuid m_assigned_to;

        // Status of the task
        Status m_status;
    };

    // Easy way to share tasks
    typedef task_ptr boost::shared_ptr<Task>;
}