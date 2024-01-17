#include "task.h"

Task::Task(int id, const std::string& title, const std::string& description){
    this->id = id;
    this->title = title;
    this->description = description;
    this->completed = false;
}

int Task::get_id() const{
    return id;
}

std::string Task::get_title() const {
    return title;
}

std::string Task::get_description() const {
    return description;
}

bool Task::isCompleted() const{
    return completed;
}

void Task::setAsCompleted(bool completed){
    this->completed = true;
}