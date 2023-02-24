#pragma once
#include "std_lib_facilities.h"

class CourseCatalog {
private:
    map<std::string, std::string> courses;
public:
    void addCourse(const std::string& courseCode, const std::string& courseName);
    void removeCourse(const std::string& courseCode);
    std::string getCourse(const std::string& courseCode);
    void loadCoursesFromFile(const std::string& fileName);
    void saveCoursesToFile(const std::string& fileName);
    friend std::ostream& operator<<(std::ostream& os, const CourseCatalog& c);
};
